#ifndef ELECTRONIC_OHM_LAW_CONTROLLER_H
#define ELECTRONIC_OHM_LAW_CONTROLLER_H

#include <escher.h>
#include "../electronic_law.h"

#include "../shared/battery_view.h"
#include "../shared/resistor_view.h"
#include "../shared/cable_view.h"
#include "../shared/current_view.h"
#include "../../shared/text_field_delegate.h"

namespace Electronic {

class ohmLawController : public electronicLaw, public ViewController {
  public:
    ohmLawController(Responder * parentResponder, InputEventHandlerDelegate * inputEventHandlerDelegate);
    View * view() override;
    bool handleEvent(Ion::Events::Event event) override;
    void didBecomeFirstResponder() override;
    const I18n::Message lawName() override {return I18n::Message::OhmLaw; }

  class ohmLawView : public View, public Shared::TextFieldDelegate, public Responder {
    public:
      ohmLawView(Responder * parentResponder, InputEventHandlerDelegate * inputEventHandlerDelegate);
      void drawRect(KDContext * ctx, KDRect rect) const override;
      void reload();
      int numberOfSubviews() const override;
      View * subviewAtIndex(int index) override;
      int selectionIndex() const {return m_selectionIndex;}
      void setSelectionIndex(int selectionIndex) {m_selectionIndex = selectionIndex; }
      void refreshSelection();
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
      TextField m_fields[3];
      int m_selectionIndex = 0;
  };
  private:
      ohmLawView m_ohmLawView;
    };
}

#endif
