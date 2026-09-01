
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Observer
class Observer {
public:
    string name;

    Observer(string name) {
        this->name = name;
    }

    virtual void notify(string channelName) = 0;

    virtual ~Observer() {}
};

// Observable / Subject
class Observable {
public:
    virtual void notifyAll() = 0;
    virtual void add(Observer* observer) = 0;
    virtual void remove(Observer* observer) = 0;

    virtual ~Observable() {}
};


// Concrete Subject
class YouTubeChannel : public Observable {

private:
    vector<Observer*> observers;
    string name;

public:

    YouTubeChannel(string name) {
        this->name = name;
    }

    void add(Observer* observer) override {
        observers.push_back(observer);

        cout << observer->name
             << " subscribed to "
             << name << endl;
    }

    void remove(Observer* observer) override {

        for (auto it = observers.begin(); it != observers.end(); ++it) {

            if (*it == observer) {
                observers.erase(it);
                break;
            }
        }
    }

    void notifyAll() override {

        for (Observer* observer : observers) {
            observer->notify(name);
        }
    }

    void uploadVideo(string video) {

        cout << "\nNew video uploaded: "
             << video << endl;

        notifyAll();
    }
};


// Concrete Observer
class Subscriber : public Observer {

public:

    Subscriber(string name) : Observer(name) {}

    void notify(string channelName) override {

        cout << name
             << " received notification from "
             << channelName << endl;
    }
};


int main() {

    YouTubeChannel channel("Rocky Tech");

    Subscriber s1("Alice");
    Subscriber s2("Bob");
    Subscriber s3("Charlie");

    channel.add(&s1);
    channel.add(&s2);
    channel.add(&s3);

    channel.uploadVideo("Observer Design Pattern");

    return 0;
}

