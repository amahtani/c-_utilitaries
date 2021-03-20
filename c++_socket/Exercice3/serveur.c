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
    int readfd, writefd, result;
	char* tab = (char*) malloc(3*sizeof(char));

    if( (mkfifo(TUBE1,PERMISSIONS)<0) && (errno != EEXIST) )
    {
        printf("server: can't create tube1 to read: %s \n", TUBE1); return 1;
    }
    
    if( (mkfifo(TUBE2,PERMISSIONS)<0) && (errno != EEXIST) )
    {
        unlink(TUBE1);
        printf("server: can't create tube2 to write: %s \n", TUBE2); return 1;
    }
    



    if ( (readfd = open(TUBE1, 0)) < 0)
        { printf("server: can't open tube1 to read \n"); return 1; }
    if ( (writefd = open(TUBE2, 1)) < 0)
        { printf("server: can't open tube2 to write \n"); return 1; }
    

    printf("server: wait for incoming connection \n");
   

    read(readfd, &tab, 3*sizeof(char));


	
	if(strcmp(&tab[2],"+")){	
    	result = atoi(&tab[0])+ atoi(&tab[1]);    
		printf("server: read %d + %d and sent %d \n",atoi(&tab[0]),atoi(&tab[1]),result);
	}
	else if (strcmp(&tab[2],"-")){	
    	result = atoi(&tab[0])- atoi(&tab[1]);
		printf("server: read %d - %d and sent %d \n",atoi(&tab[0]),atoi(&tab[1]),result);
	}
	else if (strcmp(&tab[2],"*")){	
    	result = atoi(&tab[0])* atoi(&tab[1]);
		printf("server: read %d * %d and sent %d \n",atoi(&tab[0]),atoi(&tab[1]),result);
	}
	else if (strcmp(&tab[2],"/")){	
    	result = atoi(&tab[0])/ atoi(&tab[1]);
		printf("server: read %d / %d and sent %d \n",atoi(&tab[0]),atoi(&tab[1]),result);
	}



    // sending reply

    write( writefd, &result, sizeof(int));
               
    close(readfd);
    close(writefd);     
    return 0;
}
