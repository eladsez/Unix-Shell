/**
 * This is the utilities File for the program
 */

#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#include "shell.h"

extern size_t char_count;

/**
 * This function is printing the prompt of the shell with special colors
 *  including the path of the current working directory
 */
void print_prompt() { // this is a cool prompt printer

    char cwd[PATH_MAX]; // PATH_MAX taken from limits.h
    if (getcwd(cwd, PATH_MAX) != NULL) {
        printf( "\033[1;35m");
        printf( "λ");
        printf("\033[1;36m");
        printf(":%s$ ", cwd);
        printf("\033[0;37m");
    } else {
        perror("cwd ERROR");
        exit(1);
    }
}

void print_dynamic_prompt(){

    if (getenv(PROMPT)){
        printf("%s ", getenv(PROMPT));
    }
    else print_prompt();
    char_count = 0;
}

/**
 *
 * @param paths is a string represent file path
 * @return the first space char found in path
 */
size_t find_space(char *paths) {
    for (size_t i = 0; i < strlen(paths); ++i) {
        if (paths[i] == ' ')
            return i;
    }

    return -1;
}

/**
 *
 * @param str
 * @param to_count
 * @return return the occurrences number of the to_count char in str
 */
int count_chars(char *str, char to_count) {
    int count = 0;
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] == to_count)
            ++count;
    }
    return count;
}

/**
 *This function take a string and split it to separate string according to the parse_by char
 * @param str the origin string
 * @param splited - the returned separated strings
 * @param parse_by
 */
void parse_str(char *str, char **splited, char *parse_by) {
    static char str_cpy[4096]; // must to be static in order to point it with split
    // if it wont be static it will free after this function and when we do stuff with split array it is segmentation fault
    strcpy(str_cpy, str);
    int index = 0;
    char *temp;
    temp = strtok(str_cpy, parse_by);

    while (temp != NULL) {
        splited[index++] = temp;
        temp = strtok(NULL, parse_by);
    }
}

/***
 * This function take array of strings and clean spaces from all the strings from the prefix and suffix
 * if the strings are not statically allocated dont call this function on them !!!
 * @param str_s - the array of strings
 * @param size - the size of the array
 */
void clean_spaces(char **str_s, size_t size){
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < strlen(str_s[i]); ++j){
            if (str_s[i][j] != ' ') break;
            str_s[i] = &str_s[i][j];
        }
        for (int j = strlen(str_s[i]) - 1; j >= 0 ; --j){
            if (str_s[i][j] != ' ') break;
            str_s[i][j] = '\0';
        }
    }
}


/***
 * This is a helper function for input_command function
 * it get a user command trim the spaces from the edges of the command
 * and return the trimmed command
 * @param command
 * @return the return value is a dynamically allocated pointer to the new trimmed command (the given one was free)
 */
char *trim(char* command){

    printf ("before trimmed: %s\n", command);
    int start = 0, end = strlen(command) - 1;

    /* find the edges */
    for (int i = 0; i < strlen(command); ++i) {
        if (command [i] == ' ') ++start;
        else break;
    }
    for (int i = strlen(command) - 1; i >= 0; --i) {
        if (command [i] == ' ') --end;
        else break;
    }

    char *ret = (char *) malloc(sizeof (char ) * (end - start + 2)); /* + 2 (one for logic one for \0) */
    for (int i = 0, j = start; j <= end; ++j, ++i){ /* copy the actual string */
        ret[i] = command[j];
    }

    ret[end + 1] = '\0';

    free(command);
    printf("trimmed: %s\n", ret);
    return ret;
}