#include<stdio.h> 
#include<string.h> 
#include<pthread.h> 
#include<stdlib.h> 
#include<unistd.h> 
  
pthread_t tid[2]; 
int sum, max; 
pthread_mutex_t lock; 
typedef struct node 
{
	int start, end;

	int *a;
}addition;

addition s;

void* trythis(void *arg) 
{ 
	

	
    pthread_mutex_lock(&lock); 
	
	for(int i = s.start; i <= s.end; i++)
	{
		printf("%d\n", s.a[i]);
		sum = sum + s.a[i];
	}
	s.start = s.end + 10;
	s.end = s.end + 10;
    pthread_mutex_unlock(&lock); 
  
    return NULL; 
} 
  
int main(void) 
{ 
    int i = 5;
	s.a = malloc(50 * sizeof(int));
	s.start = 0;
	s.end = 9;

	for(int j = 0; j < 50; j++)
	{
		s.a[j] = rand() %  100;

		printf("%d\n", s.a[j]);
	}
 

    int error, err; 
  
    if (pthread_mutex_init(&lock, NULL) != 0) 
    { 
        printf("\n mutex init has failed\n"); 
        return 1; 
    } 
  
    while(i < 5) 
    { 
        err = pthread_create(&(tid[i]), NULL, &trythis, NULL); 
        if (error != 0) 
            printf("\nThread can't be created :[%s]", strerror(error)); 
        i++; 
    } 
  
    pthread_join(tid[0], NULL); 
    pthread_join(tid[1], NULL); 
    pthread_join(tid[2], NULL); 
    pthread_join(tid[3], NULL); 
    pthread_join(tid[4], NULL); 

    printf("sum: %d\n", sum);
    pthread_mutex_destroy(&lock); 
  
    return 0; 
} 


