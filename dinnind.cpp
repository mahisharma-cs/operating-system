#include<iostream>
#include<stdlib.h>
using namespace std;

int mutex=1;
int teacher_write=0;
int pen=4;
int x=0;

int main()
{
	int n;
	void write();
	void penLeft();
	int wait(int);
	int signal(int);
	cout<<"\n1. Teacher writes   2. Teacher leave the pen   3. Exit";
	while(1)
	{
	cout<<"\nEnter your choice : ";
	cin>>n;
	switch(n)
		{
			case 1: if((mutex==1)&&(pen!=0))
			write();
			else
			cout<<"\nMaximum teachers are writing \t please wait.. ";
			break;
			case 2: if((mutex==1)&&(teacher_write!=0))
			penLeft();
			else
			cout<<"All pens are on table";
			break;
			case 3:
			exit(0);
			break;
		}
	}
}

int wait(int s)
{
	return (--s);
}

int signal(int s)
{
	return(++s);
}

void write()
{
	mutex=wait(mutex);
	teacher_write=signal(teacher_write);
	pen=wait(pen);
	x++;
	cout<<"\nTeacher that are writing : "<<x;
	mutex=signal(mutex);
}

void penLeft()
{
	mutex=wait(mutex);
	teacher_write=wait(teacher_write);
	pen=signal(pen);
	x--;
	cout<<"\nPens that are under use :"<<x;
	mutex=signal(mutex);
}