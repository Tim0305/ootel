#include "TUI.h"
#include "TUIManager.h"
#include <exception>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>
#include <thread>

using namespace std;

TUI::TUI(Ootel *ootel, User *user, TUIManager *manager) {
  if (manager == nullptr)
    throw invalid_argument("Manager must exist");

  this->ootel = ootel;
  this->user = user;
  this->manager = manager;

  // Limpiar la pantalla
  clear_screen();
}
/*
const string TUI::BANNER = R"(
    ███████       ███████    ███████████ ██████████ █████
  ███░░░░░███   ███░░░░░███ ░█░░░███░░░█░░███░░░░░█░░███
 ███     ░░███ ███     ░░███░   ░███  ░  ░███  █ ░  ░███
░███      ░███░███      ░███    ░███     ░██████    ░███
░███      ░███░███      ░███    ░███     ░███░░█    ░███
░░███     ███ ░░███     ███     ░███     ░███ ░   █ ░███      █
 ░░░███████░   ░░░███████░      █████    ██████████ ███████████
   ░░░░░░░       ░░░░░░░       ░░░░░    ░░░░░░░░░░ ░░░░░░░░░░░
)";
*/

const string TUI::BANNER = R"(
  .oooooo.                 .             oooo  
 d8P'  `Y8b              .o8             `888  
888      888  .ooooo.  .o888oo  .ooooo.   888  
888      888 d88' `88b   888   d88' `88b  888  
888      888 888   888   888   888ooo888  888  
`88b    d88' 888   888   888 . 888    .o  888  
 `Y8bood8P'  `Y8bod8P'   "888" `Y8bod8P' o888o 
)";

void TUI::clear_screen() { cout << "\033[2J\033[1;1H"; }

void TUI::print_banner() { cout << "\033[33m" << BANNER << "\033[0m" << endl; }

void TUI::sleep_for(int seconds) {
  this_thread::sleep_for(chrono::seconds(seconds));
}

Ootel *TUI::get_ootel() { return ootel; }

User *TUI::get_user() { return user; }

TUIManager *TUI::get_manager() { return manager; }

optional<User> TUI::user_form() {
  string name;
  string last_name;
  string email;
  string password;
  long phone_number;
  int year;
  int month;
  int day;

  cout << "Client signup" << endl << endl;
  cout << "Name: ";
  getline(cin, name); // Limpiar el buffer
  getline(cin, name);
  cout << "Last Name: ";
  getline(cin, last_name);
  cout << "Email: ";
  getline(cin, email);
  cout << "Password: ";
  getline(cin, password);
  cout << "Phone number: ";
  cin >> phone_number;
  cout << "=====================" << endl;
  cout << "     Birthdate" << endl;
  cout << "=====================" << endl;
  cout << "Year (xxxx): ";
  cin >> year;
  cout << "Month (1-12): ";
  cin >> month;
  cout << "Day (1-31): ";
  cin >> day;

  try {
    Datetime birthdate(year, month, day);
    User user(name, last_name, email, phone_number, password, birthdate,
              User::CLIENT);
    return user;
  } catch (const exception &e) {
    cout << endl << e.what() << endl;
  }
  return nullopt;
}

void TUI::print_incorrect_option() {
  cout << endl;
  cout << "Incorrect option... Try again" << endl;
  sleep_for(1);
  clear_screen();
}

void TUI::press_enter_continue() {
  cout << "Press ENTER to exit...";
  cin.ignore(); // Limpiar el buffer
  cin.get();
}
