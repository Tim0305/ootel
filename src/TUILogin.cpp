#include "TUILogin.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void TUILogin::print() {
  cout << BANNER << endl;

  string email;
  string password;
  cout << "Email: ";
  cin >> email;
  cout << "Password: ";
  cin >> password;

  User *user = get_ootel()->login(email, password);

  if (user == nullptr)
    get_manager()->go_back();
  else {
    cout << endl;
    cout << "Welcome, " + user->get_name() << "!" << endl;
    this_thread::sleep_for(chrono::seconds(1));
  }
}
