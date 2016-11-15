#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "ReadConfig.h"

extern "C"  
{  
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
} 

void errorProcess(lua_State* L, const char *fmt, ...);
void easyTest1();
void easyTest();

using namespace std;

int main()
{
	
	//easyTest();
	string config = "config.lua";
	ReadConfig::getInstance().init();
	if (-1 == ReadConfig::getInstance().loadFile(config))
	{
		cout<<"open config error:"<<ReadConfig::getInstance().GetError()<<endl;
		return -1;
	}
	
	int tst = 0;
		ReadConfig::getInstance().readInt("test",tst);

	cout<<"hello test:"<<tst<<endl;
	system("PAUSE");
	return 0;
}


//�򵥴�����

//��ӡ������Ϣ�رճ���
void errorProcess(lua_State* L, const char *fmt, ...)
{
	va_list argp;
	va_start(argp,fmt);
	vfprintf(stderr,fmt,argp);
	va_end(argp);
	lua_close(L);
	exit(EXIT_FAILURE);
}

void easyTest1()
{
	char buff[256];
	int error;
	lua_State *L = luaL_newstate();	//open lua
	luaopen_base(L);				// opens the basic library
	luaopen_table(L);				//opens the table library
	luaopen_io(L);					//open the I/O library;
	luaopen_string(L);				//opens the string lib;
	// 	while(fgets(buff,sizeof(buff),stdin) != NULL)
	// 	{
	// 		error = luaL_loadbuffer(L,buff,strlen(buff),"line")
	// 			|| lua_pcall(L,0,0,0);
	// 		if (error)
	// 		{
	// 			fprintf(stderr,"%s",lua_tostring(L,-1));
	// 			lua_pop(L,1); // pop error message from the stack
	// 		}
	// 	}

	while(cin>>buff != NULL)
	{
		error = luaL_loadbuffer(L,buff,strlen(buff),"line")
			|| lua_pcall(L,0,0,0);
		if (error)
		{
			errorProcess(L,(char*)&error);
			cout<<lua_tostring(L,-1);
			lua_pop(L,1); // pop error message from the stack
		}
	}
	//lua_close(L);
	// 	cin >> buff;
	// 	cout<<buff<<endl;
}


void easyTest()
{
	//1.����һ��state  
	lua_State *L = luaL_newstate();  

	//2.��ջ����  
	lua_pushstring(L, "I am so cool~");   
	lua_pushnumber(L,20);  

	//3.ȡֵ����  
	if( lua_isstring(L,1)){             //�ж��Ƿ����תΪstring  
		cout<<lua_tostring(L,1)<<endl;  //תΪstring������  
	}  
	if( lua_isnumber(L,2)){  
		cout<<lua_tonumber(L,2)<<endl;  
	}  

	//4.�ر�state  
	lua_close(L);  
	return ;  
}
