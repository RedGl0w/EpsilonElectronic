#include "ohm_controller.h"
#include <assert.h>
#include <kandinsky/color.h>
#include <escher.h>
#include <iostream>


namespace Electronic {

ohmLawController::ohmLawController(Responder * parentResponder, InputEventHandlerDelegate * inputEventHandlerDelegate) :
  ViewController(parentResponder),
  m_ohmLawView(this, inputEventHandlerDelegate)
{
}

View * ohmLawController::view() {
  return &m_ohmLawView;
}


ohmLawController::ohmLawView::ohmLawView(Responder * parentResponder, InputEventHandlerDelegate * inputEventHandlerDelegate) :
  View(),
  m_batteryView(verticalFormat::landscape),
  m_currentView(verticalFormat::portrait),
  m_resistorView(verticalFormat::landscape),
  Responder(parentResponder),
  m_fields({TextField(this, nullptr, TextField::maxBufferSize(), TextField::maxBufferSize(), inputEventHandlerDelegate, this),
  TextField(this, nullptr, TextField::maxBufferSize(), TextField::maxBufferSize(), inputEventHandlerDelegate, this),
  TextField(this, nullptr, TextField::maxBufferSize(), TextField::maxBufferSize(), inputEventHandlerDelegate, this)})
{}

void ohmLawController::ohmLawView::drawRect(KDContext * ctx, KDRect rect) const {
  ctx->fillRect(KDRect(0, 0, bounds().width(), bounds().height()), Palette::WallScreen);
}

void ohmLawController::ohmLawView::reload() {
  markRectAsDirty(bounds());
}

int ohmLawController::ohmLawView::numberOfSubviews() const {
  return 12;
}

View * ohmLawController::ohmLawView::subviewAtIndex(int index) {
  switch(index) {
    case 0 : {
      return &m_batteryView;
    }
    case 1 : {
      return &m_topRightCable;
    }
    case 2 : {
      return &m_rightCable;
    }
    case 3 : {
      return &m_currentView;
    }
    case 4 : {
      return &m_bottomRightCable;
    }
    case 5 : {
      return &m_resistorView;
    }
    case 6 : {
      return &m_bottomLeftCable;
    }
    case 7 : {
      return &m_leftCable;
    }
    case 8 : {
      return &m_topLeftCable;
    }
    case 9 : {
      return &m_fields[0];
    }
    case 10 : {
      return &m_fields[1];
    }
    case 11 : {
      return &m_fields[2];
    }
    default : {
      assert(false);
      return nullptr;
    }
  }
}

void ohmLawController::ohmLawView::layoutSubviews(bool force) {
  m_batteryView.setFrame(KDRect(135,20, m_batteryView.minimalSizeForOptimalDisplay()), force);
  m_topRightCable.setFrame(KDRect(184, 35, m_topRightCable.sizeForOrientationAndBold(verticalFormat::landscape, 105)), force);
  m_rightCable.setFrame(KDRect(289, 35, m_rightCable.sizeForOrientationAndBold(verticalFormat::portrait, 170)), force);
  m_currentView.setFrame(KDRect(282, 105, m_currentView.minimalSizeForOptimalDisplay()), force);
  m_bottomRightCable.setFrame(KDRect(184,205, m_bottomRightCable.sizeForOrientationAndBold(verticalFormat::landscape, 105)), force);
  m_resistorView.setFrame(KDRect(135,198, m_resistorView.minimalSizeForOptimalDisplay()), force);
  m_bottomLeftCable.setFrame(KDRect(30,205, m_bottomLeftCable.sizeForOrientationAndBold(verticalFormat::landscape, 105)), force);
  m_leftCable.setFrame(KDRect(30,35, m_leftCable.sizeForOrientationAndBold(verticalFormat::portrait, 170)), force);
  m_topLeftCable.setFrame(KDRect(30, 35, m_topLeftCable.sizeForOrientationAndBold(verticalFormat::landscape, 105)), force);
  m_fields[0].setFrame(KDRect(140, 50, m_fields[0].minimalSizeForOptimalDisplay()), force);
  m_fields[1].setFrame(KDRect(140, 70, m_fields[1].minimalSizeForOptimalDisplay()), force);
  m_fields[2].setFrame(KDRect(140, 90, m_fields[2].minimalSizeForOptimalDisplay()), force);
}

void ohmLawController::ohmLawView::refreshSelection(){
  for(int i = 0; i < sizeof(m_fields) / sizeof(TextField); i++){
    m_fields[i].setBackgroundColor(i == m_selectionIndex ? KDColorBlack : KDColorWhite);
    m_fields[i].setText("wow");
  }
  std::cout << m_selectionIndex << std::endl;
}

void ohmLawController::didBecomeFirstResponder() {
}

bool ohmLawController::handleEvent(Ion::Events::Event event) {
  if (event == Ion::Events::Back) {
    StackViewController * stack = (StackViewController *)(parentResponder());
    stack->pop();
    return true;
  }
  if((event == Ion::Events::Up && m_ohmLawView.selectionIndex() > 0) || (event == Ion::Events::Down && m_ohmLawView.selectionIndex() < 2)){
    int direction = event == Ion::Events::Up ? (-1) : (+1);
    m_ohmLawView.setSelectionIndex(m_ohmLawView.selectionIndex() + direction);
    m_ohmLawView.refreshSelection();
    return true;
  }
  return false;
}

}
