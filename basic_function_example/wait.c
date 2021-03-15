//헤더
#include <sys/types.h>
#include <sys/wait.h>

//원형
//pid_t wait(int *status);

//주로 fork()를 이용해서 자식 프로세스를 생성 했을 때 사용한다. wait()를 쓰면
//자식 프로세스가 종료 될 때까지 해당 영역에서 부모 프로세스가 sleep 모드로 기다리게 된다.
//이는 자식프로세스와 부모프로세스의 동기화를 위한 목적으로 사용된다.

//wait 의 인자 status 를 통해 자식 프로세스의 상태를 받아올 수 있는데, 자식 프로세스의 상태값은
//자식프로세스의 종료값 * 256(FF)이다 (???)

//예제

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int     main()
{
    int pid;
    int status;

    pid = fork();
    
    //자식
    if (pid < 0)
    {
        perror("FORK ERROR.");
        exit(1);
    }

    if (pid == 0)
    {
        int i;
        for (int i=0; i<3;i++)
        {
            printf("child : %d\n", i);
            sleep(1); // 자바랑은 다르게 ms 단위가 아니라 s 단위인듯.
        }
        exit(3);
    }else{
        printf("waiting child %d\n", pid);
        //위에서 child 가 exit(3) 했기 때문에
        wait(&status);
        //wait 이후 status 는 3 * 256 = 768 이 반환된다.

        printf("child is exit(%d)\n",status);
    }
}