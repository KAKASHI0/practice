#pragma once
#include<string>

extern "C"  
{  
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
} 

#define  NAME_LENGTH 40

class ReadConfig
{
public:
	~ReadConfig(void);
	
	static ReadConfig& getInstance()
	{
		static ReadConfig instance;
		return instance;
	}
	void init();
	int readInt(std::string name,int& value);
	int loadFile(std::string name);
	std::string GetError()
	{
		return lua_tostring(L,-1);
	}
private:
	ReadConfig(void);
	ReadConfig& operator = (const ReadConfig &); //µ¥ÀýÄ£Ê½
private:
	lua_State * L;
};

