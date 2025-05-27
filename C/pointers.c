#include<stdio.h>
#include<stdlib.h>

/*
POINTERS - a variable like reference that holds a memory address to another variable, array, etc
* - indirection operator(value at address)
& - address of operator 
%p - format specifier for printing address
Advantages:
- less time in program execution
- working on original variable
- returning more than one values from functions
- dynamic mem allocation


*/

int main()
{
    int age = 20;
    int *ptr_age = &age; //accessing age by reference instead of value

    int x = *ptr_age; //x = value of age

    printf("address of age: %p\n", &age);
    printf("value of ptr_age: %p\n", ptr_age);

    printf("size of age: %d bytes\n", sizeof(age));
    printf("size of ptr_age: %d bytes\n", sizeof(ptr_age));

    printf("value of age: %d\n", age);
    printf("value at stored address: %d\n", *ptr_age); //de-referencing operator




    
    return 0;
}