#include "StandardRoom.h"
#include <sstream>

using namespace std;

int StandardRoom::DISCOUNT = 0;
double StandardRoom::PRICE = 600;

// Getter
int StandardRoom::get_discount() { return DISCOUNT; }

double StandardRoom::get_price() { return PRICE; }

double StandardRoom::get_final_price() {
  return PRICE * ((100 - DISCOUNT) / 100.0);
}

// Setter
void StandardRoom::set_discount(int discount) { DISCOUNT = discount; }

void StandardRoom::set_price(double price) { PRICE = price; }

string StandardRoom::to_string() {
  stringstream ss;
  ss << Room::to_string();
  ss << "Price: $" << PRICE << endl;
  ss << "Discount: " << DISCOUNT << "%" << endl;
  ss << "Final Price: $" << get_final_price() << endl;
  return ss.str();
}
