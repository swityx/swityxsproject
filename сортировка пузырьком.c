#include <stdio.h>

#include <stdlib.h>

int main()
{
    int N;
    printf("Enter the size of the array: ");
    scanf_s("%d", &N);

    int* mass;
    mass = (int *)malloc(N * sizeof(int));// выделение памяти под массив

    printf("Input the array elements:\n");//считывание элементов массива
    for (int i = 0; i < N; i++)
        scanf_s("%d", &mass[i]);

    //далее сама сортировка
    int save; //сейв
    //int point; //указатель

    for (int i = N - 1; i >= 0; i--)
    {
        //point = 1;
        for (int j = 0; j < i; j++)
        {
            if (mass[j] > mass[j + 1])
            {
                save = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = save;
                //point = 0;
            }
        }
        //if (point == 1)
            //break;
    }
    printf("Sorted array:\n");
    for (int i = 0; i < N; i++)
        printf("%d ", mass[i]);
    printf("\n");
    free(mass);
    return 0;
}
