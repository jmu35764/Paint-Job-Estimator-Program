// Paint Job Estimator Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


int getRooms(int rooms)
{
    cout << "How many rooms need to be painted? \n";
    cin >> rooms;
    while (rooms < 1)
    {
        cout << "Invalid Entry. The number of rooms must be greater than 1 \n";
        cin >> rooms;
    }

    return rooms;

}

int getSqFt(int &squareFeet)
{
    //cout << "How many square feet is in the room \n";
    cin >> squareFeet;
    while (squareFeet < 0)
    {
        cout << "Invalid entry. Square feet must be greater that 0 \n";
        cin >> squareFeet;
    }

    return squareFeet;
}

int gallonsForRoom(int sqft)
{
    if (sqft % 110 == 0)
    {
        return sqft / 110;
    }

    else
    {
        return sqft / 110 + 1;
    }
}

double getPricePerGallon(double ppg)
{
    cout << "What is the price per gallon of paint? \n";
    cin >> ppg;
    while (ppg < 10)
    {
        cout << "Invalid entry. Square feet must be greater than 10 \n";
        cin >> ppg;
    }

    return ppg;
}

void displayEstimate(double paintcharge, int gallonsNeeded, double laborCharge, double laborHours)
{
    cout << "gallons needed " << gallonsNeeded << endl;
    cout << "labor hours " << laborHours << endl;
    cout << "paint cost " << paintcharge << endl;
    cout << "labor charge " << laborCharge << endl;
    cout << "total cost " << paintcharge + laborCharge << endl;
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

    cout << laborPerSqFt << endl;
    numRooms = getRooms(numRooms);
   

    for (int x = 1; x <= numRooms; x++)
    {
        cout << "What is the square feet of room " << x << "? \n";
        squareFeet = getSqFt(squareFeet);
        //cout << squareFeet << endl;

        gallons = gallonsForRoom(squareFeet);
        //cout << gallons << endl;

        gallonsNeeded += gallons;
        
        paintPrice = getPricePerGallon(paintPrice);
        //cout << paintPrice << endl;

        paintcharge += gallons * paintPrice;
        
        labor = squareFeet * laborPerSqFt;

        laborHours += labor;

        laborCharge += labor * laborChargePerHour;
    }
    displayEstimate(paintcharge, gallonsNeeded, laborCharge, laborHours);
}


