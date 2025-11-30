#include "Reservation.h"

//Getters
int Reservation::get_id() const {
    return id;
}

Datetime Reservation::get_start_date() const{
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

//Setters
void Reservation::set_id(int id) {
    this->id = id;
}

void Reservation::set_start_date(Datetime start_date) {
    this->start_date = start_date;
}

void Reservation::set_end_date(Datetime end_date) {
    this->end_date = end_date;
}

void Reservation::set_active(bool active) {
    this->active = active;
}

void Reservation::set_fee(Fee &fee) {
    this->fee = fee;
}