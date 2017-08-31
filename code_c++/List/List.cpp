// List.cpp : 定义控制台应用程序的入口点。
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

SNode *Add(SNode *sHead1,SNode *sHead2);//连表加法
void Print(SNode *sHead);
void DestroyNode(SNode *sHead);
bool Reserval(SNode *sHead, int from, int to);//链表翻转
bool DelDumplateNode(SNode*pHead);	//删除重复的元素 保留第一个
bool DelDumplateNode_1(SNode*pHead);//删除重复的元素 保留最后一个
bool DelDumplateNode_2(SNode*pHead);//删除重复的元素 不保留
bool PartitionNode(SNode *pHead,int pKey);//将两边分成两部分 左边 小于key 右边大于key（链表的快排结构）

void TestAdd();//测试链表加法
void TestReserval();//测试翻转
void TestDelDumplate();//测试删除重元素
void TestPartition();

int _tmain(int argc, _TCHAR* argv[])
{
	//TestReserval();
	//TestDelDumplate();
	TestPartition();
	system("PAUSE");
	return 0;
}

void TestPartition()
{
	SNode *pHead = new SNode(0);
	srand(time(0));
	for (int i=0; i<20; i++)
	{
		SNode *pNode = new SNode(rand()%100);
		pNode->pNext = pHead->pNext;
		pHead->pNext = pNode;
	}
	Print(pHead);
	PartitionNode(pHead,30);
	Print(pHead);
	DestroyNode(pHead);
}

bool PartitionNode(SNode *pHead,int pKey)
{
	if (pHead==NULL)
	{
		return false;
	}
	//两个链表
	SNode*pLeftHead = new SNode(0);
	SNode*pRightHead = new SNode(0);

	SNode* curNode = pHead->pNext;
	SNode* leftHead=pLeftHead; //记录链表尾端
	SNode* rightHead=pRightHead;
	SNode* nextNode = NULL;
	//遍历
	while(curNode)
	{
		if (curNode->value < pKey)
		{
			leftHead->pNext = curNode;
			leftHead = curNode;
		}
		else
		{
			rightHead->pNext = curNode;
			rightHead = curNode;
		}
		curNode = curNode->pNext;
	}
	rightHead->pNext=NULL;
	leftHead->pNext = NULL;
	leftHead->pNext = pRightHead->pNext;
	pHead = pLeftHead;
	delete pRightHead;
	delete pLeftHead;
}

bool DelDumplateNode_1(SNode*pHead)//删除重复的元素 保留最后一个
{
	if (!pHead)
	{
		return false;
	}
	SNode* preSNode = pHead->pNext;
	SNode* curSNode = NULL;
	while (preSNode)
	{
		curSNode = preSNode->pNext;
		if (curSNode && curSNode->pNext && curSNode->value == curSNode->pNext->value)
		{
			preSNode->pNext = curSNode->pNext;
			delete curSNode;
			curSNode =  preSNode->pNext;
			continue;
		}
		preSNode = preSNode->pNext;
	}
	return true;
}

bool DelDumplateNode_2(SNode*pHead)//删除重复的元素 不保留
{
	if (!pHead)
	{
		return false;
	}
	bool isDump = false;
	SNode *preSNode = pHead->pNext;
	SNode *curSNode = NULL;
	while (preSNode)
	{
		curSNode = preSNode->pNext;
		while(curSNode && curSNode->pNext && curSNode->value == curSNode->pNext->value)
		{
			preSNode->pNext = curSNode->pNext;
			delete curSNode;
			curSNode = preSNode->pNext;
			isDump = true;
		}
		if (isDump && preSNode)
		{
			preSNode->pNext = curSNode->pNext;
			delete curSNode;
			isDump = false;
		}
		preSNode = preSNode->pNext;
	}
	return true;
}
void TestDelDumplate()
{
	int data[] = {1,4,3,4,5,5,7,8,8,8,8,9};
	int arrSize = sizeof(data)/sizeof(int);
	SNode *pHead = new SNode(0); 
	for (int i=arrSize-1; i>=0; i--)
	{
		SNode*node = new SNode(data[i]);
		node->pNext = pHead->pNext;
		pHead->pNext = node;
	}
	Print(pHead);
	//DelDumplateNode(pHead);
	//DelDumplateNode_1(pHead);
	DelDumplateNode_2(pHead);
	Print(pHead);
	DestroyNode(pHead);
}
bool DelDumplateNode(SNode*pHead)	//删除重复的元素
{
	if (pHead==NULL)
	{
		return false;
	}
	SNode *preNode = pHead->pNext;
	SNode *curNode;
	while(preNode!=NULL)
	{
		curNode = preNode->pNext;
		if(curNode && preNode->value == curNode->value)
		{
			preNode->pNext = curNode->pNext;
			delete curNode;
			continue;
		}
		preNode = preNode->pNext;
	}
	return true;
}
void TestReserval()//测试翻转
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
	SNode *preSNode = NULL;
	int i=0;
	//寻找翻转的点的前一个元素
	for (;i<from;i++)
	{
		preSNode = sHead;
		sHead = sHead->pNext;
	}
	//开始翻转到指定元素
	SNode* curSNode = preSNode->pNext;
	SNode* nextSNode = NULL;
	for (;i<to;i++)
	{
		nextSNode = curSNode->pNext;
		curSNode->pNext = nextSNode->pNext;
		nextSNode->pNext = preSNode->pNext;
		preSNode->pNext =  nextSNode;
	}
}

void TestAdd()//测试链表加法
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
	int value=0;//临时值
	int carry=0;//进位
	SNode *curNode = NULL ;
	sHead1 = sHead1->pNext;
	sHead2 = sHead2->pNext;
	//计算加法
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
	//长度不一样的情况
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


