#include "TUI.h"
#include "TUIManager.h"
#include <iostream>

using namespace std;

const string TUI::BANNER = R"(
    ███████       ███████    ███████████ ██████████ █████      
  ███░░░░░███   ███░░░░░███ ░█░░░███░░░█░░███░░░░░█░░███       
 ███     ░░███ ███     ░░███░   ░███  ░  ░███  █ ░  ░███       
░███      ░███░███      ░███    ░███     ░██████    ░███       
░███      ░███░███      ░███    ░███     ░███░░█    ░███       
░░███     ███ ░░███     ███     ░███     ░███ ░   █ ░███      █
 ░░░███████░   ░░░███████░      █████    ██████████ ███████████
   ░░░░░░░       ░░░░░░░       ░░░░░    ░░░░░░░░░░ ░░░░░░░░░░░ 
)";

void TUI::clear_screen() { cout << "\033[2J\033[1;1H"; }

Ootel* TUI::get_ootel() {
  return ootel;
}

User* TUI::get_user() {
  return user;
}

TUIManager* TUI::get_manager() {
  return manager;
}
