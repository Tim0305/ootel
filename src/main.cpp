#include "Ootel.h"
#include "TUILogin.h"
#include "TUIManager.h"

using namespace std;

int main() {
  Ootel *ootel = new Ootel("Mexico", "Jalisco", 54321);
  TUIManager *manager = new TUIManager();

  manager->go_to(new TUILogin(ootel, manager));

  // main loop
  do {
    manager->get_current_view()->print();
  } while (manager->get_current_view() != nullptr);

  return 0;
}
