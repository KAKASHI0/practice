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

void getConfig()
{
	string config = "config.lua";
	ReadConfig::getInstance().init();
	if (-1 == ReadConfig::getInstance().loadFile(config))
	{
		cout<<"open config error:"<<ReadConfig::getInstance().GetError()<<endl;
		return ;
	}

	int tst = 0;
	ReadConfig::getInstance().readInt("test",tst);

	cout<<"hello test:"<<tst<<endl;

	int width = ReadConfig::getInstance().readInt("width",width);
	
	cout<<"width : "<<width<<endl;
}

int main()
{
	//easyTest();
	getConfig();
	system("PAUSE");
	return 0;
}

