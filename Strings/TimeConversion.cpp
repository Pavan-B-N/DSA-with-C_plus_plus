// https://www.hackerrank.com/challenges/time-conversion/problem?isFullScreen=true
/*
Given a time in -hour AM/PM format, convert it to military (24-hour) time.

Note: - 12:00:00AM on a 12-hour clock is 00:00:00 on a 24-hour clock.
- 12:00:00PM on a 12-hour clock is 12:00:00 on a 24-hour clock.
*/
#include <iostream>
#include <string>
using namespace std;

string timeConversion(string s)
{
    // s.substr(startIndex,length)
    // s.replace(startIndex,endIndex,str)
    //  string library functions
    // stoi = string to integer conversion (string library required)
    // to_string()
    string period = s.substr(8);     // Extracting AM/PM
    int hour = stoi(s.substr(0, 2)); // Extracting hours and converting to integer
    string result = s.substr(0, 8);  // Initialize the result with hh:mm:ss part

    if (period == "AM")
    {
        if (hour == 12)
        {
            // Special case: 12 AM should be converted to 00 in 24-hour format
            result.replace(0, 2, "00");
        }
        // For other AM times (01:00:00 AM to 11:59:59 AM), hours remain the same
    }
    else
    { // PM case
        if (hour != 12)
        {
            // Convert PM times (01:00:00 PM to 11:59:59 PM) to 24-hour format
            hour += 12;
            result.replace(0, 2, to_string(hour));
        }
    }

    return result;
}
int main(int argc, char const *argv[])
{
    // string s="07:05:45PM";//19:05:45
    // string s="12:05:45PM";//12:05:45
    string s = "12:05:45AM"; // 00:05:45

    string res = timeConversion(s);
    cout << res << endl;
    return 0;
}
