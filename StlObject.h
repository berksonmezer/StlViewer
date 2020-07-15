#ifndef StlObject_H
#define StlObject_H

#include "vtkSTLReader.h"
#include "vtkPolyDataMapper.h"
#include "vtkActor.h"
#include <string>

class StlObject {

public:
	StlObject(std::string filePath);
	~StlObject();
	
	vtkActor* GetActor();

private:
	vtkNew<vtkSTLReader> stlReader;
	vtkNew<vtkPolyDataMapper> mapper;
	vtkNew<vtkActor> actor;
};

#endif // !StlObject_H
