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
  Client *client;
  Room *room;

public:
  Reservation(const Reservation& reservation);
  Reservation(int id, Datetime start_date, Datetime end_date, bool active,
              Fee fee, Client *client, Room *room)
      : id(id), start_date(start_date), end_date(end_date), active(active),
        fee(fee), client(client), room(room) {}
  Reservation(Datetime start_date, Datetime end_date, bool active, Fee fee,
              Client *client, Room *room)
      : Reservation(-1, start_date, end_date, active, fee, client, room) {}

  // Getters
  int get_id() const;
  Datetime get_start_date() const;
  Datetime get_end_date() const;
  bool is_active() const;
  Client *get_client() const;
  Room *get_room() const;
  Fee get_fee() const;

  // Setters
  void set_id(int id);
  void set_start_date(Datetime start_date);
  void set_end_date(Datetime end_date);
  void set_active(bool active);
  void set_fee(Fee fee);
  void set_client(Client *client);
  void set_room(Room *room);

  std::string to_string();
};

#endif
