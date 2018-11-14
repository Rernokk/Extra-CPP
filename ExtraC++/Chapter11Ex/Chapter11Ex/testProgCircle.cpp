 
//The user program that uses the class circleType
 
#include <iostream>                                   //Line 1
#include <iomanip>                                    //Line 2
#include "circleType.h"                               //Line 3

using namespace std;                                  //Line 4

int main()                                            //Line 5
{                                                     //Line 6
    circleType circle1(8);                            //Line 7
    circleType circle2;                               //Line 8

    double radius;                                    //Line 9

    cout << fixed << showpoint << setprecision(2);    //Line 10

    cout << "Line 11: circle1 - "
         << "radius: " << circle1.getRadius()
         << ", area: " << circle1.area()
         << ", circumference: "
         << circle1.circumference() << endl;          //Line 11

    cout << "Line 12: circle2 - "
         << "radius: " << circle2.getRadius()
         << ", area: " << circle2.area()
         << ", circumference: "
         << circle2.circumference() << endl << endl;  //Line 12

    cout << "Line 14: Enter the radius: ";            //Line 13
    cin >> radius;                                    //Line 14
    cout << endl;                                     //Line 15

    circle2.setRadius(radius);                        //Line 16

    cout << "Line 17: After setting the radius." 
         << endl;                                     //Line 17
    cout << "Line 18: circle2 - "
         << "radius: " << circle2.getRadius()
         << ", area: " << circle2.area()
         << ", circumference: "
         << circle2.circumference() << endl;          //Line 18

    return 0;                                         //Line 19
}//end main                                           //Line 20
