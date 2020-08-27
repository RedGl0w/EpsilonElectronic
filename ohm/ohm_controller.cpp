#include "ohm_controller.h"
#include <assert.h>
#include <kandinsky/color.h>
#include <escher.h>


namespace Electronic {

ohmLawController::ohmLawController(Responder * parentResponder, InputEventHandlerDelegate * inputEventHandlerDelegate) :
  electronicController(parentResponder),
  m_ohmLawView(inputEventHandlerDelegate)
{
}

View * ohmLawController::view() {
  return &m_ohmLawView;
}


ohmLawController::ohmLawView::ohmLawView(InputEventHandlerDelegate * inputEventHandlerDelegate) :
  View(),
  m_batteryView(verticalFormat::landscape),
  m_currentView(verticalFormat::portrait),
  m_resistorView(verticalFormat::landscape),
  m_subViews{&m_batteryView, &m_topRightCable, &m_rightCable, &m_currentView, &m_bottomRightCable, &m_resistorView,
                  &m_bottomLeftCable, &m_leftCable, &m_topLeftCable}
  {}

void ohmLawController::ohmLawView::drawRect(KDContext * ctx, KDRect rect) const {
  ctx->fillRect(KDRect(0, 0, bounds().width(), bounds().height()), Palette::WallScreen);
}

void ohmLawController::ohmLawView::reload() {
  markRectAsDirty(bounds());
}

int ohmLawController::ohmLawView::numberOfSubviews() const {
  return sizeof(m_subViews)/sizeof(View*);
}

View * ohmLawController::ohmLawView::subviewAtIndex(int index) {
  assert(index > 0 && index < 9);
  return m_subViews[index];
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
}

void ohmLawController::didBecomeFirstResponder() {
}

bool ohmLawController::handleEvent(Ion::Events::Event event) {
  return electronicController::handleEvent(event);
}

}
