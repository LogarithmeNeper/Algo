  /**
* \file limited-weights-knapsack.c
* \author Charles Javerliat
*
* Programme permettant de déterminer si il est possible de remplir un sac d'une
* capacité donnée avec certains poids en quantité limitée (un seul objet de chaque poids).
*/
#include <stdio.h>
#include <stdint.h>
#include <string.h>

void solve_limited_weights_knapsack(int capacity, size_t nWeights, int weights[]) {

  short possible[nWeights][capacity + 1];
  memset(possible, 0, sizeof(short) * nWeights * (capacity + 1));

  int i;
  int j;

  //Initialise les cases pour la capacité 0 à 1
  for(i = 0; i < nWeights; i++) {
    possible[i][0] = 1;
  }

  for(i = 0; i < nWeights; i++) {
    for(j = 1; j < capacity + 1; j++) {

      if(i == 0) {
        possible[i][j] = j == weights[i];
      } else {
        int x = j - weights[i];
        possible[i][j] = possible[i][j] || possible[i-1][j];

        if(x >= 0) {
          possible[i][j] = possible[i][j] || possible[i-1][x];
        }

      }
    }
  }

  if(possible[nWeights-1][capacity]) {
    printf("OUI\r\n");
  } else {
    printf("NON\r\n");
  }

}

int main(void) {

  int capacity;
  scanf("%d", &capacity);

  int weights[100] = {};
  int weight;
  size_t n = 0;

  while(scanf("%d", &weight)) {
    if(weight == -1) {
      break;
    } else {
      weights[n] = weight;
      n++;
    }
  }

  solve_limited_weights_knapsack(capacity, n, weights);

  return 0;

}
