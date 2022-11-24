#include <iostream>
#include <cstring>

/*
This program will verify whether a number is a sphenic number
A sphenic number's product has 3 distinct prime numbers. It has 8 divisors

Pseudocode
BEGIN

Initialize a global array of size 1001

function FindPrimes(n):
    FOR i <- 2 to n/2 do
        IF n % i == 0
            is prime, end
    is not prime, end
    ENDFOR

function CheckSphenic(int n):
    let divisors be array of integers, initially set to 0
    let counter be an integer, initially set to 0

    FOR i <- 1 to i <= x do
        IF x mod i == 0 and counter < 9
            increment counter
            increment j
            divisors[j] <- i
    ENDFOR

    let primeDivisors be an integer, initially set to 0

    FOR i <- 1; i < counter
        IF divisors[i] is prime
                increment primeDivisors
    ENDFOR

    IF counter == 8 and primeDivisors == 3
        return true
    ELSE return false

function main():
    Run FindPrime algorithm
    Prompt the user for input
    Check if the number is a sphenic number
    Return the result
END


*/

bool isPrime(int n)
{
    for(int i = 2; i <= n/2; i++)
    {
        if(n % i == 0)
        {
            return true;
        }
    }
    return false;
}

bool CheckSphenic(int n)
{
    int divisors[8] = {0};
    int counter = 0;
    int j = 0;

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0 && counter < 9)
        {
            counter++; 
            divisors[j++] = i;
        }
    }

    int primeDivisors = 0;
    
    for(int i = 0; i < 8; i++)
    {
        if(isPrime(divisors[i]))
        {
            primeDivisors++;
        }
    }

    return (counter == 8 && primeDivisors == 3);
}

int main()
{

    int x;
    std::cout << "Enter a natural number: ";
    std::cin >> x;

    if(CheckSphenic(x))
        std::cout << "this is a sphenic number";
    else
        std::cout << "this is not a sphenic number";

    return 0;
}

// Complexity of the program is O(n^2)