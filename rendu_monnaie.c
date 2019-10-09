/**
* \file rendu-monnaie.c
* \author Charles Javerliat
*
* Programme de calcul de rendu de monnaie optimal pour une somme donnée
* L'exercice utilise un système de monnaie canonique
*/

#include <stdio.h>

/**
* Affiche le nombre de pièces utilisés pour rendre la monnaie
* On suppose que coins est un système de monnaie canonique trié de manière décroissante
*/
void solve_change_making(unsigned int sum, size_t nCoins, unsigned int coins[]) {

  //Le compteur de pièces
  unsigned int count;
  size_t i;

  /*
  * Si on peut rendre de l'argent avec la pièce actuelle, on en rend le maximum possible
  * Ceci est du au fait que le problème utilise un système de monnaie canonique
  */
  for(i = 0; i < nCoins; i++) {

    count = 0;

    if(sum >= coins[i]) {
      count = sum / coins[i];
      sum -= coins[i] * count;
    }

    printf("%u\r\n", count);
  }

}

int main(void) {

  //La somme à atteindre avec les pièces
  int sum;
  scanf("%d", &sum);

  unsigned int coins[] = {50, 20, 10, 5, 1};

  solve_change_making(sum, 5, coins);

  return 0;
}
