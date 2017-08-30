// List.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>

struct tagSNode
{
	int value;
	tagSNode *pNext;
	tagSNode(int value):value(value),pNext(NULL){};
};
typedef tagSNode SNode;

SNode *Add(SNode *sHead1,SNode *sHead2);//����ӷ�
void Print(SNode *sHead);
void DestroyNode(SNode *sHead);
bool Reserval(SNode *sHead, int from, int to);//����ת

void TestAdd();//��������ӷ�
void TestReserval();//���Է�ת

int _tmain(int argc, _TCHAR* argv[])
{
	TestReserval();//���Է�ת
	system("PAUSE");
	return 0;
}
void TestReserval()//���Է�ת
{
	srand(time(0));
	SNode*pHead1 = new SNode(0);
	for (int i=0; i<10; i++)
	{
		SNode *curNode = new SNode(rand()%10);
		curNode->pNext = pHead1->pNext;
		pHead1->pNext = curNode;
	}
	Print(pHead1);
	Reserval(pHead1,4,8);
	Print(pHead1);
	DestroyNode(pHead1);
}

bool Reserval(SNode *sHead, int from, int to)
{
	if (from>=to)
	{
		return false;
	}
	//�ҵ���ת����ʼλ��
	SNode* preSNode = NULL;
	SNode* curSNode = NULL;
	SNode* nextSNode = NULL; 
	int i=0;
	for (;i<from;i++)
	{
		preSNode = sHead;
		sHead = sHead->pNext;
	}
	curSNode = preSNode->pNext;
	//��ʼ��ת
	for (;i<=to;i++)
	{
		nextSNode = curSNode->pNext;
		curSNode->pNext = nextSNode->pNext;
		nextSNode->pNext = preSNode->pNext;
		preSNode->pNext=nextSNode;
	}
}

void TestAdd()//��������ӷ�
{
	srand(time(0));
	SNode*pHead1 = new SNode(0);
	for (int i=0; i<6; i++)
	{
		SNode *curNode = new SNode(rand()%10);
		curNode->pNext = pHead1->pNext;
		pHead1->pNext = curNode;
	}

	SNode*pHead2 = new SNode(0);
	for (int i=0; i<6; i++)
	{
		SNode *curNode = new SNode(rand()%10);
		curNode->pNext = pHead2->pNext;
		pHead2->pNext = curNode;
	}

	Print(pHead1);
	Print(pHead2);
	SNode*pTail = Add(pHead2,pHead1);
	Print(pTail);
	DestroyNode(pHead1);
	DestroyNode(pHead2);
	DestroyNode(pTail);
}

SNode *Add(SNode *sHead1,SNode *sHead2)
{
	if (sHead2==NULL && sHead1==NULL)
	{
		return NULL;
	}
	SNode*pTail = new SNode(0);
	int value=0;//��ʱֵ
	int carry=0;//��λ
	SNode *curNode = NULL ;
	sHead1 = sHead1->pNext;
	sHead2 = sHead2->pNext;
	//����ӷ�
	while(sHead1 && sHead2)
	{
		value = sHead2->value + sHead1->value + carry;
		carry = value / 10;
		value %= 10;
		printf("%d+%d;%d,%d\n",sHead2->value,sHead1->value,value,carry);
		curNode = new SNode(value);
		curNode->pNext = pTail->pNext;
		pTail->pNext = curNode;
		sHead1 = sHead1->pNext;
		sHead2 = sHead2->pNext;
		curNode = NULL;
	}
	//���Ȳ�һ�������
	SNode *pExtra = sHead1==NULL ? sHead2 : sHead1;
	while(pExtra)
	{
		value = pExtra->value + carry;
		carry = value / 10;
		value %= 10;
		curNode = new SNode(value);
		curNode->pNext = pTail->pNext;
		pTail->pNext = curNode;
		pExtra = pExtra->pNext;
		curNode = NULL;
	}
	if(carry)
	{
		curNode = new SNode(carry);
		curNode->pNext = pTail->pNext;
		pTail->pNext = curNode;
		curNode = NULL;
	}
	return pTail;
}

void DestroyNode(SNode *sHead)
{
	while (sHead)
	{
		SNode*curNode = sHead;
		sHead = sHead->pNext;
		delete curNode;
	}
}

void Print(SNode *sHead)
{
	if (sHead==NULL)
	{
		return;
	}
	while(sHead->pNext)
	{
		printf("%d->",*sHead->pNext);
		sHead = sHead->pNext;
	}
	printf("\n");
}


