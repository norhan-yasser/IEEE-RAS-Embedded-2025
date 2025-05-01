#include <stdio.h>


struct employee {

    char name[50];
    int age ;
    int salary;


};


 struct employee get_empolyee_data(){

   struct employee emp;

   printf("Enter name : ");
   scanf("%s",&emp.name);
   printf("Enter age : ");
   scanf("%d",&emp.age);
   printf("Enter salary : ");
   scanf("%d",&emp.salary);


   return emp;

 };


 void display_struct (struct employee*employee_obj){

   printf("display employee data\n");
   printf("Name : %s\n",employee_obj->name);
   printf("age : %d\n",employee_obj->age);
   printf("salary : %d\n",employee_obj->salary);

 }


int main(){


   struct employee emp1=get_empolyee_data();
   display_struct(&emp1);

   return 0;
}
