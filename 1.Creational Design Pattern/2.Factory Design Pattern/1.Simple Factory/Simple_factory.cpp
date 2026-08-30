#include <iostream>
#include <string>
#include <map>

using namespace std;

class Burger{
    public:
    virtual void make()=0;
};
class simpleBuger: public Burger{

    public:
    void make() override{
        cout<<"Simple Buger created "<<endl;
    }

};
class StandardBurger: public Burger{
    public: 
    void make() override{
        cout<<"Standard Burger created"<<endl;
    }
};
class PremiumBurger: public Burger{
    public:
    void make() override{
        cout<<"Premium Burger created"<<endl;

    }
};

class Factory{
    public:
    Burger* createBurger(string type){

        if(type=="simple"){
            return new simpleBuger();
        }
        else if (type=="standard"){
            return new StandardBurger();
        }
        else if(type=="premium"){
            return new PremiumBurger();
        }

        return nullptr;

    }
};

int main(){

    //Client Code
    Factory* factory= new Factory();
    Burger *simpleBurger = factory->createBurger("simple");
    Burger *standarBurger= factory->createBurger("standard");
    Burger *premiumBurger= factory->createBurger("premium");
    simpleBurger->make();
    standarBurger->make();
    premiumBurger->make();

    /*
    ################# Disadvantanges #################
    1. Violates OCP
    2. Tight coupling with concrete classes
    3. Factory becomes a God class
    4. Large if-else/switch logic
    5. Difficult to scale and maintain
    ####################################################
    
    */


}