// https://codeforces.com/problemset/problem/431/C
#include <bits/stdc++.h>
using namespace std;
int n,k,d,mem[200][2];
int branch(int x,int y){
    int i;
    if(x>n) return 0;
    if(!mem[x][y])
    {
        if(x==n && y==1)
        {
            mem[x][y]=1;
        }
        if(x<n)
            for(i=1;i<=k;i++)
            {
                if(i>=d || y==1)
                {
                    y=1;
                }
                else y=0;
                mem[x][y]+=mem[x+i][y];
            }
    }

    return mem[x][y];
}
int main(){
    scanf("%d%d%d",&n,&k,&d);
    printf("%d",branch(0,0));
}
