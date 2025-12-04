#ifndef TUI_CLIENT_H
#define TUI_CLIENT_H
  
#include "TUI.h"
#include "TUIManager.h"
#include <vector>

class TUIClient : public TUI{
private:
  void reservations();
  void bank_cards();
  void see_reservations();
  void print_reservations(std::vector<Reservation> reservations);
  void sign_out();
  void profile();
  void update_profile();
  void add_bank_card();
  void select_bank_card();
  void update_bank_card();
  void delete_bank_card();
  void print_bank_cards();
  void see_bank_cards();
  void book();
  void update_reservation();
  void delete_reservation();
public:
  TUIClient(Ootel* ootel, User* user, TUIManager* manager);
  void run() override;
};
#endif // !TUI_CLIENT_H
