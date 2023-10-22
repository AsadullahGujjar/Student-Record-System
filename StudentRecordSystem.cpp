#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "json.hpp"
#include "Student.cpp"
#include "Basic_Functions.cpp"

using json = nlohmann::json;
class StudentRecordSystem {
private:
    vector<Student> studentRecords;
    Basic_Functions file;

public:
    Student student;
    StudentRecordSystem(const string &filePath, Student student) : file(filePath), student(student) {
        studentRecords = file.readRecordsFromFile();
    }
    void createStudentRecord() {
        string name;
        int id;
        double gpa;
        cout << "Enter the student's name: ";
        cin >> name;
        cout << "Enter the student's ID: ";
        cin >> id;
        cout << "Enter the student's GPA: ";
        cin >> gpa;

        Student student(name.c_str(), id, gpa);
        studentRecords.push_back(student);

        file.writeRecordsToFile(studentRecords);
        cout << "Student record created and saved." << endl;
    }

    void readStudentRecord(int id) {
        for (Student student : studentRecords) {
            if (student.getID() == id) {
                cout << "Student ID: " << student.getID() << endl;
                cout << "Name: " << student.getName() << endl;
                cout << "GPA: " << student.getGPA() << endl;
                return;
            }
        }
        cout << "Student with ID " << id << " not found." << endl;
    }
    void updateStudentRecord(int id) {
        for (Student& student : studentRecords) {
            if (student.getID() == id) {
                string newName;
                double newGPA;
                cout << "Enter the updated name: ";
                cin >> newName;
                cout << "Enter the updated GPA: ";
                cin >> newGPA;

                student = Student(newName.c_str(), id, newGPA);
                file.writeRecordsToFile(studentRecords);
                cout << "Student record updated." << endl;
                return;
            }
        }
        cout << "Student with ID " << id << " not found." << endl;
    }
    void deleteStudentRecord(int id) {
        for (auto it = studentRecords.begin(); it != studentRecords.end(); ++it) {
            if (it->getID() == id) {
                studentRecords.erase(it);
                file.writeRecordsToFile(studentRecords);
                cout << "Student record deleted." << endl;
                return;
            }
        }
        cout << "Student with ID " << id << " not found." << endl;
    }
    void displayAllRecords() {
        if (studentRecords.empty()) {
            cout << "No student records to display." << std::endl;
        } else {
            cout << "Student Records:" << endl;
            for (Student student : studentRecords) {
                cout << "ID: " << student.getID() << " | Name: " << student.getName() << " | GPA: " << student.getGPA() << endl;
            }
        }
    }
    void sortRecordsByGPA() {
        sort(studentRecords.begin(), studentRecords.end(), [](Student a, Student b) {
            return a.getGPA() > b.getGPA();
        });
        file.writeRecordsToFile(studentRecords);
        cout << "Student records sorted by GPA." << endl;
    }
};