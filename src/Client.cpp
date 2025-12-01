#include "Client.h"
#include "BankCard.h"
#include "Datetime.h"
#include <algorithm>
#include <stdexcept>
#include <vector>

using namespace std;

Client::Client(int id, string name, string last_name, string email, long phone_number,
               string password, Datetime birthdate)
    : User(id, name, last_name, email, phone_number, password, birthdate, User::CLIENT),
      selected_card(nullptr) {}

Client::~Client() {
  for (BankCard *card : bank_cards)
    delete card;

  bank_cards.clear();
}

vector<BankCard *> Client::get_bank_cards() { return this->bank_cards; }

void Client::add_card(BankCard *card) { bank_cards.push_back(card); }

void Client::remove_bank_card(int index) {
  if (index >= 0 && index < bank_cards.size()) {
    if (selected_card == bank_cards[index])
      selected_card = nullptr;
    delete bank_cards[index];
    bank_cards.erase(bank_cards.begin() + index);
  } else
    throw runtime_error("Invalid index");
}

void Client::update_bank_card(int index, BankCard *card) {
  if (card == nullptr)
    throw runtime_error("Card cannot be null");
  if (index >= 0 && index < bank_cards.size()) {
    if (selected_card == bank_cards[index])
      selected_card = card;
    delete bank_cards[index];
    bank_cards[index] = card;
  } else
    throw runtime_error("Invalid index");
}

void Client::set_selected_card(BankCard *card) {
  if (find(bank_cards.begin(), bank_cards.end(), card) != bank_cards.end())
    selected_card = card;
  else
    throw runtime_error("Card doesn't exist");
}

BankCard* Client::get_selected_card() {
    return selected_card;
}

void Client::pay() {
    if (selected_card == nullptr)
        throw runtime_error("No card is selected");
}
