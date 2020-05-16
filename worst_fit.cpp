#include <iostream>
using namespace std;
int main()

{
	cout<<"\nWorst Fit\n\n";
    int nBlocks,nProcess,blockSize[20],processSize[20];
    cout<<" Enter the number of blocks : "; cin>>nBlocks;
    cout<<" Enter the number of processes : "; cin>>nProcess;
	cout<<" Enter the size of each block : ";
	for(int i=0;i<nBlocks;i++) cin>>blockSize[i];
	cout<<" Enter the size of each process : ";
    for(int x=0;x<nProcess;x++) cin>>processSize[x];
	for(int k=0;k<nProcess;k++)
	{
	   int max = blockSize[0];
	   int pos = 0;
	   for(int j=0;j<nBlocks;j++)

		if(max < blockSize[j]) { max = blockSize[j]; pos = j; } if(max >= processSize[k])
		{
			cout<<"\nProcess "<<k+1<<" is allocated to block "<<pos+1;
			blockSize[pos] = blockSize[pos]-processSize[k];
		}
		else{
		cout<<"\nProcess "<<k+1<<" can't be allocated";
		}
	}
    return 0;
}
