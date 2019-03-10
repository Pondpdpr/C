// https://codeforces.com/problemset/problem/1132/F
#include <bits/stdc++.h>
using namespace std;
int n,mem[505][505];
char s[505];
int cu(int l,int r){
    // printf("at %d=%c %d=%c\n",l,s[l],r,s[r]);
    if(l==r) return 1;
    if(r<l) return 0;
    if(!mem[l][r])
    {
        mem[l][r]=r-l+1;
        int t,val;
        unordered_map<char,bool>m;
        for(int i=l;i<=r;i++)
        {
            t=i;
            val=0;
            if(m[s[i]]) continue;
            for(int j=i+1;j<=r;j++)
            {
                // printf("che %d=%c %d=%c \n",t,s[t],j,s[j]);
                if(s[t]==s[j]) 
                {
                    m[s[t]]=true;
                    val+=cu(t+1,j-1);
                    t=j;
                }
                // printf("%d %d val=%d\n",l,r,val);
            }
            if(val) val+=cu(t+1,r);
                // printf("%d %d %d %d val=%d\n",t+1,r,l,r,val);
            if(val) val+=cu(l,i-1);
                // printf("%d %d val=%d\n",l,r,val);
            if(val) mem[l][r]=min(mem[l][r],(val+1));
        }
    }
    return mem[l][r];
}
int main(){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf(" %c",&s[i]);
        if(s[i]==s[i-1]) i--,n--;
    }
    printf("%d",cu(0,n-1));
}
