#include <stdio.h>  
#include <unistd.h>  
#include <stdlib.h>  
#include <pthread.h>  
#include <semaphore.h>   
#define MAX_PATIENTS 25 // Function prototypes...  
  
void *patient(void *num); 
void *doctor(void *); 
void randwait(int secs); 
sem_t waitingRoom;  
//doctorChair ensures mutually exclusive access to the doctor chair. 
sem_t doctorChair; 
sem_t doctorPillow; 
sem_t seatBelt;  
int allDone = 0;  
  
int main(int argc, char *argv[])  
{  
    pthread_t btid;  
    pthread_t tid[MAX_PATIENTS];  
    int i, x, numPatients, numChairs; int Number[MAX_PATIENTS];  
    printf("Maximum number of patients can only be 25.\nEnter number of patients and chairs.\n");     
	scanf("%d",&x);     
	numPatients = x;     
	scanf("%d",&x);     
	numChairs = x;      
	if (numPatients > MAX_PATIENTS) 
	{  
	   printf("The maximum number of Patients is %d.\n",MAX_PATIENTS);
	   system("PAUSE");     
	   return 0;      
	}      
	printf("A solution to the sleeping doctor problem using semaphores.\n");     
	for (i = 0; i < MAX_PATIENTS; i++) 
	{  
		Number[i] = i;  
	}  
	sem_init(&waitingRoom, 0, numChairs);      
	sem_init(&doctorChair, 0, 1);     
	sem_init(&doctorPillow, 0, 0);     
	sem_init(&seatBelt, 0, 0);     
	pthread_create(&btid, NULL, doctor, NULL);     
	for (i = 0; i < numPatients; i++) {  
		pthread_create(&tid[i], NULL, patient, (void*)&Number[i]);
	}  
	for (i = 0; i < numPatients; i++) 
	{          
		pthread_join(tid[i],NULL);  
	}
	allDone = 1;     
	sem_post(&doctorPillow);      
	pthread_join(btid,NULL);     
	system("PAUSE");     
    return 0;  
}    

void *patient(void *number) 
{      
	int num = *(int *)number;  
    printf("Patient %d leaving for doctor shop.\n", num);      
	randwait(5);       
	printf("Patient %d arrived at doctor shop.\n", num);      
	sem_wait(&waitingRoom);       
	printf("Patient %d entering waitingroom.\n", num);
	sem_wait(&doctorChair);
	sem_post(&waitingRoom);       
	printf("Patient %d waking the doctor.\n", num);      
	sem_post(&doctorPillow);      
	sem_wait(&seatBelt);       
	sem_post(&doctorChair);  
    printf("Patient %d leaving doctor shop.\n", num);  
}    

void *doctor(void *junk)  
{  
	while (!allDone) 
	{     
		printf("The doctor is sleeping\n");      
		sem_wait(&doctorPillow);      
		if (!allDone)      
		{   
			printf("The doctor is cutting hair\n");      randwait(3);  
			printf("The doctor has finished cutting hair.\n");       
			sem_post(&seatBelt);  
		}      
		else 
		{  
			printf("The doctor is going home for the day.\n");      
		}  
	}  
}

void randwait(int secs) 
{      
	int len = 1; // Generate an arbit number...       
}