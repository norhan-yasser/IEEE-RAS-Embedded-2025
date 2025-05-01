#include <stdio.h>

struct Cat {

    char *name;
    char *age;
    char *kind;
    char *food;
    char *Owner_name;
};


struct employee {

    char *name;
    int age ;
    int salary;
    unsigned long int id;
    char *job_title;

};


int main(){

   struct Cat cat1;
   struct employee emp1;

    cat1.name="coco";
    cat1.age="4 months";
    cat1.kind="Siamese cat";
    cat1.Owner_name="john";


    printf("%s\n",cat1.name);
    printf("%s\n",cat1.age);
    printf("%s\n",cat1.kind);
    printf("%s\n\n",cat1.Owner_name);


    emp1.name="john";
    emp1.age=28;
    emp1.salary=50000;
    emp1.id=389479872;
    emp1.job_title="embedded engineer";

    printf("%s\n",emp1.name);
    printf("%d\n",emp1.age);
    printf("%d\n",emp1.salary);
    printf("%lu\n",emp1.id);
    printf("%s\n",emp1.job_title);



}
