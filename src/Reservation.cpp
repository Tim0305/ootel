#include "Reservation.h"
#include <sstream>

using namespace std;

int Reservation::get_id() { return id; }

Datetime Reservation::get_start_date() { return start_date; }

Datetime Reservation::get_end_date() { return end_date; }

bool Reservation::is_active() { return active; }

Fee Reservation::get_fee() { return fee; }

Client *Reservation::get_client() { return client; }

Room *Reservation::get_room() { return room; }

// Setters
void Reservation::set_id(int id) { this->id = id; }

void Reservation::set_start_date(Datetime s) { start_date = s; }

void Reservation::set_end_date(Datetime e) { end_date = e; }

void Reservation::set_active(bool a) { active = a; }

void Reservation::set_fee(Fee f) { fee = f; }

void Reservation::set_client(Client *c) { client = c; }

void Reservation::set_room(Room *r) { room = r; }

string Reservation::to_string() {
  string active_str = active ? "TRUE" : "FALSE";

  stringstream ss;
  ss << "ID: " << id << endl;
  ss << "Start date: " << start_date.to_string() << endl;
  ss << "End date: " << end_date.to_string() << endl;
  ss << "Active: " << active_str << endl;

  if (client != nullptr) {
    ss << "             ----- Client ----- " << endl;
    ss << "Name: " << client->get_name() << endl;
    ss << "Last Name: " << client->get_last_name() << endl;
    ss << "Email: " << client->get_email() << endl;
    ss << "Phone Number: " << client->get_phone_number() << endl;
    ss << "Birthdate: " << client->get_birthdate().to_string() << endl;
  }

  if (room != nullptr) {
    ss << "             ------ Room ------ " << endl;
    ss << room->to_string();
  }

  ss << "             ------- Fee ------ " << endl;
  ss << fee.to_string() << endl;

  return ss.str();
}
