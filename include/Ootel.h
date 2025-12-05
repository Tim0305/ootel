#ifndef OOTEL_H
#define OOTEL_H

#include "Datetime.h"
#include "ReservationsHistory.h"
#include "Room.h"
#include "User.h"
#include <string>
#include <vector>

class Ootel {
private:
  std::string country;
  std::string state;
  int cp;
  std::vector<Room *> rooms;
  std::vector<User *> users;
  ReservationsHistory reservations_history;
  int users_id;
public:
  Ootel(std::string country, std::string state, int cp);
  ~Ootel();

  // Getters
  std::string get_country();
  std::string get_state();
  int get_cp();
  std::vector<Room *> get_rooms();
  std::vector<User *> get_users();
  Room *get_available_room(int room_type, Datetime start, Datetime end);
  ReservationsHistory &get_reservations_history();

  // Setters
  void set_country(std::string country);
  void set_state(std::string state);
  void set_cp(int cp);

  void create_room(Room *room);
  void update_room(int number, Room &room);
  void delete_room(int number);
  void create_user(User *user);
  void delete_user(int id);
  User* find_user(int id);
  User *find_user(std::string name);
  Room *find_room(int number);
  User *log_in(std::string email, std::string password);
};

#endif // !OOTEL_H
