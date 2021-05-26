#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main(int argc, char** argv) {
    struct winsize ws;

    if( ioctl( STDOUT_FILENO, TIOCGWINSZ, &ws ) != -1 ) {
        char *hrstr = "-";
        if (argc > 1) {
            hrstr = argv[1];
        }
        for (int i = 0; i < ws.ws_col / strlen(hrstr); i++) {
            printf("%s", hrstr);
        }
        int rem = ws.ws_col - ws.ws_col / strlen(hrstr) * strlen(hrstr);
        for (int i = 0; i < rem; i++) {
            printf("%c", *(hrstr + i));
        }
        printf("\n");
        return 0;
    }
    return 1;
}
