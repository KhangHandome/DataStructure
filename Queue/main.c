#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#define MAX_DATA 10 
#define TRUE 1 
#define FALSE 0 
typedef struct
{
    /* data */
    uint8_t masv[10];
    uint8_t name[50];
    float   diemtb;
} myData_t;

typedef struct
{
    myData_t myData[MAX_DATA];
    uint8_t back;
    uint8_t front;
} myQueue_t;
static void QueueInit(myQueue_t *myQueue)
{
    myQueue->front = 0 ; 
    myQueue->back  = 0 ; 
}
static void Enqueue(myQueue_t *myQueue,myData_t* myData)
{
    strcpy(myQueue->myData[myQueue->front].masv,myData->masv);
    strcpy(myQueue->myData[myQueue->front].name,myData->name);
    myQueue->myData[myQueue->front].diemtb = myData->diemtb; 
    myQueue->front = (myQueue->front % MAX_DATA) + 1 ;
}
static myData_t Dequeue(myQueue_t *myQueue)
{
    myData_t myData ;
    myData = myQueue->myData[myQueue->back];
    myQueue->back = (myQueue->back % MAX_DATA) +1 ; 
    return myData;
}
static uint8_t isEmpty(myQueue_t *myQueue)
{
    uint8_t retVal = 0 ; 
    if ( abs(myQueue->front - myQueue->back) == 0 )
    {
        retVal = TRUE;
    }
    else
    {
        retVal = FALSE;
    }
    return retVal  ; 
}
static uint8_t isFull(myQueue_t *myQueue)
{
    uint8_t retVal = 0 ; 
    if ( abs(myQueue->front - myQueue->back) == MAX_DATA)
    {
        retVal = TRUE;
    }
    else
    {
        retVal = FALSE;
    }
    return retVal  ; 
}
int main(void)
{
    myQueue_t myStudent ;
    myData_t  myData ; 
    QueueInit(&myStudent);
    if ( isEmpty(&myStudent) == TRUE)
    {
        printf("Queue is empty \n");
    }
    myData.diemtb = 10 ; 
    strcpy(myData.masv,(uint8_t*) "2018");
    strcpy(myData.name,(uint8_t*) "Khang");
    Enqueue(&myStudent,&myData);

    myData.diemtb = 9 ; 
    strcpy(myData.masv,(uint8_t*) "2019");
    strcpy(myData.name,(uint8_t*) "Khanh");
    Enqueue(&myStudent,&myData);


    myData = Dequeue(&myStudent);
    return 0 ; 
}