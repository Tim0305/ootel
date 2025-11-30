#ifndef TUI_CLIENT_H
#define TUI_CLIENT_H
  
#include "TUI.h"
#include "TUIManager.h"

class TUIClient : public TUI{
public:
  TUIClient(Ootel* ootel, User* user, TUIManager* manager): TUI(ootel, user, manager){}
  void print() override;
};
#endif // !TUI_CLIENT_H
