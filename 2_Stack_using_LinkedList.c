#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};

struct stack *top = NULL; // Globally TOP Ko declare kar diya
struct stack *pop(struct stack **); 
struct stack *push(struct stack **, int num);
struct stack *display(struct stack **);
int peek(struct stack **);

int main()
{
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
            printf("ENTER THE NUMBER TO BE PUSHED: ");
            scanf("%d",&val);
            push(&top,val);
            break;

        case 2:
            pop(&top);
            break;

        case 3:
        if(peek(&top)==-1)
        {
            break;
        }
        else{
            printf("Value to be peek is %d ",peek(&top));
            break;
        }
        case 4:
         display(&top);

            break;
        }

    } while (option != 5);
    
    return 0;
}
struct stack *pop(struct stack **top)
{
    struct stack *ptr;
    ptr = *top;
    if (*top == NULL)
    {
        printf("UNDERFLOW");
    }
    else
    {
        *top = (*top)->next;
        printf("The value that is being deleted is: %d", ptr->data);
       
    }
    return *top;
}
struct stack *push(struct stack **top, int num)
{
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    if (ptr == NULL)
    {
        printf("MEMORY NOT AVAILABLE");
    }
    else
    {
        ptr->data = num;
    }
    if (*top == NULL)
    {
        ptr->next = NULL;
        *top = ptr;
    }
    else
    {
        ptr->next = *top;
        *top = ptr;
    }
    
    return *top;
}
struct stack *display(struct stack **top)
{
    struct stack *ptr;
    ptr = *top;
        if(*top==NULL)
        {
            printf("STACK IS EMPTY");
            
        }
       
        while (ptr!= NULL)
        {
            printf("|%d|-->\t",ptr->data);
            ptr=ptr->next;
        }
    
    
    return *top;
}
int peek(struct stack **top)
{
    struct stack *ptr;
    ptr = *top;
    if (*top == NULL)
    {
        printf("UNDERFLOW");
        return -1;
    }
    else 
    {
        return ptr->data;
    }
    
}
