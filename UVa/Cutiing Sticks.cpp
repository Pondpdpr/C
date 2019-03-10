#include <bits/stdc++.h>
using namespace std;
int n,m,mem[55][55],t1,t2;
vector<int>v;
int stick(int x,int y){
    if(x+1==y) return 0;
    if(!mem[x][y])
    {
        mem[x][y]=1e9;
        for(int i=x+1;i<y;i++)
            mem[x][y]=min(mem[x][y],stick(x,i)+stick(i,y)+(v[y]-v[x]));
    }
    return mem[x][y];
}
int main(){
    int i,j;
//    freopen("Cutting Sticks-out.txt","w",stdout);
    while(1)
    {
        scanf("%d",&n);
        if(!n) return 0;
        fill(&mem[0][0],&mem[54][54],0);
        while(!v.empty()) v.pop_back();
        scanf("%d",&m);
        v.push_back(0);
        for(i=0;i<m;i++)
        {
            scanf("%d",&t1);
            v.push_back(t1);
        }
        v.push_back(n);
        printf("The minimum cutting is %d.\n",stick(0,m+1));
    }
}
