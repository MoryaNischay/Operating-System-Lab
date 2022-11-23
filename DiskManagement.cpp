#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void firstfit(int blocksize[],int m,int processsize[],int n){
    int allocation[n];
    memset(allocation ,-1,sizeof(allocation));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(blocksize[j] >= processsize[i]){
                allocation[i] = j;
                blocksize[j]-=processsize[i];
                break;
            }
        }
    }
    cout<<"\nProces no.\tprocess size\tblock no.\n";
    for(int i=0;i<n;i++){
        cout<<" "<<i+1<<"\t\t"
        <<processsize[i]<<"\t\t";
        if(allocation[i]!=-1){
            cout<<allocation[i]+1;
        }
        else{
            cout<<"not alloted";
        }
        cout<<endl;
    }
}

void worstfit(int blocksize[],int m,int processsize[],int n){
    int allocation[n];
    memset(allocation ,-1,sizeof(allocation));
    for(int i=0;i<n;i++){
        int wrstidx = -1;
        for(int j=0;j<m;j++){
            if(blocksize[j] >= processsize[i]){
               if(wrstidx==-1){
                   wrstidx = j;
               }
               else if(blocksize[wrstidx]<blocksize[j]){
                   wrstidx = j;
                   
               }
            }
        }
        if(wrstidx !=-1){
            allocation[i] = wrstidx;
            blocksize[wrstidx] -= processsize[i];
        }
    }
   
    cout<<"\nProces no.\tprocess size\tblock no.\n";
    for(int i=0;i<n;i++){
        cout<<" "<<i+1<<"\t\t"
        <<processsize[i]<<"\t\t";
        if(allocation[i]!=-1){
            cout<<allocation[i]+1;
        }
        else{
            cout<<"not alloted";
        }
        cout<<endl;
    }
}

void bestfit(int blocksize[],int m,int processsize[],int n){
    int allocation[n];
    memset(allocation ,-1,sizeof(allocation));
    for(int i=0;i<n;i++){
        int bstidx = -1;
        for(int j=0;j<m;j++){
            if(blocksize[j] >= processsize[i]){
               if(bstidx==-1){
                   bstidx = j;
               }
               else if(blocksize[bstidx] > blocksize[j]){
                   bstidx = j;
                   
               }
            }
        }
        if(bstidx !=-1){
            allocation[i] = bstidx;
            blocksize[bstidx] -= processsize[i];
        }
    }
   
    cout<<"\nProces no.\tprocess size\tblock no.\n";
    for(int i=0;i<n;i++){
        cout<<" "<<i+1<<"\t\t"
        <<processsize[i]<<"\t\t";
        if(allocation[i]!=-1){
            cout<<allocation[i]+1;
        }
        else{
            cout<<"not alloted";
        }
        cout<<endl;
    }
}

int main() {
    int blocksize[]={100, 500, 200, 300, 600};
    int processsize[]={212, 417, 112, 426};
    int m = sizeof(blocksize)/sizeof(blocksize[0]);
    int n = sizeof(processsize)/sizeof(processsize[0]);
    firstfit(blocksize,m,processsize,n);
    return 0;
}