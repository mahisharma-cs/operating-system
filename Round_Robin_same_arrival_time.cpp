#include<iostream> 
using namespace std; 

void findWaitingTime(int*,int,int*,int*,int);

void findTurnAroundTime(int processes[], int num_process, int bt[], int wt[], int tat[]) 
{ 
	for (int i = 0; i < num_process ; i++) 
		tat[i] = bt[i] + wt[i]; 
} 

void findavgTime(int processes[], int num_process, int bt[],int quantum) 
{ 
	int wt[num_process], tat[num_process], total_wt = 0, total_tat = 0; 
	findWaitingTime(processes, num_process, bt, wt, quantum); 
	findTurnAroundTime(processes, num_process, bt, wt, tat); 
	for (int i=0; i<num_process; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
    } 	
	cout << "\nAverage waiting time = "<< (float)total_wt / (float)num_process; 
	cout << "\nAverage turn around time = "<< (float)total_tat / (float)num_process; 
	cout<<endl;
} 

void findWaitingTime(int processes[], int n,int bt[], int wt[], int quantum)
{ 
	int rem_bt[n]; 
	for (int i = 0 ; i < n ; i++) 
		rem_bt[i] = bt[i]; 
	int t = 0;
	while (1) 
	{ 
		bool done = true; 
		for (int i = 0 ; i < n; i++) 
		{ 
			if (rem_bt[i] > 0) 
			{ 
				done = false;
				if (rem_bt[i] > quantum) 
				{ 
					t += quantum; 
					rem_bt[i] -= quantum; 
				} 
				else
				{ 
					t = t + rem_bt[i]; 
					wt[i] = t - bt[i]; 
					rem_bt[i] = 0; 
				} 
			} 
		} 
		if (done == true) 
		break; 
	} 
}

int main() 
{ 
	int num_process,i,quantum; 
	cout<<endl;
	cout<<"Enter number of processes : ";
	cin>>num_process;
	cout<<"Enter time quantum : ";
	cin>>quantum;
	cout<<endl;
	int processes[num_process];
	int burst_time[num_process];

	for(i=0;i<num_process;i++)
	{
		processes[i] = i+1;
	}
	for(i=0;i<num_process;i++)
	{
		cout<<"Enter burst  time  of P"<<i+1<<" : ";
		cin>>burst_time[i];
	}
	cout<<endl;
	findavgTime(processes, num_process, burst_time, quantum);
	return 0; 
}
