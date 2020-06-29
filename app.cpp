#include "app.h"
#include "electronic_icon.h"
#include <apps/i18n.h>

namespace Electronic {

I18n::Message App::Descriptor::name() {
  return I18n::Message::ElectronicApp;
}

I18n::Message App::Descriptor::upperName() {
  return I18n::Message::ElectronicAppCapital;
}

const Image * App::Descriptor::icon() {
  return ImageStore::ElectronicIcon;
}

App * App::Snapshot::unpack(Container * container) {
  return new (container->currentAppBuffer()) App(this);
}

App::Descriptor * App::Snapshot::descriptor() {
  static Descriptor descriptor;
  return &descriptor;
}

App::App(Snapshot * snapshot) :
  Shared::TextFieldDelegateApp(snapshot, &m_stackViewController),
  m_menuController(&m_stackViewController, this),
  m_stackViewController(&m_modalViewController, &m_menuController)
{
}

}
