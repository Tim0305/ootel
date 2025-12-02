#include "BankCard.h"
#include <cctype>
#include <sstream>
#include <stdexcept>

using namespace std;

BankCard::BankCard(std::string cardholder, int expiration_year, int cvc) {
  set_cardholder(cardholder);
  set_expiration_year(expiration_year);
  set_cvc(cvc);
}

bool BankCard::is_number_digits(const string &number) {
  for (char c : number) {
    if (!isdigit(c))
      return false;
  }
  return true;
}

string BankCard::get_number() const { return number; }

int BankCard::get_expiration_year() const { return expiration_year; }

int BankCard::get_cvc() const { return cvc; }

string BankCard::get_cardholder() const { return cardholder; }

void BankCard::set_number(string number) {
  if (BankCard::is_number_digits(number))
    if (is_valid(number))
      BankCard::set_number(number);
    else
      throw invalid_argument("Invalid card number");
  else
    throw invalid_argument("Number must cointain only digits");
}

void BankCard::set_expiration_year(int expiration_year) {
  this->expiration_year = expiration_year;
}

void BankCard::set_cvc(int cvc) {
  if (cvc < 0 || cvc > 999)
    throw invalid_argument("Invalid CVC");

  this->cvc = cvc;
}

void BankCard::set_cardholder(string cardholder) {
  this->cardholder = cardholder;
}

string BankCard::to_string() {
  stringstream ss;
  ss << "Cardholder: " << get_cardholder() << endl;
  ss << "Number: " << get_number() << endl;
  ss << "Expiration year: " << get_expiration_year() << endl;
  ss << "CVC: " << get_cvc() << endl;
  return ss.str();
}
