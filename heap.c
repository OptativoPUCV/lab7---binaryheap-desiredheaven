#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){

  if (pq->size ==0)
  {
    return NULL;
  }
    return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){

  if (pq->size == pq->capac)
  {
    pq->capac = pq->capac*2+1;
    pq->heapArray = realloc(pq->heapArray, pq->capac*(sizeof(heapElem)));
  }

  int pos = pq->size;
  while (pos > 0  && pq->heapArray[(pos-1)/2].priority < priority)
    {
    pq->heapArray[pos] = pq->heapArray[(pos-1)/2];
    pos = (pos -1)/2;
    }
  pq->heapArray[pos].priority = priority;
  pq->heapArray[pos].data = data;
  pq->size++;
  
}


void heap_pop(Heap* pq){

  pq->size--;
  pq->heapArray[0] = pq->heapArray[pq->size];

  int pos = 0;
  int posizq = 1;
  int posder = 2;

  while (posizq < pq->size)
    {
      int hijo = posizq;
      if (posder < pq->size && pq->heapArray[posder].priority>pq->heapArray[posizq].priority)
      {
        hijo = posder;
      }
      if (pq->heapArray[pos].priority>=pq->heapArray[hijo].priority)
      {
        break;
      }
      heapElem aux = pq->heapArray[pos];
      pq->heapArray[pos] = pq->heapArray[hijo];
      pq->heapArray[hijo] = aux;
      pos = hijo;
      posizq = posizq *2+1;
      posder = posder *2+2;
    }
  

}

Heap* createHeap(){
  
 Heap* monticulo = (Heap*)malloc(sizeof(Heap));
  monticulo->heapArray =  (heapElem*)calloc(3,sizeof(heapElem));
  monticulo->size = 0;
  monticulo->capac = 3;
  
   return monticulo;
}
