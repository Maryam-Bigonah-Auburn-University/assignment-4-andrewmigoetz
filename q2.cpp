#include <iostream>

using namespace std;

class Temperature {
private:
    double degreesKelvin,
           degreesFahrenheit,
           degreesCelsius;
public:
    // For each public function, return or set a value based on private variables:
    void setTempKelvin(double kelvin) { degreesKelvin = kelvin; }
    double getTempKelvin() { return degreesKelvin; }
    // With kelvin formula, solve for celsius
    void setTempCelsius(double kelvin) { degreesCelsius = kelvin-273.15; }
    double getTempCelsius() { return degreesCelsius; }
    // Isolate fahrenheit and model relationship between kelvin and fahrenheit
    void setTempFahrenheit(double kelvin) { degreesFahrenheit = ((kelvin-273.15) * 9/5) + 32; }
    double getTempFahrenheit() { return degreesFahrenheit; }
};

int main() {
    // Define variables
    double kelvin;

    // Define class object
    Temperature temperature;

    // Prompt user to enter temperature in degrees Kelvin
    cout << "Enter a temperature in degrees Kelvin: " << endl;
    cin >> kelvin;

    // Set temperatures of celsius and fahrenheit based upon kelvin input
    temperature.setTempKelvin(kelvin);
    temperature.setTempCelsius(kelvin);
    temperature.setTempFahrenheit(kelvin);

    // Return temperature in kelvin, celsius, and fahrenheit
    cout << "Celsius: " << temperature.getTempCelsius() << endl;
    cout << "Fahrenheit: " << temperature.getTempFahrenheit() << endl;



}
