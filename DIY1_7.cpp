#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int id;

public:
    Employee(string n = "", int i = 0) : name(n), id(i) {}

    void display() const {
        cout << "Name: " << name << endl;
        cout << "ID  : " << id << endl;
    }
};

class Manager : public Employee {
    int teamSize;

public:
    Manager(string n, int i, int t) : Employee(n, i), teamSize(t) {}

    void display() const {
        cout << "--- Manager ---" << endl;
        Employee::display();
        cout << "Team size: " << teamSize << endl;
    }
};

class Engineer : public Employee {
    string skill;

public:
    Engineer(string n, int i, string s) : Employee(n, i), skill(s) {}

    void display() const {
        cout << "--- Engineer ---" << endl;
        Employee::display();
        cout << "Skill: " << skill << endl;
    }
};

int main() {
    string name, skill;
    int id, team;

    cout << "Enter manager name: ";
    getline(cin, name);
    cout << "Enter manager id: ";
    cin >> id;
    cout << "Enter team size: ";
    cin >> team;
    cin.ignore();
    Manager m(name, id, team);

    cout << "\nEnter engineer name: ";
    getline(cin, name);
    cout << "Enter engineer id: ";
    cin >> id;
    cin.ignore();
    cout << "Enter engineer skill: ";
    getline(cin, skill);
    Engineer e(name, id, skill);

    cout << endl;
    m.display();
    cout << endl;
    e.display();
    return 0;
}
