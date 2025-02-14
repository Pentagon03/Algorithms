# Data Structure/Date.cpp

This file defines a `Date` struct for representing and manipulating dates.

## Date Struct

*   **Description:** This file defines a `Date` struct that allows you to represent and manipulate dates, including incrementing, decrementing, and comparing dates.

*   **Struct Members:**
    *   `month`: The month of the date.
    *   `day`: The day of the date.
    *   `year`: The year of the date.

*   **Functions:**
    *   `Date(int mm = 1, int dd = 1, int yy = 1900)`: Constructor that initializes the date with the given month, day, and year.
    *   `static constexpr bool isLeap(int y)`: Checks if a given year is a leap year.
    *   `bool operator<(const Date& date) const`: Less than operator for comparing dates.
    *   `bool operator<=(const Date& date) const`: Less than or equal to operator for comparing dates.
    *   `bool operator>(const Date& date) const`: Greater than operator for comparing dates.
    *   `bool operator>=(const Date& date) const`: Greater than or equal to operator for comparing dates.
    *   `void inc()`: Increments the date to the next day.
    *   `void dec()`: Decrements the date to the previous day.
    *   `void change(int step)`: Increments or decrements the date by a specified number of days.
    *   `friend istream& operator>>(istream& is, Date& date)`: Overloads the input stream operator to read a `Date`.
    *   `friend ostream& operator<<(ostream& os, const Date& date)`: Overloads the output stream operator to print a `Date`.
