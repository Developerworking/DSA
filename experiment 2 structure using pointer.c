#include <stdio.h>
#include <string.h>

// Define a structure named "Person" to store information about a person
struct Person {
    char name[50];
    int age;
    char address[100];
};

int main() {
    // Declare a structure variable of type "Person"
    struct Person person1;

    // Declare a pointer to a structure of type "Person"
    struct Person *personPtr;

    // Initialize the structure fields using the pointer
    personPtr = &person1;
    strcpy(personPtr->name, "John Doe");
    personPtr->age = 30;
    strcpy(personPtr->address, "123 Main Street, City");

    // Display the information stored in the structure using the pointer
    printf("Person Information (using pointer):\n");
    printf("Name: %s\n", personPtr->name);
    printf("Age: %d\n", personPtr->age);
    printf("Address: %s\n", personPtr->address);

    return 0;
}
