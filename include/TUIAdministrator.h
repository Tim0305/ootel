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
  void update_prices();
  void update_discounts();
  void see_rooms_info();
  void create_room();
  void update_room();
  void delete_room();
  void see_rooms();
  void print_rooms();
  void reservations();
public:
  TUIAdministrator(Ootel* ootel, User* user, TUIManager* manager);
  void run() override;
};

#endif // !TUI_ADMINISTRATOR_H
