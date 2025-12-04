#ifndef DOUBLE_ROOM_H
#define DOUBLE_ROOM_H

#include "Room.h"

class DoubleRoom : public Room {
private:
  static const int PEOPLE = 4;
  static const int BEDS = 2;
  static int DISCOUNT;
  static double PRICE;

public:
  DoubleRoom(int number) : Room(number, Room::DOUBLE, PEOPLE, BEDS) {}

  // Getters
  static int get_discount();
  static double get_price();
  static double get_final_price();

  // Setters
  static void set_discount(int discount);
  static void set_price(double price);

  std::string to_string() override;
};

#endif // !DOUBLE_ROOM_H
