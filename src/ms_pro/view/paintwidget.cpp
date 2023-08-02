#include "paintwidget.h"


PaintWidget::PaintWidget(QWidget *parent)
  : QWidget{parent}
  , controller_(nullptr)
{
  //  pen_ = new QPen(Qt::white, kDefaultPenWidth, Qt::SolidLine, Qt::SquareCap, Qt::RoundJoin);
  pen_ = std::make_unique<QPen>( QPen(Qt::white, kDefaultPenWidth, Qt::SolidLine, Qt::SquareCap, Qt::RoundJoin));
}

void PaintWidget::paintEvent(QPaintEvent *event) {  // override
  QPainter painter(this);
  painter.drawPixmap(0, 0, pixmap_);
  this->update();
}

void PaintWidget::resizeEvent(QResizeEvent *event)  {  // override
  auto newRect = pixmap_.rect().united(rect());
  if (!(newRect == pixmap_.rect())) {
    QPixmap newPixmap{newRect.size()};
    QPainter painter{&newPixmap};
    painter.fillRect(newPixmap.rect(), Qt::black);
    painter.drawPixmap(0, 0, pixmap_);
    pixmap_ = newPixmap;
  }
}





void PaintWidget::Draw(const QPoint& pos) {
  QPainter painter{&pixmap_};
//  painter.setPen(*pen_);
  painter.drawPoint(pos);
  update();
}

void PaintWidget::Clear() {
  pixmap_.fill(Qt::black);
  this->clearMask();
}

void PaintWidget::DrawObject(Model::Type type) {
//  Clear();
//  auto& object = controller_->GetObj();
//  if (type == Model::Type::kCave) {
//    DrawCave(object.GetData(), object.GetSize(), object.GetRows(), object.GetColumns());
//  } else if (type == Model::Type::kMaze) {
////    is_have_start_point_ = false;
//    DrawMaze(object.GetData(), object.GetSize(), object.GetColumns());
//  }
}



void PaintWidget::DrawLine(QPainter *painter, const std::vector<bool>& vertical,
          const std::vector<bool>& horizontal, int line_number, int cols_number) {
  const int kStepH = kAreaSize/horizontal.size();
  const int kStepV = kAreaSize/cols_number;
  int hx = 0;
  int hy = kStepV + (kStepV * line_number);
  int vx = kStepH;
  int vy = 0 + (kStepV * line_number);
  for (size_t i = 0; i < vertical.size(); ++i) {
    if  (horizontal[i] && line_number != cols_number - 1) painter->drawLine(hx, hy, hx+kStepH, hy);
    hx += kStepH;
    if (vertical[i] && i!= vertical.size() - 1) painter->drawLine(vx, vy, vx, vy+kStepV);
    vx += kStepH;
  }
}



void  PaintWidget::DrawCave(const std::vector<bool>& data, size_t size, size_t rows, size_t columns) {
//  mouse_event_ = false;
  size_t k = 0;
  std::vector<std::vector<bool>> cells = Converter(&k, columns, size, data);

  const double kStepH = kAreaSize / columns;
  const double kStepV = kAreaSize / rows;
  QPainter painter{&pixmap_};

//  pen_->setWidth(0);
//  pen_->setColor(Qt::white);
//  painter.setPen(*pen_);
  painter.setBrush(QBrush("#FFF"));

  for (size_t i = 0; i < rows; ++i)
    for (size_t j = 0; j < columns; ++j) {
      if (cells[i][j]) painter.drawRect(QRect(j * kStepH, i * kStepV, kStepH, kStepV));
  }
  update();
}

void PaintWidget::SetController(Controller* controller) {
  controller_ = controller;
}

std::vector<std::vector<bool>> PaintWidget::Converter(
                size_t *index, size_t line_size,
                size_t size, const std::vector<bool>& data) {
  std::vector<std::vector<bool>> result;
  for (int k = -1; *index < size; ++(*index)) {
    if (*index % line_size == 0) {
      result.push_back(std::vector<bool>());
      ++k;
    }
    result[k].push_back(data[*index]);
  }
  return result;
}

// void PaintWidget::SetPathPoint(QMouseEvent* event) {
//   lastPos_ = event->pos();
//   const size_t kStepH = kAreaSize / controller_->GetColumns();
//   const size_t kStepV = kAreaSize / controller_->GetRows();
//   int current_x = lastPos_.x() / kStepH;
//   int current_y = lastPos_.y() / kStepV;

//   if (is_have_start_point_ == false) {
//     start_point_ = QPoint(current_x, current_y);
//     Draw(event->pos());
//   } else {
//     DrawObject(Model::Type::kMaze);
//     std::pair<size_t, size_t> start(start_point_.y(), start_point_.x());
//     std::pair<size_t, size_t> end(current_y, current_x);
//     controller_->FindMazePath(start, end);
//     DrawMazePath();
//   }
//   is_have_start_point_ = true;
// }

// void PaintWidget::DrawMazePath() {
//   const std::vector<std::pair<int, int> >& path = controller_->GetMazePath();
//   QPainter painter{&pixmap_};
//   pen_->setColor(Qt::blue);
//   painter.setPen(*pen_);

//   const int kStepH = kAreaSize / controller_->GetColumns();
//   const int kStepV = kAreaSize / controller_->GetRows();
//   static const double kScale = 0.5;
//   const int kCenterX = kStepH * kScale;
//   const int kCenterY = kStepV * kScale;
//   int x_start = start_point_.x();
//   int y_start = start_point_.y();

//   for (size_t i = 0; i < path.size(); ++i) {
//     int a = ((path[i].first + 1) * kStepH) - kCenterX;
//     int b = ((path[i].second + 1) * kStepV) - kCenterY;
//     if (i > 0) painter.drawLine(x_start, y_start, a, b);
//     x_start = a;
//     y_start = b;
//   }
//   update();
// }

// void  PaintWidget::DrawMaze(const std::vector<bool>& data, size_t size, size_t columns) {
//   mouse_event_ = true;
//   size_t i = 0;
//   std::vector<std::vector<bool>> vertical = Converter(&i, columns, size/2, data);
//   std::vector<std::vector<bool>> horizontal = Converter(&i, columns, size, data);

//   QPainter painter{&pixmap_};
//   pen_->setColor(Qt::white);
//   painter.setPen(*pen_);
//   painter.drawLine(1, 0, 1, kAreaSize);
//   painter.drawLine(0, 1, kAreaSize, 1);
//   painter.drawLine(kAreaSize - 1, 0, kAreaSize - 1, kAreaSize);
//   painter.drawLine(0, kAreaSize - 1, kAreaSize, kAreaSize - 1);
//   for (size_t k = 0; k < vertical.size(); ++k) {
//     DrawLine(&painter, vertical[k], horizontal[k], k, vertical.size() );
//   }
//   update();
// }

//void PaintWidget::mousePressEvent(QMouseEvent* event)  {
//  if (controller_->GetObj().GetSize() > 0 && mouse_event_) {
//    if (event->button() == Qt::RightButton) {
//      Clear();
//      DrawObject(Model::Type::kMaze);
//    } else if (event->button() == Qt::LeftButton) {
//      SetPathPoint(event);
//    }
//  }
//}
