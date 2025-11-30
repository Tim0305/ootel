#include "Room.h"
#include <iostream>

//Getters

int Room::get_number() const { 
    return number; 
}
int Room::get_type() const { 
    return type; 
}
double Room::get_price() const { 
    return price; 
}
bool Room::is_available() const { 
    return available; 
}
int Room::get_number_people() const {
    return number_people;
}
int Room::get_number_beds() const{
    return number_beds;
}

// Setters

void Room::set_number(int number) {
    this->number = number;
}
void Room::set_type(int type) {
    this->type = type;
}
void Room::set_price(double price) {
    this->price = price;
}
void Room::set_available(bool available) {
    this->available = available;
}
void Room::set_client(Client *client) {
    this->client = client;
}
void Room::set_number_people(int number_people) {
    this->number_people = number_people;
}
void Room::set_number_beds(int number_beds) {
    this->number_beds = number_beds;
}

//Opciones de reserva

void Room::book(Client *client) {
    if (!available) {
        std::cout << "La habitación " << number << " no está disponible.\n";
        return;
    }
    this->client = client;
    this->available = false;
}

void Room::release() {
    this->client = nullptr;
    this->available = true;
}