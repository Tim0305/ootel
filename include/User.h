#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
  int id;
  std::string name;
  std::string email;
  long phone_number;
  std::string password;
  std::string birthdate;
  int tipo;

public:
  User(int id, std::string name, std::string email, long phone_number,
       std::string password, std::string birthdate);
  virtual ~User() = default;

  // Constants
  const static int ADMINISTRATOR;
  const static int CLIENT;

  // Getters
  int get_id();
  long get_phone_number();
  std::string get_name();
  std::string get_email();
  std::string get_password();
  std::string get_birthdate();

  // Setters
  void set_id(int id);
  void set_phone_number(long phone_number);
  void set_name(std::string name);
  void set_email(std::string email);
  void set_birthdate(std::string birthdate);
  void update_password(std::string current_password, std::string new_password);
  virtual void update_profile(std::string name, std::string email,
                              long phone_number, std::string birthdate) = 0;

  bool login(std::string username, std::string password);
  bool sign_out();
};

#endif // !USER_H
