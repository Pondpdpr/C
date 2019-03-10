#include <bits/stdc++.h>
using namespace std;
int n,r,ris[9],t1,t2,t3,t4,t5,t6,t7,t8;
int main(){
    int i,j;
    scanf("%d%d",&n,&r);
    for(i=0;i<r;i++)
    {
        scanf("%d",&t1);
        ris[t1]=1;
    }
    if(n==1)
    {
        for(t1=1;t1<=n;t1++) if(!ris[t1]) printf("%d\n",t1);
    }
    else if(n==2)
    {
        for(t1=1;t1<=n;t1++) if(!ris[t1])
            for(t2=1;t2<=n;t2++) if(t2!=t1)
                printf("%d %d\n",t1,t2);
    }else if(n==3)
    {
        for(t1=1;t1<=n;t1++) if(!ris[t1])
            for(t2=1;t2<=n;t2++) if(t2!=t1)
                for(t3=1;t3<=n;t3++) if(t3!=t1&&t3!=t2)
                    printf("%d %d %d\n",t1,t2,t3);
    }else if(n==4)
    {
        for(t1=1;t1<=n;t1++) if(!ris[t1])
            for(t2=1;t2<=n;t2++) if(t2!=t1)
                for(t3=1;t3<=n;t3++) if(t3!=t1&&t3!=t2)
                    for(t4=1;t4<=n;t4++) if(t4!=t1&&t4!=t2&&t4!=t3)
                        printf("%d %d %d %d\n",t1,t2,t3,t4);
    }else if(n==5)
    {
        for(t1=1;t1<=n;t1++) if(!ris[t1])
            for(t2=1;t2<=n;t2++) if(t2!=t1)
                for(t3=1;t3<=n;t3++) if(t3!=t1&&t3!=t2)
                    for(t4=1;t4<=n;t4++) if(t4!=t1&&t4!=t2&&t4!=t3)
                        for(t5=1;t5<=n;t5++) if(t5!=t1&&t5!=t2&&t5!=t3&&t5!=t4)
                        printf("%d %d %d %d %d\n",t1,t2,t3,t4,t5);
    }else if(n==6)
    {
        for(t1=1;t1<=n;t1++) if(!ris[t1])
            for(t2=1;t2<=n;t2++) if(t2!=t1)
                for(t3=1;t3<=n;t3++) if(t3!=t1&&t3!=t2)
                    for(t4=1;t4<=n;t4++) if(t4!=t1&&t4!=t2&&t4!=t3)
                        for(t5=1;t5<=n;t5++) if(t5!=t1&&t5!=t2&&t5!=t3&&t5!=t4)
                            for(t6=1;t6<=n;t6++) if(t6!=t1&&t6!=t2&&t6!=t3&&t6!=t4&&t6!=t5)
                            printf("%d %d %d %d %d %d\n",t1,t2,t3,t4,t5,t6);
    }else if(n==7)
    {
        for(t1=1;t1<=n;t1++) if(!ris[t1])
            for(t2=1;t2<=n;t2++) if(t2!=t1)
                for(t3=1;t3<=n;t3++) if(t3!=t1&&t3!=t2)
                    for(t4=1;t4<=n;t4++) if(t4!=t1&&t4!=t2&&t4!=t3)
                        for(t5=1;t5<=n;t5++) if(t5!=t1&&t5!=t2&&t5!=t3&&t5!=t4)
                            for(t6=1;t6<=n;t6++) if(t6!=t1&&t6!=t2&&t6!=t3&&t6!=t4&&t6!=t5)
                                for(t7=1;t7<=n;t7++) if(t7!=t1&&t7!=t2&&t7!=t3&&t7!=t4&&t7!=t5&&t7!=t6)
                                    printf("%d %d %d %d %d %d %d\n",t1,t2,t3,t4,t5,t6,t7);
    }else if(n==8)
    {
        for(t1=1;t1<=n;t1++) if(!ris[t1])
            for(t2=1;t2<=n;t2++) if(t2!=t1)
                for(t3=1;t3<=n;t3++) if(t3!=t1&&t3!=t2)
                    for(t4=1;t4<=n;t4++) if(t4!=t1&&t4!=t2&&t4!=t3)
                        for(t5=1;t5<=n;t5++) if(t5!=t1&&t5!=t2&&t5!=t3&&t5!=t4)
                            for(t6=1;t6<=n;t6++) if(t6!=t1&&t6!=t2&&t6!=t3&&t6!=t4&&t6!=t5)
                                for(t7=1;t7<=n;t7++) if(t7!=t1&&t7!=t2&&t7!=t3&&t7!=t4&&t7!=t5&&t7!=t6)
                                    for(t8=1;t8<=n;t8++) if(t8!=t1&&t8!=t2&&t8!=t3&&t8!=t4&&t8!=t5&&t8!=t6&&t8!=t7)
                                        printf("%d %d %d %d %d %d %d %d\n",t1,t2,t3,t4,t5,t6,t7,t8);
    }
}
