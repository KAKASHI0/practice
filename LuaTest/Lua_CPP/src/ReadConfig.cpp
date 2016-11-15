#include "ReadConfig.h"

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
		luaL_error(L,"loadfil Error,%s ",lua_tostring(L,-1));
		return -1;
	}
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