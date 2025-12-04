#ifndef SUITE_ROOM_H
#define SUITE_ROOM_H

#include "Room.h"

class SuiteRoom : public Room {
private:
  static const int PEOPLE = 8;
  static const int BEDS = 4;
  static int DISCOUNT;
  static double PRICE;

public:
  SuiteRoom(int number) : Room(number, Room::SUITE, PEOPLE, BEDS) {}

  // Getters
  static int get_discount();
  static double get_price();
  static double get_final_price();

  // Setters
  static void set_discount(int discount);
  static void set_price(double price);

  std::string to_string() override;
};

#endif // !SUITE_ROOM_H
