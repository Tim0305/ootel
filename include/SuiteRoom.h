#ifndef SUITE_ROOM_H
#define SUITE_ROOM_H

#include "Room.h"

class SuiteRoom : public Room {
private:
  static const int PEOPLE = 8;
  static const int BEDS = 4;
  static int DISCOUNT;

public:
  SuiteRoom(int number, double price)
      : Room(number, Room::SUITE, price, PEOPLE, BEDS) {}

  // Getters
  int get_discount() override;

  // Setters
  void set_discount(int discount) override;
};

#endif // !SUITE_ROOM_H
