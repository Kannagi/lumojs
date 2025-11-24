

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

unsigned char buffer_file[0x800000]; // 8MiB

int load_file_into_buffer(const char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (!file)
    {
        perror("Erreur d'ouverture du fichier");
        return -1;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    fread(buffer_file, 1, size, file);
    if (ferror(file))
    {
        perror("Erreur de lecture du fichier");
        fclose(file);
        return -2;
    }

    buffer_file[size+1] = '\0';
    fclose(file);
    return size;
}

void parse_html(const char *buffer, int n)
{
    bool in_quotes = false;
    char quote_char = '\0';
    bool in_comment = false;

    for (int i = 0; i < n; i++)
    {
        char c = buffer[i];

        // Gestion des commentaires HTML
        if (!in_quotes && !in_comment && c == '<' && i + 3 < n && buffer[i+1] == '!' && buffer[i+2] == '-' && buffer[i+3] == '-')
        {
            in_comment = true;
            i += 3; // avancer après <!--
            continue;
        }

        if (in_comment && c == '-' && i + 2 < n && buffer[i+1] == '-' && buffer[i+2] == '>')
        {
            in_comment = false;
            i += 2; // avancer après -->
            continue;
        }

        if (in_comment == true) continue; // ignorer tout dans le commentaire

        // Gestion des guillemets
        if (c == '"' || c == '\'')
        {
            if (in_quotes == false)
            {
                in_quotes = true;
                quote_char = c;
            } else if (quote_char == c)
            {
                in_quotes = false;
                quote_char = '\0';
            }
        }

        // Reconnaissance de < et > en dehors des guillemets
        if (in_quotes == false)
        {
            if (c == '<' || c == '>')
            {
                printf("Caractère spécial trouvé : %c à l'indice %d\n", c, i);
            }
        }

        // Ici tu peux traiter les autres caractères hors commentaire et hors guillemets
    }
}





int main()
{
    int n = 5;
    for(int i = 0;i < n;i++)
    {
        //char letter = buffer[i];


    }
    return 0;
}

/*

<lumo-dmacro testm "ok", "ok3" , "1"></>

bla bla bla $arg1 , $arg2

/>

<lumo-macro testm "ok", "ok3" , "1" />

<lumo-dmacro testm "ok", "ok3" , "1" />

<lumo-block name-group,new-game

>

<lumo-inner timer event-func 
<div class="partenaire-item">
    <a href="${url}" >
    <img src="${imageUrl}" alt="${title} class="partenaire-logo" width="200">
    </a>
</div>

/>


*/