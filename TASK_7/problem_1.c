#include <stdio.h>
#include <string.h>

struct student_info {
    unsigned int roll_number : 4;   // 4 bits
    unsigned int age         : 8;   // 8 bits
    unsigned int marks       : 3;   // 3 bits
    char name[50];                  // String
    char address[100];             // String
};




void print_student_info(struct student_info students[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Student %d:\n", i + 1);
        printf("  Roll Number: %u\n", students[i].roll_number);
        printf("  Age: %u\n", students[i].age);
        printf("  Marks: %u\n", students[i].marks);
        printf("  Name: %s\n", students[i].name);
        printf("  Address: %s\n\n", students[i].address);
    }
}


int main() {
    struct student_info students[5] = {
        {1, 18, 5, "osmanabdeljalilsheha", "faoos"},
        {2, 19, 6, "kanabawy", "menyaalkamh"},
        {3, 20, 7, "aykoubamaraldendebyaza", "zgazig"},
        {4, 21, 4, "khaledkashmiri", "belbes"},
        {5, 22, 3, "khidrkarawita", "abohamad"}
    };

    print_student_info(students, 5);

    printf("Size of student_info struct: %lu bytes\n", sizeof(struct student_info));

    return 0;
}
