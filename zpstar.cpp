#include<stdio.h>
#include<set>
#include<iostream>
/**
*	探索对Z*p的所有元素做平方/立方操作后的子群与群Z*p的关系
*	@author: 陈海龙
*/
using namespace std;
set<int> ans;
int shu[10000];
int num=0;
void subgroup(int p)  //i^2，对群元素做平方运算得到的子群
{
    for(int i=1;i<p;i++)
    {
        int c=(i*i)%p;   //立方的情况则在乘以一个i
        if(ans.find(c)==ans.end())
        {
            ans.insert(c); //不含相同元素的集合
        }
        shu[num++]=c;  //含有相同元素的集合
    }
}
int main()
{
    int p;
    cin>>p;
    subgroup(p);
    set<int>::iterator it=ans.begin();
    while(it!=ans.end())
    {
        cout<<*it<<" ";
       	it++;
    }
    cout<<endl;
    for(int i=0;i<num;i++)
        cout<<shu[i]<<" ";
    return 0;
}