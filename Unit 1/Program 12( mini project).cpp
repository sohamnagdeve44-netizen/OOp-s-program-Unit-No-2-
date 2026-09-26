#include <iostream>     // For input and output
#include <string>       // For using string
#include <vector>       // For storing multiple devices
using namespace std;

// Class to represent a smart home device
class SmartDevice {
private:
    string deviceId;        // Stores device ID
    string location;        // Stores device location
    string status;          // Stores device status (ON/OFF)
    string lastUpdated;     // Stores last updated time

public:
    // Constructor to initialize device details
    SmartDevice(string id, string loc, string stat, string time)
        : deviceId(id), location(loc),
          status(stat), lastUpdated(time) {}

    // Function to switch the device ON
    void switchOn(string time) {
        status = "ON";              // Change status to ON
        lastUpdated = time;         // Update time
    }

    // Function to switch the device OFF
    void switchOff(string time) {
        status = "OFF";             // Change status to OFF
        lastUpdated = time;         // Update time
    }

    // Function to change the device status
    void changeStatus(string newStatus, string time) {
        status = newStatus;         // Update device status
        lastUpdated = time;         // Update last updated time
    }

    // Function to display device information
    void display() const {
        cout << "Device ID: " << deviceId
             << " | Location: " << location
             << " | Status: " << status
             << " | Last Updated: " << lastUpdated
             << endl;
    }
};

int main() {

    // Create a vector to store smart devices
    vector<SmartDevice> devices;

    // Add different smart devices
    devices.emplace_back("L001", "Living Room", "OFF", "08:00");
    devices.emplace_back("T001", "Bedroom", "OFF", "08:05");
    devices.emplace_back("C001", "Main Gate", "ON", "08:10");
    devices.emplace_back("D001", "Main Door", "OFF", "08:15");

    // Switch the living room light ON
    devices[0].switchOn("09:00");

    // Switch the thermostat ON
    devices[1].switchOn("09:05");

    // Change camera status
    devices[2].changeStatus("Recording", "09:10");

    // Switch the door lock ON
    devices[3].switchOn("09:15");

    // Display the home dashboard
    cout << "========== SMART HOME DASHBOARD ==========" << endl;

    // Display details of all devices
    for (const auto& device : devices) {
        device.display();
    }

    cout << "==========================================" << endl;

    return 0;     // End the program
}
