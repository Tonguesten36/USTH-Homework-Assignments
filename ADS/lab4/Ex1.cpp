#include <iostream>
#include <string>
using namespace std;

/*
In this problem, we would like to implement the algorithm to calculate the digit
sum of a given natural number that can be used in detecting errors in message
transmission or data storage.

For example:
N = 103509, the digit sum = 1 + 0 + 3 + 5 + 0 + 9 = 18.
N = 9512, the digit sum = 9 + 5 + 1 + 2 = 17

using Iteration
*/

/*
pseudocode

    int n, sum;
    ask the user for n number

    size = to_string(n).length();
    print "N = " n

    for i = 0; i < size; i++
        sum = sum + (n mod 10) // you add the remainder of n / 10 to sum
        if i > 0 then
            print " + "
        print n mod 10
        n / 10
    
    print sum

*/

int main()
{
    int n, size, sum;
    cout << "Enter number: ";
    cin >> n;

    size = to_string(n).length();
    cout << "N = " << n << endl;

    
    // This loop runs O(n) time
    for(int i = 0; i < size; i++)
    {      
        sum += n % 10;
        //O(1)
        if(i > 0)
        {
            cout << " + ";
        }
        cout << n % 10;
        n = n / 10;
    }
    cout << " = " << sum << endl;

    return 0;
}

// Overall complexity: O(n)