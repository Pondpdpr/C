// https://codeforces.com/problemset/problem/158/A
#include <bits/stdc++.h>
using namespace std;
int n,k,t1,cnt;
priority_queue<int>pq;
int main(){
    int i,j;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&t1);
        if(t1>0) pq.push(t1);
    }
    while(!pq.empty() && cnt<k)
    {
        t1=pq.top(); pq.pop();
        cnt++;
    }
    while(!pq.empty() && t1==pq.top()) pq.pop(),cnt++;
    printf("%d",cnt);
}
