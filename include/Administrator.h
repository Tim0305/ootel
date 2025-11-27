#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "User.h"
#include <string>

class Administrator : public User {
private:
  std::string username;

public:
  Administrator(int id, std::string name, std::string email, long phone_number,
                std::string password, std::string birthdate,
                std::string username)
      : User(id, name, email, phone_number, password, birthdate),
        username(username) {}

  // Getters
  std::string get_username();

  // Setters
  void set_username(std::string username);
  void update_profile(std::string name, std::string email, long phone_number,
                      std::string birthdate) override;
};

#endif // !ADMINISTRATOR_H
