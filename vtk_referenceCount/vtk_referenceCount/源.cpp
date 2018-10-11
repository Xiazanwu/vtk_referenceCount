/*
#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL);
#include <vtkSmartPointer.h>
#include <vtkBMPReader.h>
#include <vtkImageData.h>

int main(int argc, char* argv[])
{
	vtkSmartPointer<vtkBMPReader> reader = vtkSmartPointer<vtkBMPReader>::New();
	reader->SetFileName("test.bmp");
	reader->Update();

	std::cout << "Reference Count of reader-> GetOutput(BeforeAssignment)="
		<< reader->GetOutput()->GetReferenceCount() << std::endl;
	
	vtkSmartPointer<vtkImageData> image1 = reader->GetOutput();
	std::cout << "Reference Count of reader->GetOutput(Assignto image1)="
		<< reader->GetOutput()->GetReferenceCount() << std::endl;
	std::cout << "Reference Cout of Image1="
		<< image1->GetReferenceCount() << std::endl;

	vtkSmartPointer<vtkImageData> image2 = reader->GetOutput();
	std::cout << "Reference Cout of reader->GetOutput(Assignto image2)="
		<< reader->GetOutput()->GetReferenceCount() << std::endl;
	std::cout << "Reference Cout of image2="
		<< image2->GetReferenceCount() << std::endl;

	return 0;
}
*/

#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL);
#include <vtkSmartPointer.h>
#include <vtkBMPReader.h>
#include <vtkImageViewer2.h>
#include <vtkRenderWindowInteractor.h>

int main(int argc, char* argv[])
{
	vtkSmartPointer<vtkBMPReader> reader = vtkSmartPointer<vtkBMPReader>::New();
	reader->SetFileName("test.bmp");
	reader->Allow8BitBMPOn();
	reader->SetDebug(1);
	reader->Update();

	vtkSmartPointer<vtkImageViewer2> viewer = vtkSmartPointer<vtkImageViewer2>::New();
	viewer->SetInputData(reader->GetOutput());

	vtkSmartPointer<vtkRenderWindowInteractor> interactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	viewer->Render();

	interactor->Initialize();
	interactor->Start();
	return 0;

}
/**
#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL);
#include <vtkSmartPointer.h>
#include <vtkBMPReader.h>
#include <vtkImageViewer2.h>
#include <vtkRenderWindowInteractor.h>
#include "vtkCallbackCommand.h"

long pressCounts = 0;
//第一步， 定义回调函数
//注意回调函数的签名，不能更改

void MyCallbackFunc(vtkObject*, unsigned long eid, void* clientdata, void* calldata)
{
	std::cout << "You have clicked:" << ++pressCounts << "times." << std::endl;
}

int main(int argc, char* argv[])
{
	vtkSmartPointer<vtkBMPReader> reader = vtkSmartPointer<vtkBMPReader>::New();
	reader->SetFileName("test.bmp");
	reader->Allow8BitBMPOn();
	reader->SetDebug(0);
	reader->GlobalWarningDisplayOff();
	reader->Update();

	vtkSmartPointer<vtkImageViewer2> viewer = vtkSmartPointer<vtkImageViewer2>::New();
	viewer->SetInputData(reader->GetOutput());

	vtkSmartPointer<vtkRenderWindowInteractor> interactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	viewer->SetupInteractor(interactor);
	viewer->Render();
	//第二步，设置回调函数
	vtkSmartPointer<vtkCallbackCommand> mouseCallback = vtkSmartPointer<vtkCallbackCommand>::New();
	mouseCallback->SetCallback(MyCallbackFunc);

	//第三步，将vtkCallbackCommand对象添加到观察者列表
	interactor->SetRenderWindow(viewer->GetRenderWindow());
	interactor->AddObserver(vtkCommand::LeftButtonPressEvent, mouseCallback);

	interactor->Initialize();
	interactor->Start();
	return 0;
}
*/