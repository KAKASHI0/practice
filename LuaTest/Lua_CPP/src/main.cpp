#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "luaFunTest.h"
#include "ReadConfig.h"
#include "CInstance.h"




using namespace std;

void TestInstance()
{
	CInstance *pInstance = CInstance::getInstance();
	pInstance->printHello();
}

int main()
{
	
	TestInstance();
// 	string config = "config.lua";
// 	ReadConfig::getInstance().init();
// 	if (-1 == ReadConfig::getInstance().loadFile(config))
// 	{
// 		cout<<"open config error:"<<ReadConfig::getInstance().GetError()<<endl;
// 		return -1;
// 	}
// 	
// 	int tst = 0;
// 		ReadConfig::getInstance().readInt("test",tst);
// 
// 	cout<<"hello test:"<<tst<<endl;
	//system("PAUSE");
	return 0;
}

