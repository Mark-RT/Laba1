#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float myfunc(float x){
    return x*x*sin(x);
}

float LeftRectangle(float a, float b, int n){
    float h;
    h=(b-a)/n;
    float sum = 0;
    for(int i=0; i<=n-1; i++)
        {
        sum+=h*myfunc(a+i*h);
        }
    return sum;
}

float RightRectangle(float a, float b, int n){
    float h;
    h=(b-a)/n;
    float sum = 0;
    for(int i=1; i<=n; i++)
        {
        sum+=h*myfunc(a+i*h);
        }
    return sum;
}

float Trapezia(float a, float b, int n){
    float h;
    h=(b-a)/n;
    float sum = myfunc(a)+myfunc(b);
    for(int i=1; i<=n-1; i++){
    sum+=2*myfunc(a+i*h);
        }
    sum*=h/2;
    return sum;
}

float Simpson(float a, float b, int n){
    float h;
    h=(b-a)/(n);
    float sum = myfunc(a)+myfunc(b);
    int k;
    for(int i=1; i<=n-1; i++){
        k=2+2*(i%2);
        sum+=k*myfunc(a+i*h);
            }
    sum*=h/3;
    return sum;
}

void Var1(float a, float b, float q, unsigned int n){
    unsigned int i=0;
    float riz;
    do{
        i+=2;
        riz=fabs(LeftRectangle(a,b,i)-LeftRectangle(a,b,i+2));
    }while(riz>q);
    printf("+----------+----------+----------+----------+----------+----------+\n");
    printf("|         1|%.6f|%.6f|%.6f|%.6f|  %u  |\n", LeftRectangle(a,b,n), LeftRectangle(a,b,10), LeftRectangle(a,b,100), LeftRectangle(a,b,1000), i);
    printf("+----------+----------+----------+----------+----------+----------+\n");
}

void Var2(float a, float b, float q, unsigned int n){
    unsigned int i=0;
    float riz;
    do{
        i+=2;
        riz=fabs(RightRectangle(a,b,i)-RightRectangle(a,b,i+2));
    }while(riz>q);
    printf("+----------+----------+----------+----------+----------+----------+\n");
    printf("|         2|%.6f|%.6f|%.6f|%.6f|  %u  |\n", RightRectangle(a,b,n), RightRectangle(a,b,10), RightRectangle(a,b,100), RightRectangle(a,b,1000), i);
    printf("+----------+----------+----------+----------+----------+----------+\n");
}

void Var3(float a, float b, float q, unsigned int n){
    unsigned int i=0;
    float riz;
    do{
        i+=2;
        riz=fabs(Trapezia(a,b,i)-Trapezia(a,b,i+2));
    }while(riz>q);
    printf("+----------+----------+----------+----------+----------+----------+\n");
    printf("|         3|%.6f|%.6f|%.6f|%.6f|  %u  |\n", Trapezia(a,b,n), Trapezia(a,b,10), Trapezia(a,b,100), Trapezia(a,b,1000), i);
    printf("+----------+----------+----------+----------+----------+----------+\n");
}

void Var4(float a, float b, float q, unsigned int n){
    unsigned int i=0;
    float riz;
    do{
        i+=2;
        riz=fabs(Simpson(a,b,i)-Simpson(a,b,i+2));
    }while(riz>q);
    printf("+----------+----------+----------+----------+----------+----------+\n");
    printf("|         4|%.6f|%.6f|%.6f|%.6f|  %u  |\n", Simpson(a,b,n), Simpson(a,b,10), Simpson(a,b,100), Simpson(a,b,1000), i);
    printf("+----------+----------+----------+----------+----------+----------+\n");
}

int main()
{
    float a, b, q;
    unsigned int n, variant, i;
    do{
    printf("Enter your variant (1: LeftRectangle, 2: RightRectangle, 3: Trapezia, 4: Simpson):\n");
    scanf("%u", &variant);
    } while(variant>4 || variant<1);

    printf("Enter lower limit:\n");
    scanf("%f",&a);
    printf("Enter upper limit:\n");
    scanf("%f",&b);
    printf("Enter allowable error:\n");
    scanf("%f",&q);
    printf("Enter number of points:\n");
    scanf("%u",&n);

    printf("\n+----------+----------+----------+----------+----------+----------+\n");
    printf("| Metod    |    N     |   N=10   |   N=100  |  N=1000  |    n     |\n");
    printf("+----------+----------+----------+----------+----------+----------+\n");

    if(variant==1) Var1(a,b,q,n);

    else if(variant==2) Var2(a,b,q,n);

    else if(variant==3) Var3(a,b,q,n);

    else if(variant==4) Var4(a,b,q,n);

    return 0;
}
