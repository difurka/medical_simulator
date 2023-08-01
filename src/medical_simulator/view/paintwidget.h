#pragma once 

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include "controller/controller.h"

#include <memory>

class PaintWidget : public QWidget {
  Q_OBJECT

 public:
  explicit PaintWidget(QWidget *parent = nullptr);
  void SetController(Controller* controller);

  void paintEvent(QPaintEvent *event) override;
  void resizeEvent(QResizeEvent *event) override;

  void Draw(const QPoint& pos);

  void DrawCave(const std::vector<bool>& data, size_t size, size_t rows, size_t columns);
  void DrawObject(Model::Type type);

  void Clear();

 private:
  static const int kDefaultPenWidth = 2;
  static const int kAreaSize = 500;

  Controller* controller_;

  QPixmap pixmap_;
  QPoint lastPos_;
  std::unique_ptr<QPen> pen_;

  std::vector<std::vector<bool>> Converter(
      size_t *index, size_t line_size, size_t size, const std::vector<bool>& data);
  void DrawLine(QPainter *painter, const std::vector<bool>& vertical,
              const std::vector<bool>& horizontal, int line_number, int cols_number);
};

