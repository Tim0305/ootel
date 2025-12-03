#ifndef BANKCARD_H
#define BANKCARD_H

#include <string>

class BankCard {
private:
  std::string number;
  std::string cardholder;
  int expiration_year;
  int cvc;
  int type;
  static bool is_number_digits(const std::string &number);

protected:
  virtual bool is_valid(std::string number) = 0;

public:
  static const int VISA = 0;
  static const int MASTERCARD = 1;

  BankCard(std::string cardholder, int expiration_year, int cvc, int type);
  virtual ~BankCard() = default;

  // Getters
  std::string get_number() const;
  int get_expiration_year() const;
  int get_cvc() const;
  std::string get_cardholder() const;
  int get_type() const;

  // Setters
  void set_number(std::string number);
  void set_expiration_year(int expiration_year);
  void set_cvc(int cvc);
  void set_cardholder(std::string cardholder);
  void set_type(int type);

  std::string to_string();
};

#endif // !BANKCARD_H
