#include "Fee.h"

double Fee::get_amount() const { return amount; }
Datetime Fee::get_date() const { return date; }
void Fee::set_amount(double a) { amount = a; }
void Fee::set_date(Datetime d) { date = d; }