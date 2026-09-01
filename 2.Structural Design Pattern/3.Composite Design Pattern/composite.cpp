// Composite Design Pattern

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// =================================
// Component
// =================================

class Employee {
public:
    virtual void printPosition() = 0;
    virtual bool isManager() = 0;

    virtual ~Employee() {}
};

// =================================
// Leaf
// =================================

class Executive : public Employee {

private:
    string name;
    string position;

public:
    Executive(string name, string position) {
        this->name = name;
        this->position = position;
    }

    void printPosition() override {
        cout << "Name: " << name
             << " Position: " << position
             << endl;
    }

    bool isManager() override {
        return false;
    }
};

// =================================
// Composite
// =================================

class Manager : public Employee {

private:
    vector<Employee*> under;
    string name;
    string position;

public:
    Manager(string name, string position) {
        this->name = name;
        this->position = position;
    }

    void add(Employee* employee) {
        under.push_back(employee);
    }

    void printPosition() override {

        cout << "Manager: "
             << name
             << " Position: "
             << position
             << endl;

        for (auto emp : under) {
            emp->printPosition();
        }
    }

    bool isManager() override {
        return true;
    }

    int bandwidth() {
        return under.size();
    }
};

// =================================
// Client
// =================================

int main() {

    Executive* e1 =
        new Executive("Rocky", "Developer");

    Executive* e2 =
        new Executive("Rahul", "Tester");

    Manager* m1 =
        new Manager("Devesh", "Engineering Manager");

    m1->add(e1);
    m1->add(e2);

    m1->printPosition();

    cout << "\nBandwidth = "
         << m1->bandwidth()
         << endl;

    delete m1;
    delete e1;
    delete e2;

    return 0;
}