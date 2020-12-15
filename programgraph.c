#include <stdio.h>
#include <stdlib.h>
FILE * fo;
int main()
{
    printf("Enter size vertex*edge:\n");
    int vertex, edge;
    scanf("%d", &vertex);
    scanf("%d", &edge);
        scanf("%*[^\n]");
    int mass[vertex][edge];

    printf("Enter matrix:\n");
    for (int i = 0; i < vertex; i++)
        for (int j = 0; j < edge; j++)
            while (scanf("%d", &(mass[i][j])) != 1 || (mass[i][j] != 0 && mass[i][j] != 1))
                scanf("%*[^\n]");
    int degree;
    int md[vertex];
    printf("Enter vertex degree:\n");
    scanf("%d", &degree);
        for (int i = 0; i < vertex; i++){
            int counter = 0;
            for (int j = 0; j < edge; j++){
                if (mass[i][j] == 1) {
                counter++;
                }
            if (degree == counter)
                md[i] = i+1;
             else
                md[i] = 0;
            }
        }
    printf("Vertices with %d degree:", degree);
    for (int i = 0; i < vertex; i++){
        if (md[i] != 0)
            printf("%d ",md[i]);
    }
    printf("\n");
    fo = fopen("test.dot","wt");
    fprintf(fo, "graph Graph {\n");
    for (int j = 0; j < edge; ++j)  {
        int x1 = -1;
        int x2 = -1;
        for (int i = 0; i < vertex; ++i)
            if (mass[i][j] == 1) {
                if  (x1 != -1)
                    x2 = i;
                else
                    x1 = i;
            }
        if (x1!=-1 && x2!=-1)
            fprintf( fo, "  %d -- %d;\n", x1+1, x2+1);
    }
    fprintf(fo, "}\n");
    fclose(fo);


    int conectx[vertex][vertex];
    for (int j = 0; j < edge; ++j) {
        int x1 = -1;
        int x2 = -1;
        for (int i = 0; i < vertex; ++i)
            if (mass[i][j] == 1) {
                if (x1 != -1)
                    x2 = i;
                else
                    x1 = i;
            }
        conectx[x1][x2] = 1;
    }


    int count = 0;
    for (int i = 0; i < vertex; ++i)
        for (int j = 0; j < vertex; ++j)
            if (conectx[i][j] == 1)
                ++count;

    //printf("%d\n", count);

    if ((vertex-1)*(vertex-2)/2 < count)
        printf("Graph is connected");
    else
        printf("Graph is not connected");

    system("dot -Tpng test.dot -o test.png");
    return 0;
}
