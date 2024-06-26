/*
 *  lab1exe_A.cpp
 *  ENSF 694 Lab 1, exercise A
 *  Created by Mahmood Moussavi
 *  Completed by: Jeff Wheeler
 *	Submission date: July 3, 2024
 */

#include <iostream>
#include <cmath>
using namespace std;

const double G = 9.8;   /* gravitation acceleration 9.8 m/s^2 */
const double PI = 3.141592654;

void create_table(double v);
double Projectile_travel_time(double a, double v);
double Projectile_travel_distance(double a, double v);
double degree_to_radian(double d);

int main(void)
{
    double velocity;
    
    cout << "Please enter the velocity at which the projectile is launched (m/sec): ";
    cin >> velocity;
    
    if(!cin)  // means if cin failed to read
    {
        cout << "Invalid input. Bye...\n";
        exit(1);
    }
    
    while (velocity < 0 )
    {
        cout << "\nplease enter a positive number for velocity: ";
        cin >> velocity;
        if(!cin)
        {
            cout << "Invalid input. Bye...";
            exit(1);
        }
    }
    
	
    return 0;
}


void create_table(double v){
	cout << "Angle" << /t << "t" << /t << "d";
	cout << "(deg)" << /t << "(sec)" << /t << "(m)";
}

double Projectile_travel_time(double a, double v){
	return 2 * v * sin(a) / G;
}

double Projectile_travel_distance(double a, double v){
	return pow(v,2) / G * sin(2 * a);
}

double degree_to_radian(double d){
	return d * PI / 180;
}
