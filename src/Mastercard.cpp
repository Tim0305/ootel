#include "Mastercard.h"
#include "BankCard.h"
#include <ctime>

using namespace std;

Mastercard::Mastercard(string number, string cardholder,
                       int expire_year, int cvc)
    : BankCard(cardholder, expire_year, cvc) {
  set_number(number);
}

bool Mastercard::is_valid(string number) {
  // 1. Longitud exacta de MasterCard
  if (number.size() != 16)
    return false;

  // 2. Prefijos válidos
  int first2 = stoi(number.substr(0, 2));
  int first4 = stoi(number.substr(0, 4));

  bool rango1 = (first2 >= 51 && first2 <= 55);     // 51–55
  bool rango2 = (first4 >= 2221 && first4 <= 2720); // 2221–2720

  if (!rango1 && !rango2)
    return false;

  // 3. Algoritmo de Luhn
  int suma = 0;
  bool doble = false;

  for (int i = number.size() - 1; i >= 0; i--) {
    int dig = number[i] - '0';

    if (doble) {
      dig *= 2;
      if (dig > 9)
        dig -= 9;
    }

    suma += dig;
    doble = !doble;
  }

  return (suma % 10 == 0);
}
