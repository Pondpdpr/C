#include <bits/stdc++.h>
using namespace std;
int n;
int dom(int x,int b){
    if(x>n) return 0;
    if(x==n)
    {
        for(int i=1;i<=n;i++)
        {
            if(b&(1<<i-1)) printf("--\n");
            else
            {
                printf("||\n");
                i++;
            }
        }
        printf("E\n");
    }
    dom(x+1,(b|(1<<x)));
    dom(x+2,b);
}
int main(){
    int i,j;
    scanf("%d",&n);
    dom(0,0);
}
