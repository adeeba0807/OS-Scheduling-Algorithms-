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

void findrrb(process proc[],int n){

    int remainingtime[n];
    int arrivaltime[n];

    for(int i=0;i<n;i++){
        remainingtime[i]=proc[i].bt;
        arrivaltime[i]=proc[i].at;
    }


    int currenttime=0;
    int completed=0;
    int shortest=0;
    int minArriv=9999;
    int tq=2;


    while(completed<n){
        minArriv=9999;
        for(int i=0;i<n;i++){
            if(proc[i].at <= currenttime && remainingtime[i] > 0 && arrivaltime[i] < minArriv){
                 minArriv=arrivaltime[i];
            shortest=i;
            }
        }
    
       if(remainingtime[shortest]>tq){

        remainingtime[shortest]=remainingtime[shortest]-tq;
        arrivaltime[shortest]=currenttime+(2*tq)-1;

        if(remainingtime[shortest]==0){
            completed++;
            proc[shortest].ct=currenttime+tq;
            proc[shortest].tat=proc[shortest].ct-proc[shortest].at;
            proc[shortest].wt=proc[shortest].tat-proc[shortest].bt;
        }
        
        currenttime=currenttime+tq;
       }
       else{
           completed++;
            proc[shortest].ct=currenttime+remainingtime[shortest];
            proc[shortest].tat=proc[shortest].ct-proc[shortest].at;
            proc[shortest].wt=proc[shortest].tat-proc[shortest].bt;
            currenttime=currenttime+remainingtime[shortest];
            remainingtime[shortest]=0;
       }
    }
}

void printrrb(process proc[],int n){
    cout<<"Process\tATime\tBTime\tCTime\tTaTime\tWTime"<<endl;
    for(int i=0;i<n;i++){
        cout<<proc[i].pno<<"\t"<<proc[i].at<<"\t"<<proc[i].bt<<"\t"<<proc[i].ct<<"\t"<<proc[i].tat<<"\t"<<proc[i].wt<<endl;
    }



}


int main(){
    int n;
    cout<<"enter the number of processes"<<endl;
    cin>>n;

    process proc[n];

    for(int i=0;i<n;i++){
        cout<<"enter process no";
        cin>>proc[i].pno;
        cout<<"enter at for P"<<proc[i].pno;
        cin>>proc[i].at;
        cout<<"enter bt for P"<<proc[i].pno;
        cin>>proc[i].bt;
    }


findrrb(proc,n);
printrrb(proc,n);



return 0;

}