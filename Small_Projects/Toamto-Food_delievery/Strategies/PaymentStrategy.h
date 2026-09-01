#ifndef CREDIT_CARD_PAYMENT_STRATEGY_H
#define CREDIT_CARD_PAYMENT_STRATEGY_H

#include <iostream>
#include "PaymentStrategy.h"
using namespace std;

class CreditCardPaymentStrategy : public PaymentStrategy {
private:
    string cardNumber;
public:
    CreditCardPaymentStrategy(const string& cardNumber) {
        this->cardNumber = cardNumber;
    }

    void pay(double amount) override {
        cout << "Paid Rs." << amount << " using Credit Card ending in "
             << cardNumber.substr(cardNumber.size() > 4 ? cardNumber.size() - 4 : 0) << endl;
    }
};

#endif // CREDIT_CARD_PAYMENT_STRATEGY_H
