#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
#include <time.h>

int main(int argc, char **argv)
{
  int fd[2];  
  int i;

  if (pipe(fd))                           /* create pipe            */
    fprintf(stderr, "pipe error\n");
  else if (fork()) 
  {                       		            /* parent: the reader  */
      close(fd[1]);                       /* close the write pipe */
      read(fd[0], &i, sizeof (int));      /* read an integer        */
      printf("Father: reading the value %d\n", i);
  } 
  else 
  {                            		      /* child: the writer      */
      close(fd[0]);
      srand(time(NULL));                  
      i = rand();                         /* generates integer */
      printf("Child: writing the value %d\n", i);
      write(fd[1], &i, sizeof (int));     /* writes the integer */
   }

  return 0;
}
