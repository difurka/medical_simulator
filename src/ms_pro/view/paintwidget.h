#pragma once 

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include "controller/controller.h"

#include <memory>

class PaintWidget : public QWidget {
  Q_OBJECT

private:
 static const int kDefaultPenWidth = 2;

 public:
  explicit PaintWidget(QWidget *parent = nullptr);
  void SetController(Controller* controller);
 void DrawFigure(figure_t type);
  void Draw(const QPoint& pos);
  void paintEvent(QPaintEvent *event) override;
  void resizeEvent(QResizeEvent *event) override;

  void Clear();
  void SetBackArea(QColor back_area);
  void SetPixelArea(QColor pixel_area);
  void SetWindowArea(QColor window_area);



 private:
  Controller* controller_;

  QPixmap pixmap_;

  std::unique_ptr<QPen> pen_;
  QColor back_area_;
  QColor pixel_area_;
  QColor window_area_;
};

