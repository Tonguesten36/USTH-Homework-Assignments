#include <iostream>
using namespace std;

/*
In this program, we implement the insertion sort algorithm using Doubly Linked List
The reason why I used Doubly Linked List is:
    - Simpler to implement compare to Stack and Queue.
    - You can easily travel front and back in the list,
        this is important because the proposed algorithm requires you to traverse back and forth.
*/


/*
pseudocode

    declare new datatypes: a Node and a DoublyLinkedList

    function init():
        initialize a new list
    function push():
        insert a new element into the list as the first element
    function display():
        display all elements in the list
*/
struct Node
{
    int value; //holds an integer
    Node *next; // points to the next node
    Node *prev; //points to previous node, if available
};
typedef struct Node Node;

struct LinkedList
{
    int size; // size of the list
    Node *head; // the first node in the list
};
typedef struct LinkedList List;

void init(List *newList)
{
    newList->size = 0;
    newList->head = NULL;
}

//insert a new node to the list->head pointer
void push(List *list, int newValue)
{
    Node *newNode = new Node();
    newNode->value = newValue;

    if(list->size == 0)
    {
        newNode->next = NULL;
        newNode->prev = NULL; 

        list->head = newNode;
    }
    else
    {
        newNode->next = list->head;
        newNode->prev = NULL;

        list->head->prev = newNode;
        list->head = newNode;
    }
    list->size++;
}

void display(List *list)
{
    Node *temp = list->head;
    while(temp != NULL)
    {
        cout << temp->value << endl;
        temp = temp->next; 
    }

}
/*

---- New Pseudocode ----

function sort(List *list):
    swapped <- true;

    temp <- first element in list;
    while swapped is true do
        swapped <- false;

        //iterate from beginning to end
        while temp->next != NULL do
            if value in current temp > value in next temp then
                swap(value in next temp, value in current temp);
                swapped <- true;
            temp <- temp->next;
        endwhile
        
        while temp->prev != NULL do 
            if value in current element < value in prev element then
                swap(value in prev element, value in current element);
                swapped <- true;     
            temp <- temp->prev;
    endwhile
        
*/

void sort(List *list)
{
    bool swapped = true;
    // Start off at the first element of the list
    Node *temp = list->head;
    while (swapped)
    {
        swapped = false;

        while(temp->next != NULL)
        {
            if(temp->value > temp->next->value)
            {
                swap(temp->next->value, temp->value);
                swapped = true;
            }

            temp = temp->next;
            
        }

        while(temp->prev != NULL)
        {
            if(temp->value < temp->prev->value)
            {
                swap(temp->prev->value, temp->value);
                swapped = true;
            }
            
            temp = temp->prev;
        }
    }
}

int main()
{
    // Initialize a new LinkedList and allocate some memory space for it
    List *arr = new List();
    init(arr);
    
    //insert elements into the array, unsorted
    push(arr, 22);
    push(arr, 77);
    push(arr, 99);
    push(arr, 11);
    push(arr, 55);
    push(arr, 88);
    push(arr, 66);
    push(arr, 33);

    cout << "Before sorting: " << endl;
    display(arr);

    // sort the array using the algorithm proposed earlier
    sort(arr);

    cout << "After sorting: " << endl;
    display(arr);


    // Free the memory
    delete arr;
    return 0;
}