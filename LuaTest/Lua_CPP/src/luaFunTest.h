#pragma once
#include <iostream>

using namespace std;

#ifdef __cplusplus
	extern "C"  
	{  
		#include "lua.h"
		#include "lualib.h"
		#include "lauxlib.h"
	} 
#endif

void errorProcess(lua_State* L, const char *fmt, ...);
void easyTest1();
void easyTest();
void stackDump(lua_State* L);



void stackDump(lua_State* L)
{
	int top = lua_gettop(L);
	for (int i=1; i<=top; i++)
	{
		int type = lua_type(L,i);
		switch (type)
		{
		case LUA_TSTRING:
			cout<<lua_tostring(L,i);
			break;
		case LUA_TBOOLEAN:
			lua_toboolean(L,i) ? cout<<"true" : cout<<"false";
			break;
		case LUA_TNUMBER:
			cout<<lua_tonumber(L,i);
			break;
		default:
			cout<<lua_typename(L,type);
			break;
		}
		cout<<" ";
	}
	cout<<endl;
}


//简单错误处理

//打印错误信息关闭程序
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
	//1.创建一个state  
	lua_State *L = luaL_newstate();  
		//2.入栈操作  
	lua_pushboolean(L,1);
	lua_pushnumber(L,10);
	lua_pushnil(L);
	lua_pushstring(L, "hello");   
	stackDump(L);
	/* true 10 nil `hello' */

	// 	3.取值操作  
	// 		if( lua_isstring(L,1)){             //判断是否可以转为string  
	// 			cout<<lua_tostring(L,1)<<endl;  //转为string并返回  
	// 		}  
	// 		if( lua_isnumber(L,2)){  
	// 			cout<<lua_tonumber(L,2)<<endl;  
	// 		}  

	lua_pushvalue(L,1);	//复制栈顶元素到 压入栈顶
	stackDump(L);
	/* true 10 nil `hello' true */

	lua_replace(L,3); //从栈顶弹出元素值并将其设置到指定索引位置，没有任何移动操作
	stackDump(L);
	/* true 10 true `hello' */

	lua_settop(L,6);	//修改栈顶
	stackDump(L);
	/* true 10 true `hello' nil nil */

	lua_remove(L,-3);//删除从栈顶数第三个元素
	stackDump(L);
	/* true 10 true nil nil */

	lua_settop(L,-5);
	stackDump(L);
	/* true */


	//4.关闭state  
	lua_close(L);  
	return ;  
}
