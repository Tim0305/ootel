#ifndef CLIENT_H
#define CLIENT_H

#include "BankCard.h"
#include "Datetime.h"
#include "User.h"
#include <string>
#include <vector>

class Client : public User {
private:
  std::vector<BankCard *> bank_cards;
  BankCard *selected_card;

public:
  Client(int id, std::string name, std::string last_name, std::string email, long phone_number,
         std::string password, Datetime birthdate);
  ~Client(); // Liberar la memoria de los punteros

  std::vector<BankCard *> get_bank_cards();
  void add_card(BankCard *card);
  void remove_bank_card(int index);
  void update_bank_card(int index, BankCard *new_card);
  void set_selected_card(BankCard *card);
  BankCard *get_selected_card();
  void pay();
  std::string to_string() override;
};

#endif // !CLIENT_H
