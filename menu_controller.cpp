#include "menu_controller.h"
#include <apps/i18n.h>
#include <assert.h>

namespace Electronic {

MenuController::MenuController(Responder * parentResponder, InputEventHandlerDelegate * inputEventHandlerDelegate) :
  ViewController(parentResponder),
  m_selectableTableView(this),
  m_ohmController(this)
{
  for (int i = 0; i < k_numberOfLaws; i++) {
    m_cells[i].setMessageFont(KDFont::LargeFont);
  }
}

View * MenuController::view() {
  return &m_selectableTableView;
}

void MenuController::didBecomeFirstResponder() {
  if (selectedRow() < 0) {
    selectCellAtLocation(0, 0);
  }
  Container::activeApp()->setFirstResponder(&m_selectableTableView);
}

bool MenuController::handleEvent(Ion::Events::Event event) {
  if(event == Ion::Events::OK || event == Ion::Events::EXE){
    stackController()->push(static_cast<ViewController*>(&m_ohmController));
    return true;
  }
  return false;
}

int MenuController::numberOfRows() const {
  return k_numberOfLaws;
};

KDCoordinate MenuController::rowHeight(int j) {
  return Metric::ParameterCellHeight;
}

KDCoordinate MenuController::cumulatedHeightFromIndex(int j) {
  KDCoordinate height = j * rowHeight(0);
  return height;
}

int MenuController::indexFromCumulatedHeight(KDCoordinate offsetY) {
  return offsetY/rowHeight(0);
}

HighlightCell * MenuController::reusableCell(int index, int type) {
  assert(index >= 0 && type == 0 && index < k_numberOfLaws);
  return &m_cells[index];
}

int MenuController::reusableCellCount(int type) {
  assert(type == 0);
  return k_numberOfLaws;
}

int MenuController::typeAtLocation(int i, int j) {
  return 0;
}

void MenuController::willDisplayCellForIndex(HighlightCell * cell, int index) {
  MessageTableCell * myCell = (MessageTableCell *)cell;
  myCell->setMessage(m_ohmController.lawName());
}

void MenuController::viewWillAppear() {
  ViewController::viewWillAppear();
  m_selectableTableView.reloadData();
}

StackViewController * MenuController::stackController() const {
  return (StackViewController *)parentResponder();
}
/* 
electronicLaw * MenuController::lawAtIndex(int index){
  switch (index){
    case 1 : {
      return &m_ohmController;
    }
    default : {
      assert(false);
    }
  }
} */

}