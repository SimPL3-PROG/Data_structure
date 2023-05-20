/*
Function in the stack using struct
1) IsFull/Isempty ()
2) Push()
3) Pop()
4) Peek()
*/

#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int num)
{
    if (isFull(ptr))
    {
        printf("\nSTACK IS FULL\n");
        
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = num;
    
    }
}
int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("\nStack is Empty\n");
        return -1;
    }
    else
    {
        return ptr->arr[ptr->top--];
    }
}
void display(struct stack *ptr)
{
    printf("\nSTACK FORMED IS\n\n");
    for (int i = ptr->top; i >= 0; i--)
    {
        printf("|%d|\n", ptr->arr[ptr->top]);
    
        ptr->top--;
    }
}

int peek(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("\nStack is Empty\n");
        return -1;
    }
    else
    {
        return ptr->arr[ptr->top];
    }
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    printf("ENTER THE SIZE OF ARRAY YOU WANT: ");
    scanf("%d", &s->size);
    s->arr = (int *)malloc(s->size * sizeof(int));
    int option, val;
    do
    {
        printf("\n********** MAIN-MENU **********\n");
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. PEEK");
        printf("\n4. DISPLAY");
        printf("\n5. EXIT");
        printf("\nENTER YOUR OPTION: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:

            printf("\n Enter the number to be pushed on the stack: ");
            scanf("%d", &val);
            push(s, val);
            break;

        case 2:
            val = pop(s);
            if (val != -1)
            {
                printf("Value deleted is %d", val);
            }
            break;

        case 3:
            printf("\nnumber to be peeked on the stack: ");
            val = peek(s);
            printf("%d", val);
            break;

        case 4:
            display(s);
            break;

      
        }

    } while (option != 5);
    free(s);
    free(s->arr);
    return 0;
}

/*
==================
TIME COMPLEXITY -
==================

isfull/isempty = O(1)

peek,pop,push = O(1)

display = O(n) where n is total elements

stackTop = O(1)

stackBottom = O(1)
*/