#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/errno.h>
#include <stdio.h>
#include <time.h>

extern int errno;

#define FIFO1 "/tmp/fifo1.txt"
#define FIFO2 "/tmp/fifo2.txt"

#define PERMISSIONS 0666


