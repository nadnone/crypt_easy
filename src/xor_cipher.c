#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char* cipher_key = malloc(sizeof(char*) * 2048);
    char* source_file = malloc(sizeof(char*) * 2048);
    char* dest_file = malloc(sizeof(char*) * 128);

    char * welcome = 
"                                                   dddddddd\n"
"NNNNNNNN        NNNNNNNN                           d::::::d\n"
"N:::::::N       N::::::N                           d::::::d\n"
"N::::::::N      N::::::N                           d::::::d\n"
"N:::::::::N     N::::::N                           d:::::d \n"
"N::::::::::N    N::::::N aaaaaaaaaaaaa     ddddddddd:::::d \n"
"N:::::::::::N   N::::::N a::::::::::::a  dd::::::::::::::d \n"
"N:::::::N::::N  N::::::N aaaaaaaaa:::::ad::::::::::::::::d \n"
"N::::::N N::::N N::::::N          a::::d:::::::ddddd:::::d \n"
"N::::::N  N::::N:::::::N   aaaaaaa:::::d::::::d    d:::::d \n"
"N::::::N   N:::::::::::N aa::::::::::::d:::::d     d:::::d \n"
"N::::::N    N::::::::::Na::::aaaa::::::d:::::d     d:::::d \n"
"N::::::N     N:::::::::a::::a    a:::::d:::::d     d:::::d \n"
"N::::::N      N::::::::a::::a    a:::::d::::::ddddd::::::dd\n"
"N::::::N       N:::::::a:::::aaaa::::::ad:::::::::::::::::d\n"
"N::::::N        N::::::Na::::::::::aa:::ad:::::::::ddd::::d\n"
"NNNNNNNN         NNNNNNN aaaaaaaaaa  aaaa ddddddddd   ddddd\n"
;

    printf("%s", welcome);

    printf("[?] Fichier source: \n");
    scanf("%s", source_file);

    printf("[?] La clef de chiffrement: \n");
    scanf("%s", cipher_key);

    printf("[?] Fichier de destination: \n");
    scanf("%s", dest_file);

    const unsigned key_length = strlen(cipher_key);
    unsigned key_inc = 0;

    FILE * src_mng = fopen(source_file, "r");
    FILE * dest_mng = fopen(dest_file, "w");

    while (!feof(src_mng))
    {
        char buffer = ' ';

        fread(&buffer, sizeof(char), 1, src_mng);
       
        buffer ^= cipher_key[key_inc++ % key_length];

        fwrite(&buffer, sizeof(char), 1, dest_mng);
    }


    fclose(src_mng);
    fclose(dest_mng);

    free(cipher_key);
    free(source_file);
    free(dest_file);

    return EXIT_SUCCESS;
}
