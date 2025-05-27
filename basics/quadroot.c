#include<stdio.h>
#include<math.h>
int main()
{   
    double a,b,c,D,r1,r2,e,f;
    printf("Enter coefficients of a, b and c");
    scanf("%lf %lf %lf", &a, &b, &c);

    D = b*b - 4*a*c;
    
    if(a == 0 && b == 0 && c == 0)
        printf("the quadratic equation has infinite solutions i.e. it is an identity");
    else if(a == 0 && b == 0 && c!= 0)
        printf("no solution i.e. inconsistent equation");
    else if(a==0)
    {   
        r1 = r2 = -c / b;
        printf("the root of linear equation is %.1lf", r1);
    }
    else if(D>0)
    {   
        r1 = (-b + sqrt(D)) / (2*a);
        r2 = (-b - sqrt(D)) / (2*a);
        printf("Real and distinct roots:\nr1 = %.1lf and r2 = %.1lf", r1, r2);
    }
    else if(D == 0)
    {   
        r1 = r2 = -b / 2*a;
        printf("Real and equal roots:\nr1 = r2 = %.1lf", r1);
    }
    else if(D<0)
    {   
        e = -b / 2*a;
        f = sqrt(-D) / 2*a;
        printf("Imaginary roots:\nr1 = %.1lf + %.1lfi and r2 = %.1lf - %.1lfi", e, f, e, f);
    }

    return 0;
}