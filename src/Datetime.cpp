#include "Datetime.h"
#include <chrono>
#include <stdexcept>
#include <string>

using namespace std;

Datetime::Datetime() : year(2000), month(1), day(1) {}

Datetime::Datetime(int year, int month, int day) {
  if (!is_valid(year, month, day))
    throw std::invalid_argument("Invalid date");

  this->year = year;
  this->month = month;
  this->day = day;
}

bool Datetime::is_leap_year(int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool Datetime::is_valid(int year, int month, int day) {
  if (year < 1)
    return false;
  if (month < 1 || month > 12)
    return false;

  int days_in_month[] = {
      31, // Ene
      28, // Feb
      31, // Mar
      30, // Abri
      31, // May
      30, // Jun
      31, // Jul
      31, // Agos
      30, // Sep
      31, // Oct
      30, // Nov
      31  // Dic
  };

  // febrero bisiesto
  if (month == 2 && is_leap_year(year))
    days_in_month[1] = 29;

  if (day < 1 || day > days_in_month[month - 1])
    return false;

  return true;
}

// Getters
int Datetime::get_year() const { return year; }
int Datetime::get_month() const { return month; }
int Datetime::get_day() const { return day; }

// Setters
void Datetime::set_year(int year) {
  if (!is_valid(year, month, day))
    throw std::invalid_argument("Fecha invalida");
  this->year = year;
}

void Datetime::set_month(int month) {
  if (!is_valid(year, month, day))
    throw std::invalid_argument("Fecha invalidad");
  this->month = month;
}

void Datetime::set_day(int day) {
  if (!is_valid(year, month, day))
    throw std::invalid_argument("Fecha invalida");
  this->day = day;
}

bool Datetime::set_date(int year, int month, int day) {
  if (!is_valid(year, month, day))
    return false;

  this->year = year;
  this->month = month;
  this->day = day;
  return true;
}

string Datetime::to_string() {
  return std::to_string(year) + " - " + std::to_string(month) + " - " +
         std::to_string(day);
}

bool Datetime::operator==(const Datetime &other) const {
  return this->year == other.year && this->month == other.month &&
         this->day == other.day;
}

bool Datetime::operator!=(const Datetime &other) const {
  return !(*this == other);
}

bool Datetime::operator<(const Datetime &other) const {
  if (this->year != other.year)
    return this->year < other.year;
  if (this->month != other.month)
    return this->month < other.month;
  return this->day < other.day;
}

bool Datetime::operator>(const Datetime &other) const { return other < *this; }

bool Datetime::operator<=(const Datetime &other) const {
  return !(*this > other);
}

bool Datetime::operator>=(const Datetime &other) const {
  return !(*this < other);
}

Datetime Datetime::now() {
  using namespace chrono;
  auto now = system_clock::now();
  std::time_t t = system_clock::to_time_t(now);
  std::tm *lt = std::localtime(&t);

  return Datetime(lt->tm_year + 1900, lt->tm_mon + 1, lt->tm_mday);
}
