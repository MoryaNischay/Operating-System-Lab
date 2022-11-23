#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int size = 8;
int disk_size = 200;

void scan(int arr[],int head,string direction){
    int seek_count = 0;
    int distance,curr_track;
    vector<int>left,right;
    vector<int>seek_seq;
    
    if(direction == "left"){
        left.push_back(0);
    }
    else if(direction =="right"){
        right.push_back(disk_size - 1);
    }
    
    for(int i=0;i<size;i++){
        if(arr[i]<head)
            left.push_back(arr[i]);
        if(arr[i]>head)
            right.push_back(arr[i]);
    }
    std::sort(left.begin(),left.end());
    std::sort(right.begin(),right.end());
    
    int run = 2;
    while(run--){
        if(direction =="left"){
            for(int i=left.size()-1;i>=0;i--){
                curr_track = left[i];
                seek_seq.push_back(curr_track);
                distance = abs(curr_track - head);
                seek_count +=distance;
                head = curr_track;
            }
            direction = "right";
        }
        else if(direction =="right"){
            for(int i=0;i<right.size();i++){
                curr_track = right[i];
                seek_seq.push_back(curr_track);
                distance = abs(curr_track - head);
                seek_count +=distance;
                head = curr_track;
            }
            direction = "left";
        }
    }
    cout<<"Total number of seek operations = "<<seek_count<<endl;
    cout<<"Seek sequence is: "<<endl;
    for(int i=0;i<seek_seq.size();i++){
        cout<<seek_seq[i]<<" "<<endl;
    }
}
int main() {
    int arr[size] = { 176, 79, 34, 60,92, 11, 41, 114 };
    int head = 50;
    string direction = "left";
    scan(arr,head,direction);

    return 0;
}