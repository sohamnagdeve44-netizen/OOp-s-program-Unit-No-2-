#include <iostream>     // For input and output
#include <string>       // For using string data type
using namespace std;

// Class to store student attendance details
class Student {
private:
    int rollNo;          // Stores student's roll number
    string name;         // Stores student's name
    int totalDays;       // Stores total number of attendance days
    int presentDays;     // Stores number of days student was present

public:
    // Constructor to initialize student details
    Student(int r, string n)
        : rollNo(r), name(n), totalDays(0), presentDays(0) {}

    // Function to mark student's attendance
    void markAttendance(bool isPresent) {
        totalDays++;     // Increase total days by 1

        // Check if student is present
        if (isPresent) {
            presentDays++;   // Increase present days by 1
        }
    }

    // Function to calculate attendance percentage
    double getAttendancePercentage() const {

        // Check if no attendance is recorded
        if (totalDays == 0) {
            return 0.0;    // Return 0% attendance
        }

        // Calculate and return attendance percentage
        return (presentDays * 100.0) / totalDays;
    }

    // Function to display student attendance
    void display() const {
        cout << "Roll: " << rollNo
             << " | Name: " << name
             << " | Attendance: "
             << getAttendancePercentage() << "%" << endl;
    }
};

int main() {

    // Create first student object
    Student s1(101, "Rahul");

    // Create second student object
    Student s2(102, "Priya");

    // Mark Rahul's attendance
    s1.markAttendance(true);    // Present
    s1.markAttendance(true);    // Present
    s1.markAttendance(false);   // Absent

    // Mark Priya's attendance
    s2.markAttendance(true);    // Present
    s2.markAttendance(true);    // Present
    s2.markAttendance(true);    // Present

    // Display attendance report heading
    cout << "=== Attendance Report ===" << endl;

    // Display Rahul's attendance
    s1.display();

    // Display Priya's attendance
    s2.display();

    return 0;   // End the program
}
