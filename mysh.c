#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void interactiveMode(const char *filename){        //Interactivemode is when the programming is using the terminal and the commands the user inputs. 

    int fd = open(filename, O_RDONLY);
    int isattyResult = isatty(fd);

    if(isattyResult == 1){
        printf("Welcome to my shell!\n");
    }

}

void batchMode(const char *filename){               //Batchmode is when there is 1 argument in the command and that is the file that will be read. 

    int fd = open(filename, O_RDONLY);
    int isattyResult = isatty(fd);

    



}







int main(int argc, char* argv[]){

const char* filename = argv[1];

int fd = open(filename, O_RDONLY);


    if(fd == -1){
        perror("Error opening file");
        EXIT_FAILURE;

    }


    if(argc > 2){
        printf("Failure, too many arguments\n");
        EXIT_FAILURE;
    }
    else if(argc == 1){
        interactiveMode(filename);
    }
    else if(argc == 2){
        batchMode(filename);
    }

return EXIT_SUCCESS;

}