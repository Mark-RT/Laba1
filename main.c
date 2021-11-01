#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int main()
{
    unsigned char V;
    double x1, x2, delta, x, y;
    unsigned int N, n=1, h=0;

   do{
    printf("Please, choose variant: 1 or 2\n");
    scanf("%d", &V);
   }while(V!=1 && V!=2);

    if(V == 1){
        printf("Enter chisla:\n");
        printf("X1:"); scanf("%lf", &x1);
        printf("X2:"); scanf("%lf", &x2);
        printf("N:"); scanf("%u", &N);

        delta=(x2-x1)/(N-1);

        printf("\nX1=%.2lf \t X2=%.2lf \t N=%u \t delta=%.4lf\n", x1, x2, N, delta);
        printf("\nPress Enter to create a table:\n");

        getch();

        paint_star(46);
        printf("*      N      *      X      *      F(X)      *\n");
        paint_star(46);

        for(x = x1; x < x2; x=x+delta){
             y = 3*cos(x)/sqrt(2*x);
             paint_line();
             paint_chisla(n, x, y);
             paint_line();
             n++;

             if(n-h == 10){
                h=n;
                printf("Press Any Key to continue ...");
                getch();
                printf("\r");
             }

             if(n==N){
                return 0;
             }
         }
     }

    else if(V == 2){
        printf("Enter chisla:\n");
        printf("X1:"); scanf("%lf", &x1);
        printf("X2:"); scanf("%lf", &x2);
        printf("delta:"); scanf("%lf", &delta);

        N = 1+(x2-x1)/delta;

        printf("\nX1=%.2lf \t X2=%.2lf \t delta=%.4lf \t N=%d\n", x1, x2, delta, N);
        printf("\nPress Enter to create a table:\n");

        getch();

        paint_star(46);
        printf("*      N      *      X      *      F(X)      *\n");
        paint_star(46);

        for(x = x1; x < x2; x=x+delta){
             y = 3*cos(x)/sqrt(2*x);
             paint_line();
             paint_chisla(n, x, y);
             paint_line();
             n++;

             if(n-h == 10){
                h=n;
                printf("Press Any Key to continue ...");
                getch();
                printf("\r");
             }

             if(n==N){
                return 0;
             }
         }
    }

    else {
        return 0;
    }
}

void paint_star(int n){
    int i=0;
    for(; i<n; i++)
    {
        printf("*");
    }
    printf("\n");
}

void paint_line(){
    printf("+-------------+-------------+----------------+\n");
}

void paint_chisla(unsigned int q, double w, double e){

printf("|      %u      |     %.2lf    |     %.4lf     |\n", q, w, e);

}
