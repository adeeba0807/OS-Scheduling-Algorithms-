#include<bits/stdc++.h>
using namespace std;
struct process{
    int process;
    int blocks;
};
int main(){

int n;
cout<<"enter the no of process";
cin>>n;
process proc[n];

for(int i=0;i<n;i++){
    cout<<"process->block"<<endl;
    cin>>proc[i].process>>proc[i].blocks;
}
int min;
int count=0;
int program;
int block;
    
    for(int i=0;i<n;i++){
        min=999;
        for(int j=0;j<n;j++){
            if((proc[i].blocks-proc[j].process)<min && (proc[i].blocks-proc[j].process)>0 ){
                program=i;
                block=j;
                min=(proc[i].blocks - proc[j].process);

            }
        }


        proc[i].process=proc[program].process;
        proc[i].blocks=proc[block].blocks;
         cout<<"pro\tblock"<<endl;
    cout<<proc[i].process<<"\t"<<proc[i].blocks<<endl;
        proc[block].blocks=9999;
  
}


    return 0;
}
