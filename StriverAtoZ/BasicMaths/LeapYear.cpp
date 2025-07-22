// https://www.geeksforgeeks.org/problems/leap-year0943/1
// a leap year has 366 days, with an extra day added to the month of February.

// A leap year is a year that is evenly divisible by 4, except for years that are divisible by 100. However, years divisible by 400 are leap years.
class Solution {
  public:
    bool checkYear(int year) {
      
     if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true; // Leap year
    } 
        return false; // Not a leap year
    
    }
};