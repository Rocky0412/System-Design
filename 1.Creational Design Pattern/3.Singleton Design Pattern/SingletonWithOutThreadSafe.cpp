#include <iostream>
#include <string>
#include <map>

using namespace std;

class Singleton
{
    private:
    static Singleton* instance ;
    // Private Constructor
    Singleton(){};
    public:

    static Singleton* getSingleton(){
        if(instance==nullptr){
            instance= new Singleton();
        }
        return instance;
    }
};
// Definition of static member
Singleton* Singleton::instance = nullptr;
int main(){
    Singleton* instance1 = Singleton::getSingleton();
    Singleton* instance2 = Singleton::getSingleton();
    cout << instance1 << endl; cout << instance2 << endl; 
    if (instance1 == instance2) { 
        cout << "Both point to the same object" << endl; } 
    return 0;
}