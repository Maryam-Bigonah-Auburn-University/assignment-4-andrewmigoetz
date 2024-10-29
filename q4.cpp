#include <iostream>
#include <cstdlib> // for exit()
#include <cctype>  // for tolower()

using namespace std;

class Month
{
public:
    //constructor to set month based on first 3 chars of the month name
    Month(char c1, char c2, char c3);   // done, debugged
    //a constructor to set month base on month number, 1 = January etc.
    Month( int monthNumber);           // done, debugged
    //a default constructor (what does it do? nothing)
    Month(); // done, no debugging to do
    //an input function to set the month based on the month number
    void getMonthByNumber(istream&); // done, debugged
    //input function to set the month based on a three character input
    void getMonthByName(istream&);   // done, debugged
    //an output function that outputs the month as an integer,
    void outputMonthNumber(ostream&); // done, debugged
    //an output function that outputs the month as the letters.
    void outputMonthName(ostream&);   // done, debugged
    //a function that returns the next month as a month object
    Month nextMonth(); //
    //NB: each input and output function have a single formal parameter
    //for the stream

    int monthNumber();

private:
    int mnth;
    void setMonthByName(const char* monthname);
};

int main() {
    // Define variable
    int choice;

    //Define class object
    Month month;

    // Show options
    while (true) {
        cout << "\nMenu:\n";
        cout << "1) Set month using first 3 letters\n";
        cout << "2) Set month by using int value\n";
        cout << "3) Output month as first 3 letters\n";
        cout << "4) Output month as number\n";
        cout << "5) Return next month\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter month number: ";
            month.getMonthByNumber(cin);
            break;
            case 2:
                cout << "Enter month name: ";
            month.getMonthByName(cin);
            break;
            case 3:
                cout << "Month number: ";
            month.outputMonthNumber(cout);
            break;
            case 4:
                cout << "Month name: ";
            month.outputMonthName(cout);
            break;
            case 5:
            {
                Month next = month.nextMonth();
                cout << "Next month number: ";
                next.outputMonthNumber(cout);
                cout << "Next month name: ";
                next.outputMonthName(cout);
            }
            break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
