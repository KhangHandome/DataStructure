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
static void DeleteAnElementByIndex(LinkedList **myList,uint8_t index);
int main()
{
    LinkedList* myStudent = NULL;
    printf("This code is an example about how to used a LinkedList in C \n");
    printf("It was creare by MaiThanhKhang \n");
    AddToFirstNode(&myStudent);
    AddToFirstNode(&myStudent);
    AddToFirstNode(&myStudent);
    ShowAllElementInNode(myStudent);
    SortElementByCondition(&myStudent);
    ShowAllElementInNode(myStudent);
}

static void AddToFirstNode(LinkedList **myList)
{
    LinkedList *newNode = NULL;
    LinkedList *tmp     = *myList;
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
        newNode->next = NULL ; 
        while( tmp->next !=NULL )
        {
            tmp = (LinkedList*) tmp->next;
        }
        tmp->next = (struct LinkedList*) newNode;
        newNode->next = NULL ; 
    }
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
static void DeleteAnElementByIndex(LinkedList **myList,uint8_t index)
{
    uint8_t i = 0 ; 
    LinkedList* tmp = *myList;
    LinkedList* nodeToDelete ;
    printf("Starting delete a node in Node \n");
    if(index == 0 )
    {
        *myList = (LinkedList*) (*myList)->next;
        free(tmp);
    }
    else
    {
        for ( i = 0 ; i < index -1 ; i ++)
        {
            tmp = (LinkedList*) tmp->next;
        }
    }
    nodeToDelete = (LinkedList*) tmp->next;
    tmp->next = nodeToDelete->next;
    free(nodeToDelete);
}
static void SortElementByCondition(LinkedList **myList)
{
    LinkedList *tmp = *myList;
    LinkedList *g_myList = *myList;
    uint8_t choice = 0 ; 
    uint8_t numOfElements  = 0 ; 
    uint8_t i = 0 ; 
    uint8_t j = 0 ;
    printf("Press your choise : ");
    printf("1 .Sort by math score    ");
    printf("2 .Sort by poet score    ");
    printf("3 .Sort by english score ");
    printf("4 .Sort by average score ");
    scanf("%c",&choice);
    while (g_myList != NULL)
    {
        /* code */        numOfElements ++ ; 
        g_myList = (LinkedList*) g_myList->next;
    }
    g_myList = *myList;
    switch (choice)

    {
        case '1': 
            if (*myList == NULL || (*myList)->next == NULL) {
                printf("Danh sach rong hoac chi co 1 phan tu, khong can sap xep.\n");
                break;
            }
            int swapped;
            LinkedList **ptr;
            do {
                swapped = 0;
                ptr = myList; // con trỏ trỏ tới con trỏ đầu danh sách

                while ((*ptr) != NULL && (*ptr)->next != NULL) {
                    g_myList = *ptr;
                    tmp = g_myList->next;
                    if (g_myList->myStudent.MathScore > tmp->myStudent.MathScore) {
                        // Hoán đổi liên kết
                        g_myList->next = tmp->next;
                        tmp->next = g_myList;
                        *ptr = tmp;
                        swapped = 1;
                    }
                    ptr = &((*ptr)->next); // tiến con trỏ tới cặp tiếp theo
                }
            } while (swapped);

            printf("Sap xep hoan tat (theo lien ket node).\n");
            break ; 
        case '2': break ; 
        case '3': break ; 
        case '4': break ; 
        default: printf("Error");
    }
}
