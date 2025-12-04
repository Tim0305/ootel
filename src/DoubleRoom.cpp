#include "DoubleRoom.h"
#include <sstream>

using namespace std;

int DoubleRoom::DISCOUNT = 0;
double DoubleRoom::PRICE = 1200;

// Getter
int DoubleRoom::get_discount() { return DISCOUNT; }

double DoubleRoom::get_price() { return PRICE; }

double DoubleRoom::get_final_price() {
  return PRICE * ((100 - DISCOUNT) / 100);
}

// Setter
void DoubleRoom::set_discount(int discount) { DISCOUNT = discount; }

void DoubleRoom::set_price(double price) { PRICE = price; }

string DoubleRoom::to_string() {
  stringstream ss;
  ss << Room::to_string();
  ss << "Price: $" << PRICE << endl;
  ss << "Discount: " << DISCOUNT << "%" << endl;
  ss << "Final Price: $" << get_final_price() << endl;
  return ss.str();
}
