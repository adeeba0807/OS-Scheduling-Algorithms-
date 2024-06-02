#include<bits/stdc++.h>
using namespace std;
struct process{
    int pno;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

void fcfs(process proc[], int n){
    int remainingtime[n];
    for(int i=0;i<n;i++){
        remainingtime[i]=proc[i].bt;
    }
    int currenttime=0;
    int counted=0;
    int minArrival=9999;
    int shortest;
    while(counted<n){
        minArrival=9999;
        for(int i=0;i<n;i++){
        if(proc[i].at <= currenttime && remainingtime[i]>0 && proc[i].at <minArrival ){
            shortest=i;
            minArrival=proc[i].at;
        }  
     
        }
        if(minArrival==9999){
            currenttime++;
        }
        else{
        proc[shortest].ct=currenttime+remainingtime[shortest];
         proc[shortest].tat=proc[shortest].ct-proc[shortest].at;
            proc[shortest].wt=proc[shortest].tat-proc[shortest].bt;

        currenttime=currenttime+remainingtime[shortest];
         remainingtime[shortest]=0;
          counted++;
        }
    }
}
void print(process proc[],int n){

     cout<<"Process\tATime\tBTime\tCTime\tTaTime\tWTime"<<endl;
    for(int i=0;i<n;i++){
        cout<<proc[i].pno<<"\t"<<proc[i].at<<"\t"<<proc[i].bt<<"\t"<<proc[i].ct<<"\t"<<proc[i].tat<<"\t"<<proc[i].wt<<endl;
    }


}
int main(){

    int n;
    cout<<"enter the no of processes"<<endl;
    cin>>n;
     process proc[n];
    for(int i=0;i<n;i++){
        cout<<"enter the process no"<<endl;
        cin>>proc[i].pno;
        cout<<"enter the at forP"<<proc[i].pno<<endl;
        cin>>proc[i].at;
        cout<<"enter the bt for P"<<proc[i].pno<<endl;
        cin>>proc[i].bt;

    }

    fcfs(proc,n);
    print(proc,n);

    return 0;
}