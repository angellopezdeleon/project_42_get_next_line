#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
    int fd;
    char *line;
    int i;

    // Abre el archivo test.txt en modo lectura (O_RDONLY)
    fd = open("test.txt", O_RDONLY);
    printf("\nFD: %d \n", fd);

    i = 0;
    // Comprueba si hay algún error al abrir el archivo
    if (fd == -1)
    {
        printf("Error al abrir el archivo");
        return 1;
    }

    // Lee el archivo línea por línea usando get_next_line
    while ((line = get_next_line(fd)) != NULL)
    {
        i++;
        printf("Linea %d", i);
        printf("%s", line);
        free(line);
    }

    printf("\nSe cierra el archivo\n");

    // Cierra el archivo
    close(fd);

    return 0;
}

