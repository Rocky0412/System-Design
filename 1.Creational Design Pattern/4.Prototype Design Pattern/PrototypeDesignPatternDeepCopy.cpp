#include <iostream>
#include <mutex>

using namespace std;

class prototype{
    public:
    virtual prototype* clone()=0;
};
class Person : public prototype{
    string name;
    int age;
    public:
    Person(string name, int age){
        this->name=name;
        this->age=age;
    };
    Person* clone(){

        // swallow copy
        return this;
    }
    void print(){
        cout<<this->name<<" "<<this->age<<endl;
    }

};

int main(){
    Person* p = new Person("Rocky",26);
    Person* p1 = p->clone();
    p->print();
    p1->print();
    if(p==p1){
        cout<<"Both Equal"<<endl;
    }
}