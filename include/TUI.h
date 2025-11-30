#ifndef TUI_H
#define TUI_H

#include "Ootel.h"
#include "TUIManager.h"
#include "User.h"
#include <string>

class TUI {
private:
  Ootel *ootel;
  User *user;
  TUIManager *manager;

public:
  TUI(Ootel *ootel, TUIManager *manager) : TUI(ootel, nullptr, manager) {}
  TUI(Ootel *ootel, User *user, TUIManager *manager)
      : ootel(ootel), user(user), manager(manager) {
    // Limpiar la pantalla
    clear_screen();
  }
  static const std::string BANNER;
  static void clear_screen();
  virtual void print() = 0;
  Ootel *get_ootel();
  User *get_user();
  TUIManager* get_manager();
};

#endif // !TUI_H
