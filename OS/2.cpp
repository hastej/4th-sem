#include<iostream>
using namespace std;
int num;
void swap(int *a, int *b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}

int main() {
    cout<<"Enter number of jobs- ";
    cin>>num;
    cout<<endl;
    int jobs[6][num];
    for(int i =0;i<num;i++){
      jobs[0][i] = i+1;
    }

    cout<<"Input arrival time of all processess - "<<endl;
 
    for(int i =0;i<num;i++){
      cin>>jobs[1][i];
    }

    cout<<"Input burst time of all processess - "<<endl;
    
    for(int i =0;i<num;i++){
      cin>>jobs[2][i];
    }

    cout<<endl;

   for(int i=0; i<num; i++) {
      for(int j=0; j<num-i-1; j++) {
         if(jobs[1][j] > jobs[1][j+1]) {
            for(int k=0; k<5; k++) {
               swap(jobs[k][j], jobs[k][j+1]);
            }
         }
      }
   }
   int temp, val;
   jobs[3][0] = jobs[1][0] + jobs[2][0];
   jobs[5][0] = jobs[3][0] - jobs[1][0];
   jobs[4][0] = jobs[5][0] - jobs[2][0];
    for(int i=1; i<num; i++) {
      temp = jobs[3][i-1];
      int low = jobs[2][i];
      for(int j=i; j<num; j++) {
         if(temp >= jobs[1][j] && low >= jobs[2][j]) {
            low = jobs[2][j];
            val = j;
         }
      }
      jobs[3][val] = temp + jobs[2][val];
      jobs[5][val] = jobs[3][val] - jobs[1][val];
      jobs[4][val] = jobs[5][val] - jobs[2][val];
      for(int k=0; k<6; k++) {
         swap(jobs[k][val], jobs[k][i]);
      }
   }
   cout<<"\nFirst Come First Serve Jobs Scheduling\n";
   cout<<"Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
   for(int i=0; i<num; i++) {
      cout<<jobs[0][i]<<"\t\t"<<jobs[1][i]<<"\t\t"<<jobs[2][i]<<"\t\t"<<jobs[4][i]<<"\t\t"<<jobs[5][i]<<"\n";
   }
}
