#include <stdio.h>

int main() {
    char myMessage[] = "First c Program";
    int i = 0;

    while (myMessage[i] != '\0') {
        putchar(myMessage[i]);
        i++;
    }
    putchar('\n');

    return 0;
}
