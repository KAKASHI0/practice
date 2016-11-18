#pragma once
#include<string>

extern "C"  
{  
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
} 

#define  NAME_LENGTH 40

enum COLORINDEX
{
	R=0,
	G,
	B
};

struct color
{
	std::string name;
	int rgb[3];
};

class ReadConfig
{
public:
	~ReadConfig(void);
	ReadConfig(std::string fname);
	static ReadConfig& getInstance()
	{
		static ReadConfig instance;
		return instance;
	}
	std::string GetError()
	{
		return lua_tostring(L,-1);
	}

	void init();
	int readInt(std::string name,int& value);
	int loadFile(std::string name);
	
	int readTable(std::string tname, std::string field,int& result);
	
	//修改配置文件
	void setColor(color& tmp);
	void setField(std::string index, int value);
private:
	ReadConfig(void);
	ReadConfig& operator = (const ReadConfig &); //单例模式
private:
	lua_State * L;
};

