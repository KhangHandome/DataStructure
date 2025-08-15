#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* Create a struct data */
typedef struct
{
    /* data */
    uint8_t StudentID[10];
    uint8_t StudentName[50];
    float MathScore;
    float PoetSocre;
    float EnglishScore;
    float AverageScore;
} Data_t;

/*Create a type of Linked Data*/
typedef struct 
{
    Data_t myStudent;
    struct LinkedList* next ; 
    struct LinkedList* previous;
} LinkedList;

/* Create a Function which used to add an element to first Node */
/* Create a function which used to add an element at the end of Node*/
/* Show all elements in the Node */
/* Delete a node in Linked List by the element */
/* Sort LinkedList by the condition */
static void AddToFirstNode(LinkedList **myList);
static void AddToEndNode(LinkedList **myList);
static void ShowAllElementInNode(LinkedList *myList);
static void ShowElementByCondition(LinkedList **myList);
static void DeleteAnElementByIndex(LinkedList **myList);
int main()
{

    printf("This code is an example about how to used a LinkedList in C \n");
    printf("It was creare by MaiThanhKhang \n");

}