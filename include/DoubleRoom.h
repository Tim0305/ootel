#ifndef DOUBLE_ROOM_H
#define DOUBLE_ROOM_H

#include "Room.h"

class DoubleRoom : public Room {
private:
  static const int PEOPLE = 4;
  static const int BEDS = 2;
  static int DISCOUNT;

public:
  DoubleRoom(int number, double price)
      : Room(number, Room::DOUBLE, price, PEOPLE, BEDS) {}

  // Getters
  int get_discount() override;

  // Setters
  void set_discount(int discount) override;
};

#endif // !DOUBLE_ROOM_H
