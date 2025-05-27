#include<stdio.h> //Q19

int main()
{
    int a, b, c, d, e, g;
    float f;
    int *ptr1, *ptr2;
    printf("enter two numbers:\n");
    scanf("%d %d", &a, &b);

    ptr1 = &a;
    ptr2 = &b;

    c = *ptr1 + *ptr2;
    d = *ptr1 - *ptr2;
    e = (*ptr1) * (*ptr2);
    f = (*ptr1)*1.0 / (*ptr2);
    g = (*ptr1) % (*ptr2);

    printf("addition of the numbers is: %d\n", c);
    printf("subtraction of the numbers is: %d\n", d);
    printf("multiplication of the numbers is: %d\n", e);
    printf("division of the numbers is: %f\n", f);
    printf("modulus of the numbers is: %d\n", g);

    return 0;

}