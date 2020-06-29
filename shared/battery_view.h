#ifndef ELECTRONIC_SHARED_BATTERY_VIEW_H
#define ELECTRONIC_SHARED_BATTERY_VIEW_H

#include <escher.h>
#include "components.h"

namespace Electronic {

class BatteryView : public TransparentView {
public:
  BatteryView(verticalFormat format = portrait);
  void drawRect(KDContext * ctx, KDRect rect) const override;
  KDSize minimalSizeForOptimalDisplay() const override;
private:
  verticalFormat m_format;
  constexpr static KDCoordinate k_batteryWidth = 50;
  constexpr static KDCoordinate k_batteryHeight = 30;
  void drawCable(KDContext * ctx, KDRect rect) const;
  constexpr static int k_anodeCathodeGap = 4/2; //The gap is not the space between anode and cathode, but the gap between middle of space and cathode / anode
  constexpr static int k_anodeBold = 2;
  constexpr static int k_anodeLength = k_batteryHeight;
  constexpr static int k_anodeTextGap = 4;
  constexpr static int k_anodeTextGapHorizentalPortrait = 7;
  constexpr static int k_anodeTextGapVerticalPortrait = 14;
  constexpr static int k_anodeTextGapVerticalLandscape = 14;
  void drawAnode(KDContext * ctx, KDRect rect) const;
  constexpr static int k_cathodeBold = 2;
  constexpr static int k_cathodeLength = k_batteryHeight / 2;
  void drawCathode(KDContext * ctx, KDRect rect) const;
  void drawHoleAnodeCathode(KDContext * ctx, KDRect rect) const;
};

}

#endif

