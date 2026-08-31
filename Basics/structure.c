#include <stdio.h>
#include <string.h>

struct Class
{
    int number;
    char name[20];
    float marks;
};

int main()
{
    int x;
    struct Class student1 = {111, "Rao", 72.50};
    struct Class student2 = {222, "Reddy", 67.00};
    struct Class student3;
    // struct Class student3 = {269,"Rawat",67.00};

    student3 = student2;

    x = ((student3.number == student2.number) && (student3.marks == student2.marks)) ? 1 : 0;

    if (x == 1)
    {
        printf("\nStudent2 and Student3 are same\n\n");

        printf("%d %s %.1f", student3.number, student3.name, student3.marks);
    }
    else
    {
        printf("\nStudent2 and Student3 are different");
    }
}

#include <stdio.h>
#include <string.h>

struct Class
{
    char name[30];
    char address[50];
};

struct Class student[100];

struct Marks
{
    int subject1;
    int subject2;
    int subject3;
};

int main()
{
    strcpy(student[0].name, "Abhirup Saha");
    printf("%s\n", student[0].name);

    struct Marks student[3] = {{45, 65, 76}, {76, 45, 23}, {78, 89, 76}};
    printf("%d\n", student[1].subject2);
}
