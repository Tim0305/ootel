#ifndef RESERVATIONS_HISTORY_H
#define RESERVATIONS_HISTORY_H

#include "Client.h"
#include "Reservation.h"
#include "Room.h"
#include <vector>

class ReservationsHistory {
private:
  std::vector<Reservation*> reservations;
public:
  ReservationsHistory();

  // Getters
  std::vector<Reservation*> get_reservations();

  // Setters
  void create_reservation(Reservation* r);
  void delete_reservation(Reservation* r);
  void update_reservation(int id, Reservation* reservation);

  //Finders
  Reservation* find_reservation(Client* client, int room_number);
  std::vector<Reservation*> find_by(int id);
  std::vector<Reservation*> find_by(const Client &client);
  std::vector<Reservation*> find_by(const Room &room);
};

#endif // !RESERVATIONS_HISTORY_H

