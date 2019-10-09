#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int allocated; /* current allocation of array */
  int filled;    /* number of items present in the binheap */
  int *array;    /* array of values */
} BinaryHeap;

/* Init allocates the structure BinaryHeap and
* also the membre array with the given size
* it also fill allocated (size) and intializes
* filled to 0 */
BinaryHeap * Init(int size);

/* InsertValue insert value into the binary heap
* the array is reallocated if necessary (allocated changed
* with respect to the new size )
* filled is incremented by 1 */
void InsertValue(BinaryHeap * heap, int value);

/* ExtractMAx returns 0 if the binary heap is empty
* otherwise it return 1 and fills *val with the maximum
* value present in the binary heap
* filled is decremented by 1  and the max value is removed
* from the binary heap */
int ExtractMax(BinaryHeap * heap, int * val);

void Print(BinaryHeap * heap);

/* Destroy frees the structure and the array */
void Destroy(BinaryHeap * heap);

void swap(int *a, int *b);

int main(void)
{
  char lecture[100];
  int val;
  BinaryHeap * heap;
  heap = Init(10);

  fscanf(stdin,"%99s",lecture);
  while (strcmp(lecture,"bye")!=0) {
    if (strcmp(lecture,"insert")==0) {
      fscanf(stdin,"%99s",lecture);
      val = strtol(lecture,NULL,10);
      InsertValue(heap,val);
    } else if (strcmp(lecture,"extract")==0) {
      if(ExtractMax(heap,&val))
      {
        printf("%d\r\n",val);
      }
    } else if(strcmp(lecture, "print") == 0) {
      Print(heap);
    }
    fscanf(stdin,"%99s",lecture);
  }
  Destroy(heap);
  return 0;
}

BinaryHeap * Init(int size)
{
  BinaryHeap * heap;
  heap = (BinaryHeap *) malloc(sizeof(BinaryHeap));
  heap -> allocated = size;
  heap -> filled = 0;
  heap -> array = (int *) malloc(sizeof(int) * size);
  return heap;
}

void InsertValue(BinaryHeap * heap, int value)
{
  if(heap -> filled == heap -> allocated) {
    printf("Tas binaire plein\r\n");
  } else {

    int i = heap -> filled;

    //Insère la valeur en fin d'arbre
    heap -> array[i] = value;

    while(i > 0 && heap -> array[(i - 1) / 2] < heap -> array[i]) {
      //Swap des noeuds
      int tmp = heap -> array[(i-1)/2];
      heap -> array[(i-1)/2] = heap -> array[i];
      heap -> array[i] = tmp;
      i = (i - 1) / 2;
    }

    heap -> filled++;
  }
}

void Print(BinaryHeap * heap) {
  for(int i = 0; i < heap -> filled; i++) {
    printf("%d ", heap -> array[i]);
  }
  printf("\r\n");
}

int ExtractMax(BinaryHeap * heap, int *res)
{

  if(heap -> filled == 0) {
    return 0;
  }

  //On récupère le maximum (la racine)
  *res = heap -> array[0];
  //On place le dernier élément à la racine
  heap -> array[0] = heap -> array[heap -> filled - 1];
  heap -> filled--;

  int maxDepth = heap -> filled - 1;
  int i = 0;

  while(((2*i+1) <= maxDepth && heap -> array[i] > heap -> array[2*i+1])
  || ((2*i+2) <= maxDepth && heap -> array[i] > heap -> array[2*i+2])) {

    int maxSubNode;

    //Si on a deux noeuds fils
    if(2*i+2 >= maxDepth) {
      //On prend l'indice du plus grand deux noeuds fils
      if(heap -> array[2*i+2] > heap -> array[2*i+1]) {
        maxSubNode = 2*i+2;
      } else {
        maxSubNode = 2*i+1;
      }
    } else { //Si on a un seul noeud fils
      maxSubNode = 2*i+1;
    }

    //Swap
    int tmp = heap -> array[i];
    heap -> array[i] = heap -> array[maxSubNode];
    heap -> array[maxSubNode] = tmp;
    i = maxSubNode;
  }

  return 1;
}

void Destroy(BinaryHeap * heap)
{
  free(heap -> array);
  free(heap);
}
