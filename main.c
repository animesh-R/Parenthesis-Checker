#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *a)
{
    if (a->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *a)
{
    if (a->top == a->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *a, char value)
{
    if (isFull(a))
    {
        printf("Stack is overflow!!!");
    }
    else
    {
        a->top++;
        a->arr[a->top] = value;
    }
}

char pop(struct stack *a)
{
    if (isEmpty(a))
    {
        printf("Stack is underflow!!!");
        return -1;
    }
    else
    {
        char val = a->arr[a->top];
        a->top--;
        return val;
    }
}

int match(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}

int parenthesis_matching(char *exp)
{
    struct stack *a;
    a->size = 100;
    a->top = -1;
    a->arr = (char *)malloc(a->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(a, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(a))
            {
                return 0;
            }
            else
            {
                char pop_ch = pop(a);
                if (!match(pop_ch, exp[i]))
                {
                    return 0;
                }
            }
        }
    }

    if (isEmpty(a))
    {
        return 1;
    }
    return 0;
}

int main()
{
    char *exp = "[(81++)]({(--84**)})";
    if (parenthesis_matching(exp))
    {
        printf("\nThe parenthesis is balanced\n");
    }
    else
    {
        printf("\nThe parenthesis is not balanced\n");
    }
    return 0;
}
