#ifndef DATETIME_H
#define DATETIME_H

class Datetime {
private:
  int year;
  int month;
  int day;
  static bool is_valid(int year, int month, int day);
  static bool is_leap_year(int year);

public:
  // Getters
  int get_year();
  int get_month();
  int get_day();

  // Setters
  void set_year();
  void set_month();
  void set_day();
};

#endif // !DATETIME_H
