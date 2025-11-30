#ifndef FEE_H
#define FEE_H

#include "Datetime.h"

class Fee {
private:
  double amount;
  Datetime date;

public:
  Fee() : amount(0.0), date() {}
  Fee(double amount, Datetime date) : amount(amount), date(date) {}
  double get_amount() const;
  Datetime get_date() const;
  void set_amount(double amount);
  void set_date(Datetime date);
};

#endif // !FEE_H
