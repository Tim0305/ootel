#include "TUILogin.h"
#include "User.h"
#include <iostream>

using namespace std;

void TUILogin::print() {
  int opcion;
  do {
    print_menu();
    cin >> opcion;

    switch (opcion) {
    case 1:
      login();
      break;
    case 2:
      signup();
      break;
    case 3:
      get_manager()->go_back();
      break;
    default:
      cout << endl;
      cout << "Incorrect option... Try again" << endl;
      sleep_for(1);
      clear_screen();
    }
  } while (opcion < 1 || opcion > 3);
}

void TUILogin::login() {
  clear_screen();
  print_banner();

  string email;
  string password;
  cout << "Email: ";
  cin >> email;
  cout << "Password: ";
  cin >> password;

  User *user = get_ootel()->login(email, password);

  if (user == nullptr) {
    cout << endl;
    cout << "Wrong email or password... Try again" << endl;
  } else {
    cout << endl;
    cout << "Welcome, " + user->get_name() << "!" << endl;
    sleep_for(1);
  }
}

void TUILogin::signup() {
  clear_screen();
  print_banner();
  
  auto user_optional = user_form();
  if (user_optional)
  {
    cout << endl;
    cout << "Client created sucesfully... Login" << endl;
    
    // Almacenar el objeto en el heap
    get_ootel()->create_user(new User(user_optional.value()));
    sleep_for(1);
    clear_screen();
  }
}

void TUILogin::print_menu() {
    clear_screen();
    print_banner();
    cout << "[1] - Login" << endl;
    cout << "[2] - Signup" << endl;
    cout << "[3] - Exit" << endl;
    cout << endl << endl << "> ";
}
