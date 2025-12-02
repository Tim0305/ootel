#ifndef TUI_H
#define TUI_H

#include "Ootel.h"
#include "TUIManager.h"
#include "User.h"
#include <optional>
#include <string>

class TUI {
private:
  Ootel *ootel;
  User *user;
  TUIManager *manager;

public:
  TUI(Ootel *ootel, TUIManager *manager) : TUI(ootel, nullptr, manager) {}
  TUI(Ootel *ootel, User *user, TUIManager *manager);
  virtual ~TUI() = default;

  static const std::string BANNER;
  static void clear_screen();
  static void sleep_for(int seconds);
  static void print_banner();
  static void print_incorrect_option();
  static void press_enter_continue();
  virtual void print() = 0;
  std::optional<User> user_form();
  Ootel *get_ootel();
  User *get_user();
  TUIManager* get_manager();
};

#endif // !TUI_H
