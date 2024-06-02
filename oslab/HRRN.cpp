#include<iostream>
using namespace std;
struct process{
    int pno;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

void hrrn(process proc[],int n){
              int remainingtime[n];
              int arrivaltime[n];
              for(int i=0;i<n;i++){
                remainingtime[i]=proc[i].bt;
                arrivaltime[i]=proc[i].at;
              }

              int currenttime=0;
              int completed =0;
              int ratio=9999;
              float hrrn[n];
               int shortest=0;
            
                
                while(completed < n){
                    ratio=9999;
                    for(int i=0;i<n;i++){
                    hrrn[i]=(currenttime-arrivaltime[i]+remainingtime[i])/remainingtime[i];
                      if(arrivaltime[i] <= currenttime && remainingtime[i] > 0 && hrrn[i] < ratio){
                                     shortest=i;
                                     ratio=hrrn[i];
                                    
                      } 
                    }

                      proc[shortest].ct=currenttime+remainingtime[shortest];
                       proc[shortest].tat=proc[shortest].ct-proc[shortest].at;
        proc[shortest].wt=proc[shortest].tat-proc[shortest].bt;

                      completed++;
                      
                       currenttime=currenttime+remainingtime[shortest];
                       remainingtime[shortest]=0;


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
cout<<"enter the numberr of process"<<endl;
cin>>n;
process proc[n];
for(int i=0;i<n;i++){
    cout<<"enter process no"<<endl;
    cin>>proc[i].pno;
    cout<<"enetr at for P"<<proc[i].pno<<endl;
    cin>>proc[i].at;
    cout<<"enetr bt for P"<<proc[i].pno<<endl;
    cin>>proc[i].bt;
}

hrrn(proc,n);
print(proc,n);

return 0;

}