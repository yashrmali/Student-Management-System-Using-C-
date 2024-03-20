#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Structure to represent a student
struct Student {
    string name;
    int rollNumber;
    float marks;
};

// Function to add a new student
void addStudent(vector<Student>& students) {
    Student newStudent;
    cout << "Enter name: ";
    getline(cin >> ws, newStudent.name);
    cout << "Enter roll number: ";
    cin >> newStudent.rollNumber;
    cout << "Enter marks: ";
    cin >> newStudent.marks;

    students.push_back(newStudent);
    cout << "Student added successfully!" << endl;
}

// Function to display all students
void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students to display" << endl;
        return;
    }

    cout << "List of students:" << endl;
    for (const auto& student : students) {
        cout << "Name: " << student.name << ", Roll Number: " << student.rollNumber << ", Marks: " << student.marks << endl;
    }
}

// Function to search for a student by roll number
void searchStudent(const vector<Student>& students, int rollNumber) {
    auto it = find_if(students.begin(), students.end(), [&](const Student& student) {
        return student.rollNumber == rollNumber;
    });

    if (it != students.end()) {
        cout << "Student found:" << endl;
        cout << "Name: " << it->name << ", Roll Number: " << it->rollNumber << ", Marks: " << it->marks << endl;
    } else {
        cout << "Student with roll number " << rollNumber << " not found" << endl;
    }
}

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\nStudent Management System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                int rollNumber;
                cout << "Enter roll number to search: ";
                cin >> rollNumber;
                searchStudent(students, rollNumber);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please enter again." << endl;
        }
    } while (choice != 4);

    return 0;
}
