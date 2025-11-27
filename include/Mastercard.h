#ifndef MASTERCARD_H
#define MASTERCARD_H

#include "BankCard.h"
#include <string>

class Mastercard : public BankCard {
private:
  static bool is_valid(int number, int expire_date);
public:
  Mastercard(int number, std::string cardholder, int expire_date, int cvc);
};

#endif // !MASTERCARD_H
