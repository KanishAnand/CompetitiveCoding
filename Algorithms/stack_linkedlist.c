#include <stdio.h>
#include <stdlib.h>

int push(int value);
int pop();
struct node
{
    int val;
    struct node *nextnode;
};

struct node *head = NULL;

int main(void)
{
    int t, a;
    printf("enter no of operations\n");
    scanf("%d", &t);
    printf("\n1.push \n 2.display top \n 3.pop");
    while (t--)
    {
        scanf("%d", &a);
        if (a == 1)
        {
            int value;
            printf("enter value to push\n");
            scanf("%d", &value);
            push(value);
        }
        else if (a == 2)
        {
            if (head == NULL)
            {
                printf("its empty\n");
                continue;
            }
            printf("%d  ", *head);
        }
        else if (a == 3)
        {
            pop();
        }
    }
    return 0;
}

int pop()
{
    struct node *nodes = (struct node *)malloc(sizeof(struct node));
    nodes = head;
    head = nodes->nextnode;
}

int push(int value)
{
    struct node *nodes = (struct node *)malloc(sizeof(struct node));
    nodes->val = value;
    nodes->nextnode = head;
    head = nodes;
}
