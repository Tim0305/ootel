#ifndef STANDARD_ROOM_H
#define STANDARD_ROOM_H

#include "Room.h"

class StandardRoom : public Room {
private:
  static const int PEOPLE = 2;
  static const int BEDS = 1;
  static int DISCOUNT;
  static double PRICE;

public:
  StandardRoom(int number) : Room(number, Room::STANDARD, PEOPLE, BEDS) {}

  // Getters
  static int get_discount();
  static double get_price();
  static int get_number_beds();
  static int get_number_people();
  static double get_final_price();

  // Setters
  static void set_discount(int discount);
  static void set_price(double price);

  std::string to_string() override;
};

#endif // !STANDARD_ROOM_H
