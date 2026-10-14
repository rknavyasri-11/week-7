#include <iostream>
#include <string>
using namespace std;

class Shape {
protected:
    string name;

public:
    Shape(string n) : name(n) {
        cout << "Shape constructor called (name = " << name << ")" << endl;
    }
    ~Shape() { cout << "Shape destructor called" << endl; }
};

class Polygon : public Shape {
protected:
    int sides;

public:
    Polygon(string n, int s) : Shape(n), sides(s) {
        cout << "Polygon constructor called (sides = " << sides << ")" << endl;
    }
    ~Polygon() { cout << "Polygon destructor called" << endl; }
};

class Rectangle : public Polygon {
    double length, breadth;

public:
    Rectangle(string n, int s, double l, double b) : Polygon(n, s), length(l), breadth(b) {
        cout << "Rectangle constructor called (" << length << " x " << breadth << ")" << endl;
    }
    ~Rectangle() { cout << "Rectangle destructor called" << endl; }

    void display() const {
        cout << "\nShape   : " << name << endl;
        cout << "Sides   : " << sides << endl;
        cout << "Length  : " << length << endl;
        cout << "Breadth : " << breadth << endl;
        cout << "Area    : " << length * breadth << "\n" << endl;
    }
};

int main() {
    double l, b;
    cout << "Enter length and breadth: ";
    cin >> l >> b;

    cout << "\n--- Creating Rectangle object ---" << endl;
    Rectangle r("Rectangle", 4, l, b);

    r.display();

    cout << "--- Object going out of scope ---" << endl;
    return 0;
}
