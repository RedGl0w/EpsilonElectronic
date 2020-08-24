#include "electronic_law.h"

namespace Electronic {

bool electronicLaw::handleEvent(Ion::Events::Event event) {
  if (event == Ion::Events::Back) {
    StackViewController * stack = (StackViewController *)(parentResponder());
    stack->pop();
    return true;
  }
  return false;
}

}
