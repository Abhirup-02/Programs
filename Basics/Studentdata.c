#include <stdio.h>
#include <string.h>

struct StudentData
{
    int rollNo;
    char name[30];
    int age;
    float marks;
};

int main()
{

    struct StudentData abhirup;
    // struct StudentData abhirup = {014,"Abhirup Saha",20,450};

    abhirup.rollNo = 014;
    // strcpy(abhirup.name,"Abhirup Saha");
    printf("Enter your name: ");
    fgets(abhirup.name, 30, stdin);
    abhirup.age = 20;
    printf("Enter marks:");
    scanf("%f", &abhirup.marks);
    // abhirup.marks = 450;

    printf("\n%d", abhirup.rollNo);
    printf("\nYour full name is %s", abhirup.name);
    printf("%d", abhirup.age);
    printf("\n%.1f", abhirup.marks);

    return 0;
}

// #include<stdio.h>
// #include<string.h>

// typedef struct
// {
//     int roll;
//     float marks;
// }Student;

// int main(){
//     Student akash;
//     akash.roll=45;
//     akash.marks=65.67;

//     printf("%d %.2f",akash.roll,akash.marks);
// }