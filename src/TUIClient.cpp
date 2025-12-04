#include "TUIClient.h"
#include "BankCard.h"
#include "Client.h"
#include "Datetime.h"
#include "DoubleRoom.h"
#include "Mastercard.h"
#include "Reservation.h"
#include "ReservationsHistory.h"
#include "StandardRoom.h"
#include "SuiteRoom.h"
#include "Visa.h"

#include <cstdio>
#include <exception>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>
using namespace std;

TUIClient::TUIClient(Ootel *ootel, User *user, TUIManager *manager)
    : TUI(ootel, user, manager) {
  if (user == nullptr)
    throw invalid_argument("User must exist");
}

// Menu
void TUIClient::run() {
  int opcion;
  do {
    clear_screen();
    print_banner();
    cout << "Client" << endl << endl;
    cout << "[1] - Reservations" << endl;
    cout << "[2] - Bank Cards" << endl;
    cout << "[3] - Profile" << endl;
    cout << "[4] - Signout" << endl;
    cout << endl << endl;
    cout << "> ";
    cin >> opcion;

    if (opcion < 1 || opcion > 4)
      print_incorrect_option();
  } while (opcion < 1 || opcion > 4);

  switch (opcion) {
  case 1:
    reservations();
    break;
  case 2:
    bank_cards();
    break;
  case 3:
    profile();
    break;
  case 4:
    sign_out();
    break;
  }
}

// Reservations
void TUIClient::reservations() {
  int opcion;
  do {
    clear_screen();
    print_banner();

    cout << "Reservations" << endl << endl;
    cout << "[1] - Book" << endl;
    cout << "[2] - See reservations" << endl;
    cout << "[3] - Update reservation" << endl;
    cout << "[4] - Delete reservation" << endl;
    cout << "[5] - Go Back" << endl;
    cout << endl << endl;
    cout << "> ";
    cin >> opcion;

    if (opcion < 1 || opcion > 5)
      print_incorrect_option();
  } while (opcion < 1 || opcion > 5);

  switch (opcion) {
  case 1:
    book();
    // Mostrar el menu de reservaciones
    reservations();
    break;
  case 2:
    see_reservations();
    // Mostrar el menu de reservaciones
    reservations();
    break;
  case 3:
    update_reservation();
    // Mostrar el menu de reservaciones
    reservations();
    break;
  case 4:
    delete_reservation();
    // Mostrar el menu de reservaciones
    reservations();
    break;
  case 5:
    break;
  }
}

void TUIClient::book() {
  int opcion;
  do {
    clear_screen();
    print_banner();
    cout << "Reservations" << endl << endl;
    cout << "=======================================" << endl;
    cout << "              Standard Room";
    cout << "Price: $" << StandardRoom::get_price() << endl;
    cout << "Discount: " << StandardRoom::get_discount() << "%" << endl;
    cout << "Final price: $" << StandardRoom::get_final_price() << endl;
    cout << "=======================================" << endl << endl;
    cout << "=======================================" << endl;
    cout << "              Double Room";
    cout << "Price: $" << DoubleRoom::get_price() << endl;
    cout << "Discount: " << DoubleRoom::get_discount() << "%" << endl;
    cout << "Final price: $" << DoubleRoom::get_final_price() << endl;
    cout << "=======================================" << endl << endl;
    cout << "=======================================" << endl;
    cout << "              Suite Room";
    cout << "Price: $" << SuiteRoom::get_price() << endl;
    cout << "Discount: " << SuiteRoom::get_discount() << "%" << endl;
    cout << "Final price: $" << SuiteRoom::get_final_price() << endl;
    cout << "=======================================" << endl << endl;
    cout << "[1] - Standard" << endl;
    cout << "[2] - Double" << endl;
    cout << "[3] - Suite" << endl;
    cout << "[4] - Go Back" << endl;
    cout << endl;
    cout << "> ";
    cin >> opcion;

    if (opcion < 1 || opcion > 4)
      print_incorrect_option();
  } while (opcion < 1 || opcion > 4);

  if (opcion == 4)
    return;

  int room_type;
  double final_price;
  switch (opcion) {
  case 1:
    room_type = Room::STANDARD;
    final_price = StandardRoom::get_final_price();
    break;
  case 2:
    room_type = Room::DOUBLE;
    final_price = DoubleRoom::get_final_price();
    break;
  case 3:
    room_type = Room::SUITE;
    final_price = SuiteRoom::get_final_price();
    break;
  }

  int start_year;
  int start_month;
  int start_day;
  int end_year;
  int end_month;
  int end_day;

  clear_screen();
  print_banner();
  cout << "Reservations" << endl << endl;

  cout << "=======================================" << endl;
  cout << "              Start Date" << endl;
  cout << "Year (xxxx): ";
  cin >> start_year;
  cout << "Month (1-12): ";
  cin >> start_month;
  cout << "Day (1-31): ";
  cin >> start_day;
  cout << endl;
  cout << "=======================================" << endl;
  cout << "               End Date" << endl;
  cout << "Year (xxxx): ";
  cin >> end_year;
  cout << "Month (1-12): ";
  cin >> end_month;
  cout << "Day (1-31): ";
  cin >> end_day;

  try {
    Datetime start(start_year, start_month, start_day);
    Datetime end(end_year, end_month, end_day);
    Room *r = get_ootel()->get_available_room(room_type, start, end);
    if (r == nullptr) {
      cout << endl << "No rooms were found... Try with other dates" << endl;
    } else {
      Client *c = dynamic_cast<Client *>(get_user());
      if (c != nullptr) {
        ReservationsHistory& rh = get_ootel()->get_reservations_history();
        Fee fee(final_price, Datetime::now());
        cout << endl << "Paying..." << endl;
        sleep_for(MESSAGE_WAIT_TIME_SECONDS);
        cout << endl << "Transaction completed successfully..." << endl;
        Reservation reservation(start, end, false, fee, c, r);
        rh.create_reservation(reservation);
        cout << endl << "Reservation created successfully..." << endl;
      }
    }
  } catch (const exception &e) {
    cout << endl << e.what() << endl;
  }

  sleep_for(MESSAGE_WAIT_TIME_SECONDS);
}

void TUIClient::update_reservation() {
  clear_screen();
  print_banner();
  cout << "Reservations" << endl << endl;

  Client *c = dynamic_cast<Client *>(get_user());
  ReservationsHistory& rh = get_ootel()->get_reservations_history();
  vector<Reservation> reservations = rh.find_by(*c);

  print_reservations(reservations);

  int id;
  cout << "(-1 to return)" << endl;
  cout << "> ";
  cin >> id;

  if (id == -1)
    return;

  int start_year;
  int start_month;
  int start_day;
  int end_year;
  int end_month;
  int end_day;

  clear_screen();
  print_banner();
  cout << "Reservations" << endl << endl;

  cout << "=======================================" << endl;
  cout << "              Start Date" << endl;
  cout << "Year (xxxx): ";
  cin >> start_year;
  cout << "Month (1-12): ";
  cin >> start_month;
  cout << "Day (1-31): ";
  cin >> start_day;
  cout << endl;
  cout << "=======================================" << endl;
  cout << "               End Date" << endl;
  cout << "Year (xxxx): ";
  cin >> end_year;
  cout << "Month (1-12): ";
  cin >> end_month;
  cout << "Day (1-31): ";
  cin >> end_day;

  try {
    Datetime start(start_year, start_month, start_day);
    Datetime end(end_year, end_month, end_day);
    
    Reservation& r = rh.find_by(id);
    r.set_start_date(start);
    r.set_end_date(end);
    
    rh.update_reservation(id, r);
    cout << endl << "Reservation updated successfully..." << endl;
  } catch (const exception &e) {
    cout << endl << e.what() << endl;
  }

  sleep_for(MESSAGE_WAIT_TIME_SECONDS);
}

void TUIClient::delete_reservation() {
  clear_screen();
  print_banner();
  cout << "Reservations" << endl << endl;

  Client *c = dynamic_cast<Client *>(get_user());
  ReservationsHistory& rh = get_ootel()->get_reservations_history();
  vector<Reservation> reservations = rh.find_by(*c);

  print_reservations(reservations);

  int id;
  cout << "(-1 to return)" << endl;
  cout << "> ";
  cin >> id;

  if (id == -1)
    return;
  try {
    rh.delete_reservation(id);
    cout << endl << "Reservation deleted successfully..." << endl;
  } catch (const exception &e) {
    cout << endl << e.what() << endl;
  }

  sleep_for(MESSAGE_WAIT_TIME_SECONDS);
}

void TUIClient::see_reservations() {
  // Casting
  Client *c = dynamic_cast<Client *>(get_user());

  if (c != nullptr) {
    clear_screen();
    print_banner();

    cout << "Reservations" << endl << endl;

    vector<Reservation> reservations =
        get_ootel()->get_reservations_history().find_by(*c);

    if (reservations.empty())
      cout << "No reservations were found..." << endl;
    else
      print_reservations(reservations);
    press_enter_continue();
  }
}

void TUIClient::print_reservations(vector<Reservation> reservations) {
  for (int i = 0; i < reservations.size(); i++) {
    cout << endl;
    cout << "=========================================" << endl;
    cout << reservations[i].to_string();
    cout << "=========================================" << endl;
    cout << endl;
  }
}

// Bankcards
void TUIClient::bank_cards() {
  int opcion;
  do {
    clear_screen();
    print_banner();

    cout << "Bank Cards" << endl << endl;
    cout << "[1] - Add a bank card" << endl;
    cout << "[2] - Select a bank card" << endl;
    cout << "[3] - Update a bank card" << endl;
    cout << "[4] - Delete a bank card" << endl;
    cout << "[5] - See bank cards" << endl;
    cout << "[6] - Go Back" << endl;
    cout << endl;
    cout << "> ";
    cin >> opcion;

    if (opcion < 1 || opcion > 6)
      print_incorrect_option();
  } while (opcion < 1 || opcion > 6);

  switch (opcion) {
  case 1:
    add_bank_card();
    // Mostrar el menu de bank cards
    bank_cards();
    break;
  case 2:
    select_bank_card();
    // Mostrar el menu de bank cards
    bank_cards();
    break;
  case 3:
    update_bank_card();
    // Mostrar el menu de bank cards
    bank_cards();
    break;
  case 4:
    delete_bank_card();
    // Mostrar el menu de bank cards
    bank_cards();
    break;
  case 5:
    see_bank_cards();
    // Mostrar el menu de bank cards
    bank_cards();
    break;
  case 6:
    break;
  }
}

void TUIClient::add_bank_card() {
  int opcion;
  do {
    clear_screen();
    print_banner();

    cout << "Bank Cards" << endl << endl;
    cout << "[1] - Visa" << endl;
    cout << "[2] - Mastercard" << endl;
    cout << "[3] - Cancel" << endl;
    cout << endl;
    cout << "> ";
    cin >> opcion;

    if (opcion < 1 || opcion > 3)
      print_incorrect_option();
  } while (opcion < 1 || opcion > 3);

  if (opcion == 3)
    return;

  string number;
  string cardholder;
  int expiration_year;
  int cvc;

  cin.ignore(); // Limpiar el buffer

  clear_screen();
  print_banner();
  cout << "Bank Cards" << endl << endl;
  cout << "Number: ";
  getline(cin, number);
  cout << "Card Holder: ";
  getline(cin, cardholder);
  cout << "Expiration Year: ";
  cin >> expiration_year;
  cout << "CVC: ";
  cin >> cvc;

  BankCard *card;
  try {
    switch (opcion) {
    case 1:
      card = new Visa(number, cardholder, expiration_year, cvc);
      break;
    case 2:
      card = new Mastercard(number, cardholder, expiration_year, cvc);
      break;
    }

    Client *c = dynamic_cast<Client *>(get_user());
    if (c != nullptr) {
      c->add_card(card);
      cout << endl << "Card added successfully..." << endl;
    }
  } catch (const exception &e) {
    cout << endl << e.what() << endl;
  }
  sleep_for(MESSAGE_WAIT_TIME_SECONDS);
}

void TUIClient::select_bank_card() {
  clear_screen();
  print_banner();

  cout << "Bank Cards" << endl << endl;

  Client *c = dynamic_cast<Client *>(get_user());
  if (c != nullptr) {
    if (c->get_bank_cards().empty()) {
      cout << "No bank card has been created..." << endl;
      press_enter_continue();
    } else {
      print_bank_cards();

      int index;
      cout << "(-1 to return)" << endl;
      cout << "> ";
      cin >> index;

      if (index == -1)
        return;

      try {
        c->set_selected_card(index - 1);

        cout << endl
             << "Bank Card " << index << " has been selected successfully..."
             << endl;
      } catch (const exception &e) {
        cout << endl << e.what() << endl;
      }
      sleep_for(MESSAGE_WAIT_TIME_SECONDS);
    }
  }
}

void TUIClient::update_bank_card() {
  clear_screen();
  print_banner();

  cout << "Bank Cards" << endl << endl;

  Client *c = dynamic_cast<Client *>(get_user());
  if (c != nullptr) {
    if (c->get_bank_cards().empty()) {
      cout << "No bank card has been created..." << endl;
      press_enter_continue();
    } else {
      print_bank_cards();

      int index;
      cout << "(-1 to return)" << endl;
      cout << "> ";
      cin >> index;

      if (index == -1)
        return;

      try {
        clear_screen();
        print_banner();

        cout << "Bank Cards" << endl << endl;

        string number;
        string cardholder;
        int expiration_year;
        int cvc;

        cin.ignore(); // Limpiar el buffer

        cout << "Number: ";
        getline(cin, number);
        cout << "Card Holder: ";
        getline(cin, cardholder);
        cout << "Expiration Year: ";
        cin >> expiration_year;
        cout << "CVC: ";
        cin >> cvc;

        switch (c->get_bank_card(index - 1)->get_type()) {
        case BankCard::VISA:
          c->update_bank_card(
              index - 1, new Visa(number, cardholder, expiration_year, cvc));
          cout << endl << "Bank Card updated successfully..." << endl;
          break;
        case BankCard::MASTERCARD:
          c->update_bank_card(index - 1, new Mastercard(number, cardholder,
                                                        expiration_year, cvc));
          cout << endl
               << "Bank Card " << index << " updated successfully..." << endl;
          break;
        default:
          cout << endl << "Invalid type for BankCard" << endl;
        }
      } catch (const exception &e) {
        cout << endl << e.what() << endl;
      }
      sleep_for(MESSAGE_WAIT_TIME_SECONDS);
    }
  }
}

void TUIClient::delete_bank_card() {
  clear_screen();
  print_banner();

  cout << "Bank Cards" << endl << endl;

  Client *c = dynamic_cast<Client *>(get_user());
  if (c != nullptr) {
    if (c->get_bank_cards().empty()) {
      cout << "No bank card has been created..." << endl;
      press_enter_continue();
    } else {
      print_bank_cards();

      int index;
      cout << "(-1 to return)" << endl;
      cout << "> ";
      cin >> index;

      if (index == -1)
        return;

      try {
        c->remove_bank_card(index - 1);

        cout << endl
             << "Bank Card " << index << " has been removed successfully..."
             << endl;
      } catch (const exception &e) {
        cout << endl << e.what() << endl;
      }
      sleep_for(MESSAGE_WAIT_TIME_SECONDS);
    }
  }
}

void TUIClient::print_bank_cards() {
  Client *c = dynamic_cast<Client *>(get_user());
  for (int i = 0; i < c->get_bank_cards().size(); i++) {
    cout << "======================================" << endl;
    if (c->get_bank_card(i) == c->get_selected_card())
      cout << "[*] SELECTED" << endl;
    else
      cout << "[ ]" << endl;

    cout << "No. " << i + 1 << endl;
    cout << c->get_bank_card(i)->to_string();
    cout << "======================================" << endl;
    cout << endl;
  }
}

void TUIClient::see_bank_cards() {
  clear_screen();
  print_banner();

  cout << "Bank Cards" << endl << endl;

  Client *c = dynamic_cast<Client *>(get_user());

  if (c->get_bank_cards().empty())
    cout << "No bank card has been created..." << endl;
  else
    print_bank_cards();

  press_enter_continue();
}

// Profile
void TUIClient::profile() {
  Client *c = dynamic_cast<Client *>(get_user());

  if (c != nullptr) {
    int opcion;
    do {
      clear_screen();
      print_banner();

      cout << "Profile" << endl << endl;
      cout << get_user()->to_string() << endl;

      cout << endl;
      cout << "[1] - Update Profile" << endl;
      cout << "[2] - Go Back" << endl;
      cout << endl;
      cout << "> ";
      cin >> opcion;

      if (opcion < 1 || opcion > 2)
        print_incorrect_option();

    } while (opcion < 1 || opcion > 2);

    switch (opcion) {
    case 1:
      update_profile();
      // Mostrar otra vez el perfil
      profile();
      break;
    case 2:
      break;
    }
  }
}

void TUIClient::update_profile() {
  clear_screen();
  print_banner();

  cout << "Profile" << endl << endl;
  auto optional_user = user_form();
  if (optional_user) {
    string curr_password;
    cout << endl;
    cout << "Current password: ";
    cin.ignore(); // Limpiar el buffer
    getline(cin, curr_password);

    User u = optional_user.value();

    try {
      // Primero actualizar el password
      get_user()->update_password(curr_password, u.get_password());
      // Actualizar perfil
      get_user()->update_profile(u.get_name(), u.get_last_name(), u.get_email(),
                                 u.get_phone_number(), u.get_birthdate());
      cout << endl << "Profile updated successfully..." << endl;
    } catch (const exception &e) {
      cout << endl << e.what() << endl;
    }
  }
  sleep_for(MESSAGE_WAIT_TIME_SECONDS);
}

// Signout
void TUIClient::sign_out() {
  get_user()->sign_out();
  cout << endl << "Signing out..." << endl;
  get_manager()->go_back();
  sleep_for(MESSAGE_WAIT_TIME_SECONDS);
}
