#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

void fifo(char[],char[],int,int);
void lru(char[],char[],int,int);

int main(){
    int ch,yn=1,i,l,fr;
    char f[10],s[25];
    cout<<"enter no of empty frames: ";
    cin>>fr;
    cout<<"\nenter length of string: ";
    cin>>l;
    cout<<"\nenter the string: ";
    cin>>s;
    for(i=0;i<fr;i++)
        f[i]=-1;
    do{
        cout<<"\nmenu";
        cout<<"\n1:fifo";
        cout<<"\n2:lru";
        cout<<"\n3:exit";
        cout<<"\n enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:for(i=0;i<fr;i++)
                        f[i]=-1;
                    fifo(s,f,l,fr);
                    break;
            case 2:for(i=0;i<fr;i++)
                        f[i]=-1;
                    lru(s,f,l,fr);
                    break;
            case 3:exit(0);
        }
        cout<<"press 1 to continue";
        cin>>yn;
    }while(yn==1);
    return(0);
}

void fifo(char s[],char f[],int l, int fr){
    int i,j=0,k,flag=0,cnt=0;
    cout<<"\npage\tframes\t\t\tfaults\n";
    for(i=0;i<l;i++){
        for(k=0;k<fr;k++){
            if(f[k]==s[i])
                flag=1;
        }
        if(flag==0){
            cout<<s[i];
            f[j]=s[i];
            j++;
            for(k=0;k<fr;k++){
                cout<<"\t"<<f[k];
            }
            cout<<"\tpage-fault "<<cnt<<"\n";
            cnt++;
        }
        else{
            flag=0;
            cout<<s[i];
            for(k=0;k<fr;k++)
                cout<<"\t"<<f[k];
            cout<<"\tno page-fault\n";
        }
        if(j==fr)
            j=0;
    }
}
void lru(char s[],char f[],int l, int fr){
    int i,j=0,k,m,flag=0,cnt=0,top=0;
    cout<<"\npage\tframes\t\t\tfaults\n";
    for(i=0;i<l;i++){
        for(k=0;k<fr;k++){
            if(f[k]==s[i]){
                flag=1;
                break;
            }
        }
        cout<<s[i];
        if(j!=fr && flag!=1){
            f[top]=s[i];
            j++;
            if(j!=fr)
                top++;
        }
        else{
            if(flag!=1){
                for(k=0;k<top;k++)
                    f[k]=f[k+1];
                f[top]=s[i];
            }
            if(flag==1)
            {
                for(m=k;m<top;m++)
                    f[m]=f[m+1];
                f[top]=s[i];
            }
        }
        for(k=0;k<fr;k++){
            cout<<"\t"<<f[k];
        }
        if(flag==0){
            cout<<"\tpage-fault "<<cnt<<"\n";
            cnt++;
        }
        else{
            cout<<"\tno page-fault\n";
        }
        flag=0;
    }
}