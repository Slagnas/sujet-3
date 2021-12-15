#include <stdio.h>
#include <string.h>

int error(int nb);
void parse_argv(char *argv[]);
void display(char *arg[]);
void get_extensions(int argc, char *argv[]);
void pid(char *argv[]);

int main(int argc, const char *argv[])
{
    get_extensions(argc, argv);

    return 0;
}

void parse_argv(char *argv[])
{
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

void get_extensions(int argc, char *argv[])
{
    char *extensions[] = {"-o", "-p"};

    for (int i = 0; i < argc-1; i++)
    {
        if (strcmp("./myps", argv[i]) == 0)
        {
            continue;
        }
        else if (i % 2 != 0)
        {

            if (strcmp(argv[i], "-o") == 0)
            {
                parse_argv(argv);
            }

            if (strcmp(argv[i], "-p") == 0)
            {
                pid(argv[i+1]);
            }
        }
    }
}

void pid(char *argv[])
{
    if (strcmp(argv, "1") == 0)
    {
        printf("   1 ");
    }
    else if (strcmp(argv, "10") == 0)
    {
        printf("  10 ");
    }
    else
    {
        printf("     ");
    }
    printf("\n");
}

int error(int nb)
{
    switch (nb)
    {
        case 0:
            printf("ERROR : wrong extension, you can only use '-o' and '-p");
            break;

        case 1:
            printf("ERROR : this function must be followed by at least one parameter");
            break;
    }
}