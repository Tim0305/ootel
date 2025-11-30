#include "Room.h"
#include <stdexcept>

using namespace std;

//Getters

int Room::get_number(){ 
    return number; 
}
int Room::get_type(){ 
    return type; 
}
double Room::get_price(){ 
    return price; 
}
bool Room::is_available(){ 
    return available; 
}
int Room::get_number_people(){
    return number_people;
}
int Room::get_number_beds() {
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
    if (!available)
        throw runtime_error("Room isn't available");
    this->client = client;
    this->available = false;
}

void Room::release() {
    this->client = nullptr;
    this->available = true;
}
