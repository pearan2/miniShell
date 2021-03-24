#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <termios.h>


# define BACKSPACE 127
# define EOF_KEY 4
# define LEFT_ARROW 4479771
# define RIGHT_ARROW 4414235
# define UP_ARROW 4283163
# define DOWN_ARROW 4348699

int		main()
{
    struct termios termios_p;
    struct termios termios_save;
    tcgetattr(0, &termios_p);
    termios_save = termios_p;

    termios_p.c_lflag &= ~(ICANON|ECHO);
    termios_p.c_cc[VTIME] = 0;
    termios_p.c_cc[VMIN] = 1;
    tcsetattr(0,TCSANOW, &termios_p);
    long buff;
    buff = 0;
    while(read(0, &buff, sizeof(buff)) > 0){
        if(buff > 0){            
            if (buff == BACKSPACE)
                printf("BACKSPACE!!\n");
            else if (buff == LEFT_ARROW)
                printf("LEFT_ARROW!!\n");
            else if (buff == RIGHT_ARROW)
                printf("RIGHT_ARROW!!\n");
            else if (buff == UP_ARROW)
                printf("UP_ARROW!!\n");
            else if (buff == DOWN_ARROW)
                printf("DOWN_ARROW!!\n");
            else
			    printf("%c\n",(char)buff);
        }
        buff = 0;
    }
    tcsetattr(0,TCSANOW, &termios_save);
    return 0;
}