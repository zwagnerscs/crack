#include <stdio.h>
#include <stdlib.h>
#include "md5.h"

FILE *openfile(char *fname);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("You must supply a hashfile and a dictionary file\n");
        return 1;
    }
    
    FILE *hf, *df;
    hf = openfile(argv[1]);
    

    
    char hash[40];
    while (fscanf(hf, "%s", hash) != EOF)
    {
        printf("%s\n", hash);
        df = openfile(argv[2]);
        // For each hash, loop through df, hashing each,
        // print a match when we find it.
        fclose(df);
    }
    
    fclose(hf);
}


FILE *openfile(char *fname)
{
    FILE *f = fopen(fname, "r");
    if (!f)
    {
        printf("Couldn't open %s for reading\n", fname);
        exit(2);
    }
    return f;
}
