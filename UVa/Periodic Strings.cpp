#include <bits/stdc++.h>
using namespace std;
int Q,siz,ta,tn,tp,ans;
bool t1;
char all[85],now[85],pus[85];
int main(){
    int i,j;
    scanf("%d",&Q);
//    freopen("Periodic Strings-out.txt","w",stdout);
    while(Q--)
    {
        scanf("%s",all);
        siz=strlen(all);
        ans=1,tn=tp=0;
        now[0]=all[0];
        for(ta=1;ta<siz;ta++)
        {
            if(all[ta]!=now[tn])
            {
//                printf("all = %c now = %c\n",all[ta],now[tn]);
//                printf("at %d when ",ta,tp);
//                for(i=0;i<6;i++) printf("%c",now[i]);
//                printf("\n");
                pus[tp++]=all[ta];
//                printf("tp = %d\n",tp);
                t1=false;
                for(i=0;i<tp;i++)
                {
                    if(t1) break;
                    if(pus[i]==now[0]) t1=true;
                    now[ans+i]=pus[i];
                }
//                printf("change to ");
//                for(j=0;j<6;j++) printf("%c",now[j]);
//                printf("\n");
                ans+=i;
                ta=ans-1;
//                printf("ans = %d ta = %d\n",ans,ta);
                tp=0;
                tn=0;
            }else
            {
//                printf("all = %c now = %c\n",all[ta],now[tn]);
                pus[tp++]=now[tn];
                tn=(tn+1)%ans;
            }
        }
        printf("%d\n",(!tn)?ans:siz);
        if(Q) printf("\n");
    }
}
/*
1
HoHoHo
*/
