#include <bits/stdc++.h>
using namespace std;
char a,t2;
int ma,mem[2][260],ans[260],cnt,t1,t3;
stack<char>st;
int main(){
    int i,j;
    while(1)
    {
        cnt++;
        scanf("%c",&a);
        if(a>='0' & a<='9')
        {
//            printf("in when %c \n",a);
            st.push(a);
        }else if(a==' ')
        {
//            printf("skip\nt3= %d\n",t3);
            t1=0;
            while(!st.empty())
            {
                t2=st.top(),st.pop();
                mem[t3][t1]=t2-'0';
                t1++;
            }
            t3++;
            ma=max(ma,cnt-1);
            cnt=0;
        }else if(a=='\n')
        {
//            printf("skip\nt3= %d\n",t3);
            t1=0;
            while(!st.empty())
            {
                t2=st.top(),st.pop();
                mem[t3][t1]=t2-'0';
                t1++;
            }
            ma=max(ma,cnt-1);
            break;
        }
    }
    for(i=0;i<ma;i++)
    {
        ans[i+1]=(ans[i]+mem[0][i]+mem[1][i])/10;
        ans[i]=(ans[i]+mem[0][i]+mem[1][i])%10;
    }
    if(ans[ma]!=0) printf("%d",ans[ma]);
    for(i=ma-1;i>=0;i--) printf("%d",ans[i]);
//    printf("\nfirst in\n");
//    for(i=ma-1;i>=0;i--) printf("%d",mem[0][i]);
//    printf("\nsecond in\n");
//    for(i=ma-1;i>=0;i--) printf("%d",mem[1][i]);
}
/*
9999999999999999999999 9999999999999999999999
*/
