 #include <iostream>
using namespace std;


void fcfs(int arr[],int head){
    int size = 8;
    int seekcount = 0;
    int current_track;
    int distance;
    for(int i = 0;i<size;i++){
        current_track = arr[i];
        distance = abs(current_track - head);
        seekcount += distance;
        head = current_track;
    }
    cout<<"Total no. of seek operations: "<<seekcount<<endl;
    cout<<"Seek sequence is: "<<endl;
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }

}

void calculatediff(int request[],int head,int diff[][2],int n){
    for(int i=0;i<n;i++){
        diff[i][0] = abs(head - request[i]);
    }
}
int findmin(int diff[][2],int n){
    int index = -1;
    int minimum = 1e9;
    for(int i = 0; i < n; i++){
        if (!diff[i][1] && minimum > diff[i][0]){
            minimum = diff[i][0];
            index = i;
        }
    }
    return index;
}

void shortestseektimefirst(int request[],int head,int n){
    if(n == 0){
        return;
    }
    int diff[n][2] = {{0,0}};
    int seekcount = 0;
    int seeksequence[n+1] = {0};
    for(int i=0;i<n;i++){
        seeksequence[i] = head;
        calculatediff(request,head,diff,n);
        int index = findmin(diff,n);
        diff[index][1] = 1;
        seekcount += diff[index][0];
        head = request[index];
    }
        seeksequence[n] = head;
        cout<<"The total no. of head movements are: "<<seekcount<<endl;
        cout<<"The seek sequence is: "<<endl;
        for(int i=0;i<=n;i++){
            cout<<seeksequence[i]<<endl;
        }
}


int main() {
    int size = 8;
    int arr[size] = {98,183,37,122,14,65,67};
    int head = 53;
    fcfs(arr,head);

    return 0;
}