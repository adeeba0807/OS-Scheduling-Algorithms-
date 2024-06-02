#include<bits/stdc++.h>
using namespace std;
struct Process{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

void calculate(Process proc[],int n){
    int remainingTime[n];
    for(int i=0;i<n;i++){
        remainingTime[i]=proc[i].bt;
    }
    vector<int> ans(n);
    int currentTime=0;
    int completed=0;
     int shortest=0;
     int minBurst=9999;
     while(completed<n){
        minBurst=9999;
     for(int i=0;i<n;i++){
        if(proc[i].at<=currentTime && remainingTime[i]>0 && remainingTime[i]<minBurst){
                     minBurst=remainingTime[i];
                      shortest=i;
        }
     }
      remainingTime[shortest]=0;
      completed++;
      proc[shortest].ct=currentTime+minBurst;
      proc[shortest].tat=proc[shortest].ct-proc[shortest].at;
        proc[shortest].wt=proc[shortest].tat-proc[shortest].bt;

        currentTime=currentTime+minBurst;
     }

}

void displaytable(Process proc[],int n){
    cout<<"Process\tATime\tBTime\tCTime\tTaTime\tWTime"<<endl;
    for(int i=0;i<n;i++){
        cout<<proc[i].pid<<"\t"<<proc[i].at<<"\t"<<proc[i].bt<<"\t"<<proc[i].ct<<"\t"<<proc[i].tat<<"\t"<<proc[i].wt<<endl;
    }



}









int main(){
    int n;
    cout<<"enter the no of processes"<<endl;
    cin>>n;
    Process proc[n];
    
    for(int i=0;i<n;i++){
        cout<<"enter the details for P"<<i+1<<endl;
        cin>>proc[i].pid;
        cin>>proc[i].at;
        cin>>proc[i].bt;
    }


    calculate(proc,n);
    displaytable(proc,n);

return 0;


}