#include "TUIAdministrator.h"
#include "Administrator.h"
#include "DoubleRoom.h"
#include "ReservationsHistory.h"
#include "StandardRoom.h"
#include "SuiteRoom.h"
#include <exception>
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
    cout << "[1] - Create an administrator" << endl;
    cout << "[2] - Update an administrator" << endl;
    cout << "[3] - Delete an administrator" << endl;
    cout << "[4] - See administrators" << endl;
    cout << "[5] - Go back" << endl;
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
  if (get_ootel()->get_users().empty()) {
    cout << "No administrators were found..." << endl;
    press_enter_continue();
  } else {
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
               << "Administrator with id " << id << " was not found..." << endl;
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
    sleep_for(MESSAGE_WAIT_TIME_SECONDS);
  }
}

void TUIAdministrator::delete_administrator() {
  clear_screen();
  print_banner();
  cout << "Delete Administrator" << endl << endl;
  if (get_ootel()->get_users().empty()) {
    cout << "No administrators were found..." << endl;
    press_enter_continue();
  } else {
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
             << "Administrator with id " << id << " was not found..." << endl;
      else {
        try {
          get_ootel()->delete_user(id);
          cout << endl << "Administrator deleted successfully..." << endl;
        } catch (const exception &e) {
          cout << endl << e.what() << endl;
        }
      }
    }
    sleep_for(MESSAGE_WAIT_TIME_SECONDS);
  }
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

void TUIAdministrator::rooms() {
  int opcion;
  do {
    clear_screen();
    print_banner();

    cout << "Rooms" << endl << endl;
    cout << "[1] - Create a room" << endl;
    cout << "[2] - Update a room" << endl;
    cout << "[3] - Delete a room" << endl;
    cout << "[4] - See rooms" << endl;
    cout << "[5] - Update prices" << endl;
    cout << "[6] - Update discounts" << endl;
    cout << "[7] - See rooms info" << endl;
    cout << "[8] - Go back" << endl;
    cout << endl;
    cout << "> ";
    cin >> opcion;

    if (opcion < 1 || opcion > 8)
      print_incorrect_option();
  } while (opcion < 1 || opcion > 8);

  switch (opcion) {
  case 1:
    create_room();
    // Regresar al menu de rooms
    rooms();
    break;
  case 2:
    update_room();
    // Regresar al menu de rooms
    rooms();
    break;
  case 3:
    delete_room();
    // Regresar al menu de rooms
    rooms();
    break;
  case 4:
    see_rooms();
    // Regresar al menu de rooms
    rooms();
    break;
  case 5:
    update_prices();
    // Regresar al menu de rooms
    rooms();
    break;
  case 6:
    update_discounts();
    // Regresar al menu de rooms
    rooms();
    break;
  case 7:
    see_rooms_info();
    // Regresar al menu de rooms
    rooms();
    break;
  case 8:
    break;
  }
}

void TUIAdministrator::create_room() {
  int opcion;
  do {
    clear_screen();
    print_banner();

    cout << "Create room" << endl << endl;

    cout << "[1] - Standard" << endl;
    cout << "[2] - Double" << endl;
    cout << "[3] - Suite" << endl;
    cout << "[4] - Go back" << endl;
    cout << endl;
    cout << "> ";
    cin >> opcion;

    if (opcion < 1 || opcion > 4)
      print_incorrect_option();
  } while (opcion < 1 || opcion > 4);

  clear_screen();
  print_banner();
  cout << "Create room" << endl << endl;

  int number;
  cout << "Number: ";
  cin >> number;

  try {
    switch (opcion) {
    case 1:
      get_ootel()->create_room(new StandardRoom(number));
      break;
    case 2:
      get_ootel()->create_room(new DoubleRoom(number));
      break;
    case 3:
      get_ootel()->create_room(new SuiteRoom(number));
      break;
    }

    cout << endl << "Room created successfully..." << endl;
  } catch (const exception &e) {
    cout << endl << e.what() << endl;
  }

  sleep_for(MESSAGE_WAIT_TIME_SECONDS);
}

void TUIAdministrator::update_room() {
  clear_screen();
  print_banner();

  cout << "Update room" << endl << endl;

  if (get_ootel()->get_rooms().empty()) {
    cout << "No rooms were found..." << endl;
    press_enter_continue();
  } else {
    print_rooms();

    int number;
    cout << "(-1 to return)" << endl;
    cout << "Number > ";
    cin >> number;

    Room *r = get_ootel()->find_room(number);

    if (r == nullptr)
      cout << endl
           << "Room with number " << number << " was not found..." << endl;
    else {
      clear_screen();
      print_banner();

      int people;
      int beds;

      cout << "Update room" << endl << endl;
      cout << "People: ";
      cin >> people;
      cout << "Beds: ";
      cin >> beds;

      try {
        switch (r->get_type()) {
        case Room::STANDARD: {
          StandardRoom new_room(number);
          new_room.update(*r);
          new_room.set_number_people(people);
          new_room.set_number_beds(beds);
          get_ootel()->update_room(number, new_room);
          break;
        }
        case Room::DOUBLE: {
          DoubleRoom new_room(number);
          new_room.update(*r);
          new_room.set_number_people(people);
          new_room.set_number_beds(beds);
          get_ootel()->update_room(number, new_room);
          break;
        }
        case Room::SUITE: {
          SuiteRoom new_room(number);
          new_room.update(*r);
          new_room.set_number_people(people);
          new_room.set_number_beds(beds);
          get_ootel()->update_room(number, new_room);
          break;
        }
        default:
          throw runtime_error("Error. Room type doesn't exist...");
        }
        cout << endl << "Room updated successfully..." << endl;
      } catch (const exception &e) {
        cout << endl << e.what() << endl;
      }
    }
    sleep_for(MESSAGE_WAIT_TIME_SECONDS);
  }
}

void TUIAdministrator::delete_room() {
  clear_screen();
  print_banner();

  cout << "Update room" << endl << endl;

  if (get_ootel()->get_rooms().empty()) {
    cout << "No rooms were found..." << endl;
    press_enter_continue();
  } else {
    print_rooms();

    int number;
    cout << "(-1 to return)" << endl;
    cout << "Number > ";
    cin >> number;

    try {
      get_ootel()->delete_room(number);
      cout << endl << "Room deleted successfully..." << endl;
    } catch (const exception &e) {
      cout << endl << e.what() << endl;
    }
    sleep_for(MESSAGE_WAIT_TIME_SECONDS);
  }
}

void TUIAdministrator::see_rooms() {
  clear_screen();
  print_banner();

  cout << "Rooms" << endl << endl;

  if (get_ootel()->get_rooms().empty())
    cout << "No rooms were found..." << endl;
  else
    print_rooms();

  press_enter_continue();
}

void TUIAdministrator::see_rooms_info() {
  clear_screen();
  print_banner();

  cout << "Rooms info" << endl << endl;
  cout << "=======================================" << endl;
  cout << "              Standard Room" << endl;
  cout << "Price: $" << StandardRoom::get_price() << endl;
  cout << "Discount: " << StandardRoom::get_discount() << "%" << endl;
  cout << "Final price: $" << StandardRoom::get_final_price() << endl;
  cout << "=======================================" << endl << endl;
  cout << "=======================================" << endl;
  cout << "              Double Room" << endl;
  cout << "Price: $" << DoubleRoom::get_price() << endl;
  cout << "Discount: " << DoubleRoom::get_discount() << "%" << endl;
  cout << "Final price: $" << DoubleRoom::get_final_price() << endl;
  cout << "=======================================" << endl << endl;
  cout << "=======================================" << endl;
  cout << "              Suite Room" << endl;
  cout << "Price: $" << SuiteRoom::get_price() << endl;
  cout << "Discount: " << SuiteRoom::get_discount() << "%" << endl;
  cout << "Final price: $" << SuiteRoom::get_final_price() << endl;
  cout << "=======================================" << endl << endl;

  press_enter_continue();
}

void TUIAdministrator::update_prices() {
  int opcion;
  do {
    clear_screen();
    print_banner();

    cout << "Update prices" << endl << endl;
    cout << "[1] - Standard" << endl;
    cout << "[2] - Double" << endl;
    cout << "[3] - Suite" << endl;
    cout << "[4] - Go back" << endl;
    cout << endl;
    cout << "> ";
    cin >> opcion;

    if (opcion < 1 || opcion > 4)
      print_incorrect_option();
  } while (opcion < 1 || opcion > 4);

  if (opcion == 4)
    return;

  clear_screen();
  print_banner();

  cout << "Update prices" << endl << endl;

  double price;
  cout << "Price: $";
  cin >> price;

  switch (opcion) {
  case 1:
    StandardRoom::set_price(price);
    cout << endl << "Price updated successfully..." << endl;
    break;
  case 2:
    DoubleRoom::set_price(price);
    cout << endl << "Price updated successfully..." << endl;
    break;
  case 3:
    SuiteRoom::set_price(price);
    cout << endl << "Price updated successfully..." << endl;
    break;
  }
  sleep_for(MESSAGE_WAIT_TIME_SECONDS);
}

void TUIAdministrator::update_discounts() {
  int opcion;

  do {
    clear_screen();
    print_banner();

    cout << "Update discounts" << endl << endl;
    cout << "[1] - Standard" << endl;
    cout << "[2] - Double" << endl;
    cout << "[3] - Suite" << endl;
    cout << "[4] - Go back" << endl;
    cout << endl;
    cout << "> ";
    cin >> opcion;

    if (opcion < 1 || opcion > 4)
      print_incorrect_option();
  } while (opcion < 1 || opcion > 4);

  if (opcion == 4)
    return;

  clear_screen();
  print_banner();

  cout << "Update discounts" << endl << endl;

  int discount;
  cout << "Discount: ";
  cin >> discount;

  switch (opcion) {
  case 1:
    StandardRoom::set_discount(discount);
    cout << endl << "Discount updated successfully..." << endl;
    break;
  case 2:
    DoubleRoom::set_discount(discount);
    cout << endl << "Discount updated successfully..." << endl;
    break;
  case 3:
    SuiteRoom::set_discount(discount);
    cout << endl << "Discount updated successfully..." << endl;
    break;
  }
  sleep_for(MESSAGE_WAIT_TIME_SECONDS);
}

void TUIAdministrator::print_rooms() {
  vector<Room *> rooms = get_ootel()->get_rooms();

  for (auto r : rooms) {
    cout << "======================================" << endl;
    cout << r->to_string();
    cout << "======================================" << endl;
    cout << endl;
  }
}

void TUIAdministrator::reservations() {
  clear_screen();
  print_banner();
  cout << "Reservations" << endl << endl;

  ReservationsHistory rh = get_ootel()->get_reservations_history();
  vector<Reservation> reservations = rh.get_reservations();

  if (reservations.empty())
    cout << "No reservations were found..." << endl;
  else
    for (int i = 0; i < reservations.size(); i++) {
      cout << "=========================================" << endl;
      cout << reservations[i].to_string();
      cout << "=========================================" << endl;
      cout << endl;
    }

  press_enter_continue();
}
