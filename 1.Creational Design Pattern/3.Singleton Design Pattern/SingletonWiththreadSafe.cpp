
#include <iostream>
#include <mutex>

using namespace std;

class Singleton
{
private:

    static Singleton* instance;

    // Mutex for thread safety
    static mutex mtx;

    // Private constructor
    Singleton()
    {
        cout << "Singleton Created" << endl;
    }

public:

    // Prevent copying
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;


    static Singleton* getSingleton()
    {
        // Lock mutex
        lock_guard<mutex> lock(mtx);

        // Double Checking

        if (instance == nullptr)
        {
            instance = new Singleton();
        }

        return instance;
    }
};


// Definition of static members
Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;


int main()
{
    Singleton* instance1 = Singleton::getSingleton();
    Singleton* instance2 = Singleton::getSingleton();

    cout << instance1 << endl;
    cout << instance2 << endl;

    if (instance1 == instance2)
    {
        cout << "Both point to the same object" << endl;
    }

    return 0;
}

