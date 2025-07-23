// Paint Job Estimator Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int getRooms(int rooms)
{
    cout << "How many rooms need to be painted? \n";
    cin >> rooms;
    while (rooms < 1) // Makes sure the number of rooms is more than 1
    {
        cout << "Invalid Entry. The number of rooms must be greater than 1 \n";
        cin >> rooms;
    }

    return rooms;

}

int getSqFt(int &squareFeet)
{
    cin >> squareFeet;
    while (squareFeet < 0) // Makes sure the Square Feet is a positive value
    {
        cout << "Invalid entry. Square feet must be greater that 0 \n";
        cin >> squareFeet;
    }

    return squareFeet;
}

int gallonsForRoom(int sqft) // Gets the number of gallons per room
{
   
    if (sqft % 110 == 0)
    {
        return sqft / 110;
    }

    else
    {
        return sqft / 110 + 1; // Round up if less than 1 gallon of paint is left over
    }
}

double getPricePerGallon(double ppg)
{
    cout << "What is the price per gallon of paint? \n";
    cin >> ppg;
    while (ppg < 10) // Makes sure the price is less than 10$
    {
        cout << "Invalid entry. Square feet must be greater than 10 \n";
        cin >> ppg;
    }

    return ppg;
}

void displayEstimate(double paintcharge, int gallonsNeeded, double laborCharge, double laborHours)
{
    cout << "Gallons of paint to purchase: " << gallonsNeeded << endl;
    cout << "Number of hours required to paint rooms: " << laborHours << endl;
    cout << "Cost of paint:  $" << paintcharge << endl;
    cout << "Cost of labor:  $" << laborCharge << endl;
    cout << "Total cost for job:  " << paintcharge + laborCharge << endl;
}

int main()
{  
    const double laborPerSqFt = 8.0 / 110.0;
    const double laborChargePerHour = 25;
     
    
    double paintcharge = 0;
    double laborCharge = 0;
    int gallonsNeeded = 0;
    double laborHours = 0;
    double labor;
    int numRooms = 0;
    int squareFeet = 0;
    int gallons = 0;
    double paintPrice = 0;

    numRooms = getRooms(numRooms);
   

    for (int x = 1; x <= numRooms; x++)
    {
        cout << "What is the square feet of room " << x << "? \n";
        squareFeet = getSqFt(squareFeet); // Gets Square feet value
        

        gallons = gallonsForRoom(squareFeet); // Uses function to take square feet value and get gallon value
        

        gallonsNeeded += gallons; // Adds the new value of the gallons needed to the previous value for each iteration
        
        paintPrice = getPricePerGallon(paintPrice); // Uses function to get the paint price from input
        

        paintcharge += gallons * paintPrice; //Adds the multiple of gallons and paintprice of the first iteration to the current paint charge
        
        labor = squareFeet * laborPerSqFt;

        laborHours += labor; // Adds value to labor to the variable for the total value of labor Hours

        laborCharge += labor * laborChargePerHour; // Gets total labor charge from each iteration by adding the multiple of 
                                                   // the labor and laborChargePerHour to the previous value of the labor charge
    }

    cout << "Estimate for Painting 5 Rooms: \n";
    displayEstimate(paintcharge, gallonsNeeded, laborCharge, laborHours);
}


