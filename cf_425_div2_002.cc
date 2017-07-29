#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=100000+10;
bool ltr[26];
char in[MAXN];
char exm[MAXN];
char good[26];
int vis[MAXN];
int pp;
int t;
int main()
{
    while(~scanf("%s",good))
    {
        memset(exm,0,sizeof exm);
        scanf("%s",exm);
        memset(ltr,0,sizeof ltr);
        int len=strlen(good);
        for(int i=0; i<len; i++)
        {
            ltr[good[i]-'a']=1;
        }
        int len1=strlen(exm),k=0;
        bool ext=0;
        for(int i=0; i<len1; i++,k++)
        {
            if(exm[i]=='*')
            {
                pp=i;
                ext=1;
            }
        }
        scanf("%d",&t);
        while(t--)
        {
            bool flag=1;
            memset(in,0,sizeof in);
            scanf("%s",in);
            int len2=strlen(in);
            //   cout<<flag<<endl;
            if(!ext&&len2!=len1) flag=0;
            //     cout<<flag<<endl;
            if(ext&&len2+1<len1)  flag=0;
            if(len2<=len1-2)    flag=0;
           //    cout<<flag<<endl;
            int p=len2-len1+1;
            if(flag)
            {
                // cout<<"!"<<endl;
                int i,j;
                for(i=0,j=0; i<len1&&j<len2&&flag; i++,j++)
                {
                    if(exm[i]==in[j]||(exm[i]=='?'&&ltr[in[j]-'a']))
                        ;
                    else if(exm[i]=='*')
                    {
                        for(int k=0; k<p&&flag; k++,j++)
                        {
                            if(ltr[in[j]-'a'])
                            {
                                flag=0;
                            }
                            // if(p)
                          //  cout<<flag<<endl;
                        }
                        j--;
                    }
                    else
                        flag=0;
                }
            }
            if(flag)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
