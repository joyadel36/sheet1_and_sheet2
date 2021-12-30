
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
//thread function
void* random_thread( void * param )
{

int randnum;
randnum= rand()%10+1 ;
return (void *) randnum;
}
int main()
{
srand(time(0));
int sum=0;
pthread_t thread[5];
int return_value[5];
//create threads
for ( int i=0; i<5; i++ )
{
pthread_create( &thread[i], 0, &random_thread, (void*)i );
}
// joining and waiting for all threads to complete
for ( int i=0; i<5; i++ )
{
 pthread_join( thread[i], (void**)&return_value[i] );
 printf("process  %d  =  %d \n",i,(int)return_value[i]);
sum+= return_value[i] ;
}
//print sum
printf( "sum =  %i ", sum );
}
