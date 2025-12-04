#include "SuiteRoom.h"
#include <sstream>

using namespace std;

int SuiteRoom::DISCOUNT = 0;
double SuiteRoom::PRICE = 3200;

// Getter
int SuiteRoom::get_discount() { return DISCOUNT; }

double SuiteRoom::get_price() { return PRICE; }

double SuiteRoom::get_final_price() { return PRICE * ((100 - DISCOUNT) / 100); }

// Setter
void SuiteRoom::set_discount(int discount) { DISCOUNT = discount; }

void SuiteRoom::set_price(double price) { PRICE = price; }

string SuiteRoom::to_string() {
  stringstream ss;
  ss << Room::to_string();
  ss << "Price: $" << PRICE << endl;
  ss << "Discount: " << DISCOUNT << "%" << endl;
  ss << "Final Price: $" << get_final_price() << endl;
  return ss.str();
}
