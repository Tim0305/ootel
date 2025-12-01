#ifndef MASTERCARD_H
#define MASTERCARD_H

#include "BankCard.h"
#include <string>

class Mastercard : public BankCard {
protected:
  bool is_valid() override;
public:
  Mastercard(int number, std::string cardholder, int expire_date, int cvc): BankCard(number, cardholder, expire_date, cvc) {}
};

#endif // !MASTERCARD_H
