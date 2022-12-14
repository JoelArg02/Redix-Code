//Trabajo en grupo
//GRUPO N°7
//NRC: 9394
//Ing. Edgar Montaluisa
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define NUMELTS 20
  
  struct {
    int info;
    int next;
  } node[NUMELTS];

void radixsort(int x[], int n);

int main(void){
  int x[50] = {0}, i;
  static int n;
  cout<<"Metodo de ordenamiento Radix"<<endl;
  cout<<"Una vez ingresado los numeros que desee ordenar aplaste la tecla Y"<<endl;
  cout<<"Cadena de numeros enteros: "<<endl;
  for (n = 0;; n++){
  	if (!scanf("%d", &x[n])) break;
  	}
  if(n){
  	radixsort (x, n);
	for (i = 0; i < n; i++){
  	cout<<x[i]<<" - ";
  	}
  }
  return 0;
}

void radixsort(int x[], int n)
{
  int front[10], rear[10];
  int exp, first, i, j, k, p, q, y;

  /* Inicializar una lista enlazada */
  for (i = 0; i < n-1; i++) {
    node[i].info = x[i];
    node[i].next = i+1;
  } 
  node[n-1].info = x[n-1];
  node[n-1].next = -1;
  first = 0; /* first es la cabeza de la lista enlazada */
  for (k = 1; k < 5; k++) {
    /* Suponer que tenemos números de cuatro dígitos */
    for (i = 0; i < 10; i++) {
      /*Inicializar colas */
      rear[i] = -1;
      front[i] = -1;
    }
    /* Procesar cada elemento en la lista */
    while (first != -1) {
      p = first;
      first = node[first].next;
      y = node[p].info;
      exp = pow(10, k-1);
      j = (y/exp) % 10; 
      /* Insertar y en lista */
      q = rear[j];
      if (q == -1)
	front[j] = p;
      else
	node[q].next = p;
      rear[j] = p;
    } 

    /* En este punto, cada registro está en su cola basándose en el dígito k
       Ahora formar una lista única de todos los elementos de la cola.
       Encontrar el primer elemento. */
    for (j = 0; j < 10 && front[j] == -1; j++);
      ;
    first = front[j];

    /* Vincular las colas restantes */
    while (j <= 9) { 	/* Verificar si se ha terminado */
      /*Encontrar el elemento siguiente */
      for (i = j+1; i < 10 && front[i] == -1; i++);
	;
      if (i <= 9) {
	p = i;
	node[rear[j]].next = front[i];
      } /* fin del if */
      j = i;
    } /* fin del while */
    node[rear[p]].next = -1;
  } /* fin del for */

  /* Copiar de regreso al archivo original */
  for (i = 0; i < n; i++) {
    x[i] = node[first].info;
    first = node[first].next;
  } /*fin del for */
} /* fin de radixsort*/


