#ifndef STANDARD_ROOM_H
#define STANDARD_ROOM_H

#include "Room.h"

class StandardRoom : public Room {
private:
  static const int PEOPLE = 2;
  static const int BEDS = 1;
  static int DISCOUNT;

public:
  StandardRoom(int number, double price)
      : Room(number, Room::STANDARD, price, PEOPLE, BEDS) {}

  // Getters
  int get_discount() override;

  // Setters
  void set_discount(int discount) override;
};

#endif // !STANDARD_ROOM_H
