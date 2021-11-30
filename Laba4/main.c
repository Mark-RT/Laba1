#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_masA(int a, int **masA)
{
    printf("Matrix *A*:\n");
    for(int i=0; i<a; i++)
    {
        for(int j=0; j<a; j++)
            printf("%d\t", masA[i][j]);

        printf("\n");
    }
    printf("\n");
}

void print_masB(int bh, int bw, int **masB)
{
    printf("Matrix *B*:\n");
    for(int i=0; i<bh; i++)
    {
        for(int j=0; j<bw; j++)
            printf("%d\t", masB[i][j]);

        printf("\n");
    }
    printf("\n");
}

void max_min_masA(int a, int **masA)
{
    int max, min;

    max = masA[0][0];
    min = masA[0][0];

    for(int i=0; i<a; i++)
    {
        for(int j=0; j<a; j++)
        {
            if(masA[i][j]>max)
                max = masA[i][j];

            else if (masA[i][j]<min)
                min = masA[i][j];
        }
    }
    print_masA(a, masA);
    printf("Maximum = %d\tMinimum = %d\n\n", max, min);
}

void transp_masB(int bh, int bw, int **masB)
{
    int TRmasB[bw][bh];

    for(int i=0; i<bh; i++)
    {
        for(int j=0; j<bw; j++)
            TRmasB[j][i] = masB[i][j];
    }
    print_masB(bh, bw, masB);
    printf("Transposed:\n");
    for(int i=0; i<bw; i++)
    {
        for(int j=0; j<bh; j++)
            printf("%d\t", TRmasB[i][j]);

        printf("\n");
    }
    printf("\n");
}

void dobut_masAB(int a, int **masA, int bh, int bw, int **masB)
{
    int s, r;

    if(a == bh) //якщо кількість стовпців першої матриці = кількості рядків другої матриці
    {
        if(a>=bh) s = a;

        else if(a<=bh) s = bh;

        r = a;
        int dob_matr[s][r];

        for(int i=0; i<s; i++)
        {
            for(int j=0; j<r; j++)
            {
                dob_matr[i][j] = 0;
                for(int k=0; k<s; k++)
                {
                    dob_matr[i][j] += masA[i][k] * masB[k][j];
                }
            }
        }

        print_masA(a, masA);
        print_masB(bh, bw, masB);

        printf("Dobutok:\n");
        for(int i=0; i<s; i++)
        {
            for(int j=0; j<r; j++)
                printf("%d\t", dob_matr[i][j]);

            printf("\n");
        }
        printf("\n");
    }

    else
    {
        printf("The columns *A* not equal columns *B*. Create new matrixs or next task.\n\n");
        return 0;
    }
}

void sorting_masA(int a, int **masA, int row)
{
    int sort_masA[a];
    for(int i=0; i<a; i++)
    {
        sort_masA[i] = masA[row][i];
    }

    for(int i = 0 ; i < a - 1; i++) // сравниваем два соседних элемента.
    {
       for(int j = 0 ; j < a - i - 1 ; j++)
        {
            if(sort_masA[j] > sort_masA[j+1]) // если они идут в неправильном порядке, то меняем их местами.
            {
              int tmp = sort_masA[j];
              sort_masA[j] = sort_masA[j+1] ;
              sort_masA[j+1] = tmp;
            }
        }
    }

    printf("Sorting:\n");
    for(int i=0; i<a; i++)
    {
        printf("%d\t", sort_masA[i]);
    }
    printf("\n\n");

}

void suma_masAB(int a, int **masA, int bh, int bw, int **masB)
{
    int sumA = 0;
    int sumB = 0;

    for(int i=0; i<a; i++)
        for(int j=0; j<a; j++)
            sumA += masA[i][j];

    for(int i=0; i<bh; i++)
        for(int j=0; j<bw; j++)
            sumB += masB[i][j];

    print_masA(a, masA);
    print_masB(bh, bw, masB);
    printf("Suma masA:%d\tSuma masB:%d\t\n\n", sumA, sumB);
}

void array_free(int a, int **masA, int bh, int **masB)
{
    for(int i = 0; i < a; i++) {
        free(masA[i]);
    }
    free(masA);

    for(int i = 0; i < bh; i++) {
        free(masB[i]);
    }
    free(masB);
}

int main()
{
    srand(time(NULL));
    int a, bh, bw, var;

    printf("1Enter the size of the matrix *A*:\n"); scanf("%d", &a);
    printf("Enter the height of the matrix *B*:\n"); scanf("%d", &bh);
    printf("Enter the width of the matrix *B*:\n"); scanf("%d", &bw);

    int **masA;
    masA = malloc(sizeof(*masA) * a);
    for(int i=0; i<a; i++)
        masA[i] = malloc(sizeof(**masA) * a);

    int **masB;
    masB = malloc(sizeof(*masB) * bh);
    for(int i=0; i<bh; i++)
        masB[i] = malloc(sizeof(**masB) * bw);

    printf("Select option:\n");
    printf("1 - enter matrix elements from the keyboard;\n");
    printf("2 - random;\n");
    scanf("%d", &var);

    if(var == 1)
    {
        printf("Enter the elements of the matrix *A* for each line:\n");
        for(int i=0; i<a; i++)
        {
            for(int j=0; j<a; j++)
                scanf("%d", &masA[i][j]);

            printf("Next line\n");
        }

        printf("Enter the elements of the matrix *B* for each line:\n");
        for(int i=0; i<bh; i++)
        {
            for(int j=0; j<bw; j++)
                scanf("%d", &masB[i][j]);

            printf("Next line\n");
        }
    }

    else if (var == 2)
    {
        for(int i=0; i<a; i++)
            for(int j=0; j<a; j++)
                masA[i][j] = rand()%10;

        for(int i=0; i<bh; i++)
            for(int j=0; j<bw; j++)
                masB[i][j] = rand()%15;
    }

    system("cls");

    print_masA(a, masA);
    print_masB(bh, bw, masB);

    do
    {
    printf("Select task:\n");
    printf("0 - stop program;\n");
    printf("1 - max and min elements of matrix *A*;\n");
    printf("2 - transponuv matrix *B*;\n");
    printf("3 - *A* x *B*;\n");
    printf("4 - sort in line matrix *A*;\n");
    printf("5 - suma rows *A* and suma columns *B*.\n");
    scanf("%d", &var);

    if(var == 1)
    {
        system("cls");
        max_min_masA(a, masA);
    }

    else if(var == 2)
    {
        system("cls");
        transp_masB(bh, bw, masB);
    }

    else if(var == 3)
    {
        system("cls");
        dobut_masAB(a, masA, bh, bw, masB);
    }

    else if(var == 4)
    {
        int row;

        do
        {
        system("cls");
        print_masA(a, masA);
        printf("Select a row of matrix:\n");
        scanf("%d", &row);
        }while(row>a-1 || row<0);

        sorting_masA(a, masA, row);
    }

    else if(var == 5)
    {
        system("cls");
        suma_masAB(a, masA, bh, bw, masB);
    }


    }while(var!=0);

    array_free(a, masA, bh, masB);

    return 0;
}


