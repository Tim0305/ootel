#include "TUIAdministrator.h"
#include "Administrator.h"
#include <iostream>
#include <stdexcept>

using namespace std;

TUIAdministrator::TUIAdministrator(Ootel *ootel, User *user,
                                   TUIManager *manager)
    : TUI(ootel, user, manager) {
  if (user == nullptr)
    throw invalid_argument("User must exist");
}

void TUIAdministrator::run() {
  int opcion;
  do {
    clear_screen();
    print_banner();
    cout << "Administrator" << endl << endl;
    cout << "[1] - Users" << endl;
    cout << "[2] - Rooms" << endl;
    cout << "[3] - Reservations" << endl;
    cout << "[4] - Sign out" << endl;
    cout << endl << endl;
    cout << "> ";
    cin >> opcion;

    if (opcion < 1 || opcion > 4)
      print_incorrect_option();
  } while (opcion < 1 || opcion > 4);

  switch (opcion) {
  case 1:
    users();
    break;
  case 2:
    rooms();
    break;
  case 3:
    reservations();
    break;
  case 4:
    sign_out();
    break;
  }
}

void TUIAdministrator::users() {
  int opcion;
  do {
    clear_screen();
    print_banner();

    cout << "Users" << endl << endl;
    cout << "[1] - Create Administrator" << endl;
    cout << "[2] - Update Administrator" << endl;
    cout << "[3] - Delete Administrator" << endl;
    cout << "[4] - See Administrators" << endl;
    cout << "[5] - Go Back" << endl;
    cout << endl;
    cout << "> ";
    cin >> opcion;

    if (opcion < 1 || opcion > 5)
      print_incorrect_option();
  } while (opcion < 1 || opcion > 5);

  switch (opcion) {
  case 1:
    create_administrator();
    // Regresar al menu de users
    users();
    break;
  case 2:
    update_administrator();
    // Regresar al menu de users
    users();
    break;
  case 3:
    delete_administrator();
    // Regresar al menu de users
    users();
    break;
  case 4:
    see_administrators();
    // Regresar al menu de users
    users();
    break;
  case 5:
    break;
  }
}

void TUIAdministrator::create_administrator() {
  clear_screen();
  print_banner();
  cout << "Create Administrator" << endl << endl;
  auto optional_user = user_form();
  if (optional_user) {
    get_ootel()->create_user(new Administrator(optional_user.value()));
    cout << endl << "Administrator created successfully..." << endl;
  }
  sleep_for(MESSAGE_WAIT_TIME_SECONDS);
}

void TUIAdministrator::update_administrator() {
  clear_screen();
  print_banner();
  cout << "Update Administrator" << endl << endl;
  if (get_ootel()->get_users().empty())
    cout << "No administrators were found..." << endl;
  else {
    print_administrators();

    int id;
    cout << "(-1 to return)" << endl;
    cout << "ID > ";
    cin >> id;

    if (id == -1)
      return;

    if (id == 0) {
      cout << endl << "Admin cannot be updated..." << endl;
    } else {
      clear_screen();
      print_banner();
      cout << "Update Administrator" << endl << endl;
      auto optional_user = user_form();

      if (optional_user) {
        string curr_password;
        cout << endl;
        cout << "Current password: ";
        cin.ignore(); // Limpiar el buffer
        getline(cin, curr_password);

        User *u = get_ootel()->find_user(id);
        User newUser = optional_user.value();
        if (u == nullptr || u->get_type() != User::ADMINISTRATOR)
          cout << endl
               << "Administrator with id " << id << " was not found" << endl;
        else {
          try {
            // Primero actualizar el password
            u->update_password(curr_password, newUser.get_password());
            // Actualizar el administrador
            u->update_profile(newUser.get_name(), newUser.get_last_name(),
                              newUser.get_email(), newUser.get_phone_number(),
                              newUser.get_birthdate());
            cout << endl << "Administrator updated successfully..." << endl;
          } catch (const exception &e) {
            cout << endl << e.what() << endl;
          }
        }
      }
    }
  }
  sleep_for(MESSAGE_WAIT_TIME_SECONDS);
}

void TUIAdministrator::delete_administrator() {
  clear_screen();
  print_banner();
  cout << "Delete Administrator" << endl << endl;
  if (get_ootel()->get_users().empty())
    cout << "No administrators were found..." << endl;
  else {
    print_administrators();

    int id;
    cout << "(-1 to return)" << endl;
    cout << "ID > ";
    cin >> id;

    if (id == -1)
      return;

    if (id == get_user()->get_id())
      cout << endl << "Administrator cannot delete himself..." << endl;
    else {
      User *u = get_ootel()->find_user(id);
      if (u == nullptr || u->get_type() != User::ADMINISTRATOR)
        cout << endl
             << "Administrator with id " << id << " was not found" << endl;
      else {
        try {
          get_ootel()->delete_user(id);
          cout << endl << "Administrator deleted successfully..." << endl;
        } catch (const exception &e) {
          cout << endl << e.what() << endl;
        }
      }
    }
  }
  sleep_for(MESSAGE_WAIT_TIME_SECONDS);
}

void TUIAdministrator::see_administrators() {
  clear_screen();
  print_banner();
  cout << "Administrators" << endl << endl;

  if (get_ootel()->get_users().empty())
    cout << "No administrators were found..." << endl;
  else
    print_administrators();
  press_enter_continue();
}

void TUIAdministrator::print_administrators() {
  vector<User *> users = get_ootel()->get_users();

  for (auto u : users) {
    if (u->get_type() == User::ADMINISTRATOR) {
      cout << "======================================" << endl;
      cout << u->to_string();
      cout << "======================================" << endl;
      cout << endl;
    }
  }
}

void TUIAdministrator::rooms() {}

void TUIAdministrator::reservations() {}
