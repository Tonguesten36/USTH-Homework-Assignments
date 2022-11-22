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

using Recursion, with Iteration if necessary
*/

/*
    pseudocode:

    function calculateDigitSum(int sum, int input, int size):
        if(size == 1):
            print input " = "
            return input;
        else:
            sum += input mod 10;

            print input mod 10;

            input /= 10

            newSize <- to_string(input).length

            print "+"

            return calculateDigitSum(input, newSize)

*/
int sum = 0;

//O(n)
int calculateDigitSum(int input, int length)
{
    if(length == 1)
    {
        cout << input << " = ";
        return input;
    }
    else
    {
        sum += input % 10;
 
        cout << input % 10;

        input /= 10;

        int newSize = to_string(input).length();
        if(newSize < length)
            cout << " + ";

        return (calculateDigitSum(input, newSize));
    }
}

int main()
{
    int a, len; 
    cin >> a; //O(1)


    len = to_string(a).length(); //O(1)
    
    cout << (sum + calculateDigitSum(a, len)); //O(n)
    cout << endl;

    return 0;
}

//The overall complexity of the program is O(n)