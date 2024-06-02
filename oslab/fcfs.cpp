#include<iostream>
using namespace std;
int main(){

int arr[10][10];
int n;
cout<<"enter the no. of processes"<<endl;
cin>>n;

for(int j=0;j<n;j++){

    cout<<"enter the process no.";
    cin>>arr[j][0];
    cout<<"enter the arrival time for P"<<arr[j][0]<<endl;
    cin>>arr[j][1];
    cout<<"enter the burst time for P"<<arr[j][0]<<endl;
    cin>>arr[j][2];

}



for(int j=0;j<n;j++){
    
        arr[0][3]=arr[0][1];
        arr[j+1][3]=arr[j][1]+arr[j][2]+arr[j][3]-arr[j+1][1];
        arr[j][4]=arr[j][1]+arr[j][2]+arr[j][3];
        arr[j][5]=arr[j][4]-arr[j][3];
    
}

cout<<"PNo"<<" "<<"AT"<<" "<<"BT"<<"  "<<"WT"<<"  "<<"CT"<<"  "<<"TAT"<<endl;
float sum=0;
for(int j=0;j<5;j++){
    for(int i=0;i<6;i++){
        cout<<arr[j][i]<<"   ";
        
    }
    sum=sum+arr[j][3];
cout<<endl;
}

float avg=sum/n;

cout<<"avg waiting time:"<<avg<<endl;


cout<<"GANTT CHART:"<<endl;

for(int i=0;i<n;i++){
cout<<"P"<<i;
for(int j=0;j<arr[i][2];j++){
    cout<<".";
}

}
cout<<endl;
return 0;
}