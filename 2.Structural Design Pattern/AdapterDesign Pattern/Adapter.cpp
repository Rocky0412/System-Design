#include <iostream>
#include <string>
#include <map>

using namespace std;

class AdapterPayment{
    public:
    virtual void pay(int amount)=0;
};

class UpiPaymet{
    public:
    void make_payment(int amount){

        cout<<"Upi payment amount "<< amount<<endl;
    }
};

// Composition adapter
class UPIAdaterComposition: public AdapterPayment{
    UpiPaymet upi;
    public:
    UPIAdaterComposition(UpiPaymet upi){
        this->upi=upi;
    }
    void pay(int amount) override{

        this->upi.make_payment(amount);
    }
};

// Inheritance Adapter
class UPIAdaterInheritence: public AdapterPayment,public UpiPaymet{
    public:
    void pay(int amount){

        make_payment(amount);

    }
};
int main(){

    cout<<"Composition Adater"<<endl;
    AdapterPayment* adapter= new UPIAdaterComposition(UpiPaymet());
    adapter->pay(1000);

   
    cout<<"Inheritence Adater"<<endl;

    AdapterPayment* adapter1 = new UPIAdaterInheritence();
    adapter1->pay(200);


}