#include <iostream>
using namespace std;

// Base class: Student
class Student {
protected:
    int roll_no;

public:
    void get_no(int a) {
        roll_no = a;
    }

    void put_no() {
        cout << "\nStudent Marks Details" << endl;
        cout << "Roll no: " << roll_no << endl;
    }
};

// Derived class: Test
class Test : public Student {
protected:
    float part1, part2;

public:
    void get_marks(float x, float y) {
        part1 = x;
        part2 = y;
    }

    void put_marks() {
        cout << "Mark 1 = " << part1 << endl;
        cout << "Mark 2 = " << part2 << endl;
    }
};

// Derived class: Sports
class Sports {
protected:
    float score;

public:
    void get_score(float s) {
        score = s;
    }

    void put_score() {
        cout << "Sports score = " << score << endl;
    }
};

// Derived class: Result (multiple inheritance)
class Result : public Test, public Sports {
    float total;

public:
    void display() {
        total = part1 + part2 + score;
        put_no();
        put_score();
        put_marks();
        cout << "Total score = " << total << endl;
    }
};

int main() {
    Result stu;

    int roll;
    float m1, m2, s;

    cout << "Enter Roll number: ";
    cin >> roll;
    stu.get_no(roll);

    cout << "Enter marks of two subjects: ";
    cin >> m1 >> m2;
    stu.get_marks(m1, m2);

    cout << "Enter sports score: ";
    cin >> s;
    stu.get_score(s);

    stu.display();

    return 0;
}