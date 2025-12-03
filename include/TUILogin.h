#ifndef TUI_LOGIN_H
#define TUI_LOGIN_H

#include "TUI.h"

class TUILogin : public TUI {
private:
  void log_in();
  void create_account();
public:
  TUILogin(Ootel *ootel, TUIManager *manager) : TUI(ootel, manager) {}
  void run() override;
};

#endif // !TUI_LOGIN_H
