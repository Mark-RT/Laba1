#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LINE_SIZE 10

void array_fill(int x, int y, int count, int **array){
    int i = count;
    int j = 0;
    array[i][j] = x;
    array[i][j+1] = y;
}

int main()
{
    char st1[LINE_SIZE];
    char st2[LINE_SIZE];
    char st3[LINE_SIZE];
    char st4[LINE_SIZE];
    char st5[LINE_SIZE];

    int x1, x2, N, delta, x, y, i, j;

//===============Зчитую дані з текстового файлу input.dat=========================//
    FILE *fin;
    fin = fopen("D:\\Laba5\\input.dat.txt", "rt");  // "rt" - відкриває текстовий файл для читання

    if(fin == NULL){
        printf("No open file. Check way");
        return;
    }

    if ( NULL != fgets ( st1, sizeof(st1), fin ) )
       //printf("%s",st1);

    if ( NULL != fgets ( st2, sizeof(st2), fin ) )
        //printf("%s",st2);
        x1 = atoi(st2);

    if ( NULL != fgets ( st3, sizeof(st3), fin ) )
        //printf("%s",st3);
        x2 = atoi(st3);

    if ( NULL != fgets ( st4, sizeof(st4), fin ) )
        //printf("%s",st4);
        N = atoi(st4);

    if ( NULL != fgets ( st5, sizeof(st5), fin ) )
        //printf("%s\n",st5);
        delta = atoi(st5);

    fclose(fin);
//==============================================================================//

    if(N == 0) N = 1+(x2-x1)/delta;

    if(delta == 0) delta = (x2-x1)/(N-1);

    int **array;
    array = malloc(sizeof(*array) * N);
    for(int i=0; i<N; i++)
        array[i] = malloc(sizeof(**array) * 2);


    for(x = x1; x <= x2; x=x+delta){
        y = 3*x;
        array_fill(x, y, i, array);
        i++;
    }
   // printf("%d\n", array[2][1]);

//===========Заношу таблицю до файлу result.txt================//
    FILE *res_txt;
    res_txt = fopen("D:\\Laba5\\result.txt", "wt");  // "wt" - відкриває текстовий файл для запису

    fprintf(res_txt, "%d\n", N);

    for(i = 0; i<N; i++){
        j = 0;
        fprintf(res_txt, "%d %d\n", array[i][j], array[i][j+1]);
    }

    fclose(res_txt);
//==============================================================//


//===========Заношу таблицю до файлу result.bin================//
    FILE *res_bin;
    res_bin = fopen("D:\\Laba5\\result.bin", "wb");  // "wb" - створює двійковий файл для запису

    fwrite(&N, 1, sizeof(N), res_bin);

    int arr_1column[N];
    int arr_2column[N];

    for(i=0; i<N; i++)
        arr_1column[i] = array[i][0];

    for(i=0; i<N; i++)
        arr_2column[i] = array[i][1];

    fwrite(arr_1column, 1, sizeof(arr_1column), res_bin);
    fwrite(arr_2column, 1, sizeof(arr_2column), res_bin);

    fclose(res_bin);
//==============================================================//


//===========Читаю таблицю з файлу result.bin================//
    res_bin = fopen("D:\\Laba5\\result.bin", "rb");  // "rb" - відкриває двійковий файл для читання

    fread(&N, 1, sizeof(N), res_bin);
    //printf("%d\n", N);

    fread(arr_1column, 1, sizeof(arr_1column), res_bin);
    fread(arr_2column, 1, sizeof(arr_2column), res_bin);

    for(i=0; i<N; i++)
       array[i][0] = arr_1column[i];

    for(i=0; i<N; i++)
        array[i][1] = arr_2column[i];

    fclose(res_bin);

    N=1;
    for(i=0; i<N; i++){
    j = 0;
    x = array[i][j];
    y = array[i][j+1];
    printf("+-------------+-------------+----------------+\n");
    printf("|      %d     |     %d      |     %d         |\n", N, x, y);
    printf("+-------------+-------------+----------------+\n");
    N++;
    }
    return 0;
}
