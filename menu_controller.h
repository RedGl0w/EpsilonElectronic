#ifndef ELECTRONIC_MENU_CONTROLLER_H
#define ELECTRONIC_MENU_CONTROLLER_H

#include <escher.h>
#include "electronic_law.h"
#include "ohm/ohm_controller.h"

namespace Electronic {

class MenuController : public ViewController, public ListViewDataSource, public SelectableTableViewDataSource {
public:
  MenuController(Responder * parentResponder, InputEventHandlerDelegate * inputEventHandlerDelegate);
  View * view() override;
  bool handleEvent(Ion::Events::Event event) override;
  void didBecomeFirstResponder() override;
  int numberOfRows() const override;
  KDCoordinate rowHeight(int j) override;
  KDCoordinate cumulatedHeightFromIndex(int j) override;
  int indexFromCumulatedHeight(KDCoordinate offsetY) override;
  HighlightCell * reusableCell(int index, int type) override;
  int reusableCellCount(int type) override;
  int typeAtLocation(int i, int j) override;
  void willDisplayCellForIndex(HighlightCell * cell, int index) override;
  void viewWillAppear() override;
private:
  StackViewController * stackController() const;
  I18n::Message promptMessage() const;
  SelectableTableView m_selectableTableView;
  constexpr static int k_numberOfLaws = 1;
  MessageTableCellWithChevronAndMessage m_cells[k_numberOfLaws];
  electronicLaw * lawAtIndex(int index);
  ohmLawController m_ohmController;

};

}

#endif