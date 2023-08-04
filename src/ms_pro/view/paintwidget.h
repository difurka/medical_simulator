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

 private:
  Controller* controller_;

  QPixmap pixmap_;

  std::unique_ptr<QPen> pen_;

};

