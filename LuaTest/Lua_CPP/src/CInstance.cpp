#include "CInstance.h"
#include <iostream>

using namespace std;

CInstance* CInstance::pInstance = NULL;


CInstance::CInstance()
{
	cout<<"Create The CInstance!"<<endl;
}

//���û�� ��̬��Ƕ����������������������� ���Ϊʲô��
//�� ��ΪpInstanc��ͨ��new��������ڴ� ���ֶ����֮ǰ��һֱ��Ч�� 
CInstance::~CInstance() 
{
	if(CInstance::pInstance)
	{
		//delete pInstance;
		cout<<"Destroy The CInstance_1!"<<endl;
	}
	cout<<"Destroy The CInstance!"<<endl;
}
void CInstance::printHello()
{
	cout<<"HaHa"<<endl;
}

#ifdef GC
CInstance::CGarbage::~CGarbage()
{
	if(CInstance::pInstance)
	{
		delete CInstance::pInstance;
		cout<<"CGarbage"<<endl;
	}
	cout<<"CGarbage_2"<<endl;
}
CInstance::CGarbage CInstance::gc;
#endif