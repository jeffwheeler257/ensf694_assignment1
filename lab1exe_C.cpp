/*
 *  lab1exe_C.cpp
 *  ENSF 694 Lab 1 - Exercise C
 *  Created by Mahmood Moussavi
 *  Completed by: Jeff Wheeler
 *  Submission date: July 3, 2024
 */

#include <iostream>
using namespace std;

void time_convert(int ms_time, int *minutes_ptr, double *seconds_ptr);
/*
 * Converts time in milliseconds to time in minutes and seconds.
 * For example, converts 123400 ms to 2 minutes and 3.4 seconds.
 * REQUIRES:
 *    ms_time >= 0.
 *    minutes_ptr and seconds_ptr point to variables.
 * PROMISES:
 *    0 <= *seconds_ptr & *seconds_ptr < 60.0
 *    *minutes_ptr minutes + *seconds_ptr seconds is equivalent to
 *    ms_time ms.
 */

int main(void)
{
  int millisec;
  int minutes;
  double seconds;
    
  cout << "Enter a time interval as an integer number of milliseconds: ";
  
 // printf("Enter a time interval as an integer number of milliseconds: ");
  cin >> millisec;
  
  if (!cin) {
    cout << "Unable to convert your input to an int.\n";
    exit(1);
  }
  
  cout << "Doing conversion for input of " <<  millisec <<" milliseconds ... \n";

  /* MAKE A CALL TO time_convert HERE. */
  time_convert(millisec, &minutes, &seconds);

  cout << "That is equivalent to " << minutes << " minute(s) and " << seconds << " second(s).\n";
  return 0;
}

/* PUT YOUR FUNCTION DEFINITION FOR time_convert HERE. */
void time_convert(int ms_time, int *minutes_ptr, double *seconds_ptr){
  double total_seconds = ms_time / 1000.0;
  *minutes_ptr = (int) total_seconds / 60;
  *seconds_ptr =  total_seconds - *minutes_ptr * 60;
}
