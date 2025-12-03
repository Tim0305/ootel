#include "Fee.h"
#include <sstream>

using namespace std;

double Fee::get_amount() { return amount; }

Datetime Fee::get_date() { return date; }

void Fee::set_amount(double amount) { this->amount = amount; }

void Fee::set_date(Datetime d) { date = d; }

string Fee::to_string() {
  stringstream ss;
  ss << "Amount: $" << amount << endl;
  ss << "Date: " << date.to_string() << endl;

  return ss.str();
}
