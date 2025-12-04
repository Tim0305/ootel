#include "Ootel.h"
#include "Administrator.h"
#include <stdexcept>
#include <string>

#include <iostream>

using namespace std;

Ootel::Ootel(std::string country, std::string state, int cp) {
  set_country(country);
  set_state(state);
  set_cp(cp);

  reservations_history = ReservationsHistory();
  // Contador de IDs
  users_id = 1;

  // Crear el administrador base
  int id = 0;
  string name = "admin";
  string last_name = "";
  string email = "admin@ootel.com";
  long phone_number = 0;
  string password = "admin";
  Datetime birthdate(2000, 5, 1);
  User *administrator = new Administrator(id, name, last_name, email,
                                          phone_number, password, birthdate);
  users.push_back(administrator);
}

Ootel::~Ootel() {
  // Limpiar la memoria
  for (auto u : users)
    delete u;
  users.clear();

  for (auto r : rooms)
    delete r;
  rooms.clear();
}

// Getters
string Ootel::get_country() { return country; }

string Ootel::get_state() { return state; }

int Ootel::get_cp() { return cp; }

vector<Room *> Ootel::get_rooms() { return rooms; }

vector<User *> Ootel::get_users() { return users; }

ReservationsHistory &Ootel::get_reservations_history() {
  return reservations_history;
}

Room *Ootel::get_available_room(int room_type, Datetime start, Datetime end) {
  for (auto r : rooms) {
    if (r->get_type() == room_type &&
        !reservations_history.is_reserved(r, start, end))
      return r;
  }

  return nullptr;
}

// Setters
void Ootel::set_country(string country) { this->country = country; }

void Ootel::set_state(string state) { this->state = state; }

void Ootel::set_cp(int cp) { this->cp = cp; }

// Control de cuartos
void Ootel::create_room(Room *room) {
  for (auto r : rooms)
    if (r->get_number() == room->get_number())
      throw invalid_argument("Room with id " + to_string(room->get_number()) +
                             " already exists...");
  rooms.push_back(room);
}

void Ootel::update_room(int number, Room *room) {
  if (room == nullptr)
    throw runtime_error("Room cannot be nullptr");

  for (int i = 0; i < rooms.size(); i++) {
    if (rooms[i]->get_number() == number) {
      delete rooms[i];
      rooms[i] = room; // sobreescribe sus datos
      return;
    }
  }

  throw runtime_error("Room with number " + to_string(number) + " not found");
}

void Ootel::delete_room(int number) {
  for (int i = 0; i < rooms.size(); i++) {
    if (rooms[i]->get_number() == number) {
      delete rooms[i];
      rooms.erase(rooms.begin() + i);
      return;
    }
  }

  throw runtime_error("Room with number " + to_string(number) + " not found");
}

// Control de Usuarios
void Ootel::create_user(User *user) {
  if (user == nullptr)
    throw runtime_error("User cannot be nullptr");
  // Update id
  user->set_id(users_id++);
  users.push_back(user);
}

void Ootel::update_user(int id, User *user) {
  if (user == nullptr)
    throw runtime_error("User cannot be nullptr");

  for (int i = 0; i < users.size(); i++) {
    if (users[i]->get_id() == id) {
      delete users[i];
      users[i] = user;
      return;
    }
  }

  throw runtime_error("User with id " + to_string(id) + " not found");
}

void Ootel::delete_user(int id) {
  if (id == 0)
    throw invalid_argument("Admin must exist...");

  for (int i = 0; i < users.size(); i++) {
    if (users[i]->get_id() == id) {
      delete users[i];
      users.erase(users.begin() + i);
      return;
    }
  }

  throw runtime_error("User with id " + to_string(id) + " not found");
}

// Finders
User *Ootel::find_user(int id) {
  for (User *u : users) {
    if (u->get_id() == id)
      return u;
  }
  return nullptr;
}

User *Ootel::find_user(string name) {
  for (User *u : users) {
    if (u->get_name() == name)
      return u;
  }
  return nullptr;
}

Room *Ootel::find_room(int number) {
  for (Room *r : rooms) {
    if (r->get_number() == number)
      return r;
  }
  return nullptr;
}

User *Ootel::log_in(std::string email, std::string password) {
  for (auto u : users)
    if (u->log_in(email, password))
      return u;
  return nullptr;
}
