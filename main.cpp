#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;

class Student {
    public:
        int id;
        string name;
        string course;
        float marks;

};
// Function to add a new student
void addStudent() {        
    Student s1;
    cout << "Enter student id: ";
    cin >> s1.id;

    ifstream checkFile("student.txt");

    int id;
    string name;
    string course;
    float marks;

    while(checkFile >> id >> name >> course >> marks) {
        if(id == s1.id) {
            cout << "\nStudent ID already exists!\n" << endl;
            return;
        }
    }
    checkFile.close();

    cout << "Enter student name: ";
    cin >> s1.name;
    cout << "Enter student course: ";
    cin >> s1.course;
    cout << "Enter student marks: ";
    cin >> s1.marks;

    ofstream file("student.txt", ios::app);

    if (!file) {
    cout << "\nError: Unable to save student!\n" << endl;
    return;
    }

    file << s1.id << " ";
    file << s1.name << " ";
    file << s1.course << " ";
    file << s1.marks << endl;

    file.close();

    cout << "\nStudent added successfully!\n" << endl;

}
// Function to display all students
void displayStudents() {
    ifstream file("student.txt");
    int id;
    string name;
    string course;
    float marks;
    bool found = false;

    cout << "\n===== STUDENT RECORDS =====\n";
    while (file >> id >> name >> course >> marks) {
        found = true;
        cout << "\n-----------------------------" << endl;
        cout << "ID      : " << id << endl;
        cout << "Name    : " << name << endl;
        cout << "Course  : " << course << endl;
        cout << "Marks   : " << marks << endl;
        cout << "-----------------------------" << endl;
    } if(!found){
        cout << "\nNo student records found.\n" << endl;
    }

    file.close();
}
// Function to search student by ID
void searchStudents() {
    int searchId;
    cout << "Enter Student ID to search: " << endl;
    cin >> searchId;

    ifstream file("student.txt");

    if (!file) {
    cout << "\nError: Unable to open student database!\n" << endl;
    return;
    }

    int id;
    string name;
    string course;
    float marks;

    bool found = false;

    while (file >> id >> name >> course >> marks) {

        if (searchId == id) {
            found = true;
            cout << "\n===== STUDENT FOUND! =====" << endl;
            cout << "ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Course: " << course << endl;
            cout << "Marks: " << marks << endl;

            break;
        }
    } 
    if (!found) {
        cout << "\nStudent not found!\n" << endl;
    }
}
// Function to delete student by ID
void deleteStudent() {
    int deleteId;

    cout << "Enter Student ID to delete: ";
    cin >> deleteId;

    ifstream file("student.txt");

    if (!file) {
    cout << "\nError: Unable to open student database!\n" << endl;
    return;
    }

    ofstream temp("temp.txt");

    int id;
    string name;
    string course;
    float marks;
    bool found = false;

    while(file >> id >> name >> course >> marks) {
        if(deleteId != id) {
            temp << id << " "
                 << name << " "
                 << course << " "
                 << marks << endl;
        } else {
            found = true;
        }
    }

    file.close();
    temp.close();
    
    if(found) {
        remove("student.txt");  
        rename("temp.txt", "student.txt");
        cout << "\nStudent deleted successfully!\n" << endl;
    } else {
        remove("temp.txt");
        cout << "\nStudent not found!\n" << endl;
    }

}
// Function to update student by ID
void updateStudent() {
    int updateId;

    cout << "Enter Student ID to update: ";
    cin >> updateId;

    ifstream file("student.txt");

    if (!file) {
    cout << "\nError: Unable to open student database!\n" << endl;
    return;
    }

    ofstream temp("temp.txt");

    int id;
    string name;
    string course;
    float marks;
    bool found = false;

    while(file >> id >> name >> course >> marks) {
        if(updateId != id) {
            temp << id << " "
                 << name << " "
                 << course << " "
                 << marks << endl;  
        } else {
            found = true;

            cout << "Enter New Name: ";
            cin >> name;

            cout << "Enter New Course: ";
            cin >> course;

            cout << "Enter New Marks: ";
            cin >> marks;

            temp << id << " "
                 << name << " "
                 << course << " "
                 << marks << endl;
        }
    }

    file.close();
    temp.close();

    if(found) {
        remove("student.txt");  
        rename("temp.txt", "student.txt");
        cout << "\nStudent updated successfully!\n" << endl;
    } else {
        remove("temp.txt");
        cout << "\nStudent not found!\n" << endl;
    }
}

int main() {
    int choice = 0;

    while (choice != 6) {

        cout << "\n===================================" << endl;
        cout << "  STUDENT DATABASE MANAGEMENT" << endl;
        cout << "===================================" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Update Student" << endl;
        cout << "5. Delete Student" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            addStudent();
        } else if (choice == 2) {
            displayStudents();
        } else if (choice == 3) {
            searchStudents();
        } else if (choice == 4) {
            updateStudent();
        } else if (choice == 5) {
            deleteStudent();
        } else if (choice == 6) {
            cout << "Exiting Program...." << endl;
        } else {
            cout << "Invalid Choice!" << endl;
        }
    }

    return 0;
};