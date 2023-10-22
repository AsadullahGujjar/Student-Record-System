#include <iostream>
#include "StudentRecordSystem.cpp"
#include "Student.cpp"
#include "Basic_Functions.cpp"
using namespace std;
int main() {
    string filePath = "StudentRecords.json";
    StudentRecordSystem recordSystem;
    int choice, id;
    while (true) {
        cout << "1. Create Student Record" <<endl;
        cout << "2. Read Student Record"<<endl;
        cout << "3. Update Student Record"<<endl;
        cout << "4. Delete Student Record"<<endl;
        cout << "5. Display All Records"<<endl;
        cout << "6. Sort Records by GPA"<<endl;
        cout << "7. Quit" <<endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                recordSystem.createStudentRecord();
                break;
            case 2:
                cout << "Enter Student ID: ";
                cin >> id;
                recordSystem.readStudentRecord(id);
                break;
            case 3:
                cout << "Enter Student ID: ";
                cin >> id;
                recordSystem.updateStudentRecord(id);
                break;
            case 4:
                cout << "Enter Student ID: ";
                cin >> id;
                recordSystem.deleteStudentRecord(id);
                break;
            case 5:
                recordSystem.displayAllRecords();
                break;
            case 6:
                recordSystem.sortRecordsByGPA();
                break;
            case 7:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}

