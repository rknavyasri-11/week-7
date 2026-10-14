#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;

public:
    Person(string n = "Unknown") : name(n) {
        cout << "Person constructor called (only once)" << endl;
    }
};

class Student : virtual public Person {
protected:
    int rollNo;

public:
    Student(string n = "Unknown", int r = 0) : Person(n), rollNo(r) {
        cout << "Student constructor called" << endl;
    }
};

class Employee : virtual public Person {
protected:
    int empId;

public:
    Employee(string n = "Unknown", int e = 0) : Person(n), empId(e) {
        cout << "Employee constructor called" << endl;
    }
};

class TA : public Student, public Employee {
public:

    TA(string n, int r, int e) : Person(n), Student(n, r), Employee(n, e) {
        cout << "TA constructor called" << endl;
    }

    void display() const {
        cout << "\nTA details" << endl;
        cout << "Name   : " << name << endl;    
        cout << "Roll No: " << rollNo << endl;
        cout << "Emp ID : " << empId << endl;
    }
};

int main() {
    string name;
    int roll, emp;

    cout << "Enter TA name: ";
    getline(cin, name);
    cout << "Enter roll number: ";
    cin >> roll;
    cout << "Enter employee id: ";
    cin >> emp;

    cout << "\n--- Creating TA object ---" << endl;
    TA t(name, roll, emp);

    t.display();
    return 0;
}
