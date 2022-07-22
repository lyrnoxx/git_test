#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int main(){
    int max[10][10],need[10][10],alloc[10][10],comp[10],avail[10],safe[10];
    int p,r,i,j,process,count=0;
    cout<<"Enter the no of processes: ";
    cin>>p;
    for(i=0;i<p;i++){
        comp[i]=0;
    }
    cout<<"Enter the no of resources: ";
    cin>>r;
    cout<<"Enter the max maxtrix for each process: ";
    for(i=0;i<p;i++){
        cout<<endl<<"for process "<<i+1<<": ";
        for(j=0;j<r;j++){
            cin>>max[i][j];
        }
    }
    cout<<"Enter allocation for each process: ";
    for(i=0;i<p;i++){
        cout<<endl<<"for process "<<i+1<<": ";
        for(j=0;j<r;j++){
            cin>>alloc[i][j];
        }
    }
    cout<<"Enter the available resources: ";
    for(i=0;i<r;i++){
        cin>>avail[i];
    }
    for(i=0;i<p;i++){
        for(j=0;j<r;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    do{
        cout<<"Max matrix:\tAllocation matrix:\n";
        for(i=0;i<p;i++){
            for(j=0;j<r;j++){
                cout<<max[i][j]<<" ";
            }
            cout<<"\t\t";
            for(j=0;j<r;j++){
                cout<<alloc[i][j]<<" ";
            }
            cout<<"\n";
        }
        process=-1;
        for(i=0;i<p;i++){
            if(comp[i]==0){
                process=i;
                for(j=0;j<r;j++){
                    if(avail[j]<need[i][j]){
                        process=-1;
                        break;
                    }
                }
            }
            if(process!=-1)
            break;
        }
        if(process!=-1)
        {
            cout<<"process "<<process+1<<" completed!\n";
            safe[count]=process+1;
            count++;
            for(j=0;j<r;j++){
                avail[j]+=alloc[process][j];
                alloc[process][j]=0;
                max[process][j]=0;
                comp[process]=1;
            }
        }
    }
    while(count!=p && process!=-1);
    if(count==p){
        cout<<"\nThe system is in safe state\n";
        cout<<"safe sequence: ";
        for(i=0;i<p;i++){
            cout<<safe[i]<<" ";
        }
    }
    else{
        cout<<"\nThe system is in unsafe state ";
    }
}