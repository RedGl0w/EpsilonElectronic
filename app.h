#ifndef ELECTRONIC_APP_H
#define ELECTRONIC_APP_H

#include "menu_controller.h"
#include "../shared/text_field_delegate_app.h"

namespace Electronic {

class App : public Shared::TextFieldDelegateApp {
public:
  class Descriptor : public ::App::Descriptor {
  public:
    I18n::Message name() override;
    I18n::Message upperName() override;
    const Image * icon() override;
  };
  class Snapshot : public ::App::Snapshot {
  public:
    App * unpack(Container * container) override;
    Descriptor * descriptor() override;
  };
private:
  App(Snapshot * snapshot);
  MenuController m_menuController;
  StackViewController m_stackViewController;
};

}

#endif
