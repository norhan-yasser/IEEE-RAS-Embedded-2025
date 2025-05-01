/* c program to remove the variable of the struct by the overwrite */

#include <stdio.h>
#include <string.h>

struct cat {
    char name[50];
    int age;
    char kind[50];
};

#define MAX_CATS 10

void displaycats(struct cat cats[], int count)
{
    printf("Array of cats after deletion:\n");
    for (int i = 0; i < count; ++i) {
        printf("Name: %s, Age: %d, kind : %s \n", cats[i].name,
               cats[i].age , cats[i].kind);
    }
    printf("\n");
}

int main()
{

    // intializing array of structure
    struct cat cats[MAX_CATS] = {
        { "cat1", 5 , "orangecat"},
        { "cat2", 3 , "blackcat" },
        { "cat3", 2 , "whitecat"},

    };

    int MAX_CATS_current
        = 3;
    // Identifying the Element to Delete
    const char* nameToDelete = "cat2";
    int indexToDelete = -1;

    // Finding the index of the person to delete
    for (int i = 0; i < MAX_CATS_current; ++i) {
        if (strcmp(cats[i].name, nameToDelete) == 0) {
            indexToDelete = i;
            break;
        }
    }


    if (indexToDelete == -1) {
        printf("cat with name %s not found.\n",
               nameToDelete);
    }
    else {

        // Deleting the Element
        for (int i = indexToDelete;
             i < MAX_CATS_current- 1; ++i) {
            cats[i] = cats[i + 1];
        }


        MAX_CATS_current--;


        displaycats(cats,MAX_CATS_current);
    }

    return 0;
}
