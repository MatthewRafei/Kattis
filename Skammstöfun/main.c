#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* skammstofun(int num, char* str) {

    char *buff = malloc(sizeof(char) * strlen(str));
    int len = 0;

    int i = 0;

    while(str[i] != '\0') {
        if(isupper(str[i]) > 0) {
            buff[len] = str[i];
            len++;
            while(str[i] && str[i] != ' ') {
                i++;
            }
        }
        else{
            while(str[i] && str[i] != ' ') {
                i++;
            }
        }
        i++;
    }

    return buff;
}

int main(void) {
    int num = 0;
    char *str = malloc(512);
    scanf("%d %s", &num, str);

    char buff[256];
    while (fgets(buff, sizeof(buff), stdin) != NULL) {
        strcat(str, buff);
        memset(buff, '\0', 256);
    }

    printf("%s\n", skammstofun(num, str));
}
