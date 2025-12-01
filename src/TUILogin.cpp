#include "TUILogin.h"
#include "Ootel.h"
#include "TUIClient.h"
#include "User.h"
#include <iostream>

using namespace std;

void TUILogin::print() {
  int opcion;
  do {
    clear_screen();
    print_banner();
    cout << "[1] - Log in" << endl;
    cout << "[2] - Signup" << endl;
    cout << "[3] - Exit" << endl;
    cout << endl << endl << "> ";
    cin >> opcion;

    switch (opcion) {
    case 1:
      log_in();
      break;
    case 2:
      create_account();
      break;
    case 3:
      get_manager()->go_back();
      break;
    default:
      print_incorrect_option();
    }
  } while (opcion < 1 || opcion > 3);
}

void TUILogin::log_in() {
  clear_screen();
  print_banner();

  string email;
  string password;
  cout << "Email: ";
  cin >> email;
  cout << "Password: ";
  cin >> password;

  User *user = get_ootel()->log_in(email, password);

  if (user == nullptr) {
    cout << endl;
    cout << "Wrong email or password... Try again" << endl;
  } else {
    cout << endl;
    cout << "Welcome, " + user->get_name() << "!" << endl;

    switch (user->get_type()) {
    case User::ADMINISTRATOR:
      break;
    case User::CLIENT:
      get_manager()->go_to(new TUIClient(get_ootel(), user, get_manager()));
      break;
    default:
      cout << endl << "Invalid user... Try again" << endl;
    }
  }
  sleep_for(1);
}

void TUILogin::create_account() {
  clear_screen();
  print_banner();

  auto user_optional = user_form();
  if (user_optional) {
    cout << endl;
    cout << "Client created sucesfully... Login" << endl;

    // Almacenar el objeto en el heap
    get_ootel()->create_user(new User(user_optional.value()));
    clear_screen();
  }
  sleep_for(1);
}
