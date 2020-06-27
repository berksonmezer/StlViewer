// QT includes
#include <QApplication>
#include <QSurfaceFormat>

#include "QVTKOpenGLWidget.h"
#include "MainWindow.h"


int main( int argc, char** argv )
{
  // needed to ensure appropriate OpenGL context is created for VTK rendering.
  QSurfaceFormat::setDefaultFormat(QVTKOpenGLWidget::defaultFormat());

  // QT Stuff
  QApplication app( argc, argv );

  QApplication::setStyle("fusion");

  MainWindow mainWindow;
  mainWindow.showMaximized();

  return app.exec();
}
