#include "User.h"
#include "Datetime.h"
#include <sstream>
#include <stdexcept>

using namespace std;

// Constructor de copia
User::User(const User &user) {
  id = user.get_id();
  phone_number = user.get_phone_number();
  name = user.get_name();
  last_name = user.get_last_name();
  email = user.get_email();
  password = user.get_password();
  birthdate = user.get_birthdate();
  type = user.get_type();
}

User::User(int id, std::string name, std::string last_name, std::string email,
           long phone_number, std::string password, Datetime birthdate,
           int type)
    : id(id), name(name), last_name(last_name), email(email),
      phone_number(phone_number), password(password), birthdate(birthdate),
      type(type), is_logged(false) {}

User::User(std::string name, std::string last_name, std::string email,
           long phone_number, std::string password, Datetime birthdate,
           int type)
    : User(-1, name, last_name, email, phone_number, password, birthdate,
           type) {}

int User::get_id() const { return id; }

long User::get_phone_number() const { return phone_number; }

string User::get_name() const { return name; }

string User::get_last_name() const { return last_name; }

string User::get_email() const { return email; }

string User::get_password() const { return password; }

Datetime User::get_birthdate() const { return birthdate; }

int User::get_type() const { return type; }

void User::set_id(int id) { this->id = id; }

void User::set_phone_number(long phone_number) {
  this->phone_number = phone_number;
}

void User::set_name(string name) { this->name = name; }

void User::set_last_name(string last_name) { this->last_name = last_name; }

void User::set_email(string email) { this->email = email; }

void User::set_birthdate(Datetime birthdate) { this->birthdate = birthdate; }

void User::set_type(int type) {
  if (type == ADMINISTRATOR || type == CLIENT)
    this->type = type;
  else
    throw runtime_error("Invalid type");
}

void User::update_password(string current_password, string new_password) {
  if (current_password == get_password())
    this->password = new_password;
  else
    throw runtime_error("Invalid password. Current password is not correct");
}

void User::update_profile(string name, string last_name, string email,
                          long phone_number, Datetime birthdate) {
  set_name(name);
  set_last_name(last_name);
  set_email(email);
  set_phone_number(phone_number);
  set_birthdate(birthdate);
}

bool User::log_in(string email, string password) {
  if (email == get_email() && password == get_password())
    is_logged = true;
  else
    is_logged = false;
  return is_logged;
}

void User::sign_out() { is_logged = false; }

string User::to_string() {
  stringstream ss;
  ss << "Name: " << get_name() << endl;
  ss << "Last Name: " << get_last_name() << endl;
  ss << "Email: " << get_email() << endl;
  ss << "Phone Number: " << get_phone_number() << endl;
  ss << "Birthdate: " << get_birthdate().to_string() << endl;
  ss << "password: " << get_password() << endl;
  return ss.str();
}
