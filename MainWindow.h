#ifndef MainWindow_H
#define MainWindow_H

#include "vtkSmartPointer.h"    // Required for smart pointer internal ivars.
#include <QMainWindow>

// Forward Qt class declarations
class Ui_MainWindow;

// Forward VTK class declarations



class MainWindow : public QMainWindow
{
  Q_OBJECT

public:

  // Constructor/Destructor
  MainWindow();
  ~MainWindow() override;

public slots:

  virtual void slotOpenFile();
  virtual void slotExit();

protected:

protected slots:

private:

  // Designer form
  Ui_MainWindow *ui;
};

#endif // MainWindow_H
