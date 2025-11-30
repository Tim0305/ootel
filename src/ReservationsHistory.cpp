#include "ReservationsHistory.h"
#include "Room.h"
#include <stdexcept>
#include <string>

using namespace std;

vector<Reservation> ReservationsHistory::get_reservations() {
  return reservations;
}

void ReservationsHistory::create_reservation(Reservation reservation) {
  reservations.push_back(reservation);
}

void ReservationsHistory::delete_reservation(int id) {
  for (int i = 0; i < reservations.size(); i++) {
    if (reservations[i].get_id() == id) {
      reservations.erase(reservations.begin() + i);
      return;
    }
  }

  throw runtime_error("Reservation with id " + to_string(id) + " not found");
}

void ReservationsHistory::update_reservation(int id, Reservation reservation) {
  for (int i = 0; i < reservations.size(); i++) {
    if (reservations[i].get_id() == id) {
      reservations[i] = reservation;
      return;
    }
  }

  throw runtime_error("Reservation with id " + to_string(id) + " not found");
}

void ReservationsHistory::release_reservation(Client& client, Room& room) {
  // Buscar reservaciones
  vector<Reservation> reservations = find_by(client, room);

  if (reservations.size() == 0)
    throw runtime_error("No reservations where found for client " +
                        to_string(client.get_id()) + " and room " +
                        to_string(room.get_number()));

  // Liberar la habitacion y la reservacion
  room.release();

  for (auto r : reservations)
    if (r.is_active())
      r.set_active(false);
}

vector<Reservation> ReservationsHistory::find_by(Client &client, Room &room) {
  vector<Reservation> reservations;
  for (auto r : reservations) {
    if (r.get_client()->get_id() == client.get_id() &&
        r.get_room()->get_number() == room.get_number())
      reservations.push_back(r);
  }
  return reservations;
}

vector<Reservation> ReservationsHistory::find_by(const int id) {
  vector<Reservation> reservations;
  for (auto r : reservations) {
    if (r.get_id() == id) {
      reservations.push_back(r);
    }
  }
  return reservations;
}

vector<Reservation> ReservationsHistory::find_by(Client &client) {
  vector<Reservation> reservations;
  for (auto r : reservations) {
    if (r.get_client()->get_id() == client.get_id()) {
      reservations.push_back(r);
    }
  }
  return reservations;
}

vector<Reservation> ReservationsHistory::find_by(Room &room) {
  vector<Reservation> reservations;
  for (auto r : reservations) {
    if (r.get_room()->get_number() == room.get_number()) {
      reservations.push_back(r);
    }
  }
  return reservations;
}
