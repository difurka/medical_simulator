#include "paintwidget.h"

#include "utils/utils.h"

PaintWidget::PaintWidget(QWidget *parent)
  : QWidget{parent}
  , controller_(nullptr)
{
    pixmap_ = QPixmap(kMaxSize, kMaxSize);
    pen_ = std::make_unique<QPen>( QPen(Qt::white, kDefaultPenWidth, Qt::SolidLine, Qt::SquareCap, Qt::RoundJoin));


//    Clear();
//    QPainter painter{&pixmap_};


//    pen_->setWidth(1);
//    pen_->setColor(back_area_);
//    painter.setPen(*pen_);
//    painter.setBrush(Qt::green);

//   for (size_t i = 0; i < kMaxSize; ++i) {
//     for (size_t j = 0; j < kMaxSize; ++j) {
//           painter.drawPoint(i, j);
//       }
//   }
//  update();

}

 void PaintWidget::paintEvent(QPaintEvent *event)   // override
 {
   QPainter painter(this);
//    pen_->setColor(back_area_);
//    painter.setPen(*pen_);
   painter.drawPixmap(0, 0, pixmap_);
   update();
 }

 void PaintWidget::resizeEvent(QResizeEvent *event)   // override
 {
  auto newRect = pixmap_.rect().united(rect());
  if (!(newRect == pixmap_.rect())) {
    QPixmap newPixmap{newRect.size()};
    QPainter painter{&newPixmap};
    painter.fillRect(newPixmap.rect(), Qt::white);
    painter.drawPixmap(0, 0, pixmap_);
    pixmap_ = newPixmap;
  }
}


void PaintWidget::Clear()
{
  pixmap_.fill(Qt::red);
  this->clearMask();
}

void PaintWidget::DrawFigure(figure_t type)
{

    Clear();
    QPainter painter{&pixmap_};
   auto matrix = controller_->GetMatr();
   for (size_t i = 0; i < kMaxSize; ++i)
     for (size_t j = 0; j < kMaxSize; ++j) {
       if (matrix[i][j] == 2) {
           pen_->setColor(pixel_area_);
           painter.setPen(*pen_);
        painter.drawPoint(i, j);
       } else if (matrix[i][j] == 1) {
           pen_->setColor(back_area_);
           painter.setPen(*pen_);
           painter.drawPoint(i, j);
         } else {
           pen_->setColor(Qt::white);
           painter.setPen(*pen_);
           painter.drawPoint(i, j);
       }
   }
  update();

}



void PaintWidget::SetController(Controller* controller)
{
    controller_ = controller;
}

void PaintWidget::SetBackArea(QColor back_area)
{
    back_area_ = back_area;
}
void PaintWidget::SetPixelArea(QColor pixel_area)
{
    pixel_area_ = pixel_area;
}

