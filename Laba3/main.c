#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double f(double x);
double metod_hord(double x1, double x2, unsigned int N, unsigned int debug, double eps);
double metod_pol_dilen(double x1, double x2, unsigned int N, unsigned int debug, double eps);
int choices(void);

int main()
{
    double x1, x2, root, start, stop, eps;
    unsigned int N, debug, var;

    do{
       system("cls");
       printf("Select a function calculation method:\n");
       printf("1 - Method hord\n");
       printf("2 - Method of half division\n");
       scanf("%u", &var);
    }while(var>2 || var<1);

    do{
       printf("Initial value (x1):\n"); scanf("%lf", &x1);
       printf("Final value (x2):\n"); scanf("%lf", &x2);
       printf("Number of iterations (N):\n"); scanf("%u", &N);
       printf("Error (e):\n"); scanf("%lf", &eps);
       printf("Operating mode (1 - to display calculations, 0 - not to display):\n"); scanf("%u", &debug);
    }while(f(x1) * f(x2) > 0);

    start = clock();
    if(var==1){
        root = metod_hord(x1, x2, N, debug, eps);
        printf("\nx=%lf   f(x)=%lf", root, f(root));
    }

    else if(var==2){
        root = metod_pol_dilen(x1, x2, N, debug, eps);
        printf("\nx=%lf   f(x)=%lf", root, f(root));
    }
    stop = clock();

    printf("\nTime spent=%lf", (stop-start)/CLK_TCK);

    return 0;
}



 double f(double x){
     return ((6*x)*(10*x-pow(x,4)))/x;
 }


 double metod_hord(double x1, double x2, unsigned int N, unsigned int debug, double eps){

    double xi;
    unsigned int n=0, n1=N, c;

    do{
        xi = (f(x2)*x1-f(x1)*x2) / (f(x2)-f(x1));

        if(f(xi)*f(x1) > 0) x1 = xi; // якщо знаходяться в одній півплощині
        else x2 = xi;                 // якщо в різних

        if(debug==1){
            printf("\n%u  %lf    %lf", n, xi, f(xi));
        }

        if(n==n1){
            c = choices();
                if(c==1) n1=n1+N;
                else if(c==2) n1=0;
                else if(c==3) return xi;
        }

        n++;
    }while(fabs(f(xi)) > eps);

    return xi;
 }


double metod_pol_dilen(double x1, double x2, unsigned int N, unsigned int debug, double eps){

    double xi;
    unsigned int n=0, n1=N, c;

    do{
        xi = (x1+x2)/2;

        if(f(xi)*f(x1) > 0) x1 = xi;
        else x2 = xi;

        if(debug==1){
            printf("\n%u  %lf    %lf", n, xi, f(xi));
        }

        if(n==n1){
            c = choices();
                if(c==1) n1=n1+N;
                else if(c==2) n1=0;
                else if(c==3) return xi;
        }

        n++;
    }while(fabs(f(xi)) > eps);

    return xi;
 }

 int choices(void){
    unsigned int q;
    printf("\nThe root of the equation was not found. You have three choices:\n");
    printf("1 - continue with the same number of iterations;\n");
    printf("2 - perform until the end, until the roots are found;\n");
    printf("3 - exit the program;\n");
    scanf("%d", &q);
    return q;
 }
