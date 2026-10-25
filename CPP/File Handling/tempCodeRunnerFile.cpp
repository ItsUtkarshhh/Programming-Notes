#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Structure to represent a student
struct Student {
    string name;
    int age;
    char grade;

    // Function to display student data
    void display() const {
        cout << "Name: " << name << ", Age: " << age << ", Grade: " << grade << endl;
    }

    // Function to input student data
    void input() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter grade: ";
        cin >> grade;
    }
};

// Function to save student data to file
void saveToFile(const vector<Student>& students) {
    ofstream outFile("students.txt", ios::out | ios::trunc);  // Open file in write mode (overwrite existing content)

    if (outFile.is_open()) {
        for (const auto& student : students) {
            outFile << student.name << " " << student.age << " " << student.grade << endl;
        }
        outFile.close();  // Close the file
        cout << "Student data saved to file." << endl;
    } else {
        cout << "Error opening file for writing!" << endl;
    }
}

// Function to load student data from file
void loadFromFile(vector<Student>& students) {
    ifstream inFile("students.txt");  // Open file in read mode

    if (inFile.is_open()) {
        Student student;
        while (inFile >> student.name >> student.age >> student.grade) {
            students.push_back(student);  // Read and store student data into vector
        }
        inFile.close();  // Close the file
        cout << "Student data loaded from file." << endl;
    } else {
        cout << "No previous records found." << endl;
    }
}

int main() {
    vector<Student> students;
    loadFromFile(students);  // Load existing student records from file

    int choice;
    do {
        cout << "\nStudent Management System\n";
        cout << "1. View All Students\n";
        cout << "2. Add New Student\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // View all student records
                if (students.empty()) {
                    cout << "No student records available.\n";
                } else {
                    cout << "\nStudent Records:\n";
                    for (const auto& student : students) {
                        student.display();
                    }
                }
                break;
            }
            case 2: {
                // Add new student
                Student newStudent;
                newStudent.input();
                students.push_back(newStudent);

                // Save updated records to file
                saveToFile(students);
                break;
            }
            case 3:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 3);

    return 0;
}