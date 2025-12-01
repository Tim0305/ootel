#include "BankCard.h"
#include <sstream>

using namespace std;

string BankCard::to_string() {
  stringstream ss;
  ss << "Cardholder: " << get_cardholder() << endl;
  ss << "Number: " << get_number() << endl;
  ss << "Expiration year: " << get_expiration_year() << endl;
  ss << "CVC: " << get_cvc() << endl;
  return ss.str();
}
