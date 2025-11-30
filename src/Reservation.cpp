#include "Reservation.h"

int Reservation::get_id(){ 
    return id; 
}

Datetime Reservation::get_start_date(){ 
    return start_date; 
}

Datetime Reservation::get_end_date(){ 
    return end_date; 
}

bool Reservation::is_active(){ 
    return active; 
}

Fee Reservation::get_fee() { 
    return fee; 
}

Client* Reservation::get_client(){ 
    return client; 
}

Room* Reservation::get_room(){ 
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

void Reservation::set_fee(Fee f) { 
    fee = f; 
}

void Reservation::set_client(Client* c) { 
    client = c; 
}

void Reservation::set_room(Room* r) { 
    room = r; 
}




