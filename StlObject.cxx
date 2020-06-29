#include "StlObject.h"

StlObject::StlObject(std::string fileWithPath) {

	stlReader->SetFileName(fileWithPath.c_str());
	stlReader->Update();
	mapper->SetInputConnection(stlReader->GetOutputPort());
	actor->SetMapper(mapper);

}

StlObject::~StlObject() {
}

vtkActor* StlObject::GetActor() {
	return actor;
}
