#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int size = 8;
int disk_size = 200;

void clook(int arr[],int head){
    int seek_count = 0;
    int distance,curr_track;
    vector<int>left,right;
    vector<int>seek_seq;
    
    for(int i=0;i<size;i++){
        if(arr[i]<head)
            left.push_back(arr[i]);
        if(arr[i]>head)
            right.push_back(arr[i]);
    }
    
    std::sort(left.begin(),left.end());
    std::sort(right.begin(),right.end());
    
    for(int i=0;i<right.size();i++){
        curr_track = right[i];
        seek_seq.push_back(curr_track);
        distance = abs(curr_track - head);
        seek_count += distance;
        head = curr_track;
    }
    
    seek_count +=abs(head - left[0]);
    head = left[0];
    
    for(int i=0;i<left.size();i++){
        curr_track = left[i];
        seek_seq.push_back(curr_track);
        distance = abs(curr_track - head);
        seek_count += distance;
        head = curr_track;
    }
    cout<<"Total number of seek operations = "<<seek_count<<endl;
    cout<<"Seek sequence is "<<endl;
    for(int i=0;i<seek_seq.size();i++){
        cout<<seek_seq[i]<<endl;
    }
    
}
  int main(){
      int arr[size] = { 176, 79, 34, 60, 92, 11, 41, 114 };
      int head = 50;
      cout<<"Initial  position of head is: "<<head<<endl;
      clook(arr,head);
      return 0;
    
}