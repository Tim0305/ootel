#include "ReservationsHistory.h"
#include "Datetime.h"
#include "Room.h"
#include <stdexcept>
#include <string>

using namespace std;

vector<Reservation> ReservationsHistory::get_reservations() {
  return reservations;
}

void ReservationsHistory::create_reservation(Reservation reservation) {
  reservation.get_room()->set_available(false);
  reservation.set_id(reservations_id++);
  reservations.push_back(reservation);
}

void ReservationsHistory::delete_reservation(int id) {
  for (int i = 0; i < reservations.size(); i++) {
    if (reservations[i].get_id() == id) {
      reservations[i].get_room()->set_available(true);
      reservations.erase(reservations.begin() + i);
      return;
    }
  }

  throw invalid_argument("Reservation with id " + to_string(id) + " was not found...");
}

void ReservationsHistory::update_reservation(int id, Reservation reservation) {
  for (int i = 0; i < reservations.size(); i++) {
    if (reservations[i].get_id() == id) {
      reservations[i] = reservation;
      return;
    }
  }

  throw invalid_argument("Reservation with id " + to_string(id) + " was not found...");
}

void ReservationsHistory::release_reservation(Client& client, Room& room) {
  // Buscar reservaciones
  vector<Reservation> reservations = find_by(client, room);

  if (reservations.size() == 0)
    throw invalid_argument("No reservations where found for client " +
                        to_string(client.get_id()) + " and room " +
                        to_string(room.get_number()) + "...");

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

Reservation& ReservationsHistory::find_by(const int id) {
  for (int i = 0; i < reservations.size(); i++) {
    if (reservations[i].get_id() == id) {
      return reservations[i];
    }
  }
  throw invalid_argument("Reservation with id " + to_string(id) + " was not found...");
}

vector<Reservation> ReservationsHistory::find_by(Client &client) {
  vector<Reservation> result;
  for (auto r : reservations) {
    if (r.get_client()->get_id() == client.get_id()) {
      result.push_back(r);
    }
  }
  return result;
}

vector<Reservation> ReservationsHistory::find_by(Room &room) {
  vector<Reservation> result;
  for (auto r : reservations) {
    if (r.get_room()->get_number() == room.get_number()) {
      result.push_back(r);
    }
  }
  return result;
}

bool ReservationsHistory::is_reserved(Room* room, Datetime start, Datetime end) {
  vector<Reservation> reservations = find_by(*room);
  for(auto res: reservations) {
    if (res.get_start_date() <= end && res.get_end_date() >= start)
      return true;
  }
  return false;
}
