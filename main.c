#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DEBUG 1

void delim(char *buffer, const char *str, const char c) {
    int i = 0;

    (void)buffer;
    while (str[i] != c)
        ++i;

    strncpy(buffer, str, i);
}

void command_split(const char *command, const char *piece_size, \
        const char *piece_names, const char *filename)
{
    char buffer[50];

    (void)buffer;
    sprintf (buffer, "\n%s %s %s %s\n", command, piece_size, filename, piece_names);
    if (DEBUG)
        printf("%s", buffer);
    system(buffer);
}

void command_execute(const char *command, const char *arg)
{
    char buffer[50];

    (void)buffer;
    sprintf (buffer, "\n%s %s\n", command, arg);
    if (DEBUG)
        printf("%s", buffer);
    system(buffer);
}

int main(int ac, char **av)
{
    char buffer[50];

    if (ac != 2)
        return 1;



    delim(buffer, av[1],  '.');
    printf("%s %s\n", buffer, popen("ls -1f | grep piece. | wc -l", "-l"));

    // ls -1f | grep piece. | wc -l
    command_execute("du -h", av[1]);
    command_split("split -b", "100M", "piece.", av[1]);
    // TODO command_execute("echo \"%s %s\" >, randomtext.txt
    command_execute("ls", ".");
    command_execute("cat piece.?? > ", strcat(buffer, "-USA.mp4"));

    return 0;
}
