#include<bits/stdc++.h>
using namespace std;
#define MAX 1000006
int node[MAX][26],isWord[MAX],root,nnode;
void initialize()
{
    root=nnode=0;
    memset(isWord,0,sizeof isWord);
    for(int i=0;i<26;i++){
        node[root][i]=-1;
    }
}
void inserting(string st)
{
    int now=root;
    for(int i=0;i<st.length();i++){
        if(node[now][tolower(st[i])-'a']==-1){
            node[now][tolower(st[i])-'a']=++nnode;
            for(int j=0;j<26;j++)
                node[nnode][j]=-1;
        }
        now=node[now][tolower(st[i])-'a'];
    }
    isWord[now]++;
}
int searching(string st)
{
    int now=root;
    for(int i=0;i<st.length();i++){
        if(node[now][tolower(st[i])-'a']!=-1)
            now=node[now][tolower(st[i])-'a'];
        else
            return -1;
    }
    if(isWord[now]){
        return now;
    }
    return -1;
}
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int tc;
    scanf("%d\n\n",&tc);

    while(tc--){
        char spces[35];
        initialize();
        vector<string> vec;
        int cnt=0;
        while(gets(spces)){
            if(spces[0]=='\0') break;

            cnt++;
            if(searching(spces)==-1){
                vec.push_back(spces);
                inserting(spces);
            }
            else{
                isWord[searching(spces)]++;
            }
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++){
            int nmbr=isWord[searching(vec[i])];
            double ans=(nmbr*1.0)*100.0/(double)cnt;
            printf("%s %.4f\n",vec[i].c_str(),ans);
        }
        if(tc) printf("\n");
    }

    return 0;
}
