// http://acm.timus.ru/problem.aspx?space=1&num=1658
#include <bits/stdc++.h>
using namespace std;
int Q,t1,t2,amo,mem[10005];
bool f(int x,int y){
    if(x<0 || y<0 || x>y) return false;
    if(x==0 && y==0) return true;
    if(x==y) 
    {
        for(int j=x;j>0;j--) mem[amo++]=1;
        return true;
    }
    for(int i=x;i>=1;i--)
    {
        // printf("at %d %d about to remove %d %d \n",x,y,i,(i*i));
        if(f(x-i,y-(i*i)))
        {
            // printf("in\n");
            mem[amo]=i;
            amo++;
            return true;
        }
    }
    return false;
}
int main(){
    int i;
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%d%d",&t1,&t2);
        amo=0;
        if(f(t1,t2))
        {
            sort(&mem[0],&mem[amo-1]);
            for(i=0;i<amo;i++) printf("%d",mem[i]);
        }
        else printf("No solution");
        if(Q) printf("\n");
    }
}

