#ifndef VISA_H
#define VISA_H

#include "BankCard.h"
#include <string>

class Visa : public BankCard {
protected:
  bool is_valid(std::string number) override;

public:
  Visa(std::string number, std::string cardholder, int expiration_year, int cvc);
};

#endif // !VISA_H
