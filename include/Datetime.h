#ifndef DATETIME_H
#define DATETIME_H

#include <string>

class Datetime {
private:
    int year;
    int month;
    int day;

    static bool is_valid(int year, int month, int day);
    static bool is_leap_year(int year);

public:
    Datetime();  
    Datetime(int year, int month, int day);

    // Getters
    int get_year() const;
    int get_month() const;
    int get_day() const;

    // Setters 
    void set_year(int year);
    void set_month(int month);
    void set_day(int day);
    bool set_date(int year, int month, int day);

    std::string to_string();

    bool operator==(const Datetime& other) const;
    bool operator!=(const Datetime& other) const;
    bool operator<(const Datetime& other) const;
    bool operator>(const Datetime& other) const;
    bool operator<=(const Datetime& other) const;
    bool operator>=(const Datetime& other) const;

    static Datetime now();
};

#endif
