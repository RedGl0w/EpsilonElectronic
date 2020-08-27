#ifndef ELECTRONIC_LAW_H
#define ELECTRONIC_LAW_H

#include <apps/i18n.h>
#include <escher.h>

namespace Electronic {

class electronicController : public ViewController {
  public:
    electronicController(Responder * parentResponder) : ViewController(parentResponder) {}
    virtual const I18n::Message lawName(){return I18n::Message::Default;};
    bool handleEvent(Ion::Events::Event event) override;
};
}

#endif