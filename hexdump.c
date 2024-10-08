//This project was a challenge to see the least amount of characters I could use to display a binary file 
//in a hexidecimal representation 
//this project is vaguely unreadable, so a different readable file will also be uploaded 


#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef ssize_t s;
typedef unsigned char u;
#define p printf
void h(u *b, s r, s o) {
    p("%08zx: ", (size_t) o);
    for (s i = 0; i < 16; i++)
        i < r ? p("%02x", b[i]) : p("  "), i % 2 && p(" ");
    p(" ");
    for (s i = 0; i < r; i++)
        p(isprint(b[i]) ? "%c" : ".", b[i]);
    p("\n");
}
void q(int z) {
    u b[16];
s o = 0, r = 0;
    for (;;) {
        s w = read(z, b + r, (size_t) (16 - r));
        if (w < 0 || (!w && !r) || (!w && (h(b, r, o), 1)))
            break;
        r += w;
        if (r >= 16 && (h(b, 16, o), 1))
            o += 16, r = 0;
    }
}
int main(int g, char **v) {
    if (g == 1) {
        q(0);
        return 0;
    }
    int n = open(v[1], O_RDONLY);
    if (n < 0)
        return -1;
    q(n), close(n);
    return 0;
}
