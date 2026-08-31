
#include <iostream>
using namespace std;

// =======================
// Implementor
// =======================

class IEngine {
public:
    virtual void start() = 0;
    virtual ~IEngine() = default;
};


// =======================
// Concrete Implementors
// =======================

class PetrolEngine : public IEngine {
public:
    void start() override {
        cout << "Petrol Engine Started" << endl;
    }
};

class DieselEngine : public IEngine {
public:
    void start() override {
        cout << "Diesel Engine Started" << endl;
    }
};

class ElectricEngine : public IEngine {
public:
    void start() override {
        cout << "Electric Engine Started" << endl;
    }
};


// =======================
// Abstraction
// =======================

class ICar {
public:
    virtual void drive() = 0;
    virtual ~ICar() = default;
};


// =======================
// Refined Abstraction
// =======================

class Sedan : public ICar {
private:
    IEngine* engine;

public:
    Sedan(IEngine* engine) {
        this->engine = engine;
    }

    void drive() override {
        cout << "Sedan Car" << endl;
        engine->start();
    }
};

class SUV : public ICar {
private:
    IEngine* engine;

public:
    SUV(IEngine* engine) {
        this->engine = engine;
    }

    void drive() override {
        cout << "SUV Car" << endl;
        engine->start();
    }
};


// =======================
// Client
// =======================

int main() {

    PetrolEngine petrol;
    DieselEngine diesel;
    ElectricEngine electric;

    Sedan sedan1(&petrol);
    sedan1.drive();

    cout << endl;

    Sedan sedan2(&electric);
    sedan2.drive();

    cout << endl;

    SUV suv1(&diesel);
    suv1.drive();

    cout << endl;

    SUV suv2(&electric);
    suv2.drive();

    return 0;
}

