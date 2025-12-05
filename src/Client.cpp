#include "Client.h"
#include "BankCard.h"
#include "Datetime.h"
#include "User.h"
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

Client::Client(int id, string name, string last_name, string email,
               long phone_number, string password, Datetime birthdate)
    : User(id, name, last_name, email, phone_number, password, birthdate,
           User::CLIENT),
      selected_card(nullptr) {}

Client::Client(const User &user) : User(user), selected_card(nullptr) {
  set_type(User::CLIENT);
}

Client::~Client() {
  for (BankCard *card : bank_cards)
    delete card;

  bank_cards.clear();
}

vector<BankCard *> Client::get_bank_cards() { return this->bank_cards; }

void Client::add_card(BankCard *card) {
  if (card->get_expiration_year() < Datetime::now().get_year())
    throw invalid_argument("Invalid expiration year...");

  if (card->get_cardholder().empty())
    throw invalid_argument("Invalid cardholder...");

  bank_cards.push_back(card);
}

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
  if (card->get_expiration_year() < Datetime::now().get_year())
    throw invalid_argument("Invalid expiration year...");
  if (card->get_cardholder().empty())
    throw invalid_argument("Invalid cardholder...");
  if (index >= 0 && index < bank_cards.size()) {
    if (selected_card == bank_cards[index])
      selected_card = card;
    delete bank_cards[index];
    bank_cards[index] = card;
  } else
    throw runtime_error("Invalid index");
}

void Client::set_selected_card(int index) {
  if (index < 0 || index >= bank_cards.size())
    throw runtime_error("Index error. Card doesn't exist");
  else
    selected_card = bank_cards[index];
}

BankCard *Client::get_bank_card(int index) {
  if (index >= 0 && index < bank_cards.size())
    return bank_cards[index];
  else
    throw invalid_argument("Invalid index");
}

BankCard *Client::get_selected_card() { return selected_card; }

void Client::pay() {
  if (selected_card == nullptr)
    throw runtime_error("No card is selected");
}

void Client::refund() {
  if (bank_cards.empty())
    throw runtime_error("No card is added");
}

string Client::to_string() {
  stringstream ss;
  ss << User::to_string() << endl;

  ss << endl;
  ss << "         ----- Selected Card -----" << endl;
  if (selected_card == nullptr)
    ss << "None" << endl;
  else
    ss << selected_card->to_string() << endl;

  ss << endl;
  ss << "          ----- Bank Cards -----" << endl;
  if (bank_cards.empty())
    ss << "Empty" << endl;
  else
    for (int i = 0; i < bank_cards.size(); i++) {
      ss << "[" << i + 1 << "]" << endl;
      ss << bank_cards[i]->to_string() << endl;
    }

  return ss.str();
}
