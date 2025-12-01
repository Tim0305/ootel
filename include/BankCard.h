#ifndef BANKCARD_H
#define BANKCARD_H

#include <string>

class BankCard {
private:
  int number;
  std::string cardholder;
  int expiration_year;
  int cvc;

protected:
  virtual bool is_valid() = 0;

public:
  BankCard();
  BankCard(int number, std::string cardholder, int expiration_year, int cvc)
      : number(number), cardholder(cardholder),
        expiration_year(expiration_year), cvc(cvc) {}

  // Getters
  int get_number();
  int get_expiration_year();
  int get_cvc();
  std::string get_cardholder();

  // Setters
  void set_number(int number);
  void set_expiration_year(int expiration_year);
  void set_cvc(int cvc);
  void set_cardholder(std::string cardholder);

  std::string to_string();
};

#endif // !BANKCARD_H
