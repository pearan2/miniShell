//헤더 > unistd.h
#include <unistd.h>

//pid_t fock(void);
// fork 는 자식 프로세스를 만들기 위해 사용되는 프로세스 생성기 이다.
// fork 에 의해 생성된 자식 프로세스는 자신만의 pid 를 가지게 되며, ppid 는 부모프로세스의 pid 를 가지게 된다.

//반환값 pid_t
//성공할 경우 자식 프로세스의 pid 가 부모에게 리턴되며, 자식에게는 0이 리턴된다.
//실패할경우 -1 이 리턴되며, 적절한 errno 값이 설정 된다.

//에러
//EAGAIN : 자식프로세스를 위한 테스크 구조체를 할당 할수 없는 경우, 주로 메모리 문제

//예제

#include <stdio.h>
#include <stdlib.h>
int     main(int ac, char **av)
{
    int pid;
    
    pid = fork();
    if (pid > 0)
    {
        printf("나는 부모 > %d:%d\n",getpid(), pid);
    }
    else if (pid == 0)
    {
        printf("나는 자식 > %d:%d\n", getpid(), pid);
    }
    else
    {
        perror("fork error:");
        exit(1);
    }
}