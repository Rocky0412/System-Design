#include <iostream>
#include <string>

using namespace std;

// Strategy Interface
class PaymentStrategy {
public:
    virtual void pay(int amount) = 0;
    virtual ~PaymentStrategy() {}
};

// Concrete Strategy 1
class CreditCardPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Paid " << amount << " using Credit Card\n";
    }
};

// Concrete Strategy 2
class UPIPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Paid " << amount << " using UPI\n";
    }
};

// Concrete Strategy 3
class PaypalPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Paid " << amount << " using PayPal\n";
    }
};

// Context
class PaymentContext {
private:
    PaymentStrategy* strategy;

public:
    PaymentContext(PaymentStrategy* strategy) {
        this->strategy = strategy;
    }

    void setStrategy(PaymentStrategy* strategy) {
        this->strategy = strategy;
    }

    void makePayment(int amount) {
        strategy->pay(amount);
    }
};

int main() {

    CreditCardPayment creditCard;
    UPIPayment upi;
    PaypalPayment paypal;

    PaymentContext payment(&creditCard);
    payment.makePayment(1000);

    payment.setStrategy(&upi);
    payment.makePayment(500);

    payment.setStrategy(&paypal);
    payment.makePayment(400);

    return 0;
}