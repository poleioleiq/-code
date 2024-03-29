#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>
#include <stack>
#define maxx 0x3f3f3f3f
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
using namespace std;
const int maxn=1e5+5;
//前后相比，找出没遗传的子串


char a[maxn];
char b[maxn];
int nextt[maxn];
int lena,lenb;
void getNext()
{
    int i=0,j=-1;
    nextt[0]=-1;//第一位-1
    while(i<lenb)//对于每个长度
    {
        if(j==-1||b[i]==b[j])
        {
            i++,j++;//游标加
            nextt[i]=j;//每次都是基础上一
        }
        else
            j=nextt[j];
    }
}
int KMP()
{
    int i=0,j=0;
    int ans=0;
    getNext();
    while(i<lena)
    {
        if(j==-1||a[i]==b[j])
            i++,j++;
        else
            j=nextt[j];
        if(j==lenb)
        {
            ans++;
            j=0;//若两个不同的匹配没有交集则j=0,若存在交集则j=next[j];
        }
    }
    return ans;//
}
int main()
{

    while(cin>>a)
    {
        if(a[0]=='#')
            break;
        cin>>b;
        lena=strlen(a);
        lenb=strlen(b);
        cout<<KMP()<<endl;
    }

    return 0;
}
