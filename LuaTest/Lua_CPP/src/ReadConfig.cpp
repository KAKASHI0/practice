#include "ReadConfig.h"
#include <iostream>
using namespace std;

ReadConfig::ReadConfig(void)
{
}


ReadConfig::~ReadConfig(void)
{
}
void ReadConfig::init()
{
	L = luaL_newstate();
	luaL_openlibs(L); //open lua libs;
}

int ReadConfig::loadFile(string name)
{
	if (luaL_loadfile(L,name.c_str()) || lua_pcall(L,0,0,0))
	{
		
		//luaL_error(L,"loadfil Error,%s ",lua_tostring(L,-1));
		return -1;
	}
	//lua_pcall(L,0,0,0);
	return 0;
}

int ReadConfig::readInt(std::string name,int& value)
{
	 lua_getglobal(L,name.c_str());
	 if ( lua_isnumber(L,-1) )
	 {
		value = (int)lua_tonumberx(L,-1,&value);
		 return value;
	 }
	 luaL_error(L,"get %s error",name.c_str());
	 return -1;
}

ReadConfig::ReadConfig(std::string fname)
{
	init();
	loadFile(fname);
}


int ReadConfig::readTable(std::string tname, std::string field,int &result)
{
	lua_getglobal(L,tname.c_str());
	if ( !lua_istable(L,-1) )
	{
		cout<<"get Table error !"<<endl;
		return -1;
	}
	lua_pushstring(L,field.c_str());
	lua_gettable(L,-2);
	cout<< (int)lua_tonumber(L,-1)<<endl;
	int type = lua_type(L,-1);
	switch (type)
	{
	case LUA_TSTRING:
		{
			string tmp = lua_tostring(L,-1);
			cout<< tmp <<endl;
		}
		break;
	case LUA_TBOOLEAN:
		result = (int)lua_toboolean(L,-1);
		break;
	case LUA_TNUMBER:
		result = (int)lua_tonumber(L,-1);
		break;
	default:
		{
			string typStr = lua_typename(L,type);
			cout<<typStr<<endl;
		}
		break;
	}
	return 0;
}

void ReadConfig::setField(string index, int value)
{
	lua_pushstring(L,index.c_str());
	lua_pushnumber(L,value);
	lua_settable(L,-3);
	lua_pop(L,2);
}

void ReadConfig::setColor(color& tmp)
{
	lua_newtable(L);
	
	setField("r",tmp.rgb[R]);
	setField("g",tmp.rgb[R]);
	setField("b",tmp.rgb[R]);
	lua_setglobal(L,tmp.name.c_str());
}