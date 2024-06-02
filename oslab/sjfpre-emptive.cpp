#include<iostream>
using namespace std;
struct Process{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

void findSJF(Process proc[],int n){
    int remainingTime[n];

for(int i=0;i<n;i++){
    remainingTime[i]=proc[i].bt;
}
//denotes current time
int currentTime=0;
//completed processes
int complete=0;
//index of shortest bt
int shortest=0;
//shortest bt
int minBurst=9999;
while(complete<n){
    minBurst=9999;
    for(int i=0;i<n;i++){
        if(proc[i].at<=currentTime && remainingTime[i]<minBurst && remainingTime[i]>0){
            minBurst=remainingTime[i];
            shortest=i;
        }
    }
    remainingTime[shortest]--;
    if(remainingTime[shortest]==0){
        complete++;
        proc[shortest].ct=currentTime+1;
        proc[shortest].tat=proc[shortest].ct-proc[shortest].at;
        proc[shortest].wt=proc[shortest].tat-proc[shortest].bt;
    }
    currentTime++;
    
}
}
void displayProcessDetails(Process proc[],int n){
    cout<<"Process\tATime\tBTime\tCTime\tTaTime\tWTime"<<endl;
    for(int i=0;i<n;i++){
        cout<<proc[i].pid<<"\t"<<proc[i].at<<"\t"<<proc[i].bt<<"\t"<<proc[i].ct<<"\t"<<proc[i].tat<<"\t"<<proc[i].wt<<endl;
    }



}
int main(){
int n;
cout<<"enter the no. of process"<<endl;
cin>>n;

Process proc[n];
cout<<"enter process details(id,at,bt) "<<endl;
for(int i=0;i<n;i++){
    cout<<"enter the details of process"<<i+1<<endl;
    cin>>proc[i].pid;
    cin>>proc[i].at;
    cin>>proc[i].bt;

}
findSJF(proc,n);
displayProcessDetails(proc,n);













    return 0;
}