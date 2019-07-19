#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
#include <cctype>
#define maxx 0x3f3f3f3f
#define ll long long
#define minn(a, b) a < b ? a : b
#define maxx(a, b) a > b？a:b
#define FAST_IO std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
using namespace std;
const int maxn = 1e6 + 5;
char str[maxn];
char ss[maxn<<1];
int p[maxn<<1];
int len;
void manacher(){
  int i;
  ss[0]='$';
  ss[1]='#';
  for(i=0;i<len;i++){
    ss[i*2+2]=str[i];
    ss[i*2+3]='#';
  }
  len=i*2+2;
  ss[len]='\0';
  int maxl ,id =0;
  maxl=0;
  memset(p,0,sizeof(p));
  for(int i=0;i<len;i++){
    if(p[id]+id>i)
      p[i]=minn(p[2*id-i],p[id]+id-i);
    else
      p[i]=1;
    while (ss[i+p[i]]==ss[i-p[i]])
      p[i]++;
    if(p[i]+i>p[id]+id)
      id=i;
  }
  if(p[i]-1>maxl)
    maxl=p[i]-1;
}
