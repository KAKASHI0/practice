#pragma once

#define GC

//ʹ����Ƕ������ڴ�
//������Ƕ�಻�߱��������
//�� ��ΪpInstanc��ͨ��new��������ڴ� ���ֶ����֮ǰ��һֱ��Ч�� 
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
