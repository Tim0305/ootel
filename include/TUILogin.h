#ifndef TUI_LOGIN_H
#define TUI_LOGIN_H

#include "TUI.h"

class TUILogin : public TUI {
private:
  void login();
  void signup();
  void print_menu();
public:
  TUILogin(Ootel *ootel, TUIManager *manager) : TUI(ootel, manager) {}
  void print() override;
};

#endif // !TUI_LOGIN_H
