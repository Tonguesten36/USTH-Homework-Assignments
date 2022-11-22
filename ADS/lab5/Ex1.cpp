#include <iostream>
using namespace std;

/*
pseudocode

function swapValue(int &a, int &b):
    tmp <- a
    a <- b
    b <- tmp

function insertionAlgo(arr[]):
    sort the array using a mixture of insertion sort and bubble sort algorithms
*/
// This function has O(1) because this function does not depend on the size of input
// This func has ref variables
void swapValue(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

/*
---- New algorithm ----

For the first step, we perform insertion sort from the index 1 to n (n is the
number of elements in the array).

In the next pass, we perform a reserved bubble sort from the index n to 1.

The process is repeated until all the array is sorted.

---- Pseudocode ----

function insertion(arr[], size):
    swapped <- true;
    while swapped == true do

        swapped <- false;
        
        // iterate from 1 to n (insertion)
        for i <- 1 to size do
            j <- i;

            while j > 0 and arr[j - 1] > arr[j]
                swap(a[j], a[j - 1]);
                swapped <- true;
                j--;
            endwhile
        endfor

        //iterate from n to 1 (bubble)
        for j <- size to 0 do
            if arr[j] < arr[j - 1] then
                swap(arr[j - 1], arr[j])
                swapped = true      
        endfor
    endwhile
*/
void newInsertionAlgo(int arr[], int arr_size)
{
    //initialize new boolean value
    //set it as true in order to start the loop
    bool swapped = true;

    //this loop will keep going as long as swapped is true
    // Overall complexity of this while-loop: O(n^2)
    while(swapped)
    {
        // set it back to false in case if the array is already sorted
        swapped = false;
        
        //iterate from 1 to n (forward)
        //for loop = O(n)
        for(int i = 1; i < arr_size; i++)
        {
            int j = i;
            while(j > 0 && arr[j - 1] > arr[j])
            {
                swap(arr[j], arr[j - 1]);
                swapped = true;
                j--;
            }
        }

        //iterate from n to 1 (backward)
        //for loop = O(n)
        for(int i = arr_size; i > 0; i--)
        {
            //if current element < previous element 
            if(arr[i] < arr[i - 1])
            {
                //swap the element
                swap(arr[i - 1], arr[i]);
                swapped = true;
            }
        }
        //Both for loops here are O(n) + O(n) = O(2n) => O(n)
    }
}

// Driver code
int main()
{
    int n[8] = {99, 55, 66, 33, 11, 88, 77, 22};
    
    int size = sizeof(n) / sizeof(int);

    cout << "Before: "  << endl;
    //O(n)
    for(int i = 0; i < size; i++)
    {
        cout << n[i] << endl;
    }

    //O(n^2)
    newInsertionAlgo(n, size);

    cout << "After: " << endl;
    //O(n)
    for(int i = 0; i < size; i++)
    {
        cout << n[i] << endl;
    }

    return 0;
}

// T(n) = n^2 + 2n + 4
// => Overall complexity: O(n^2)
