#include <iostream>
#include <vector>
#include <fstream>
#include "json.hpp"
#include "StudentRecordSystem.cpp"
#include "Student.cpp"
using namespace std;
using json = nlohmann::json;
class Basic_Functions {
private:
    string path;

public:
    Basic_Functions(const std::string& filePath) {
        path = filePath;
    }

    void writeRecordsToFile(const vector<Student> studentRecords) {
        json recordsJson;
        for (const Student student : studentRecords) {
            recordsJson.push_back(student.toJson());
        }

        ofstream file(path);
        if (file.is_open()) {
            file << recordsJson.dump(4);
            file.close();
        } else {
            cerr << "Error opening the file for writing: " << path << endl;
        }
    }
    vector<Student> readRecordsFromFile() {
        ifstream file(path);
        if (file.is_open()) {
            json recordsJson;
            file >> recordsJson;
            vector<Student> studentRecords;
            for (const auto& studentJson : recordsJson) {
                studentRecords.push_back(Student::fromJson(studentJson));
            }
            file.close();
            return studentRecords;
        } else {
            cerr << "Error opening the file for reading: " << path << endl;
            return vector<Student>();
        }
    }
};
