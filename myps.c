#include <stdio.h>
#include <string.h>

int error(int nb);
void parse_argv(char *argv[]);
void display(char *arg[]);

int main(int argc, const char *argv[])
{
    if (strcmp(argv[1], "-o") == 0)
    {
        if (argc > 1)
        {
            parse_argv(argv);
        }
        else
        {
            error(1);
        }
    }
    else
    {
        error(0);
    }

    return 0;
}

void parse_argv(char *argv[])
{
    char string[] = "pid,ppid,command";
    char *param;

    param = strtok(argv[2],",");

    while(param)
    {
        display(param);
        param = strtok(NULL,",");
    }
    printf("\n");
}

void display(char *arg[])
{
    if (strcmp(arg, "pid") == 0)
    {
        printf(" PID ");
    }
    else if (strcmp(arg, "ppid") == 0)
    {
        printf(" PPID");
    }
    else if (strcmp(arg, "command") == 0)
    {
        printf(" COMMAND");
    }
}

int error(int nb)
{
    switch (nb)
    {
        case 0:
            printf("ERROR : wrong extension, you can only use '-o'");
            break;

        case 1:
            printf("ERROR : this function must be followed by at least one parameter");
            break;
    }
}