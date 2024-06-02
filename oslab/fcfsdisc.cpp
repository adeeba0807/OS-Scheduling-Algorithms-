#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter the size of sequence";
    cin>>n;
    int arr[n];
    cout<<"enter the values"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int head;
    cout<<"enter the location of head pointer"<<endl;
    cin>>head;
int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+fabs(arr[i]-head);

    }

    cout<<"total number of seek count is"<<sum;
    return 0;
}