#include <iostream>

struct _node
{
    int data;
    struct _node *next;
};
typedef struct _node Node;

struct _stack
{
    int size;
    Node *top;
};
typedef struct _stack Stack;

bool isEmpty(Stack *st)
{
    return (st->size < 0);
}
bool isFull(Stack *st)
{
    return (st->size == 15);
}

void push(int newData, Stack *st)
{
    Node *p = new Node();
    if(p != NULL)
    {
        p->data = newData;
        // i n s e r t at the b e g i n n i n g o f the l i s t
        p->next = st->top->next;
        st->top = p;
        st->size++;
    }
}

void pop(Stack *st)
{
    Node *p;
    if(isEmpty(st))
    {
        printf("fail to pop\n");
        return;
    }
    p = st->top;
    st->top = st->top->next;
    st->size--;
    delete p;
}

void display(Stack *st)
{
    Node *tmp;
    
    if(isEmpty(st))
    {
        printf("stack is empty\n");
        return;
    }

    tmp = st->top;
    while(tmp != NULL)
    {
        printf("%d", tmp->data);

        tmp = tmp->next;
        if(tmp != NULL)
        {
            printf(" -> ");
        }
    }
    printf("\n");
}

int main()
{

    return 0;
}