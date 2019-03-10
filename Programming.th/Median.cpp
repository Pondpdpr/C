// https://programming.in.th/task/rev2_problem.php?pid=1110
#include <bits/stdc++.h>
using namespace std;
long long int n,k,l[2][1000005],r[2][1000005],mal[2],mar[2],t1,t2,t,z[2];
long long int amo;
stack<int>st;
int main(){
    int i,j;
    scanf("%lld%lld",&n,&k);
    while(1)
    {
        n--;
        scanf("%lld",&t1);
        if(t1==k) break;
        st.push(t1);
//        printf("yang yu\n");
    }
    while(!st.empty())
    {
        t=st.top(); st.pop();
        if(t>k) t2++;
        else t2--;
        if(t2>0) l[1][t2]++,mal[1]=max(mal[1],t2);
        else if(t2<0) l[0][-t2]++,mal[0]=max(mal[0],-t2);
        else z[0]++,amo++;
    }
    t2=0;
    for(i=0;i<n;i++)
    {
        scanf("%lld",&t1);
        if(t1>k) t2++;
        else t2--;
        if(t2>0) r[1][t2]++,mar[1]=max(mar[1],t2);
        else if(t2<0) r[0][-t2]++,mar[0]=max(mar[0],-t2);
        else z[1]++,amo++;
    }
    amo+=(z[0]*z[1]);
    for(i=1;i<=mal[0] && i<=mar[1];i++) amo+=(l[0][i]*r[1][i]);
    for(i=1;i<=mal[1] && i<=mar[0];i++) amo+=(l[1][i]*r[0][i]);
    printf("%lld",amo+1);
}
