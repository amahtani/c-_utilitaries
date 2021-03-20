/******************************** TP numéro 4 : Ankur MAHTANI & Bastien PESAMOSCA - Exercice 2 ********************************/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/errno.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <fcntl.h>  


extern int errno;

#define TUBE1 "/tmp/fifo1.txt"
#define TUBE2 "/tmp/fifo2.txt"

#define PERMISSIONS 0666



int main(int argc, char **argv) 
{
    int readfd, writefd;
	char tab[3];
	tab[0] = *argv[1];
	tab [1] = *argv[2];
	tab[2]= *argv[3];
	printf("\n%s\n",argv[2]);
	int result;
    // open the fifos: assume the server already created them
       
    if ( (writefd = open(TUBE1, 1)) < 0)
      { printf("client: can't open TUBE1 to write\n"); return 1; }
    if ( (readfd = open(TUBE2, 0)) < 0)
      { printf("client: can't open TUBE2 to read\n"); return 1; }
    

    // connecting to server
   printf("client sent:  %d %c %d ",atoi(&tab[0]),tab[2],atoi(&tab[1]));
    write( writefd, &tab, 3*sizeof(int)); 
    // wait for the server to reply
    printf("client: wait for server reply \n");
    read( readfd, &result, sizeof(int));
    printf("The result is : %d \n",result);
      
    printf("client: closing fifos \n");
    close(readfd);
    close(writefd);

    // now delete the fifos since we're finished
    printf("client: unlink \n"); 
    if (unlink(TUBE1) < 0)
      { printf("client: can't unlink TUBE1"); return 1; }
    if (unlink(TUBE2) < 0)
      { printf("client: can't unlink TUBE2"); return 1; }

    return 0;
}
    
