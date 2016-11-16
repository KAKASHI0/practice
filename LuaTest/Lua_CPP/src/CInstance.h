#pragma once

#define GC

//使用内嵌类回收内存
//不用内嵌类不走本身的析构
//答 因为pInstanc是通过new来分配的内存 在手动清除之前是一直有效的 
class CInstance
{
private:
	CInstance();
public:
	~CInstance();
	static CInstance * getInstance()
	{
		if( !pInstance )
		{
			pInstance  = new CInstance();
		}
		return pInstance;
	}
	void printHello();
public:
#ifdef GC
	class CGarbage
	{
	public:
		~CGarbage();
	};
	static CGarbage gc;
#endif
public:
	static CInstance *pInstance;

};
