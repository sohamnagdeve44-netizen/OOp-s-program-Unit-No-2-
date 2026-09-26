#include <iostream>     // For input and output
#include <string>       // For using string data type
#include <vector>       // For using vector
using namespace std;

// Class to represent a soil moisture sensor
class SoilSensor {
private:
    string sensorId;        // Stores the sensor ID
    double moistureLevel;  // Stores the moisture level
    string timestamp;      // Stores the time of reading

public:
    // Constructor to initialize sensor details
    SoilSensor(string id, double moisture, string time)
        : sensorId(id), moistureLevel(moisture), timestamp(time) {}

    // Function to update sensor reading
    void readSensor(double newMoisture, string newTime) {
        moistureLevel = newMoisture;  // Update moisture level
        timestamp = newTime;          // Update time
    }

    // Function to display sensor data
    void displayData() const {
        cout << "Sensor: " << sensorId
             << " | Moisture: " << moistureLevel << "%"
             << " | Time: " << timestamp << endl;
    }
};

int main() {

    // Create a vector to store multiple soil sensors
    vector<SoilSensor> farmSensors;

    // Add first sensor with ID, moisture level and time
    farmSensors.emplace_back("S001", 45.2, "08:00");

    // Add second sensor
    farmSensors.emplace_back("S002", 52.8, "08:00");

    // Add third sensor
    farmSensors.emplace_back("S003", 38.5, "08:00");

    // Display heading for morning readings
    cout << "=== Morning Sensor Readings ===" << endl;

    // Loop through all sensors and display their data
    for (const auto& sensor : farmSensors) {
        sensor.displayData();
    }

    // Update the reading of the first sensor
    farmSensors[0].readSensor(47.5, "09:00");

    // Display heading for updated reading
    cout << "\n=== Updated Reading ===" << endl;

    // Display the updated data of the first sensor
    farmSensors[0].displayData();

    return 0;  // End the program
}
