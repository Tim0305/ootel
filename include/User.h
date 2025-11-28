#ifndef USER_H
#define USER_H

#include "Datetime.h"
#include <string>

class User {
private:
  int id;
  std::string name;
  std::string email;
  long phone_number;
  std::string password;
  Datetime birthdate;
  int type;
  bool is_logged;

public:
  User(int id, std::string name, std::string email, long phone_number,
       std::string password, Datetime birthdate, int type)
      : id(id), name(name), email(email), phone_number(phone_number),
        password(password), birthdate(birthdate), type(type), is_logged(false) {}
  virtual ~User() = default;

  // Constants
  const static int ADMINISTRATOR = 0;
  const static int CLIENT = 1;

  // Getters
  int get_id();
  long get_phone_number();
  std::string get_name();
  std::string get_email();
  std::string get_password();
  Datetime get_birthdate();
  int get_type();

  // Setters
  void set_id(int id);
  void set_phone_number(long phone_number);
  void set_name(std::string name);
  void set_email(std::string email);
  void set_birthdate(Datetime birthdate);
  void set_type(int type);
  void update_password(std::string current_password, std::string new_password);
  void update_profile(std::string name, std::string email, long phone_number,
                      Datetime birthdate);

  bool login(std::string email, std::string password);
  void sign_out();
};

#endif // !USER_H
