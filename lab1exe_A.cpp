/*
 *  lab1exe_A.cpp
 *  ENSF 694 Lab 1 - Exercise A
 *  Created by Mahmood Moussavi
 *  Completed by: Jeff Wheeler
 *  Submission date: July 3, 2024
 */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double G = 9.8;   /* gravitation acceleration 9.8 m/s^2 */
const double PI = 3.141592654;  /* constant for pi */

void create_table(double v);
/*
 * REQUIRES:
 *    v - veloctiy in m/s
 * PROMISES:
 * Using a given velocity the fucntion creates a table of projectile's maximum travel distance 
 * and time for trajectory angles of 0 to 90 degrees in increments of 5 degrees
 */

double Projectile_travel_time(double a, double v);
/*
 * REQUIRES:
 *    a - angle in degrees
 *    v - velocity in m/s
 * PROMISES:
 * Calculates projectile travel time for a given angle and velocity
 */

double Projectile_travel_distance(double a, double v);
/*
 * REQUIRES:
 *    a - angle in degrees
 *    v - velocity in m/s
 * PROMISES:
 * Calculates projectile travel distance for a given angle and velocity
 */

double degree_to_radian(double d);
/*
 * REQUIRES:
 *    d - anlge in degrees
 * PROMISES:
 * Converts a degree angle into radians
 */

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

    std::cout << std::fixed;
    std::cout << std::setprecision(3);
    create_table(velocity);
	
    return 0;
}

void create_table(double v){
	cout << "\nAngle" << "\t\t" << "t" << "\t\t" << "d\n";
	cout << "(deg)" << "\t\t" << "(sec)" << "\t\t" << "(m)\n";
    for (double a = 0.00000; a <= 90.00000; a += 5.00000){
        cout << a << "\t\t" << Projectile_travel_time(a,v) << "\t\t" 
        << Projectile_travel_distance(a,v) << "\n";
    }
}

double Projectile_travel_time(double a, double v){
	return 2 * v * sin(degree_to_radian(a)) / G;
}

double Projectile_travel_distance(double a, double v){
	return pow(v,2) / G * sin(2 * degree_to_radian(a));
}

double degree_to_radian(double d){
	return d * PI / 180;
}
