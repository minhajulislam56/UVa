#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;

int func(int i, char keyword[], char lines[]) /****************** COMPARE FUNCTION ******************/
{
    int m, n=0;
    char chk[1000];
    for(m=0;m<strlen(lines);m++)
    {
        if(isalpha(lines[m]))
        {
            chk[n]=tolower(lines[m]);
            n++;

            if(m==strlen(lines)-1)
                goto comp;
        }
        else{
            comp:
                if(strcmp(keyword,chk)==0){
                    i++;
                }
                n=0;
                memset(chk,'\0',strlen(chk));
        }
    }
    return i;
}
int main()
{
    int i,j,k,l, max, w[1000],t=1;
    char keyword[1000][1000], lines[1000][1000];

    while(scanf("%d%d", &k, &l)==2)
    {
        getchar();
        for(i=0;i<k;i++) /********* KEYWORD INPUT *********/
        {
            gets(keyword[i]);
        }
        max=0;
        for(i=0;i<l;i++) /********** LINES INPUT ***********/
        {
            gets(lines[i]);
            w[i]=0;
            for(j=0;j<k;j++)
            {
                w[i]=func(w[i], keyword[j], lines[i]); /*************** FUNCTION CALLING ******************/

                if(max<w[i])
                    max=w[i];
            }
        }
        cout<<"Excuse Set #"<<t<<endl;
        for(i=0;i<l;i++)
        {
            if(max==w[i]){
                cout<<lines[i]<<endl;
            }
        }
        cout<<endl;
        t++;
    }
    return 0;
}
