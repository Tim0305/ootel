#include "TUIClient.h"
#include "Client.h"
#include "Reservation.h"

#include <iostream>
using namespace std;

void TUIClient::print() {
  int opcion;
  do {
    clear_screen();
    print_banner();
    cout << "[1] - Reservations" << endl;
    cout << "[2] - BankCards" << endl;
    cout << "[3] - Profile" << endl;
    cout << "[4] - Signout" << endl;
    cout << endl << endl;
    cout << "> ";
    cin >> opcion;

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
    default:
      print_incorrect_option();
    }
  } while (opcion < 1 || opcion > 4);
}

void TUIClient::reservations() {
  int opcion;
  do {
    clear_screen();
    print_banner();

    cout << "[1] - Book" << endl;
    cout << "[2] - See reservations" << endl;
    cout << "[3] - Update reservation" << endl;
    cout << "[4] - Delete reservation" << endl;
    cout << "[5] - Go Back" << endl;
    cout << endl << endl;
    cout << "> ";
    cin >> opcion;

    switch (opcion) {
    case 1:
      break;
    case 2:
      print_reservations();
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    default:
      print_incorrect_option();
    }
  } while (opcion < 1 || opcion > 5);
}

void TUIClient::print_reservations() {
  // Casting
  Client *c = dynamic_cast<Client *>(get_user());
  if (c != nullptr) {
    vector<Reservation> reservations =
        get_ootel()->get_reservations_history().find_by(*c);

    if (reservations.empty())
      cout << endl << "No reservations were found..." << endl;
    else
      for (auto r : reservations) {
        string active = r.is_active() ? "TRUE" : "FALSE";

        string type_room;
        switch (r.get_room()->get_type()) {
        case Room::STANDARD:
          type_room = "STANDARD";
          break;
        case Room::DOUBLE:
          type_room = "DOUBLE";
          break;
        case Room::SUITE:
          type_room = "SUITE";
          break;
        }

        cout << endl;
        cout << "=========================================" << endl;
        cout << "ID: " << r.get_id() << endl;
        cout << "Start Day: " << r.get_start_date().to_string() << endl;
        cout << "End Day: " << r.get_end_date().to_string() << endl;
        cout << "Active " << active << endl;
        cout << endl;
        cout << "              ----- Room ----- " << endl;
        cout << "Number: " << r.get_room()->get_number() << endl;
        cout << "Type: " << type_room << endl;
        cout << "Price: " << r.get_room()->get_price();
        cout << endl;
        cout << "              ----- Fee ----- " << endl;
        cout << "Amount: " << r.get_fee().get_amount() << endl;
        cout << "Date: " << r.get_fee().get_date().to_string() << endl;
        cout << "=========================================" << endl;
      }

    cout << endl;
    press_enter_continue();
  }
}

void TUIClient::sign_out() {
  get_user()->sign_out();
  cout << endl << "Signing out..." << endl;
  get_manager()->go_back();
  sleep_for(1);
  
}

void TUIClient::profile() {
  clear_screen();
  print_banner();

  cout << endl << "Profile" << endl << endl;
  cout << get_user()->to_string() << endl;

  cout << endl;
  press_enter_continue();
}

void TUIClient::bank_cards() {

}
