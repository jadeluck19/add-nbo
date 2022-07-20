#define _CRT_SECURE_NO_WARNINGS //fopen security error
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf

uint32_t my_ntohl(uint32_t n);

int main(int argc, char *argv[])
{
    uint32_t buf1, buf2;
    FILE *p1 = fopen(argv[1],"r");
    fread(&buf1, sizeof(uint32_t), 1, p1);
    FILE *p2 = fopen(argv[2],"r");
    fread(&buf2, sizeof(uint32_t), 1, p2);
    buf1 = my_ntohl(buf1);
    buf2 = my_ntohl(buf2);
    uint32_t sum = buf1 + buf2;
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)",buf1, buf1, buf2, buf2, sum, sum);
    fclose(p1); fclose(p2);
    return 0;
}

uint32_t my_ntohl(uint32_t n){
    uint32_t n1 = (n & 0xff000000) >> 24;
    uint32_t n2 = (n & 0x00ff0000) >> 8;
    uint32_t n3 = (n & 0x0000ff00) << 8;
    uint32_t n4 = (n & 0x000000ff) << 24;
    return n1 | n2 | n3 | n4;
}
