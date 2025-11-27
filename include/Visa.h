#ifndef VISA_H
#define VISA_H

#include "BankCard.h"
#include <string>

class Visa : public BankCard {
private:
  static bool is_valid(int number, int expire_date);
public:
  Visa(int number, std::string cardholder, int expire_date, int cvc);
};

#endif // !VISA_H
