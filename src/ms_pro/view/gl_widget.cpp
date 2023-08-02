#include "gl_widget.h"

//static constexpr  char* kPathVshader = CURRENT_PATH"/shaders/vshader.glsl";
//static constexpr  char* kPathFshader = CURRENT_PATH"/shaders/fshader.glsl";
static constexpr float kWindowWidth = 960.0;
static constexpr float kWindowHeight = 720.0;

GLWidget::GLWidget(QWidget *parent) :
  QOpenGLWidget(parent),
  opgl_shader_program_(nullptr),
  position_attr_(0),
  matrix_uniform_(0),
  list_of_vertices_(nullptr),
  number_of_vertices_(0)
//  controller_(nullptr),
//  settings_(nullptr)
{
}

void GLWidget::initializeGL() {
  _FormatInitialization();
  _ShadersInitialization();
}

void GLWidget::_FormatInitialization() {
  format.setDepthBufferSize(24);
  format.setStencilBufferSize(8);
  format.setVersion(4, 5);
  format.setProfile(QSurfaceFormat::CoreProfile);
  QSurfaceFormat::setDefaultFormat(format);
}

void GLWidget::_ShadersInitialization() {
  glEnable(GL_PROGRAM_POINT_SIZE);
  opgl_shader_program_ = std::make_unique<QOpenGLShaderProgram>(new QOpenGLShaderProgram(this));
//  _LoadShaderFromFile(QOpenGLShader::Vertex, kPathVshader);
//  _LoadShaderFromFile(QOpenGLShader::Fragment, kPathFshader);
  opgl_shader_program_->link();

  position_attr_ = opgl_shader_program_->attributeLocation("posAttr");
  Q_ASSERT(position_attr_ != -1);
  matrix_uniform_ = opgl_shader_program_->uniformLocation("matrix");
  Q_ASSERT(matrix_uniform_ != -1);
  opgl_shader_program_->uniformLocation("color");
  opgl_shader_program_->uniformLocation("projection");
}

void GLWidget::_LoadShaderFromFile(QOpenGLShader::ShaderType type, const std::string& file_name) {
//  std::ifstream file_stream(file_name);
//  std::stringstream vshader;
//  vshader << file_stream.rdbuf();
//  opgl_shader_program_->addShaderFromSourceCode(type, vshader.str().c_str());
}

void GLWidget::RenderingModel() {
//  list_of_vertices_ = controller_->GetAllVertices();
//  number_of_vertices_ = controller_->GetNumberOfVertices() / 3;
//  controller_->ClearDataObj();
//  _MatrixInitialization();
}

void GLWidget::_MatrixInitialization() {
//  controller_->MakeInitialization();
}

void GLWidget::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);
  opgl_shader_program_->bind();
}

void GLWidget::paintGL() {
  _SetSettings();
  _MatrixTransformation();
//  glVertexAttribPointer(position_attr_, 3, GL_FLOAT, GL_FALSE, 0, list_of_vertices_);
//  glEnableVertexAttribArray(position_attr_);

  _DrawLines();
//  if (settings_->GetVertisesType() != s21::VertisesType::NONE) {
//    _DrawPoints();
//  }
//  if (gif_maker_.IsRecordOn()) {
//    _RecordScreencast();
//  }
//  glDisableVertexAttribArray(position_attr_);
}

void GLWidget::_SetSettings() {
//  glLineWidth(settings_->GetLineWidth());
//  glPointSize(settings_->GetVertisesSize());
//  auto color = settings_->GetBackgroundColor();
//  glClearColor(color.redF(), color.greenF(), color.blueF(), color.alphaF());
//  glClear(GL_COLOR_BUFFER_BIT);
//  opgl_shader_program_->setUniformValue("projection", settings_->GetProjectionType(),
//    1.0, kWindowHeight / kWindowWidth);
}

void GLWidget::_MatrixTransformation() {
//  auto matrix_ = controller_->GetTransformerMatrix();
//  opgl_shader_program_->setUniformValue(matrix_uniform_, _QMatrixAdaptor(matrix_));
}

//QMatrix4x4 GLWidget::_QMatrixAdaptor(const s21::S21Matrix &matrix) {
//  QMatrix4x4 qmatrixTransform_;
//    for (int i = 0; i < 4; i++)
//      for (int j = 0; j < 4; j++)
//        qmatrixTransform_(i, j) = matrix(i, j);
//  return qmatrixTransform_;
//}
void GLWidget::_DrawLines() {
//  auto color = settings_->GetLineColor();
//  opgl_shader_program_->setUniformValue("color", color.redF(), color.greenF(), color.blueF(), color.alphaF());
//  _SetLineType(settings_->GetLineType());
//  glDrawArrays(GL_LINES, 0, number_of_vertices_);
}


void GLWidget::_DrawPoints() {
//  if (settings_->GetVertisesType() == s21::VertisesType::CIRCLE) {
//    _SetVertexTypeCircle();
//  } else {
//    _SetVertexTypeSquare();
//  }
//  auto color = settings_->GetPointColor();
//  opgl_shader_program_->setUniformValue("color", color.redF(), color.greenF(), color.blueF(), color.alphaF());
  glDrawArrays(GL_POINTS, 0, number_of_vertices_);
}

void GLWidget::_SetVertexTypeCircle() {
  glEnable(GL_ALPHA_TEST);
  glAlphaFunc(GL_NOTEQUAL, 0);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_POINT_SMOOTH);
}

void GLWidget::_SetVertexTypeSquare() {
  glDisable(GL_ALPHA_TEST);
  glDisable(GL_BLEND);
  glDisable(GL_POINT_SMOOTH);
}

//void GLWidget::_SetLineType(s21::LineType type) {
//    GLboolean result;
//    glGetBooleanv(GL_LINE_STIPPLE, &result);
//  if (type == s21::LineType::DASHED && (result == false)) {
//    glLineStipple(1, 0x00F0);
//    glEnable(GL_LINE_STIPPLE);
//  } else if (type == s21::LineType::SOLID && result == true) {
//    glDisable(GL_LINE_STIPPLE);
//  }
//}

void GLWidget::_RecordScreencast() {
//  gif_maker_.AddImageToGIF(grabFramebuffer());
//  if (gif_maker_.IsRecordOn() == false) {
//    emit recordStop();
//  }
}



//void GLWidget::SetController(s21::Controller *controller) {
////  controller_ = controller;
//}

//void GLWidget::SetSettings(s21::Settings *settings) {
//  settings_ = settings;
//}



