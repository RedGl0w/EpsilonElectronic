#ifndef ELECTRONIC_SHARED_CABLE_VIEW_H
#define ELECTRONIC_SHARED_CABLE_VIEW_H

#include <escher.h>
#include "components.h"

namespace Electronic {

class CableView : public TransparentView {
public:
  void drawRect(KDContext * ctx, KDRect rect) const override;
  KDSize sizeForOrientationAndBold(verticalFormat format, int length) const;
  constexpr static int k_cableBold = 1;
};

}

#endif

