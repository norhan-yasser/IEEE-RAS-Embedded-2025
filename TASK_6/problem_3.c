#include <stdio.h>
#include <string.h>

#define MAX_LEN 100


struct Cat {
    char name[MAX_LEN];
    char age[MAX_LEN];
    char kind[MAX_LEN];
};


struct Cat create_cat(const char *name, const char *age, const char *kind) {
    struct Cat cat;

    strncpy(cat.name, name, MAX_LEN);
    strncpy(cat.age, age, MAX_LEN);
    strncpy(cat.kind, kind, MAX_LEN);

    return cat;
}


void display_cat(const struct Cat *cat) {
    printf("Cat's Name: %s\n", cat->name);
    printf("Age: %s\n", cat->age);
    printf("Kind: %s\n", cat->kind);
}

int main() {
    struct Cat my_cat = create_cat("Coco", "4 months", "Siamese");

    display_cat(&my_cat);

    return 0;
}
