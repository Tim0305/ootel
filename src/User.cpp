#include "User.h"
#include "Datetime.h"
#include <stdexcept>

using namespace std;

int User::get_id() {
  return id;
}

long User::get_phone_number() {
  return phone_number;
}

string User::get_name() {
  return name;
}

string User::get_email() {
  return email;
}

string User::get_password() {
  return password;
}

Datetime User::get_birthdate() {
  return birthdate;
}

int User::get_type() {
  return type;
}

void User::set_id(int id) {
  this->id = id;
}

void User::set_phone_number(long phone_number) {
  this->phone_number = phone_number;
}

void User::set_name(string name) {
  this->name = name;
}

void User::set_birthdate(Datetime birthdate) {
  this->birthdate = birthdate;
}

void User::set_type(int type) {
  if (type == ADMINISTRATOR || type == CLIENT)
    this->type = type;
  else
    throw runtime_error("Invalid type");
}

void User::update_password(string current_password, string new_password) {
  if (current_password == get_password())
    this->password = new_password;
}

void User::update_profile(string name, string email, long phone_number, Datetime birthdate) {
  set_name(name);
  set_email(email);
  set_phone_number(phone_number);
  set_birthdate(birthdate);
}

bool User::login(string email, string password) {
  if (email == get_email() && password == get_password())
    is_logged = true;
  else
    is_logged = false;
  return is_logged;
}

void User::sign_out() {
  is_logged = false;
}
