#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <string>
#include "User.h"

using namespace std;

class Administrator : public User{
private:
  string username;
public:
  string get_username();
  void set_username();
  bool update_profile() override;
};

#endif // !ADMINISTRATOR_H
