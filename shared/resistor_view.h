#ifndef ELECTRONIC_SHARED_RESISTOR_VIEW_H
#define ELECTRONIC_SHARED_RESISTOR_VIEW_H

#include <escher.h>
#include "components.h"

namespace Electronic {

class ResistorView : public TransparentView {
public:
  ResistorView(verticalFormat format = portrait);
  void drawRect(KDContext * ctx, KDRect rect) const override;
  KDSize minimalSizeForOptimalDisplay() const override;
private:
  verticalFormat m_format;
  constexpr static int k_width = 50;
  constexpr static int k_height = 15;
  constexpr static int k_cableLength = 7;
  constexpr static int k_borderLength = 2;
};

}

#endif

