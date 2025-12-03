#ifndef MASTERCARD_H
#define MASTERCARD_H

#include "BankCard.h"
#include <string>

class Mastercard : public BankCard {
protected:
  bool is_valid(std::string number) override;

public:
  Mastercard(std::string number, std::string cardholder, int expiration_year,
             int cvc);
};

#endif // !MASTERCARD_H
