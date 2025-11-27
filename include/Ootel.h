#ifndef OOTEL_H
#define OOTEL_H

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

public:
  // Getters
  std::string get_country();
  std::string get_state();
  int get_cp();
  std::vector<Room *> get_rooms();
  std::vector<User *> get_users();
  ReservationsHistory& get_reservations_history();

  // Setters
  void set_country(std::string country);
  void set_state(std::string state);
  void set_cp(int cp);

  void create_room(Room* room);
  void update_room(int number, Room* room);
  void delete_room(Room *room);
  void create_user(User* user);
  void update_user(int id, User* user);
  void delete_user(User* user);
  void release_reservation(Client* client, int room);
  User* find_user(std::string name);
  Room* find_room(int number);
};

#endif // !OOTEL_H
