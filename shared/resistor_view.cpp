#include "resistor_view.h"

#include <escher.h>

namespace Electronic {

ResistorView::ResistorView(verticalFormat format) :
  m_format(format)
{}

void ResistorView::drawRect(KDContext * ctx, KDRect rect) const {

  //Drawing the cable
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

  //Filling the big black rect

  KDRect blackRect = KDRectZero;
  if(m_format == verticalFormat::landscape){
    blackRect = KDRect(rect.x() + k_cableLength, rect.y(), rect.width() - 2*k_cableLength, rect.height());
  } else {
    assert(m_format == verticalFormat::portrait);
    blackRect = KDRect(rect.x(), rect.y() + k_cableLength, rect.width(), rect.height() - 2*k_cableLength);
  }
  ctx->fillRect(blackRect, KDColorBlack);

  //Filling the small white rect
  blackRect.setOrigin(KDPoint(blackRect.x() + k_borderLength, blackRect.y() + k_borderLength));
  blackRect.setSize(KDSize(blackRect.width() - 2*k_borderLength, blackRect.height() - 2*k_borderLength));
  ctx->fillRect(blackRect, KDColorWhite);
}

KDSize ResistorView::minimalSizeForOptimalDisplay() const {
  if(m_format == verticalFormat::landscape){
    return KDSize(k_width, k_height);
  }
  assert(m_format == verticalFormat::portrait);
  return KDSize(k_height, k_width);
}

}

