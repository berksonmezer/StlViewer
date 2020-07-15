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

#include "StlObject.h"
#include "FileDialog.h"
#include <memory>

// Constructor
MainWindow::MainWindow()
{
  this->ui = new Ui_MainWindow;
  this->ui->setupUi(this);
  this->setWindowIcon(QIcon(":/Icons/stl.png"));

  // Read Stl File
  std::unique_ptr<StlObject> stlObject(new StlObject(std::string("C:\\Users\\Berk\\Downloads\\Impeller.stl")));
  vtkActor* actor = stlObject->GetActor();

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
	FileDialog *fileDialog = new FileDialog();
	fileDialog->getOpenFileName(this, "Select File", "/", "Stl Files (*.stl)");
}

void MainWindow::slotExit() {
  qApp->exit();
}
