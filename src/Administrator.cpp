#include "Administrator.h"
#include <sstream>

using namespace std;

Administrator::Administrator(const User& user): User(user) {
  set_type(User::ADMINISTRATOR);
}

string Administrator::to_string() {
  stringstream ss;
  ss << "ID: " << get_id() << endl;
  ss << User::to_string();
  return ss.str();
}
