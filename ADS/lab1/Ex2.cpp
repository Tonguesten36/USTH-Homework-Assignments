#include <iostream>
#include <cstring>

/*
This program will verify whether a number is a sphenic number
A sphenic number's product has 3 distinct prime numbers. It has 8 divisors

Pseudocode
BEGIN

Initialize a global array of size 1001

function FindPrimes():
    FOR i <- 1 to sqrt(1001) do
        IF arr[i] is true then
            FOR j <- i^2 to 1001 do
                arr[i] <- false
            ENDFOR
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

    FOR i <- 1 to n do 
        IF i is sphenic
            print i

    Return the result
END


*/
bool numbers[1001];

void FindPrimes() 
{
    memset(numbers, true, sizeof(numbers));

    for (int i = 2; i*i < 1001; i++) 
    {
        if (numbers[i]) {
            for (int j = i*2; j < 1001; j = j + i) 
            {
                numbers[j] = false;
            }
        }
    }
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
    
    for (int i = 1; i < counter; i++)
    {
        if (numbers[divisors[i]])
        {
            primeDivisors++;
        }
    }

    return (counter == 8 && primeDivisors == 3);
}

int main()
{
    FindPrimes();

    int x;
    std::cout << "Enter a natural number: ";
    std::cin >> x;

    for (int i = 1; i < x; i++) {
        if (CheckSphenic(i)) {
            std::cout << i << std::endl;
        }
    }

    return 0;
}

//Complexity of the program is O(n^2)