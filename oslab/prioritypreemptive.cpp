#include<bits/stdc++.h>
using namespace std;

struct process{
    int pno;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int priority;
};

void priorityp(process proc[],int n){
         int remainingtime[n];
         int arrivaltime[n];
         for(int i=0;i<n;i++){
                  remainingtime[i]=proc[i].bt;
                  arrivaltime[i]=proc[i].at;
         } 
         int currenttime=0;
         int counted=0;
         int highpriority=0;
         int priority;
         int shortest;


         while(counted < n){
           highpriority=0;
           for(int i=0;i<n;i++){
            if(arrivaltime[i]<=currenttime && remainingtime[i]>0 && proc[i].priority>highpriority){
                shortest=i;
                highpriority=proc[i].priority;
            }
           }

           remainingtime[shortest]=remainingtime[shortest]-1;
           if(remainingtime[shortest]==0){
           proc[shortest].ct=currenttime+remainingtime[shortest]+1;
           proc[shortest].tat=proc[shortest].ct-proc[shortest].at;
           proc[shortest].wt=proc[shortest].tat-proc[shortest].bt;
           counted++;
           }
           currenttime++;
           
         }
}
void print(process proc[],int n){
    cout<<"pno\tat\tbt\tpri\tct\ttat\twt\t"<<endl;
    for(int i=0;i<n;i++){
        cout<<proc[i].pno<<"\t"<<proc[i].at<<"\t"<<proc[i].bt<<"\t"<<proc[i].priority<<"\t"<<proc[i].ct<<"\t"<<proc[i].tat<<"\t"<<proc[i].wt<<endl;
    }

}

int main(){
int n;
cout<<"enter the no. of processes"<<endl;
cin>>n;
process proc[n];
for(int i=0;i<n;i++){
    cout<<"enter the process no"<<endl;
    cin>>proc[i].pno;
    cout<<"enter the at for P"<<proc[i].pno;
    cin>>proc[i].at;
    cout<<"enter the bt for P"<<proc[i].pno;
    cin>>proc[i].bt;
    cout<<"enter the priority for P"<<proc[i].pno;
    cin>>proc[i].priority;
}

priorityp(proc,n);
print(proc,n);
return 0;
}