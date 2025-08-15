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
static void SortElementByCondition(LinkedList **myList);
static void DeleteAnElementByIndex(LinkedList **myList);
int main()
{
    LinkedList* myStudent = NULL;
    printf("This code is an example about how to used a LinkedList in C \n");
    printf("It was creare by MaiThanhKhang \n");
    AddToEndNode(&myStudent);
    AddToEndNode(&myStudent);
    AddToEndNode(&myStudent);
    AddToEndNode(&myStudent);
    ShowAllElementInNode(myStudent);

}

static void AddToEndNode(LinkedList **myList)
{
    LinkedList *newNode = NULL;
    Data_t newData ;
    uint8_t c = 0 ;
    printf("Press the Student ID    : ");
    fgets(newData.StudentID, sizeof(newData.StudentID), stdin);
    printf("Press the Student name  : ");
    fgets(newData.StudentName, sizeof(newData.StudentName), stdin);
    printf("Press the Math Score    : ");
    scanf("%f",&newData.MathScore);
    printf("Press the Poet Score    : ");
    scanf("%f",&newData.PoetSocre);
    printf("Press the English Score : ");
    scanf("%f",&newData.EnglishScore);
    while ((c = getchar()) != '\n' && c != EOF) { }
    newData.AverageScore = (newData.MathScore + newData.EnglishScore + newData.PoetSocre) / 3 ; 
    newNode = (LinkedList *) malloc( sizeof(LinkedList));
    newNode->myStudent = newData;
    if(*myList == NULL)
    {
        printf("There is no element in the node, creating a new node \n");
        newNode->next = NULL;
        (*myList) = newNode;
    }
    else
    {
        printf("Adding a new alement in to the node \n");
        newNode->next = (struct LinkedList*)(*myList);
        (*myList) = newNode;
    }
}
static void ShowAllElementInNode(LinkedList *myList)
{
    printf("Export all data in node to the screen \n");
    do
    {
        printf("Student ID   : %s",myList->myStudent.StudentID);
        printf("Student name : %s",myList->myStudent.StudentName);
        printf("Math Score   : %.2f\n",myList->myStudent.MathScore);
        printf("Poet Score   : %.2f\n",myList->myStudent.PoetSocre);
        printf("English Score: %.2f\n",myList->myStudent.EnglishScore);
        printf("Average Score: %.2f\n",myList->myStudent.AverageScore);
        myList = (LinkedList*) myList->next;
    }
    while(myList != NULL);

}
