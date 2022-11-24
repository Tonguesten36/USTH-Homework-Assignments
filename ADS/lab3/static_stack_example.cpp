#include <iostream>

typedef struct Stack
{
    int data[15];
    int top;
};

// create an empty static array-based stack
void init_static_array(Stack *st)
{
    st->top = -1;
}

bool isEmpty(Stack *st)
{
    return (st->top < 0);
}
bool isFull(Stack *st)
{
    return (st->top == 15);
}

void push(Stack *st, int val)
{
    if(isFull(st))
    {
        printf("Stack is full\n");
    }
    else
    {
        st->top++;
        st->data[st->top] = val;
    }
}

void pop(Stack *st)
{
    if(isEmpty(st))
    {
        printf("Stack is empty\n");
    }
    else
    {
        st->top--;
    }
}

int top(Stack *st)
{
    return (st->data[st->top]);
}

int size(Stack *st)
{
    return (st->top + 1);
}

void display(Stack *st)
{
    int i = 0;
    while(i <= st->top)
    {
        std::cout << st->data[i];
        if(i != st->top)
        {
            std::cout << " -> ";
        }
        i++;
    }
    std::cout << std::endl;
}

int main()
{

    return 0;
}