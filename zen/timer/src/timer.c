#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void childProcess(int argc, char** argv, char** envp);
void parentProcess(int argc, char** argv);
int callWithFork(int argc, char** argv, char** envp);

int main(int argc, char** argv, char **envp) {
    callWithFork(argc, argv, envp);
}

int callWithFork(int argc, char** argv, char** envp) {
    if (fork() == 0) {
        childProcess(argc, argv, envp);
    } else {
        parentProcess(argc, argv);
    }

    return 0;
}

void childProcess(int argc, char** argv, char** envp) {
    char* const execParams[] = {"asdf", "Nachricht", "Die Zeit ist abgelaufen", NULL};

    ++argv;

    sleep(atoi(*argv));
    execv("/usr/bin/notify-send", execParams);
}

void parentProcess(int argc, char** argv) {
}
