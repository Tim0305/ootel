#include "Reservation.h"

//Getters
int Reservation::get_id() {
    return id;
}

Datetime Reservation::get_start_date() {
    return start_date;
}

Datetime Reservation::get_end_date() {
    return end_date;
}

bool Reservation::is_active() {
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