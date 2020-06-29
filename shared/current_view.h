#ifndef ELECTRONIC_SHARED_CURRENT_VIEW_H
#define ELECTRONIC_SHARED_CURRENT_VIEW_H

#include <escher.h>
#include "components.h"

namespace Electronic {

class CurrentView : public TransparentView {
public:
  CurrentView(verticalFormat format = portrait);
  void drawRect(KDContext * ctx, KDRect rect) const override;
  KDSize minimalSizeForOptimalDisplay() const override;
  constexpr static int k_size = 15;
private:
  verticalFormat m_format;
};

}

#endif

