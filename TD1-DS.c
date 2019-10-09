#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nb;
    scanf("%d",&nb);

    int it=0;
    float somme=0;
    float avg;

    int i=0;
    for (i=0; i<nb; i++)
    {
        float fValeur;
        scanf("%f",&fValeur);

        if (fValeur<=0)
        {
            somme+=fValeur;
            it++;
        }
    }

    if (it!=0)
    {
        avg=somme/it;
        printf("%f\r\n",avg);
    }
    else
    {
        printf("-\r\n");
    }

    return 0;
}
