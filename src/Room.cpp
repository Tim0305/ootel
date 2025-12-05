#include "Room.h"
#include <sstream>

using namespace std;

// Getters

int Room::get_number() const { return number; }
int Room::get_type()const { return type; }
bool Room::is_available()const { return available; }
int Room::get_number_people()const { return number_people; }
int Room::get_number_beds()const { return number_beds; }

// Setters

void Room::set_number(int number) { this->number = number; }
void Room::set_type(int type) { this->type = type; }
void Room::set_available(bool available) { this->available = available; }
void Room::set_number_people(int number_people) {
  this->number_people = number_people;
}
void Room::set_number_beds(int number_beds) { this->number_beds = number_beds; }

// Opciones de reserva

void Room::release() {
  this->available = true;
}

string Room::to_string() {
  string type_room;
  switch (type) {
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

  stringstream ss;
  ss << "Type: " << type_room << endl;
  ss << "Number: " << number << endl;
  ss << "People: " << number_people << endl;
  ss << "Beds: " << number_beds << endl;
  return ss.str();
}

void Room::update(const Room& room) {
  this->number = room.type;
  this->type = room.type;
  this->available = room.available;
  this->number_people = room.number_people;
  this->number_beds = room.number_beds;
}
