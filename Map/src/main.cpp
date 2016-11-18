#include <iostream>
#include <map>

using namespace std;

/*****************
*
*
*
*****************/

int main()
{
	map<int ,int> cMap;
	cMap.insert(make_pair(1,2));
	cMap.insert(make_pair(1,4));
	cout<<cMap[1];
	map<int,int>::iterator it = cMap.begin();
	
	cout<<"~~~~~~~"<<endl;
	system("PAUSE");
	return 0;
}