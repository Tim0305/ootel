#ifndef TUI_MANAGER_H
#define TUI_MANAGER_H

#include <vector>

// Forward declarations
class TUI;

class TUIManager{
private:
  std::vector<TUI*> stack_views;
  TUI* current_view;
public:
  TUIManager() : current_view(nullptr) {}
  ~TUIManager();
  void go_to(TUI* view);
  void go_back();
  TUI* get_current_view();
};

#endif // !TUI_MANAGER_H
