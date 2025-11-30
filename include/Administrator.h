#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "Datetime.h"
#include "User.h"
#include <string>

class Administrator : public User {
public:
  Administrator(int id, std::string name, std::string email, long phone_number,
                std::string password, Datetime birthdate)
      : User(id, name, email, phone_number, password, birthdate, User::ADMINISTRATOR) {}
};

#endif // !ADMINISTRATOR_H
