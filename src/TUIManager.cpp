#include "TUIManager.h"
#include "TUI.h"

using namespace std;
TUIManager::~TUIManager() {
  for (TUI* tui: stack_views)
    delete tui;
  stack_views.clear();
}

void TUIManager::go_to(TUI* view) {
  stack_views.push_back(view);
  current_view = view;
}

void TUIManager::go_back() {
  if (stack_views.empty()) return;
  
  stack_views.pop_back();

  if (stack_views.empty())
    current_view = nullptr;
  else
    current_view = stack_views.back();
}

TUI* TUIManager::get_current_view() {
  return current_view;
}
