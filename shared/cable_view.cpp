#include "cable_view.h"

#include <escher.h>

namespace Electronic {

void CableView::drawRect(KDContext * ctx, KDRect rect) const {
  ctx->fillRect(rect, KDColorBlack);
}

KDSize CableView::sizeForOrientationAndBold(verticalFormat format, int length) const {
  if(format == verticalFormat::landscape){
    return KDSize(length, k_cableBold);
  }
  assert(format == verticalFormat::portrait);
  return KDSize(k_cableBold, length);
}

}

