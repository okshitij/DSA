#include<stdio.h> //contains all the predefined fuctions like printf(), scanf(), etc.
#include<stdlib.h> //contains all the predefined fuctions like malloc(), free(), etc.
#include<math.h> //contains all the predefined fuctions like pow(), sqrt(), etc.
#include<string.h> //contains all the predefined fuctions like strlen(), strcpy(), strrev() etc.
#include<ctype.h> //contains all the predefined fuctions like toupper(), tolower(), etc.

int z; //global variable declaration

#define PI = 3.14 //constant declaration ie value of PI is 3.14 through the program
// PI is capitalized because thats the syntax

const g = 9.8; //constant declaration ie value of g is 9.8 through the program

void swap(int a, int b); //fuction declaration
/*if you want to write the function after main() then you have to write the function declaration before main()
    but no need to declare the function if we write the function before main().
    - A function needs to have a return type or void if you arent returning anything*/

struct student
{
    int rollno;
    char name[20];
    double phone_no;
}student1; //declaration of structure
/*a structure is basically used to store all the attributes(variables) of a specific entity
ie if you use student1 as a variable it will contain all the sub variables: rollno, name, phone_no
- the memory allocated to a structure is the total or sum of each variable in the structure
    in above struct, the mem allocated is: 4 bytes + 20 bytes + 8 bytes = 36 bytes*/

union teacher
{
    int prn; 
    char email[20];
    double phone_no;
}teacher1; //declaration of union
/*same as structure but only difference is that the memory allocated to a union will be the
variable with the highest memory allocation ie in above union, the mem allocated is: 20 bytes*/


int main() // function which is called first when the program starts
{
    int a; // declaration of variable
    int b = 10; // initialization of variable

    printf("Enter the value of a: ");
    scanf("%d", &a); //%d is the format specifier, &a is the address of the variable a
    /*%s->string,
     %c->character,
     %d->integer, 
     %f->floating point, 
     %e->exponential
     %p->address of the variable*/

    for(int i = 0; i < 10; i++) // for(initialization; condition; increment or decrement)
    {
        //indexing in C usually starts from 0
    }

    while(a > 0){} // while(condition)

    do{} while(a > 0); // do{} while(condition)

    if(a > 0){} // if(condition)

    swap(a, b); // calling the function by value(call by value)
    //in call by reference we mention the address of the variable(pointer) in the function call

    int array[5]; //array declaration with size 5(can store 5 elements with same datatype)
    //the array name points to the starting address of the array ie it acts as a pointer
    for(int i=0; i<5; i++)
    {
        scanf("%d", &array[i]); //take input of the array elements
    }

    char string[10];
    /*if the size is 10 then we can store 9 characters cause the last character is '\0' which is a null
    character(represents the end of the string)*/



    return 0; // return 0 to indicate that the program ran successfully and return -1 to indicate that the program failed
}

//function syntax: returntype function_name(datatype parameter1, datatype parameter2,...)
void swap(int a, int b) // function definition
{
    int temp; // here temp is a local variable, it is not accessible outside the function
    //in a function, priority is: local variable > global variable > static variable
    temp = a;
    a = b;
    b = temp;
}

/*
    OTHER IMP POINTS:
    - 1 byte = 8 bits
    - static mem allocation - stack mem and dynamic mem allocation - heap mem
    - while(1) acts as an infinite loop
    - break acts as a statement to exit the loop and continue acts as a statement to continue the loop but skip to the next iteration in the same loop
    - arrays use static mem allocation
    - ternary operator(one line if else statement) -  condition? true_value : false_value
    - use abs() function to get the absolute value of a number ie positive value
    - every string ends with '\0'
    - DRY RUNNING THE CODE HELPS A LOT: use pencil and paper!
*/