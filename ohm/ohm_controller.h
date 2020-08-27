#ifndef ELECTRONIC_OHM_LAW_CONTROLLER_H
#define ELECTRONIC_OHM_LAW_CONTROLLER_H

#include <escher.h>
#include "../electronic_controller.h"

#include "../shared/battery_view.h"
#include "../shared/resistor_view.h"
#include "../shared/cable_view.h"
#include "../shared/current_view.h"

namespace Electronic {

class ohmLawController : public electronicController {
  public:
    ohmLawController(Responder * parentResponder, InputEventHandlerDelegate * inputEventHandlerDelegate);
    View * view() override;
    bool handleEvent(Ion::Events::Event event) override;
    void didBecomeFirstResponder() override;
    const I18n::Message lawName() override {return I18n::Message::OhmLaw; }

  class ohmLawView : public View {
    public:
      ohmLawView(InputEventHandlerDelegate * inputEventHandlerDelegate);
      void drawRect(KDContext * ctx, KDRect rect) const override;
      void reload();
      int numberOfSubviews() const override;
      View * subviewAtIndex(int index) override;
    private:
      void layoutSubviews(bool force = false) override;
      BatteryView m_batteryView;
      CableView m_topRightCable;
      CableView m_rightCable;
      CurrentView m_currentView;
      CableView m_bottomRightCable;
      ResistorView m_resistorView;
      CableView m_bottomLeftCable;
      CableView m_leftCable;
      CableView m_topLeftCable;
      View * m_subViews[9];
  };
  private:
      ohmLawView m_ohmLawView;
    };
}

#endif
