#include "battery_view.h"

//TODO Maybe refractor with a blend pixels ?

#include <escher.h>

namespace Electronic {

BatteryView::BatteryView(verticalFormat format) :
  m_format(format)
{}

void BatteryView::drawRect(KDContext * ctx, KDRect rect) const {
  drawCable(ctx,rect);
  drawAnode(ctx,rect);
  drawCathode(ctx,rect);
  drawHoleAnodeCathode(ctx,rect);
}

void BatteryView::drawCable(KDContext * ctx, KDRect rect) const {
  KDPoint pointA = KDPointZero;
  KDPoint pointB = KDPointZero;
  if(m_format == verticalFormat::landscape){
    int middle = rect.y() + rect.height()/2;
    pointA = KDPoint(rect.x(), middle);
    pointB = KDPoint(rect.right(), middle);
  } else {
    assert(m_format == verticalFormat::portrait);
    int middle = rect.x() + rect.width()/2;
    pointA = KDPoint(middle, rect.top());
    pointB = KDPoint(middle, rect.bottom());
  }
  ctx->drawLine(pointA, pointB, KDColorBlack);
}

void BatteryView::drawAnode(KDContext * ctx, KDRect rect) const {
  KDRect anode = KDRectZero;
  KDPoint anodeText = KDPointZero;
  if(m_format == verticalFormat::landscape){
    int middle = rect.x() + rect.width()/2;
    anode = KDRect(middle + k_anodeCathodeGap, rect.top(), k_anodeBold, rect.height());
    anodeText = KDPoint(anode.right() + k_anodeTextGap, anode.height() / 2 - k_anodeTextGap - k_anodeTextGapVerticalLandscape);
  } else {
    assert(m_format == verticalFormat::portrait);
    int middle = rect.y() + rect.height()/2;
    anode = KDRect(rect.left(), middle - k_anodeCathodeGap - k_anodeBold, rect.width(), k_anodeBold);
    anodeText = KDPoint(anode.width() / 2 - k_anodeTextGap - k_anodeTextGapHorizentalPortrait, anode.y() - k_anodeTextGap - k_anodeTextGapVerticalPortrait);
  }
  ctx->fillRect(anode, KDColorBlack);
  ctx->drawString("+", anodeText, KDFont::LargeFont, KDColorRed);
}

void BatteryView::drawCathode(KDContext * ctx, KDRect rect) const {
  KDRect cathode = KDRectZero;
  if(m_format == verticalFormat::landscape){
    int middle = rect.x() + rect.width()/2;
    cathode = KDRect(middle - k_anodeCathodeGap - k_cathodeBold, rect.top() + k_cathodeLength / 2, k_cathodeBold, k_cathodeLength);
  } else {
    assert(m_format == verticalFormat::portrait);
    int middle = rect.y() + rect.height()/2;
    cathode = KDRect(rect.left() + k_cathodeLength / 2, middle + k_anodeCathodeGap + k_cathodeBold, k_cathodeLength, k_cathodeBold);
  }
  ctx->fillRect(cathode, KDColorBlack);
}

void BatteryView::drawHoleAnodeCathode(KDContext * ctx, KDRect rect) const {
  KDRect hole = KDRectZero;
  if(m_format == verticalFormat::landscape){
    int middle = rect.x() + rect.width()/2;
    hole = KDRect(middle - k_anodeCathodeGap, rect.y(), 2*k_anodeCathodeGap, rect.height());
  } else {
    assert(m_format == verticalFormat::portrait);
    int middle = rect.y() + rect.height()/2;
    hole = KDRect(rect.left(), middle - k_anodeCathodeGap, rect.width(), 2*k_anodeCathodeGap);
  }
  ctx->fillRect(hole, Palette::WallScreen);
}

KDSize BatteryView::minimalSizeForOptimalDisplay() const {
  if(m_format == verticalFormat::landscape){
    return KDSize(k_batteryWidth, k_batteryHeight);
  }
  assert(m_format == verticalFormat::portrait);
  return KDSize(k_batteryHeight, k_batteryWidth);
}

}

