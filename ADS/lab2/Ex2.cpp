#include <iostream>
using namespace std;

/*

This program manages a railway train. It can add new cars into the train, remove any car that has no passengers,
display all cars' info or length of the train

Pseudocode (this pseudocode may not accurately represent the code)

    Initialize a new datatype of Car
        Number of passengers
        Name of the car
        A pointer that points to the next car
    Initialize a new datatype of Train (technically a list)
        Length of the train
        Car *firstCar 

    Create a new train line w/ the 1st car
        The 1st car must point to NULL
        Length = 1

    Function that can   display all cars' info (optional)
                            Iterate through the train from 1st element to last
                             and display their names and passengers
                        display length of the train
                            Count how many cars linked together and display it
                        Add new car
                            Allocate memory for the new car
                            Prompt user for car name and passengers
                            Insert the car into the line as the first element (at the beginning of the train)
                            Increment the length of the train
                        Remove car if no passenger inside
                            Check if the Car tergeted for deletion has any passenger
                            The car behind the Car targeted for deletion
                                will point to the car in front of the deleted Car
                            Free the memory which was allocated for the deleted car
                            Decrement the length of the train
                        Check if the train is empty (optional but why not...)
*/

/*
Datatype of Car:
    - Number of passengers
    - Name of the car
    - A pointer that points to the next car
*/
typedef struct Car
{
    int passengers;
    string name;
    struct Car *nextCar;
};
typedef struct Train
{
    int length; //Length of the train
    Car *firstCar; //Points to the 1st car in the train (the 1st element in the list)
};

/*
Create a new train line w/ no car
    - The car pointer must point to NULL
    - Length = 0
*/
void InitializeNewTrain(Train *newTrain)
{
    newTrain->length = 0;
    newTrain->firstCar = NULL;
}

/*
Add new car, can do:
        - Allocate memory for the new car's name and passengerNo
        - Prompt user for car name and passengers
        - Insert the new car right in front of the first car (if the train has one)
        - Increment the length of the train
*/
void AddNewCar(Train *train, int passengerNo, string carName)
{
    Car *newCar = new Car();

    newCar->passengers = passengerNo;
    newCar->name = carName;

    //If the "train" is empty
    if(train->length == 0)
    {
        newCar->nextCar = NULL;
        train->firstCar = newCar;
    }
    else // If there is at lest 1 car
    {
        newCar->nextCar = train->firstCar;
        train->firstCar = newCar;
    }

    train->length++;
}


/*
    Remove car if no passenger inside (with car name)
        Check if the Car tergeted for deletion has any passenger
        The car behind the Car targeted for deletion
            will point to the car in front of the deleted Car
        Free the memory which was allocated for the deleted car
        If the first car got deleted, the firstCar pointer must point to the car pointed by the deleted car
        If the last car got deleted, the car that points to it must point to NULL
        If the car got deleted somewhere else in the train, the car pointed to it must point to the car that was pointed by it

        Decrement the length of the train
*/
void RemoveCar(Train *train, string target)
{
    Car *deleteTarget = train->firstCar;
    Car *previousCar = NULL;

    //Traverse through the train
    while(deleteTarget != NULL)
    {
        if(train->firstCar->name == target && deleteTarget->passengers == 0)
        {
            cout << "Deleted: " << deleteTarget->name << endl;
            train->firstCar = deleteTarget->nextCar;
            
            train->length--;
            delete deleteTarget;
            break;
        }
        if(deleteTarget->name == target && deleteTarget->passengers == 0)
        {
            cout << "Deleted: " << deleteTarget->name << endl;
            previousCar->nextCar = deleteTarget->nextCar;

            train->length--;
            delete deleteTarget;
            break;
        }
        if(deleteTarget->nextCar == NULL && deleteTarget->passengers == 0)
        {
            cout << "Deleted: " << deleteTarget->name << endl;
            previousCar->nextCar = NULL;
            
            train->length--;
            delete deleteTarget;
            break;
        }
        previousCar = deleteTarget;
        deleteTarget = deleteTarget->nextCar;
    }

    
}

// Get the length of the train
int GetTrainLength(Train *train)
{
    return train->length;
}

// Display all cars' info on the train
void GetAllCarInfo(Train *train)
{
    Car *tempCar = train->firstCar;

    // Check if the train has any car in it
    if(tempCar != NULL)
    {
        cout << "---A list of every cars on the train: " << endl;
        // Traversing through the train, until it hits NULL
        int i = 1;
        while(tempCar != NULL)
        {
            cout << i << ". Name: " << tempCar->name << " Passenger(s): " << tempCar->passengers;
            // Mark the tempCar as Head of the train if its the firstCar
            if(tempCar == train->firstCar)
                cout << " (Head of the train)";
            
            cout << endl;

            // Move on to the next car
            i++;
            tempCar = tempCar->nextCar;
        }
    }
    else
    {
        cout << "This train has no car." << endl;
    }
}


int main()
{
    //Testing all functions

    // Create a new train
    Train *theTrain = new Train();
    InitializeNewTrain(theTrain);
    
    int a = 0;
    while(a == 0)
    {
        int i;
        string name;
        int passengers;

        cout << "---Welcome to the train management system.\nA new train has been created for you.\nIt has no car at the moment" << endl;
        cout << "A list of available commands: " << endl;
        cout << "1. Insert a new car to the head of the train\n2. Remove a specific car (it must have no passengers in it)\n3. Get the length of the train\n4. Display all cars\' info\n5. End program" << endl;
        
        cout << "Enter the number that represents the command: ";
        cin >> i;

        switch (i)
        {
            case 1:
                cout << "---Please enter the name for the new car: ";
                cin >> name;
                
                cout << "---Please enter the number of passengers for the car: ";
                cin >> passengers;
                
                AddNewCar(theTrain, passengers, name);
                break;
            case 2:
                cout << "---Enter the car that you wish to delete: ";
                cin >> name;

                RemoveCar(theTrain, name);
                break;
            case 3:
                cout << "---Train length: " << GetTrainLength(theTrain) << endl;
                break;
            case 4:
                GetAllCarInfo(theTrain);
                break;
            case 5:
                a = 1;
                break;
            default:
                break;
        }
    }
    delete theTrain;
    return 0;
}