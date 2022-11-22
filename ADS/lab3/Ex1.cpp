
/*
Implement a queue of customers, each customer can buy only a
few products among the available three items

- Determine the item name, their quantity in stock; (done)

- Specify a queue of n customers; each customer can buy k products from one
item (k is different for each customer);

- Customers take turns to enter (enqueue) and leave (dequeue) the queue
according to the FIFO order to purchase wanted products;

- If a customer successfully purchases products, then display a message and
reduce the number of products in stock; otherwise, if the item has been run
out, display a warning message.

Implement the above problems in C/C++ using a Queue data structure. Write
the main function for testing all written functions (init(), display(), enqueue(), dequeue(),...). .
*/

#include <iostream>
using namespace std;

//3 items, each has 10 quantity
int shoes = 10;
int shirts = 10;
int socks = 10;

// A queue of customers
struct _Queue
{
    string customers[100];
    int front, back;
};
typedef struct _Queue Queue;

/*
pseudocode

    function init():
        initialize a new queue with front = 0; back = 0
    
    function isEmpty():
        check if the queue is empty
    
    function length():
        return the length of the queue
*/
void init(Queue *q)
{
    q->front = 0;
    q->back = 0;
}
bool isEmpty(Queue *q)
{
    return (q->back == 0);
}
int length(Queue *q)
{
    return (q->back - q->front);
}


int enqueue(Queue *q, string newName)
{
    if(length(q) == 100)
    {
        cout << "queue is full" << endl;
        return 0;
    }
    if(isEmpty(q))
    {
        q->customers[0] = newName;
    }
    else
    {
        int index = q->back;
        q->customers[index] = newName;
    }
    q->back++;
    return 1;
}
int dequeue(Queue *q)
{
    if(isEmpty(q))
    {
        return 0;
    }
    else
    {
        if(length(q) > 1)
        {
            for(int i = 1; i < length(q); i++)
            {
                q->customers[i - 1] = q->customers[i];
            }
        }
        q->back = q->back - 1;
    }
    return 1;
}
void displayQueue(Queue *q)
{
    cout << "Queue line: " << endl;
    for(int i = q->front; i < q->back; i++)
    {
        cout << q->customers[i];
        if(i < q->back - 1)
            cout << " <--- ";   
    }
    cout << endl;
}

/*
pseudocode

    function transaction():
        customer specify the item name and how many do they want to buy
        if there is enough item for customer
            print "Transaction successful"
            decrease the item quantity
            dequeue
        else
            print"Transaction failed"
            dequeue
*/
void transaction(Queue *q)
{
    int a, amount;
    
    cout << "-----------------" << endl;
    cout << "Customer " << q->customers[0] << endl;
    printf("1. Shoes (%d) \n2. Shirts (%d) \n3. Socks (%d) \n",shoes,shirts,socks);
    
    cout << "What do you want to buy (1-3): ";
    cin >> a;
    
    cout << "How many: ";
    cin >> amount;
    
    switch (a)
    {
        case 1:
            if(amount <= shoes)
            {
                cout << "Customer " << q->customers[0] << " has successfully purchased shoes." << endl;
                shoes -= amount;
            }
            else
            {
                cout << "Amount exceeded item's quantity" << endl;
            }
            
            break;
        case 2:
            if(amount <= shirts)
            {
                cout << "Customer " << q->customers[0] << " has successfully purchased shirts." << endl;
                shirts -= amount;
            }
            else
            {
                cout << "Amount exceeded item's quantity" << endl;
            }
            break;
        case 3:
            if(amount <= socks)
            {
                cout << "Customer " << q->customers[0] << " has successfully purchased socks." << endl;
                socks -= amount;
            }
            else
            {
                cout << "Amount exceeded item's quantity" << endl;
            }
            break;
        default:
            cout << "Invalid input" << endl;
            break;
    }
    dequeue(q);
}


int main()
{
    // 
    Queue *q = new Queue();
    init(q);


    enqueue(q, "Lorem Ipsum 1");
    enqueue(q, "Lorem Ipsum 2");
    enqueue(q, "Lorem Ipsum 3");
    enqueue(q, "Lorem Ipsum 4");

    displayQueue(q);

    while(!isEmpty(q))
        transaction(q);

    delete q;
    return 0;
}