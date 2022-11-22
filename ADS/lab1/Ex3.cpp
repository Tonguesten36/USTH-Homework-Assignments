#include <iostream>

/*
This program finds the max number in a sequence of numbers


Pseudocode
BEGIN
    // findMax is a pass-by-ref function, with max being a ref var
    function findMax(int &max, int n):
        if a > max then
            //this will affect the original argument
            max = a
        Output the max number

    function main():
        Get the length of the sequence from the user, store it in length_of_seq variable
        
        //initialize a dynamic array for the sequence
        sequence[length_of_seq] = {} 

        FOR i <- 0 to length_of_seq - 1 DO
            sequence[i] <- an integer from user input
        ENDFOR

        //initialize maxValue variable
        maxValue <- sequence[0]

        //finding max value in the sequence
        FOR i <- 0 to length_of_seq - 1 DO
            findMax(maxValue, sequence[i])
        ENDFOR

        Output the maxValue variable
END
*/


void findMax(int &max, int a) //O(1)
{
    if(a > max){
        max = a;
    }
}

int main()
{
    //Get the size of the sequence
    int lengthOfSeq;
    printf("Enter the size of sequence: ");
    scanf("%d", &lengthOfSeq); //O(1)

    // the sequence is a dynamic array
    int *sequence = new int(lengthOfSeq);
    //Creating the sequence array
    for(int i = 0; i < lengthOfSeq;i++) // O(n)
    {
        printf("Enter a value for the element %d in the sequence: ", i);
        scanf("%d", &sequence[i]); //O(1)
    }

    //Initialize maxValue
    int maxValue = sequence[0]; //O(1)
    //Finding maxValue of the sequence
    for(int i = 0; i < lengthOfSeq; i++) // O(n)
    {
        findMax(maxValue, sequence[i]);
    }

    //Output the maxValue
    printf("The maximum number in the sequence is: %d", maxValue);
    
    return 0;
}

// Complexity of the program: O(n)
