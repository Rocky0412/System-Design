#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Forward declaration
class User;

// ===============================
// Mediator Interface
// ===============================
class Mediator {
public:
    virtual void send(User* sender,
                      const string& receiver,
                      const string& message) = 0;

    virtual void broadcast(User* sender,
                           const string& message) = 0;

    virtual void addUser(const string& name,
                         User* user) = 0;

    virtual ~Mediator() = default;
};


// ===============================
// Colleague Abstract Class
// ===============================
class User {

   

public:
    string name;
    User(const string& name) {
        this->name = name;
    }

    virtual void sendMessage(const string& receiver,
                             const string& message) = 0;

    virtual void sendToAll(const string& message) = 0;

    virtual void receiveMessage(const string& sender,
                                const string& message) = 0;

    virtual ~User() = default;
};


// ===============================
// Concrete Colleague
// ===============================
class Person : public User {
private:
    Mediator* mediator;

public:
    Person(const string& name, Mediator* mediator)
        : User(name) {
        this->mediator = mediator;
    }

    void sendMessage(const string& receiver,
                     const string& message) override {

        mediator->send(this, receiver, message);
    }

    void sendToAll(const string& message) override {

        mediator->broadcast(this, message);
    }

    void receiveMessage(const string& sender,
                        const string& message) override {

        cout << "[" << name << "] "
             << "Message from "
             << sender << " : "
             << message
             << endl;
    }
};


// ===============================
// Concrete Mediator
// ===============================
class ChatMediator : public Mediator {
private:
    unordered_map<string, User*> users;

public:

    void addUser(const string& name,
                 User* user) override {

        users[name] = user;
    }

    void send(User* sender,
              const string& receiver,
              const string& message) override {

        auto it = users.find(receiver);

        // Receiver doesn't exist
        if (it == users.end()) {

            cout << "User "
                 << receiver
                 << " not found"
                 << endl;

            return;
        }

        // Send message to receiver
        it->second->receiveMessage(
            sender->name,
            message
        );
    }

    void broadcast(User* sender,
                   const string& message) override {

        for (auto& [name, user] : users) {

            // Don't send message back to sender
            if (user == sender)
                continue;

            user->receiveMessage(
                sender->name,
                message
            );
        }
    }
};


// ===============================
// Main
// ===============================
int main() {

    // Create Mediator
    ChatMediator chatRoom;

    // Create users
    Person rocky("Rocky", &chatRoom);
    Person dipa("Dipa", &chatRoom);
    Person jui("Jui", &chatRoom);

    // Register users with Mediator
    chatRoom.addUser("Rocky", &rocky);
    chatRoom.addUser("Dipa", &dipa);
    chatRoom.addUser("Jui", &jui);


    // ===============================
    // Personal Message
    // ===============================

    cout << "=== Personal Message ==="
         << endl;

    rocky.sendMessage(
        "Dipa",
        "Hello Dipa!"
    );


    // ===============================
    // Broadcast Message
    // ===============================

    cout << endl;

    cout << "=== Broadcast Message ==="
         << endl;

    rocky.sendToAll(
        "Good Morning Everyone!"
    );


    // ===============================
    // User Not Found
    // ===============================

    cout << endl;

    cout << "=== Invalid User ==="
         << endl;

    rocky.sendMessage(
        "Rahul",
        "Hello Rahul!"
    );


    return 0;
}