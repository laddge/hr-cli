#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

int u8len(const char *str) {
    int cnt = 0;  // 文字数のカウント用
    while (*str != '\0') {
        if ((*str & 0xC0) != 0x80) { cnt++; }  //
        str++;
    }
    return cnt;
}

int main(int argc, char** argv) {
    struct winsize ws;

    if( ioctl( STDOUT_FILENO, TIOCGWINSZ, &ws ) != -1 ) {
        char *hrstr = "─";
        if (argc > 1) {
            hrstr = argv[1];
        }
        for (int i = 0; i < ws.ws_col / u8len(hrstr); i++) {
            printf("%s", hrstr);
        }
        int rem = ws.ws_col - ws.ws_col / u8len(hrstr) * u8len(hrstr);
        for (int i = 0; i < rem; i++) {
            printf("%c", *(hrstr + i));
        }
        printf("\n");
        return 0;
    }
    return 1;
}
