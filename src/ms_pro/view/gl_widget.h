#ifndef SRC_VIEW_GL_WIDGET_H_
#define SRC_VIEW_GL_WIDGET_H_

#include <QOpenGLWidget>
#include <QGuiApplication>
#include <QOpenGLShaderProgram>
#include <QScreen>
#include <QtMath>
#include <QDebug>
#include <QWidget>
#include <QGridLayout>
#include <memory>
#include <QPixmap>
#include <QImage>


//#include "controller.h"
//#include "settings.h"
#include "mainwindow.h"

class GLWidget : public QOpenGLWidget {
  Q_OBJECT

 public:
  explicit GLWidget(QWidget *parent);
//  void SetController(s21::Controller *controller);
//  void SetSettings(s21::Settings *settings);
  void RenderingModel();



 signals:
  void recordStop();

 protected:
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;

 private:
  std::unique_ptr<QOpenGLShaderProgram> opgl_shader_program_;
  GLint position_attr_;
  GLint matrix_uniform_;
  float* list_of_vertices_;
  int number_of_vertices_;
  QSurfaceFormat format;

//  s21::Controller* controller_;
//  s21::GifMaker gif_maker_;
//  s21::Settings* settings_;

  void _LoadShaderFromFile(QOpenGLShader::ShaderType type, const std::string& file_name);
  void _FormatInitialization();
  void _ShadersInitialization();
  void _MatrixInitialization();
  void _SetVertexTypeCircle();
  void _SetVertexTypeSquare();
  void _MatrixTransformation();
  void _RecordScreencast();
  void _DrawLines();
  void _DrawPoints();
  void _SetSettings();
//  void _SetLineType(s21::LineType type);
//  QMatrix4x4 _QMatrixAdaptor(const s21::S21Matrix& matrix);
};

#endif  // SRC_VIEW_GL_WIDGET_H_
