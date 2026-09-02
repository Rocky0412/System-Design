#include <iostream>
#include <string>
#include <vector>

using namespace std;
class IMoneyHandaler{
    
    public:
    IMoneyHandaler* nextHandaler;
    IMoneyHandaler(){
        this->nextHandaler=nullptr;
    }
    void setNextHandler(IMoneyHandaler* next){
        this->nextHandaler=next;
    }
    virtual void dispense(int amount)=0;
};
class FiveHundred: public IMoneyHandaler{
    public:

    void dispense(int amount){
        int count= amount/500;
        if(count>0){
            amount=amount - count * 500;
            cout<< "No. 500 notes is : "<< count<<endl;
        }
        nextHandaler->dispense(amount);

    }
};
class OneHundred: public IMoneyHandaler{
    public:

    void dispense(int amount){
        int count= amount/100;
        if(count>0){
            amount=amount - count * 100;
            cout<< "No. 100 notes is : "<< count<<endl;
        }
        cout<<"Remaining amount : "<<amount<<endl;
      
    }
};

int main(){
    IMoneyHandaler* five= new FiveHundred();
    IMoneyHandaler* one= new OneHundred();
    five->setNextHandler(one);
    five->dispense(5420);

}

