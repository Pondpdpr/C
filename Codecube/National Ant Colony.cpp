// https://www.codecube.in.th/task/165
#include <bits/stdc++.h>
using namespace std;
int n,m,k,now[50005],a[50005],t1,t2,t3,ans,all;
bool mem[50005],che[50005];
struct node{
    int x,y,val;
    bool operator <(node a)const{
        return a.val>val;
    }
}t;
priority_queue<node>pq;
int main(){
    int i,j;
    scanf("d%d%d",&n,&m,&k);
    all=k;
    for(i=0;i<n;i++) 
    {
        scanf("%d",&t1);
        a[t1]++;
        if(!che[t1]) all--,che[t1]=true;
    }
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&t1,&t2,&t3);
    }
    
}