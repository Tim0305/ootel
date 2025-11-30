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
  void create_reservation(Reservation reservation);
  void delete_reservation(int id);
  void update_reservation(int id, Reservation reservation);
  void release_reservation(Client& client, Room& room);
  std::vector<Reservation> find_by(Client &client,Room &room);
  std::vector<Reservation> find_by(const int id);
  std::vector<Reservation> find_by(Client &client);
  std::vector<Reservation> find_by(Room &room);
};

#endif // !RESERVATIONS_HISTORY_H

