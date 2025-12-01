#ifndef VISA_H
#define VISA_H

#include "BankCard.h"
#include <string>

class Visa : public BankCard {
protected:
  bool is_valid() override;

public:
  Visa(int number, std::string cardholder, int expire_date, int cvc)
      : BankCard(number, cardholder, expire_date, cvc) {}
};

#endif // !VISA_H
