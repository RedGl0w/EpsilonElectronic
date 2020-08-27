#include "electronic_controller.h"

namespace Electronic {

bool electronicController::handleEvent(Ion::Events::Event event) {
  if (event == Ion::Events::Back) {
    StackViewController * stack = (StackViewController *)(parentResponder());
    stack->pop();
    return true;
  }
  return false;
}

}
