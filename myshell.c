#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "LineParser.h"
#include <string.h>



void execute(cmdLine* pCmdLine){
    pid_t pid = fork();
    if (pid == -1) {
        // fork failed!
        perror("fork failed");
        return; 
    }
    else if(pid==0){
        execvp(pCmdLine->arguments[0], pCmdLine->arguments);
        perror("Error executing command");
        _exit(1);
    }
    else{
    fprintf(stderr, "PID is: %d\n", pid);
    fprintf(stderr, "Executing program file name is: %s\n", pCmdLine -> arguments[0]);
    fprintf(stderr, "Foreground or backgound is: %d\n", pCmdLine -> blocking);
    }
}

int main(int argc, char **argv)
{
    int b = 1;
    while(b==1){
        char cwd[PATH_MAX];
        getcwd(cwd, PATH_MAX);
        printf("Current working directory: %s\n", cwd);

        char input[2048];
        fgets(input, 2048, stdin);
        cmdLine *pCmdLine = parseCmdLines(input);
        if(pCmdLine == NULL){
            continue;
        }
        if(strcmp(pCmdLine -> arguments[0], "quit")==0){
            b=0;
        }
        else{
            execute(pCmdLine);
        }
        freeCmdLines(pCmdLine);
    }
    return 0;
}