#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main()
{
    int tc;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>tc;
    while(1){
        string s[15];
        map<string,int> mp;
        for(int i=0;i<tc;i++){
            cin>>s[i];
            mp[s[i]]=0;
        }
        for(int i=0;i<tc;i++){
            string ts;
            int person, amount, tmp;
            cin>>ts>>amount>>person;
            if(person==0)
                continue;
            tmp=amount/person;
            mp[ts]-=(tmp*person);
            for(int j=0;j<person;j++){
                string toperson;
                cin>>toperson;
                mp[toperson]+=tmp;
            }
        }
        for(int i=0;i<tc;i++)
            cout<<s[i]<<" "<<mp[s[i]]<<endl;
        if(cin>>tc)
            cout<<endl;
        else
            break;
    }

    return 0;
}

