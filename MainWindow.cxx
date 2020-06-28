#include "ui_MainWindow.h"
#include "MainWindow.h"

#include <vtkDataObjectToTable.h>
#include <vtkElevationFilter.h>
#include "vtkGenericOpenGLRenderWindow.h"
#include <vtkNew.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include "vtkSmartPointer.h"
#include <vtkVectorText.h>



// Constructor
MainWindow::MainWindow()
{
  this->ui = new Ui_MainWindow;
  this->ui->setupUi(this);
  this->setWindowIcon(QIcon(":/Icons/stl.png"));


  // Geometry
  vtkNew<vtkVectorText> text;
  text->SetText("VTK and Qt");
  vtkNew<vtkElevationFilter> elevation;
  elevation->SetInputConnection(text->GetOutputPort());
  elevation->SetLowPoint(0,0,0);
  elevation->SetHighPoint(10,0,0);

  // Mapper
  vtkNew<vtkPolyDataMapper> mapper;
  mapper->SetInputConnection(elevation->GetOutputPort());

  // Actor in scene
  vtkNew<vtkActor> actor;
  actor->SetMapper(mapper);

  // VTK Renderer
  vtkNew<vtkRenderer> ren;

  // Add Actor to renderer
  ren->AddActor(actor);

  // Set background color
  ren->SetBackground(0.7, 1, 1);

  // VTK/Qt wedded
  vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
  this->ui->qvtkWidget->SetRenderWindow(renderWindow);
  this->ui->qvtkWidget->GetRenderWindow()->AddRenderer(ren);

  // Set up action signals and slots
  connect(this->ui->actionOpenFile, SIGNAL(triggered()), this, SLOT(slotOpenFile()));
  connect(this->ui->actionExit, SIGNAL(triggered()), this, SLOT(slotExit()));

};

MainWindow::~MainWindow()
{
  // The smart pointers should clean up for up

}

// Action to be taken upon file open
void MainWindow::slotOpenFile()
{

}

void MainWindow::slotExit() {
  qApp->exit();
}
