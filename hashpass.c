#import <stdio.h>
#import <stdlib.h>
#import <string.h>
#import "md5.h"

int main (int argc, char *argv[]) {
    if (argc < 3) {
        printf("Please enter 2 files.\n");
        exit(1);
    }
    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");
    if (!in) {
        printf ("Invalid 1st file.\n");
        exit(1);
    }
    if (!out) {
        printf ("Invalid 2nd file.\n");
        exit(1);
    }
    char line[1000];
    while (fgets(line, 1000, in) != NULL){
        int line_length = strlen(line);
        if (line[line_length - 1] == '\n') {
            line_length = line_length - 1;
            line[line_length] = '\0';
            char *md5_line = md5(line, line_length);
            fprintf (out, "%s\n", md5_line);
            free(md5_line);
        } else {
            char *md5_line = md5(line, line_length);
            fprintf (out, "%s\n", md5_line);
            free(md5_line);
        }
    }
}