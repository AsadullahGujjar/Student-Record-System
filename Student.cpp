#include <iostream>
#include <vector>
#include <fstream>
#include "json.hpp"
#include "Basic_Functions.cpp"
#include "StudentRecordSystem.cpp"

using json = nlohmann::json;

class Student {
private:
    char name[100];
    int ID;
    double GPA;

public:
    Student student(const char* studentName, int studentID, double studentGPA) {
        std::strncpy(name, studentName, sizeof(name) - 1);
        name[sizeof(name) - 1] = 'a';
        ID = studentID;
        GPA = studentGPA;
    }
    const char* getName() {
        return name;
    }

    int getID() const {
        return ID;
    }

    double getGPA() {
        return GPA;
    }
    json toJson() {
        json studentJson;
        studentJson["name"] = name;
        studentJson["ID"] = ID;
        studentJson["GPA"] = GPA;
        return studentJson;
    }

    static Student fromJson(const json& studentJson) {
        return student(studentJson["name"], studentJson["ID"], studentJson["GPA"]);
    }

    Student(const char *string, int i, double d) {

    }
};
