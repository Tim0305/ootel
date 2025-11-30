#include "ReservationsHistory.h"

ReservationsHistory::ReservationsHistory() {}

std::vector<Reservation*> ReservationsHistory::get_reservations() {
    return reservations;
}

void ReservationsHistory::create_reservation(Reservation* reservation) {
    reservations.push_back(reservation);
}

void ReservationsHistory::delete_reservation(Reservation* reservation) {
    for (auto it = reservations.begin(); it != reservations.end(); ++it) {
        if (*it == reservation) {
            reservations.erase(it);
            return;
        }
    }
}

void ReservationsHistory::update_reservation(int id, Reservation* reservation) {
    for (auto &r : reservations) {
        if (r->get_id() == id) {
            r = reservation;
            return;
        }
    }
}

Reservation* ReservationsHistory::find_reservation(Client* client, int room_number) {
    for (auto* r : reservations) {
        if (r->get_client()->get_id() == client->get_id() &&
            r->get_room()->get_number() == room_number) 
        {
            return r;
        }
    }
    return nullptr;
}

std::vector<Reservation*> ReservationsHistory::find_by(int id) {
    std::vector<Reservation*> found;
    for (auto* r : reservations) {
        if (r->get_id() == id) {
            found.push_back(r);
        }
    }
    return found;
}

std::vector<Reservation*> ReservationsHistory::find_by(const Client &client) {
    std::vector<Reservation*> found;
    for (auto* r : reservations) {
        if (r->get_client()->get_id() == client.get_id()) {
            found.push_back(r);
        }
    }
    return found;
}

std::vector<Reservation*> ReservationsHistory::find_by(const Room &room) {
    std::vector<Reservation*> found;
    for (auto* r : reservations) {
        if (r->get_room()->get_number() == room.get_number()) {
            found.push_back(r);
        }
    }
    return found;
}