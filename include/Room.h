#ifndef ROOM_H
#define ROOM_H

#include "Client.h"

class Room {
private:
  int number;
  int type;
  double price;
  bool available;
  Client *client;
  int number_people;
  int number_beds;

public:
  Room(int number, int type, double price, int number_people, int number_beds)
      : number(number), type(type), price(price), number_people(number_people),
        number_beds(number_beds), available(true), client(nullptr) {}
  virtual ~Room() = default;

  // Constants
  static const int STANDARD = 0;
  static const int DOUBLE = 1;
  static const int SUITE = 2;

  // Getters
  int get_number() const;
  int get_type() const;
  double get_price() const;
  bool is_available() const;
  Client *get_client() const;
  int get_number_people() const;
  int get_number_beds() const;
  virtual int get_discount() const = 0;

  // Setters
  void set_number(int number);
  void set_type(int type);
  void set_price(double price);
  void set_available(bool available);
  void set_client(Client *client);
  void set_number_people(int number_people);
  void set_number_beds(int number_beds);
  virtual void set_discount(int descount) = 0;

  void book(Client *client);
  void release();

};
#endif // !ROOM_H


