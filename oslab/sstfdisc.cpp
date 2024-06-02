#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
int n;
cout<<"enter the size";
cin>>n;
vector<int> arr(n);
int ar[n];
 cout<<"enter the sequence"<<endl;
 for(int i=0;i<n;i++){
    cin>>ar[i];
    arr.push_back(ar[i]);
 }
 
 vector<int> sub(n);

int head;
cout<<"enter the head position"<<endl;
cin>>head;
int min=9999;
int index;
int count=0;
int sum=0;
while(count<n){
    min=9999;
 for(int i=0;i<arr.size();i++){
    
            sub.push_back(abs(head-arr[i]));
            if(sub[i]<min){
                min=sub[i];
                index=i;
            }
     
 }

sum=sum+min;
head=arr[index];
arr[index]=20000;
sub.clear();
count++;
}
cout<<sum;

    return 0;
}


