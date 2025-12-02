#include "Visa.h"
#include "BankCard.h"
#include <ctime>

using namespace std;

Visa::Visa(string number, string cardholder, int expire_year, int cvc): BankCard(cardholder, expire_year, cvc) {
  set_number(number);
}

bool Visa::is_valid(string number) {
    // 1. Debe iniciar con '4'
    if (number.empty() || number[0] != '4') return false;

    // 2. Longitud válida para Visa: 13, 16 o 19
    if (number.size() != 13 && number.size() != 16 && number.size() != 19)
        return false;

    // 3. Validar con algoritmo de Luhn
    int suma = 0;
    bool doble = false;

    // Recorrer de derecha a izquierda
    for (int i = number.size() - 1; i >= 0; i--) {
        int dig = number[i] - '0';

        if (doble) {
            dig *= 2;
            if (dig > 9) dig -= 9;
        }

        suma += dig;
        doble = !doble;
    }

    return (suma % 10 == 0);
}
