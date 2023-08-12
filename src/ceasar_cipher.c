#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int ceasar_key = 0;
    switch (argc)
    {
        case 3:
            ceasar_key = atoi(argv[2]);
        break;

        case 1: 
            printf("[!] joindre un fichier en argument, ou en le glissant sur l'executable\n");
            #ifdef _WIN32
                _sleep(10000);
            #endif
        return EXIT_FAILURE;

    default:
        printf("Nombre de la clef Ceasar: ");
        scanf("%i", &ceasar_key);
        break;
    }
    ceasar_key %= 26;


    const char* filename = argv[1];
    char* ext = strchr(filename, '.');
    if (strcmp(ext, ".txt"))
    {
        printf("[!] fichier *.txt uniquement.\nPas *%s", ext);

        #ifdef _WIN32
            _sleep(10000);
        #endif

        return EXIT_FAILURE;
    }

    FILE* file = fopen(filename, "r");
    FILE* output = fopen("text_crypted.txt", "w");

    int sign = (ceasar_key > 0) - (ceasar_key < 0);




    while (!feof(file))
    {
        char* buffer = malloc(sizeof(char)*30);

        fgets(buffer, 30, file);

        for (unsigned i = 0; i < strlen(buffer); i++)
        {
            char c = buffer[i];

            if (c >= 'A' && c <= 'Z')
            {
                int l = c + ceasar_key;
                buffer[i] = ( l > 'Z' || l < 'A') ? l - 26 * sign : l;
            }
            else if (c >= 'a' && c <= 'z')
            {
                int l = c + ceasar_key;
                buffer[i] = ( l > 'z' || l < 'a') ? l - 26 * sign : l;
            }
        }

        fputs(buffer, output);

    }
    
    fclose(file);
    fclose(output);

    return EXIT_SUCCESS;
}
