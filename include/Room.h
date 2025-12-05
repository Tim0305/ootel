#ifndef ROOM_H
#define ROOM_H

#include <string>

class Room {
private:
  int number;
  int type;
  bool available;
  int number_people;
  int number_beds;

public:
  Room(int number, int type, int number_people, int number_beds)
      : number(number), type(type), number_people(number_people),
        number_beds(number_beds), available(true) {}
  virtual ~Room() = default;

  // Constants
  static const int STANDARD = 0;
  static const int DOUBLE = 1;
  static const int SUITE = 2;

  // Getters
  int get_number() const;
  int get_type() const;
  bool is_available() const;
  int get_number_people() const;
  int get_number_beds() const;

  // Setters
  void set_number(int number);
  void set_type(int type);
  void set_available(bool available);
  void set_number_people(int number_people);
  void set_number_beds(int number_beds);
  virtual void update(const Room& room);

  void release();

  virtual std::string to_string();
};
#endif // !ROOM_H
