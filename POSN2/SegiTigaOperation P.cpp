#include <bits/stdc++.h>
using namespace std;
int test=20,n,mem[260][260];
char s[260];
int f(int x,int y){
    if(!mem[x][y])
    {
        for(int i=x;i<y;i++)
        {
            int l=f(x,i);
            int r=f(i+1,y);
            if(l&1)
            {
                if(r&1) mem[x][y]|=4;
                if(r&2) mem[x][y]|=2;
                if(r&4) mem[x][y]|=1;
            }
            if(l&2)
            {
                if(r&1) mem[x][y]|=4;
                if(r&2) mem[x][y]|=2;
                if(r&4) mem[x][y]|=2;
            }
            if(l&4)
            {
                if(r&1) mem[x][y]|=2;
                if(r&2) mem[x][y]|=4;
                if(r&4) mem[x][y]|=2;
            }
            if(mem[x][y]==7) return mem[x][y];
        }
    }
    return mem[x][y];
}
int main(){
    int i,j;
    while(test--)
    {
        scanf("%d",&n);
        scanf("%s",s);
        fill(&mem[0][0],&mem[n][n],0);
        for(i=0;i<n;i++)
        {
            if(s[i]=='0') mem[i][i]=1;
            if(s[i]=='1') mem[i][i]=2;
            if(s[i]=='2') mem[i][i]=4;
        }
        if(mem[0][0]!=1)
        {
            printf("no\n");
            continue;
        }
        if(1&f(0,n-1)) printf("yes\n");
        else printf("no\n");
    }
}
