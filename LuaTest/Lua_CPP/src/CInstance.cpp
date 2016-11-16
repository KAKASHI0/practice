#include "CInstance.h"
#include <iostream>

using namespace std;

CInstance* CInstance::pInstance = NULL;


CInstance::CInstance()
{
	cout<<"Create The CInstance!"<<endl;
}

//如果没有 静态内嵌变量并不会走这个析构函数 这个为什么呢
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