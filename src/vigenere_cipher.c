#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char const *argv[])
{

    char clef[256] = "";
    char char_message[2048] = "";
    char filename[128];

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


    printf("[?] fichier source:\n");
    scanf("%s", filename);

    printf("[?] Clef:\n");
    scanf("%s", clef);

    
    FILE* file = fopen(filename, "r");
    FILE* output = fopen("output.txt", "w");
    unsigned i = 0;

    while (!feof(file))
    {
        char let_clef = ' ';
        char char_message = fgetc(file);
        char encrypted = ' ';

        if (char_message >= 'a' && char_message <= 'z')
        {
            let_clef = clef[i % strlen(clef)] - 'a';

            encrypted = char_message - 'a' + let_clef;
            encrypted %= 26;
            encrypted += 'a';
            i++;
        }
        else if (char_message >= 'A' && char_message <= 'Z')
        {
            let_clef = clef[i % strlen(clef)] - 'A';
            
            encrypted = char_message - 'A' + let_clef ;
            encrypted %= 26;
            encrypted += 'A';
            i++;

        }
        else
        {
            encrypted = char_message;
        }
        
        fputc(encrypted, output);
        fputc('\0', output);

    }
    
    fclose(file);
    fclose(output);

}
