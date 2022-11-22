#include <iostream>
#include <cmath>
using namespace std;


struct _Polynomial
{
    int term;
    int constant[100];
    int degree[100];
};
typedef struct _Polynomial poly;

//Initialize a new, empty function
void init(poly*func)
{
    func->term = 0;
}
//Check if the list is empty
int isEmpty(poly*func)
{
    return (func->term == 0);
}

//Return length of list
int length(poly*func)
{
    return func->term + 1;
}

//AddElement(Polynomial *func, int newConstant, int newDegree)
/*
    Initialize a new element

    If length == max_capacity
        return
    If illegal index
        return

    Verify that old terms exist by iterating through the func
        If old terms exist then
            The final constant = old term's const + newConstant 
            Add the new element with the final constant
            Remove the old element
        If not
            Just add the new element with the newConstant and newDeg as usual
    

*/
void addElement(poly*func, int index, int newConst, int newDeg)
{
    if(length(func) == 100)
    {
        printf("cannot add more item to the list");
        return;
    }
    if(index < 0 || index > length(func))
    {
        printf("Illegal index");
        return;
    }
    else
    {
        for(int i = length(func); i > index; i--)
        {
            func->constant[i] = func->constant[i-1];
            func->degree[i] = func->degree[i-1];
        }
        for(int a = 0; a < length(func); a++)
        {
            //If old terms exist then
            if(func->degree[a] == newDeg)
            {
                func->constant[index] = func->constant[a] + newConst;
                func->degree[index] = newDeg;

                func->constant[a] = func->constant[a+1];
                func->degree[a] = func->degree[a+1];
                return;
            }
        }
        //If old term not exist
        func->constant[index] = newConst;
        func->degree[index] = newDeg;
        func->term++;
    }
}

//Removing function
/*
    Initialize a tmp pointer that points to the pHead
    Initialize a prev pointer that points to NULL
    
    If the func is empty
        Terminate operation immediately
    If term exceeded the maximum amount of term in the function
        Terminate operation immediately
    
    If the operation has yet to be terminated, then iterate through the func
        Remove the item at specified index
        Shift all item to left

*/
void removeElement(poly*func, int index)
{
    if(isEmpty(func))
    {
        printf("List is empty");
        return;
    }
    if(index < 0 || index > length(func))
    {
        printf("Illegal index");
        return;
    }
    else
    {
        for(int i = index; i < length(func); i++)
        {
            func->constant[i] = func->constant[i+1];
            func->degree[i] = func->degree[i+1];
        }
        func->term--;
    }
}

//Calculate function (Polynomial *func, int x)
/*
    result = 0
    tmp points to the first element of func

    Iterate through the function as long as tmp != NULL
        result += tmp->constant * pow(x, tmp->degree)
        tmp = tmp->next

    return result
*/
int calculate(poly*func, int x)
{
    int result = 0;
    printf("f(%d) = ", x);
    
    for(int i = 0; i < length(func); i++)
    {
        if(func->degree[i] == 0)
        {
            result += func->constant[i];
        }
        else
        {
            result += func->constant[i] * pow(x, func->degree[i]);
        }
    }

    return result;
}

//Display the function
void displayFunc(poly*func)
{
    cout << "f(x) = ";
    for (int i = 0; i < length(func); i++)
    {
        if(func->constant[i] < 0)
        {
            cout << "(" << func->constant[i] << "x^" << func->degree[i] << ")";
        }
        else if (func->constant[i] > 0)
        {
            cout << func->constant[i] << "x^" << func->degree[i];
        }
        else
        {
            cout << "";
        }

        if(i < length(func) - 1 && i != 0)
        {
            cout << " + ";
        }
    }
    cout << endl;
}

int main()
{
    //Initialize a new polynomial
    poly *_poly = new poly();
    init(_poly);

    //Adding new elements to the polynomial functions
    addElement(_poly, 0, 5, 0);
    addElement(_poly, 1, 4, 1);
    addElement(_poly, 2, 5, 2);
    addElement(_poly, 3, 2, 2);

    //Displaying the function
    printf("Before deletion: \n");
    displayFunc(_poly);

    //Calculate the function with x = 2
    printf("%d\n", calculate(_poly, 2));

    //Removing element 1 in the function
    removeElement(_poly, 1);

    //Display it again
    printf("After deletion: \n");
    displayFunc(_poly);
    printf("%d\n", calculate(_poly, 2));

    //Free the memory and end the program
    delete _poly;
    return 0;
}
