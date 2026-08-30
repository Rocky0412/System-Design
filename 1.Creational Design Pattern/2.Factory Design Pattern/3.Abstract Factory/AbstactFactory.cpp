/*
Factory Method creates one type of product.
Abstract Factory creates a family of related products.
*/

/*
 American Restaurant
    ├── American Burger
    └── American Pizza

Italian Restaurant
    ├── Italian Burger
    └── Italian Pizza

*/
#include <iostream>

using namespace std;


// =====================================================
// Abstract Product 1 - Burger
// =====================================================

class Burger {
public:
    virtual void make() = 0;
    virtual ~Burger() = default;
};


// =====================================================
// Abstract Product 2 - Pizza
// =====================================================

class Pizza {
public:
    virtual void make() = 0;
    virtual ~Pizza() = default;
};


// =====================================================
// Concrete Product - American Burger
// =====================================================

class AmericanBurger : public Burger {
public:
    void make() override {
        cout << "American Burger created" << endl;
    }
};


// =====================================================
// Concrete Product - Italian Burger
// =====================================================

class ItalianBurger : public Burger {
public:
    void make() override {
        cout << "Italian Burger created" << endl;
    }
};


// =====================================================
// Concrete Product - American Pizza
// =====================================================

class AmericanPizza : public Pizza {
public:
    void make() override {
        cout << "American Pizza created" << endl;
    }
};


// =====================================================
// Concrete Product - Italian Pizza
// =====================================================

class ItalianPizza : public Pizza {
public:
    void make() override {
        cout << "Italian Pizza created" << endl;
    }
};


// =====================================================
// Abstract Factory
// =====================================================

class RestaurantFactory {
public:

    virtual Burger* createBurger() = 0;

    virtual Pizza* createPizza() = 0;

    virtual ~RestaurantFactory() = default;
};


// =====================================================
// Concrete Factory - American
// =====================================================

class AmericanRestaurantFactory : public RestaurantFactory {
public:

    Burger* createBurger() override {
        return new AmericanBurger();
    }

    Pizza* createPizza() override {
        return new AmericanPizza();
    }
};


// =====================================================
// Concrete Factory - Italian
// =====================================================

class ItalianRestaurantFactory : public RestaurantFactory {
public:

    Burger* createBurger() override {
        return new ItalianBurger();
    }

    Pizza* createPizza() override {
        return new ItalianPizza();
    }
};


// =====================================================
// Client
// =====================================================

class Restaurant {
private:

    Burger* burger;
    Pizza* pizza;

public:

    Restaurant(RestaurantFactory* factory) {

        burger = factory->createBurger();

        pizza = factory->createPizza();
    }

    void order() {

        burger->make();

        pizza->make();
    }

    ~Restaurant() {

        delete burger;
        delete pizza;
    }
};


// =====================================================
// Main
// =====================================================

int main() {

    // Choose American family
    RestaurantFactory* factory =
        new AmericanRestaurantFactory();

    Restaurant restaurant(factory);

    restaurant.order();

    delete factory;

    return 0;
}

