#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _pile
{
	int valeur;
	struct _pile* next;
}pile;

pile* aVoir=NULL;

void ajouter(int n)
{
	pile* nouvel_element= (pile*) malloc(sizeof(pile));
	nouvel_element->valeur=n;
	nouvel_element->next=aVoir;

	aVoir=nouvel_element;
}

int pop()
{
	int res;
	res=aVoir->valeur;
	pile* suite=aVoir->next;
	aVoir=suite;
	return res;
}

void afficher()
{
	pile* _aVoir=aVoir;
	while(_aVoir!=NULL)
	{
		printf("%d\n",_aVoir->valeur);
		_aVoir=_aVoir->next;
	}
}//non utilisée, mais utile

void destroy()
{
	pile* current=aVoir;
	pile* suivant=NULL;

	while(current!=NULL)
	{
		suivant=current->next;
		free(current);
		current=suivant;
	}
	aVoir=NULL;
}


int main()
{

	/* Idée du programme :
	On fixe un tableau de pseudos-booléens entre 0 et volume (1 si déjà traité, 0 sinon)
	On utilise une pile (possible avec une file, adapter au besoin) pour mettre les valeurs à traiter.
	On initialise la pile puis on ajoute la valeur initiale. Tant que non NULL, on dépile et on regarde si déjà traité (en O(1))
	Si non traité on empile ce qui est permis, avec un max.


	L'algorithme termine car au maximum (volumes+1) valeurs à traiter, le tableau de pseudo-booléens assure qu'on ne traite pas deux fois.
	*/

	int volume;
	scanf("%d",&volume);

	int dejaVus[volume+1];
	int i;

	int max=0;

	// initialisation du tableau de booléens
	for(i=0;i<=volume;i++)
	{
		dejaVus[i]=0;
	}

	int initial;
	scanf("%d",&initial);

	ajouter(initial);

	while(aVoir!=NULL)
	{
		int local=pop();

		if(local>max)
		{
			max=local;
		}

		if(dejaVus[local]==0)
		{
			dejaVus[local]=1;

			if(3*local<=volume)
			{
				ajouter(3*local);
			}
			if(2*local<=volume)
			{
				ajouter(2*local);
			}
			int localissime=floor(local/5);
			if(dejaVus[localissime]==0) // evite l'ajout inutile
			{
				ajouter(localissime); 
			}
		}
	}

	printf("%d\r\n",max);
	destroy();
	return 0;
}
