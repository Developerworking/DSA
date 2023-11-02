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

    // Initialize the structure fields
    strcpy(person1.name, "John Doe");
    person1.age = 30;
    strcpy(person1.address, "123 Main Street, City");

    // Display the information stored in the structure
    printf("Person Information:\n");
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    printf("Address: %s\n", person1.address);

    return 0;
}
