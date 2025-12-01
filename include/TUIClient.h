#ifndef TUI_CLIENT_H
#define TUI_CLIENT_H
  
#include "TUI.h"
#include "TUIManager.h"

class TUIClient : public TUI{
private:
  void reservations();
  void bank_cards();
  void print_reservations();
  void sign_out();
  void profile();
public:
  TUIClient(Ootel* ootel, User* user, TUIManager* manager): TUI(ootel, user, manager){}
  void print() override;
};
#endif // !TUI_CLIENT_H
