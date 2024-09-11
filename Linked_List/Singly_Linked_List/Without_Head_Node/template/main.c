#include "linkedList.h"
#include <stdio.h>

typedef struct person
{
    char *name;
    int age;
    int salary;
} Person;

char * const names[] = {
    "John",
    "Jane",
    "Doe",
    "Smith",
    "Alex"
};

int ages[] = {25, 30, 35, 40, 45};

int salaries[] = {50000, 60000, 70000, 80000, 90000};

void main()
{
    LinkedList *linkedList = initLinkedList(1);

    Person **persons = malloc(5 * sizeof(Person *));
    for (size_t i = 0; i < 5; i++)
    {
        Person *person = malloc(sizeof(Person));
        person->name = names[i];
        person->age = ages[i];
        person->salary = salaries[i];
        persons[i] = person;
    }

    for (size_t i = 0; i < 5; i++)
    {
        push(linkedList, persons[i]);
    }
    
    printf("Length: %ld\n", length(linkedList));

    for (size_t i = 0; i < length(linkedList); i++)
    {
        printf("Person %ld: %s, %d, %d\n", i, ((Person *)valueAt(linkedList, i, Person *))->name, ((Person *)valueAt(linkedList, i, Person *))->age, ((Person *)valueAt(linkedList, i, Person *))->salary);
    }

    for (size_t i = 0; i < 2; i++)
    {
        pop(linkedList);
    }
    
    printf("Length: %ld\n", length(linkedList));

    for (size_t i = 0; i < length(linkedList); i++)
    {
        printf("Person %ld: %s, %d, %d\n", i, ((Person *)valueAt(linkedList, i, Person *))->name, ((Person *)valueAt(linkedList, i, Person *))->age, ((Person *)valueAt(linkedList, i, Person *))->salary);
    }

    popAt(linkedList, 1);

    printf("Length: %ld\n", length(linkedList));

    for (size_t i = 0; i < length(linkedList); i++)
    {
        printf("Person %ld: %s, %d, %d\n", i, ((Person *)valueAt(linkedList, i, Person *))->name, ((Person *)valueAt(linkedList, i, Person *))->age, ((Person *)valueAt(linkedList, i, Person *))->salary);
    }

    for (size_t i = 0; i < length(linkedList); i++)
    {
        free(persons[i]);
    }

    free(persons);

    deleteLinkedList(linkedList);
}