#include "Visa.h"
#include <ctime>

bool Visa::is_valid() {
  int digits = 0;
  long long temp = number;
  while (temp > 0) {
    temp /= 10;
    digits++;
  }
  if (digits != 16)
    return false;
  std::string numStr = std::to_string(number);
  if (numStr[0] != '4')
    return false;
  time_t t = time(nullptr);
  tm now;
  localtime_s(&now, &t);
  int currentDate = (now.tm_year + 1900) * 100 + (now.tm_mon + 1);

  if (expire_date <= currentDate)
    return false;

  return true;
}

bool Visa::isValid() const {
  return is_valid(number, expire_date) && (cvc >= 100 && cvc <= 999);
}
