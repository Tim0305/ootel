#include "TUI.h"
#include "TUIManager.h"
#include <exception>
#include <iostream>
#include <optional>
#include <string>
#include <thread>

using namespace std;

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

void TUI::clear_screen() { cout << "\033[2J\033[1;1H"; }

void TUI::print_banner() { cout << BANNER << endl; }

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
