// Command Design Pattern

#include <iostream>
using namespace std;

// =========================
// Command Interface
// =========================

class ICommand {
public:
    virtual void executeON() = 0;
    virtual void executeOFF() = 0;

    virtual ~ICommand() = default;
};

// =========================
// Receiver Interface
// =========================

class IComponent {
public:
    virtual void On() = 0;
    virtual void Off() = 0;

    virtual ~IComponent() = default;
};

// =========================
// Receivers
// =========================

class TV : public IComponent {
public:
    void On() override {
        cout << "TV: On" << endl;
    }

    void Off() override {
        cout << "TV: Off" << endl;
    }
};

class Fan : public IComponent {
public:
    void On() override {
        cout << "Fan: On" << endl;
    }

    void Off() override {
        cout << "Fan: Off" << endl;
    }
};

// =========================
// Concrete Commands
// =========================

class TvCommand : public ICommand {
private:
    IComponent* component;

public:
    TvCommand(IComponent* component) {
        this->component = component;
    }

    void executeON() override {
        component->On();
    }

    void executeOFF() override {
        component->Off();
    }
};

class FanCommand : public ICommand {
private:
    IComponent* component;

public:
    FanCommand(IComponent* component) {
        this->component = component;
    }

    void executeON() override {
        component->On();
    }

    void executeOFF() override {
        component->Off();
    }
};

// =========================
// Client
// =========================

int main() {

    IComponent* tv = new TV();
    IComponent* fan = new Fan();

    ICommand* fanCommand = new FanCommand(fan);
    ICommand* tvCommand = new TvCommand(tv);

    fanCommand->executeON();
    fanCommand->executeOFF();

    tvCommand->executeON();
    tvCommand->executeOFF();

    delete fanCommand;
    delete tvCommand;

    delete fan;
    delete tv;

    return 0;
}