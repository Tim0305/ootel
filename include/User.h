#ifndef USER_H
#define USER_H

#include "Datetime.h"
#include <string>

class User {
private:
  int id;
  std::string name;
  std::string last_name;
  std::string email;
  long phone_number;
  std::string password;
  Datetime birthdate;
  int type;
  bool is_logged;

public:
  User();
  User(const User &user);
  User(int id, std::string name, std::string last_name, std::string email, long phone_number,
       std::string password, Datetime birthdate, int type)
      : id(id), name(name), last_name(last_name), email(email), phone_number(phone_number),
        password(password), birthdate(birthdate), type(type), is_logged(false) {
  }
  User(std::string name, std::string last_name, std::string email, long phone_number,
       std::string password, Datetime birthdate, int type)
      : User(-1, name, last_name, email, phone_number, password, birthdate, type) {}
  virtual ~User() = default;

  // Constants
  const static int ADMINISTRATOR = 0;
  const static int CLIENT = 1;

  // Getters
  int get_id() const;
  long get_phone_number() const;
  std::string get_name() const;
  std::string get_last_name() const;
  std::string get_email() const;
  std::string get_password() const;
  Datetime get_birthdate() const;
  int get_type() const;

  // Setters
  void set_id(int id);
  void set_phone_number(long phone_number);
  void set_name(std::string name);
  void set_last_name(std::string last_name);
  void set_email(std::string email);
  void set_birthdate(Datetime birthdate);
  void set_type(int type);
  void update_password(std::string current_password, std::string new_password);
  void update_profile(std::string name, std::string email, long phone_number,
                      Datetime birthdate);

  bool log_in(std::string email, std::string password);
  void sign_out();
};

#endif // !USER_H
