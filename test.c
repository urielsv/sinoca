#include <stdio.h>
#include <unistd.h>

int main()
{

    char c_buff;
    
    sleep(1);
    setvbuf(stdin, &c_buff, _IOFBF, 2);
    printf("%c\n", c_buff);
    return 0;
}
