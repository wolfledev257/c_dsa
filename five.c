#include<stdio.h>
#include<stdlib.h>

typedef struct CircularQueue{
    int maxsize, front, rear, *a;
} q;

void menu(){
    printf("Enter option.\n");
    printf("1. INSERT ELEMENT.\n");
    printf("2. DELETE ELEMENT. \n");
    printf("3. FIND NUMBER OF ELEMENTS.\n");
    printf("4. Check overflow or underflow.\n");
    printf("0. Exit.\n");
    printf("YOUR OPTION: \t");
}

void init(q* ptr){
    printf("Enter maxsize of queue. \n");
    scanf("%d", &ptr->maxsize); //scanf("%d ") causes problems of whitespace characters
    ptr->front = -1;
    ptr->rear = -1;
    ptr->a = (int*)malloc(sizeof(int)*ptr->maxsize);
}

int overflow(q* ptr){
    if((ptr->rear == ptr->maxsize - 1 && ptr->front == 0) || (ptr->rear == ptr->front-1)){
        printf("Overflow!\n");
        return 1;
    } 
    return 0;
}

int underflow(q* ptr){
    if(ptr->front == -1){
        printf("Underflow!\n");
        return 1;
    }
    return 0;
}

void enqueue(q* ptr, int element){
    if(overflow(ptr)){
        return;
    }
    if(ptr->front==-1) ptr->front = 0;
    ptr->rear = (ptr->rear+1)%(ptr->maxsize);
    ptr->a[ptr->rear]=element;
    printf("Element successfully inserted.\n");
}

int dequeue(q* ptr){
    if(underflow(ptr)){
        return 0;
    }
    int item = ptr->a[ptr->front];
    if(ptr->front == ptr->rear){
        ptr->front = -1;
        ptr->rear = -1;
    }
    else if(ptr->front == ptr->maxsize-1) ptr->front=0;
    else ptr->front = 0;
    printf("We removed %d from front.\n", item);
    return item;
}

void display(q* ptr){
    if(underflow(ptr)){
        printf("No element in queue.\n");
        return ;
    }
    printf("The elements are: \t");
    for(int i = ptr->front;i<=ptr->rear;i++){
        printf("%d ",ptr->a[i]);
    }
    printf("\n");
}


int main(){
    q myqueue;
    init(&myqueue);
    printf("Circular Queue created.\n");
    int option;
    int element, overflow_check, underflow_check;
    while(1){
        printf("\n");
        menu();
        scanf("%d", &option);
        if(option==0) break;
        switch(option){
            case 1:
                printf("Enter element to be inserted.\n");
                scanf("%d", &element);
                enqueue(&myqueue,element);
            break;
            case 2:
                dequeue(&myqueue);
            break;
            case 3:
                if(myqueue.front!=-1) printf("Currently %d elements in queue.\n", myqueue.rear-myqueue.front+1);
                display(&myqueue);
            break;
            case 4:
                overflow_check = overflow(&myqueue);
                underflow_check = underflow(&myqueue);
                if(overflow_check==0 && underflow_check==0){
                    printf("Neither overflow nor underflow.\n");
                }
            break;
            default:
            printf("Invalid choice. \n");
            break;
        }
    }
    printf("Program ended. \n");
    return 0;
}