#ifndef TUI_ADMINISTRATOR_H
#define TUI_ADMINISTRATOR_H

#include "TUI.h"
class TUIAdministrator: public TUI{
private:
  void users();
  void create_administrator();
  void update_administrator();
  void delete_administrator();
  void see_administrators();
  void print_administrators();
  void rooms();
  void reservations();
public:
  TUIAdministrator(Ootel* ootel, User* user, TUIManager* manager);
  void run() override;
};

#endif // !TUI_ADMINISTRATOR_H
