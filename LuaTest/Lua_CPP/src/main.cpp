#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "luaFunTest.h"
#include "ReadConfig.h"
#include "CInstance.h"




using namespace std;


color colorTable[]=
{
	{"back",8,8,8}
};



void TestInstance()
{
	CInstance *pInstance = CInstance::getInstance();
	pInstance->printHello();
}

void setConfig()
{
	string fname = "config.lua";
	ReadConfig config(fname);
	int result=0;
	int g=0;
	int codeErro = config.readTable("back","r",result);
	codeErro = config.readTable("back","g",g);

	cout<<"back->r : "<<result<<endl;
	cout<<"back->g : "<<g<<endl;
	
	int i=0;
	while (!colorTable[i].name.empty())
	{
		config.setColor(colorTable[i]);
		i++;
	}
}

void getConfig()
{
	string fname = "config.lua";
	ReadConfig config(fname);
	int tst = 0;
	config.readInt("test",tst);

	cout<<"hello test:"<<tst<<endl;

	int width = config.readInt("width",width);
	
	cout<<"width : "<<width<<endl;
	int result=0;
	int g=0;
	int codeErro = config.readTable("back","r",result);
	codeErro = config.readTable("back","g",g);
	if (codeErro)
	{
		cout<<"readTable error !"<<endl;
		return;
	}
	cout<<"back->r : "<<result<<endl;
	cout<<"back->g : "<<g<<endl;
}

int main()
{
	//easyTest();
	setConfig();
	system("PAUSE");
	return 0;
}

