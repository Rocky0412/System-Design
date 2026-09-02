#include <iostream>
using namespace std;

class VendingMachine;

// State Interface
class State {
public:
    virtual void insertCoin(VendingMachine* machine) = 0;
    virtual void selectProduct(VendingMachine* machine) = 0;
    virtual void dispense(VendingMachine* machine) = 0;

    virtual ~State() {}
};


// Forward declarations of concrete states
class NoCoinState;
class HasCoinState;
class DispenseState;


// Context
class VendingMachine {
private:
    State* state;

public:
    VendingMachine();

    void setState(State* state) {
        this->state = state;
    }

    void insertCoin() {
        state->insertCoin(this);
    }

    void selectProduct() {
        state->selectProduct(this);
    }

    void dispense() {
        state->dispense(this);
    }
};


// =============================
// Concrete State Classes
// =============================

class NoCoinState : public State {
public:
    void insertCoin(VendingMachine* machine) override;
    void selectProduct(VendingMachine* machine) override;
    void dispense(VendingMachine* machine) override;
};


class HasCoinState : public State {
public:
    void insertCoin(VendingMachine* machine) override;
    void selectProduct(VendingMachine* machine) override;
    void dispense(VendingMachine* machine) override;
};


class DispenseState : public State {
public:
    void insertCoin(VendingMachine* machine) override;
    void selectProduct(VendingMachine* machine) override;
    void dispense(VendingMachine* machine) override;
};


// =============================
// Method Implementations
// =============================

void NoCoinState::insertCoin(VendingMachine* machine) {

    cout << "Coin inserted." << endl;

    machine->setState(new HasCoinState());
}


void NoCoinState::selectProduct(VendingMachine* machine) {

    cout << "Please insert a coin first." << endl;
}


void NoCoinState::dispense(VendingMachine* machine) {

    cout << "Please insert a coin first." << endl;
}


void HasCoinState::insertCoin(VendingMachine* machine) {

    cout << "Coin already inserted." << endl;
}


void HasCoinState::selectProduct(VendingMachine* machine) {

    cout << "Product selected." << endl;

    machine->setState(new DispenseState());
}


void HasCoinState::dispense(VendingMachine* machine) {

    cout << "Please select a product first." << endl;
}


void DispenseState::insertCoin(VendingMachine* machine) {

    cout << "Please wait, dispensing product." << endl;
}


void DispenseState::selectProduct(VendingMachine* machine) {

    cout << "Product already selected." << endl;
}


void DispenseState::dispense(VendingMachine* machine) {

    cout << "Product dispensed." << endl;

    machine->setState(new NoCoinState());
}


// Initial State
VendingMachine::VendingMachine() {

    state = new NoCoinState();
}


// =============================
// Main
// =============================

int main() {

    VendingMachine machine;

    machine.selectProduct();

    machine.insertCoin();

    machine.insertCoin();

    machine.selectProduct();

    machine.dispense();

    machine.insertCoin();

    return 0;
}