#include <stdio.h>

struct Node 
{
    int data;
    struct Node *next; //self referential pointer

}*Head; //global pointer


void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    Head=(struct Node*)malloc(sizeof(struct Node));
    Head->data=A[0];
    Head->next=Head;
    last=Head;

    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }

}

void Display(struct Node *p)
{
    do
    {
        printf("%d ", p->data);
        p=p->next;
    }
    while(p!=Head);
    printf("\n");
}


int main()
{
    int A[]={2,3,4,5,6};
    create(A,5);
    
    Display(Head);
    return 0;
}

















// // recursive circular linkedlist

// void Display(Node *p)
// {
//     int flag = 0;
//     if(p!=head || flag == 0)
//     {
//         flag = 1;
//         printf("%d", p->data);
//         Display(p->next);
//     }
//     flag=0;
// }