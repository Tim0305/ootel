#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User{
private:
  int id;
  string name;
  string email;
  long phone_number;
  string password;
  string birthdate;
  int tipo;
public:
  User();
  const static int ADMINISTRATOR;
  const static int CLIENT;
  int get_id();
  long get_phone_number();
  string get_name();
  string get_email();
  string get_password();
  string get_birthdate();
  void set_id(int id);
  void set_phone_number(long phone_numer);
  void set_name(string name);
  void set_email(string email);
  void set_birthdate(string birthdate);
  bool login(string username, string password);
  bool sign_out();
  virtual bool update_profile(string name, string email, long phone_number, string birthdate);
  bool update_password(string password, string new_password);
};

#endif // !USER_H
