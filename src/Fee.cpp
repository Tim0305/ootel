#include "Fee.h"

double Fee::get_amount() { return amount; }

Datetime Fee::get_date() { return date; }

void Fee::set_amount(double amount) { this->amount = amount; }

void Fee::set_date(Datetime d) { date = d; }
