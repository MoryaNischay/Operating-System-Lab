#include <iostream>
using namespace std;
int main(){
    int i,j,k;
    int n=5;
    int m=3;
    

    int max[5][3] = {{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
    int alloted[5][3] = {{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};\
    int aval[3] = {3,3,2};
    int stat[n] = {0};
    int seq[n] = {0};
    int x = 0;
    int need[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            need[i][j]=max[i][j]-alloted[i][j];
        }
    }
    int y=0;
    for(int k=0;k<5;k++){
        for(int i=0;i<n;i++){
            if(stat[i]==0){
                int flag=0;
                for(int j=0;j<m;j++){
                    if(need[i][j]>aval[j]){
                        flag = 1;
                        break;
                    }
                }
                if(flag==0){
                    seq[x++] = i;
                    for(int y=0;y<m;y++){
                        aval[y] +=alloted[i][y];
                    }
                    stat[i]=1;
                }
            }
        }
    }
    bool flag = true;
    for(int i=0;i<n;i++){
        if(stat[i] == 0){
            flag = false;
            cout<<"System is in deadlock";
            break;
        }
    }
    if(flag = true){
        cout<<"Sysetm is in safe state and the sequence is"<<endl;
        for(int i=0;i<n-1;i++){
            cout<<"P"<<seq[i]<<" ->";
        }
        cout<<"P"<<seq[n-1]<<endl;
    }
    return 0;
}