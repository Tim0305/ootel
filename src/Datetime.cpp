#include "Datetime.h"
#include <stdexcept>

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
    if (year < 1) return false;
    if (month < 1 || month > 12) return false;

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
