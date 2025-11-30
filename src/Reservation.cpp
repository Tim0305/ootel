#include "Reservation.h"

// Constructor
Reservation::Reservation() : id(0), start_date(), end_date(), active(false), fee(), client(nullptr), room(nullptr) {}

Reservation::Reservation(int id, Datetime start_date, Datetime end_date, bool active,
                         Fee fee, Client* client, Room* room)
    : id(id), start_date(start_date), end_date(end_date), active(active), fee(fee),
      client(client), room(room) {}


int Reservation::get_id() const { 
    return id; 
}

Datetime Reservation::get_start_date() const { 
    return start_date; 
}

Datetime Reservation::get_end_date() const { 
    return end_date; 
}

bool Reservation::is_active() const { 
    return active; 
}

Fee& Reservation::get_fee() { 
    return fee; 
}

Client* Reservation::get_client() const { 
    return client; 
}

Room* Reservation::get_room() const { 
    return room; 
}

// Setters
void Reservation::set_id(int id) { 
    this->id = id; 
}

void Reservation::set_start_date(Datetime s) { 
    start_date = s; 
}

void Reservation::set_end_date(Datetime e) { 
    end_date = e; 
}

void Reservation::set_active(bool a) { 
    active = a; 
}

void Reservation::set_fee(Fee &f) { 
    fee = f; 
}

void Reservation::set_client(Client* c) { 
    client = c; 
}

void Reservation::set_room(Room* r) { 
    room = r; 
}




