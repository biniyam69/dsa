#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *first=NULL, *second=NULL, *third=NULL;


// Display data in linked list
void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p=p->next;
    }
}

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i=1; i<n; i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next=t;
        last=t;
    }
}

int isSorted(struct Node *p)
{
    int x = -65536;
    while(p!=NULL)
    {
        if(p->data < x)
            return 0;
        x=p->data;
        p=p->next;
    }
    return 1;
}

void RemoveDuplicates(struct Node *p)
{
    struct Node *q = p->next;

    while (q!=NULL)
    {
        if (p->data != q->data)
        {
            p=q;
            q=q->next;

        }
        else
        {
            p->next = q->next;
            free(q);
            q=p->next;

        }
    }
}


void Reverse(struct Node *p)
{
    // create an auxilary array
    // copy the data and add it to the array
    // then copy the data from the array to the linked list
    int *A, i=0;

    struct Node *q = p;

    A = (int *)malloc(sizeof(int)*count(p));
    while (p!= NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;

    while (p!= NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}


























int main()
{
    int A[] = {10, 10, 30, 40, 40, 50};
    create(A, 6);

    RemoveDuplicates(first);
    Display(first);
    printf("\n\n");
    return 0;
}