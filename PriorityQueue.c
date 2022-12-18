#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct elem
{
    int data;
    int p;
    struct elem *next;
};

void addQueue(struct elem **head, int data, int p)
{
    struct elem *temp, *temp2, *prev;
    temp = *head;
    if (temp == NULL)
    {
        temp = (struct elem *)malloc(sizeof(struct elem));
        temp->data = data;
        temp->p = p;
        temp->next = NULL;
        *head = temp;
    }
    else
    {
        temp2 = (struct elem *)malloc(sizeof(struct elem));
        temp2->data = data;
        temp2->p = p;
        prev = temp;
        while (temp != NULL && temp->p >= p)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            prev->next = temp2;
            temp2->next = NULL;
        }
        else if (prev == temp)
        {
            *head = temp2;
            temp2->next = temp;
        }
        else
        {
            prev->next = temp2;
            temp2->next = temp;
        }
    }
}

void traverse(struct elem *head)
{
    struct elem *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("Element %d, Priority %d\n", temp->data, temp->p);
        temp = temp->next;
    }
}

int main()
{
    int ch, data, p;
    struct elem *priority_queue = NULL;
    printf("Do You Want to Make Priority Queue(1 to Start): ");
    scanf("%d", &ch);
    while (ch)
    {
        printf("Enter Data and Priority: ");
        scanf("%d", &data);
        scanf("%d", &p);
        addQueue(&priority_queue, data, p);
        printf("Do You Want to Continue(0 to Exit): ");
        scanf("%d", &ch);
    }
    traverse(priority_queue);
    getch();
    clrscr();
    return 0;
}