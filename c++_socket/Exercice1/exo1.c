/******************************** TP numéro 4 : Ankur MAHTANI & Bastien PESAMOSCA - Exercice 1 ********************************/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) // Programme qui affiche le nombre de fichiers dans le répertoire courant
{

	int desc[2]; //on initialise un descripteur de pipe

	char *ls_args[] = {"ls", NULL}; 
	char *wc_args[] = {"wc", "-l", NULL};
	
	int pid;
	if(pipe(desc))  //si cette valeur est différente de 0, le pipe n'a pas été créé
	{
		perror("Echec dans la création du pipe");
		return(1);  //fin du programme en cas d'échec de création d'un pipe
	}
	
	pid = fork();   //on créé un processus fils
	if (pid == 0)   //si le fils est bien créé, pid = 0, sinon pid=-1
	{
		//l'enfant s'occupe du wc -l
		
		close(desc[1]); //on ferme le pipe en écriture
		
		dup2(desc[0], STDIN_FILENO); //on remplace l'entrée standard avec la lecture sur le pipe
		
		execvp("wc", wc_args); //On execute wc -l
	}

	else //quand on est dans le processus père
	{
		//le parent s'occupe du ls
		
		close(desc[0]); //on ferme le pipe en lecture
		
		dup2(desc[1], STDOUT_FILENO); //On remplace la sortie standard avec l'écriture sur le pipe
		
		execvp("ls", ls_args); //On exécute ls
	}

return 0;
}

