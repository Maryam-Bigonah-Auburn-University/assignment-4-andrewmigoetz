#include <iostream>
#include <iomanip>

using namespace std;

class GasPump {
private:
    double amountDispensed,
           amountCharged,
           costPerGallon;

public:
    double getAmountDispensed() { return amountDispensed; }
    double getAmountCharged() { return amountCharged; }
    double getCostPerGallon() { return costPerGallon; }
    void setCostPerGallon(double cpg) { costPerGallon = cpg; }

    void dispense(int seconds) {
        // Dispensing 0.10 gallons of gas per second
        amountDispensed = seconds * 0.10;
        amountCharged = amountDispensed * costPerGallon;
    }

    //Reset the amount dispensed and charged before each use
    void reset() {
        amountDispensed = 0.0;
        amountCharged = 0.0;
    }
};

int main() {
// Add repump char variable in case the user wants to reset and try again
    char repump = 'Y';
    do {
        //Define variables
        double costPerGallon;
        int seconds;

        // Define Class Object
        GasPump gasPump;

        // Call Functions

	// Reset values from previous gas pump usage (if any)
        gasPump.reset();

	// Get a gas cost per gallon and use public method to set costPerGallon
        cout << "Enter the cost per gallon: " << endl;
        cin >> costPerGallon;
        gasPump.setCostPerGallon(costPerGallon);

	// Get a gas cost per gallon and call the dispense method with the input no. of seconds
        cout << "How many seconds do you want to pump gas for?" << endl;
        cin >> seconds;
        gasPump.dispense(seconds);

        // Set the precision for all values to 2 to accurately reflect currency notation
        std::cout << std::fixed << std::setprecision(2);

        // Display the gallons of gas pumped, cost per gallon, and total cost
        cout << "Gallons of gas pumped: " << gasPump.getAmountDispensed() << endl;
        cout << "Cost per gallon of gas: $" << gasPump.getCostPerGallon() << endl;
        cout << "Total cost of the gas: $" << gasPump.getAmountCharged() << endl;

        //If repumping, type Y to reset and do again:
        cout << "Enter Y to pump again: " << endl;
        cin >> repump;
    } while(repump=='Y');
    return 0;
}
