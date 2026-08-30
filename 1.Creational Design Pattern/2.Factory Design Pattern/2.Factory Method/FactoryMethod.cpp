
#include <iostream>
#include <string>

using namespace std;
/*
Instead of modifying one central factory whenever a new product is added,
create a new Concrete Creator that overrides the Factory Method.

The main disadvantage of Factory Method is that it increases the number of classes and overall complexity. 
Each new product may require a new concrete creator, leading to class explosion. 
It can also be over-engineering when object creation is simple.
*/

// =====================================================
// Product
// =====================================================

class Burger {
public:
    virtual void make() = 0;
    virtual ~Burger() = default;
};


// =====================================================
// Concrete Products
// =====================================================

class SimpleBurger : public Burger {
public:
    void make() override {
        cout << "Simple Burger created" << endl;
    }
};

class StandardBurger : public Burger {
public:
    void make() override {
        cout << "Standard Burger created" << endl;
    }
};

class PremiumBurger : public Burger {
public:
    void make() override {
        cout << "Premium Burger created" << endl;
    }
};


// =====================================================
// Creator
// =====================================================

class BurgerFactory {
public:

    // Factory Method
    virtual Burger* createBurger() = 0;

    // Common business/workflow logic
    void orderBurger() {

        Burger* burger = createBurger();

        burger->make();

        delete burger;
    }

    virtual ~BurgerFactory() = default;
};


// =====================================================
// Concrete Creators
// =====================================================

class SimpleBurgerFactory : public BurgerFactory {
public:

    Burger* createBurger() override {
        return new SimpleBurger();
    }
};


class StandardBurgerFactory : public BurgerFactory {
public:

    Burger* createBurger() override {
        return new StandardBurger();
    }
};


class PremiumBurgerFactory : public BurgerFactory {
public:

    Burger* createBurger() override {
        return new PremiumBurger();
    }
};


// =====================================================
// Client
// =====================================================

int main() {

    BurgerFactory* simpleFactory =
        new SimpleBurgerFactory();

    BurgerFactory* standardFactory =
        new StandardBurgerFactory();

    BurgerFactory* premiumFactory =
        new PremiumBurgerFactory();


    simpleFactory->orderBurger();
    standardFactory->orderBurger();
    premiumFactory->orderBurger();


    delete simpleFactory;
    delete standardFactory;
    delete premiumFactory;

    return 0;
}

