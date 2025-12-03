#ifndef FEE_H
#define FEE_H

#include "Datetime.h"

class Fee {
private:
  double amount;
  Datetime date;

public:
  Fee(double amount, Datetime date) : amount(amount), date(date) {}
  double get_amount();
  Datetime get_date();
  void set_amount(double amount);
  void set_date(Datetime date);
  std::string to_string();
};

#endif // !FEE_H
