#ifndef RESERVATION_H
#define RESERVATION_H

#include "Client.h"
#include "Datetime.h"
#include "Fee.h"
#include "Room.h"

class Reservation {
private:
  int id;
  Datetime start_date;
  Datetime end_date;
  bool active;
  Fee fee;
  Client &client;
  Room &room;

public:
  Reservation();
  Reservation(int id, Datetime start_date, Datetime end_date, bool active,
              Fee fee, Client &client, Room &room)
      : id(id), start_date(start_date), end_date(end_date), active(active),
        fee(fee), client(client), room(room) {}

  // Getters
  int get_id();
  Datetime get_start_date();
  Datetime get_end_date();
  bool is_active();
  Client &get_client();
  Room &get_room();
  Fee &get_fee();

  // Setters
  void set_id(int id);
  void set_start_date(Datetime start_date);
  void set_end_date(Datetime end_date);
  void set_active(bool active);
  void set_fee(Fee fee);
  void set_client(Client &client);
  void set_room(Room &room);
};

#endif
