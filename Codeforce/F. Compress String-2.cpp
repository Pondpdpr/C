// https://codeforces.com/problemset/problem/1121/F
#include <bits/stdc++.h>
using namespace std;
int n,a,b,mem[5005];
string s;
int f(int x){
    if(x==n-1) return 0;
    if(!mem[x])
    {
        mem[x]=1e9;
        string to;
        for(int i=1;i<=x+1 && (x+i)<n;i++)
        {
            to=s.substr(x+1,i);
            if(i==1) mem[x]=min(mem[x],f(x+i)+a);
            for(int j=0;j<=(x-i+1);j++)
                if(to==s.substr(j,i))
                {
                    mem[x]=min(mem[x],f(x+i)+b);
                    break;
                }
        }
    }
    return mem[x];
}
int main(){
    scanf("%d",&n,&a,&b);
    cin >> s;
    printf("%d",f(0)+a);
}
