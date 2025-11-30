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

    // Setter completo
    bool set_date(int year, int month, int day);
};

#endif
