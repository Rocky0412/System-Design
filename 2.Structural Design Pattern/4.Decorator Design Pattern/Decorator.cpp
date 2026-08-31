#include <iostream>
using namespace std;

class ICoffee{
    public:
    virtual string make()=0;
    virtual int price()=0;
};

class SimpleCoffee: public ICoffee{
    public:
    string make(){
        return "Simple Coffee";
    };
    int price(){
        return 100;
    }
};
class MilkDecorator: public ICoffee{
    public:
    ICoffee* coffee;
    MilkDecorator(ICoffee* coffee){
        this->coffee=coffee;
    }
    string make() override{
        return this->coffee->make()+ " ,milk";
    }
    int price() override{
        return 10 + this->coffee->price();
    }
};


class SugarDecorator : public ICoffee {

public:

    ICoffee* coffee;

    SugarDecorator(ICoffee* coffee) {
        this->coffee = coffee;
    }

    string make() override {
        return this->coffee->make() + " ,sugar";
    }

    int price() override {
        return 5 + this->coffee->price();
    }
};
 int main(){
    ICoffee* simpleCoffee= new SimpleCoffee();
    cout<< simpleCoffee->make() << endl;
    cout<<simpleCoffee->price() << endl;
    ICoffee* milkCoffe = new MilkDecorator(simpleCoffee);
    cout<<milkCoffe->make()<<endl;
    cout<<milkCoffe->price()<<endl;
    ICoffee* sugerCoffe= new SugarDecorator(milkCoffe);
    cout<<sugerCoffe->make()<<endl;
    cout<<sugerCoffe->price()<<endl;
    return 0;

 }
