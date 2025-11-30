#include "Ootel.h"
#include <iostream>

//gETERS

std::string Ootel::get_country() {
    return country;
}

std::string Ootel::get_state() {
    return state;
}

int Ootel::get_cp() {
    return cp;
}

std::vector<Room*> Ootel::get_rooms() {
    return rooms;
}

std::vector<User*> Ootel::get_users() {
    return users;
}

ReservationsHistory& Ootel::get_reservations_history() {
    return reservations_history;
}


//Setters

void Ootel::set_country(std::string country) {
    this->country = country;
}

void Ootel::set_state(std::string state) {
    this->state = state;
}

void Ootel::set_cp(int cp) {
    this->cp = cp;
}


//Control de cuartos

void Ootel::create_room(Room* room) {
    rooms.push_back(room);
}

void Ootel::update_room(int number, Room* newRoomData) {
    for (Room* r : rooms) {
        if (r->get_number() == number) {
            *r = *newRoomData; // sobreescribe sus datos
            return;
        }
    }
    std::cout << "Room " << number << " not found.\n";
}

void Ootel::delete_room(Room* room) {
    for (auto it = rooms.begin(); it != rooms.end(); ++it) {
        if (*it == room) {
            rooms.erase(it);
            return;
        }
    }
}


//Control de Usuarios

void Ootel::create_user(User* user) {
    users.push_back(user);
}

void Ootel::update_user(int id, User* newUserData) {
    for (User* u : users) {
        if (u->get_id() == id) {
            *u = *newUserData;
            return;
        }
    }
    std::cout << "User with ID " << id << " not found.\n";
}

void Ootel::delete_user(User* user) {
    for (auto it = users.begin(); it != users.end(); ++it) {
        if (*it == user) {
            users.erase(it);
            return;
        }
    }
}


//Finders

User* Ootel::find_user(std::string name) {
    for (User* u : users) {
        if (u->get_name() == name)
            return u;
    }
    return nullptr;
}

Room* Ootel::find_room(int number) {
    for (Room* r : rooms) {
        if (r->get_number() == number)
            return r;
    }
    return nullptr;
}


//Crear Rservaciones

void Ootel::release_reservation(Client* client, int roomNumber) {
    // Busca habitación
    Room* room = find_room(roomNumber);
    if (!room) {
        std::cout << "Room does not exist.\n";
        return;
    }

    // Busca reserva en historial
    Reservation* reservation =
        reservations_history.find_reservation(client, roomNumber);

    if (!reservation) {
        std::cout << "No reservation found for this client.\n";
        return;
    }

    // Asumo que Room ya tiene método release()
    room->release();

    // Remueve de historial
    reservations_history.delete_reservation(reservation);

    std::cout << "Reservation released successfully.\n";
}

