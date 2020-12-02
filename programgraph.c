#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
FILE* f;

int main(void)
{   setlocale(LC_ALL, "Rus");
    printf("введите количество ребер и вершин\n");
    int rb, vr;

    scanf("%d",&rb);
    printf("\n");
    scanf("%d",&vr);

    int m[rb][vr];

        for (int i = 0; i < rb; i++) {
            for (int j = 0; j < vr; j++){
                scanf("%d",&m[i][j]);
                }
        }

        f = fopen("text.dot","w");
        if (f == NULL)
            return 0;

        fprintf(f,"graph MyGraf {\n");

        for (int i = 0; i < rb; i++)
        {
            int x1 = -1;
            int x2 = -1;

            for (int j = 0; j < vr; j++)
            {
                if (m[i][j] == 1 && x1 == -1 )
                    x1 = j+1;
                else if (m[i][j] == 1 && x2 == -1 )
                    x2 = j+1;
                 else if (m[i][j] == 2 )
                    x2 = x1 = j+1;
            }
            if (x1 == -1)
                fprintf(f,"%d;\n",x2);
            else if (x2 == -1)
                fprintf(f,"%d;\n",x1);
            else
                fprintf(f,"%d -- %d\n",x1,x2);

        }

        fprintf(f,"}");

        int kols = rb;

        // finding loops and multiple edges
        for (int i = 0; i < rb; i++)
        {
            for (int j = 0; j < vr; j++)
            {
                if (m[i][j] == 2)
                    kols--;
            }
        }
        int sovp;
        for(int p = 0; p < rb; p++)
        {
            kols++;
            for (int i = 0; i < rb; i++)
            {
                sovp = 0;
                for (int j = 0; j < vr; j++)
                {
                    if ( m[p][j] == m[i][j])
                    sovp++;
                }
                if (sovp == rb)
                kols--;
            }
        }
        int sum1 = 0;
        for (int i = 0; i < rb; i++)
        {
            sum1 = 0;
            for (int j = 0; j < vr; j++)
            {
                if ( m[i][j] > 0)
                sum1++;
            }
            if (sum1 == 1)
            kols--;
        }

        if (vr == 2)
        {
            if (kols >= 1)
                printf("Граф подключен");
            else
                printf("Граф не подключен");
            return 0;
        }
            if (vr == 3)
        {
            if (kols >= 2)
                printf("The graph is connected");
            else
                printf("The graph is not connected");
            return 0;
        }



    return 0;
}
