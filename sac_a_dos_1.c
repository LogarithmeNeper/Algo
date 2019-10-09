#include <stdio.h>
#include <stdlib.h>

int main()
{
	int capacite;
	scanf("%d",&capacite);

	int tableau[capacite+1];
	int valeur[100];

    int max=0;
	int val=0;

	while(val!=-1)
	{
	    scanf("%d",&val);
	    valeur[max]=val;
	    max++;
	}

	tableau[0]=1;

	int i;
    int j;

    for (i=0;i<=capacite;i++)
    {
        if (tableau[i]==1)
        {
            for (j=0;j<=max;j++)
            {
                int local=valeur[j]+i;
                if (local<=capacite)
                {
                    tableau[local]=1;
                }
            }
        }
    }

	if (tableau[capacite]==1)
	{
	    printf("OUI\r\n");
	}
    else
    {
        printf("NON\r\n");
    }
    return 0;
}
