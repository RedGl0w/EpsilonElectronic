#ifndef ELECTRONIC_LAW_H
#define ELECTRONIC_LAW_H

#include <apps/i18n.h>
#include <escher.h>

namespace Electronic {

class electronicLaw {
  public:
    virtual const I18n::Message lawName(){return I18n::Message::Default;};
};
}

#endif