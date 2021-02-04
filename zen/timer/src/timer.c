#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void childProcess(int argc, char** argv, char** envp);
void parentProcess(int argc, char** argv, int* childStatus);
int callWithFork(int argc, char** argv, char** envp, int* childStatus);

int main(int argc, char** argv, char **envp) {
  
    for (char **p = argv; *p != 0; ++p) {
        printf("%s\n", *p);
    }

    // printf("Starting sleep ...");
    // fflush(stdout);
    // sleep(atoi(*argv++));
    // // ++argv;
    // printf("call execve ...");
    // execve(argv[0], argv, envp);
}

int callWithFork(int argc, char** argv, char** envp, int* childStatus) {
    // for (char **env = envp; *env != 0; env++) {
    //     char *thisEnv = *env;
    //     printf("%s\n", thisEnv);
    // }

    if (fork() == 0) {
        childProcess(argc, argv, envp);
    } else {
        parentProcess(argc, argv, childStatus);
    }

    printf("Bye\n");
    return 0;
}

void childProcess(int argc, char** argv, char** envp) {
    printf("HC: hello from child\n");
    fflush(stdout);
    sleep(10);
    ++argv;
    execve(argv[0], argv, envp);
}

void parentProcess(int argc, char** argv, int *childStatus) {
    printf("HP: hello from parent\n");
    fflush(stdout);

    wait(childStatus);

    printf("CT: child has terminated\n");
    fflush(stdout);

}
