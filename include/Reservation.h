#ifndef RESERVATION_H
#define RESERVATION_H

#include "Client.h"
#include "Fee.h"
#include "Datetime.h"

class Reservation {
private:
  int id;
  Datetime start_date;
  Datetime end_date;
  bool active;
  Fee fee;
  Client *client;

public:
  Reservation();
  Reservation(int id, Datetime start_date, Datetime end_date, bool active,
              Fee fee, Client *client)
      : id(id), start_date(start_date), end_date(end_date), active(active),
        fee(fee), client(client) {}

  // Getters
  int get_id();
  Datetime get_start_date();
  Datetime get_end_date();
  bool is_active();
  Fee get_fee();

  // Setters
  void set_id(int id);
  void set_start_date(Datetime start_date);
  void set_end_date(Datetime end_date);
  void set_active(bool active);
  void set_fee(Fee &fee);
};

#endif // !RESERVATION_H
