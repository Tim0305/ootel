#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>
#include "BankCard.h"
using namespace std;

class Client{
private:
  vector<BankCard> bank_cards;
  BankCard current_card;
public:
  vector<BankCard> get_bank_cards();
  void add_card(const BankCard& card);
  void remove_bank_card(const BankCard& card);
  void update_bank_card(const BankCard& prev_card, const BankCard& new_card);
  bool pay();
};

#endif // !CLIENT_H
