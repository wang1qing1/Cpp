// #include <stdio.h>

// int func(int a, int b)
// {
//     int a1 = a * 10;
//     int b1 = b * 10;
//     int sum = a1 + b1;
//     return sum;
// }

// int main()
// {
//     int count = 10;
//     int sum = 0;
//     for (int i = 0; i < count; i++)
//     {
//         printf("hello:%d->%d\n", i, count);
//         sum += i;
//     }
//     func(1, 2);

//     return 0;
// }
// #include <stdio.h>
// int main()
// {
//     extern char **environ;
//     int i = 0;
//     for (; environ[i]; i++)
//     {
//         printf("%s\n", environ[i]);
//     }
//     return 0;
// }
// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
// int g_val = 0;
// int main()
// {
//     pid_t id = fork();
//     if (id == 0) // child
//     {
//         g_val = 1000;
//         printf("child[%d]: %d : %p\n", getpid(), g_val, &g_val);
//     }
//     else // parent
//     {
//         printf("parent[%d]: %d : %p\n", getpid(), g_val, &g_val);
//     }
//     return 0;
// }

#include <iostream>
#include <unistd.h>
#include <stdlib.h>

// using namespace std;
// int main()
// {
//     std::cout << "hello C++" << endl;
//     std::cout << "hello Linux" << endl;
//     _exit(100);
//     std::cout << "hello world" << endl;
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// int main()
// {
//     int id = fork();
//     int status;

//     if (id == 0) // 子进程
//     {
//         int n = 15;
//         while (n--)
//         {
//             printf("我是一个子进程,我的pid:%d,我的ppid:%d\n", getpid(), getppid());
//             sleep(1);
//         }
//         return 0;
//     }
//     else if (id > 0) // 父进程
//     {
//         int n = 20;
//         while (n--)
//         {
//             // wait(nullptr); //阻塞
//             // waitpid(-1,&status,0);//阻塞
//             pid_t ret = waitpid(id, &status, WNOHANG);
//             if (ret == 0)
//             {
//                 printf("chind pid:%d,子进程还未退出\n", id);
//             }
//             else
//             {
//                 // // 前8位是退出码，第九位是core dump标志,最后七位是用来判断是否正常退出，正常退出0
//                 // if ((status & (0x7f)) == 0)
//                 // {
//                 //     printf("子进程正常退出,退出码：%d\n", (status >> 8) & (0xff));
//                 // }
//                 // else // 前8位是非正常退出忽略，第九位是core dump标志,最后七位是接收的信号
//                 // {
//                 //     printf("子进程非正常退出,接收信号：%d\n", status & (0x7f));
//                 // }
//                 // 前8位是退出码，第九位是core dump标志,最后七位是用来判断是否正常退出，正常退出0
//                 if (WIFEXITED(status))
//                 {
//                     printf("子进程正常退出,退出码：%d\n", WEXITSTATUS(status));
//                 }
//                 else // 前8位是非正常退出忽略，第九位是core dump标志,最后七位是接收的信号
//                 {
//                     printf("子进程非正常退出,接收信号：%d\n", status & (0x7f));
//                 }
//                 break;
//             }
//             printf("我是一个父进程,我的pid:%d,我的ppid:%d\n", getpid(), getppid());
//             sleep(1);
//         }
//     }
//     return 0;
// }

#include <stdio.h>
#include <string.h>
int main()
{
    FILE *fp = fopen("myfile", "r");
    if (!fp)
    {
        printf("fopen error!\n");
    }
    char buf[1024];
    const char *msg = "hello bit!\n";
    while (1)
    {
        // 注意返回值和参数，此处有坑，仔细查看man手册关于该函数的说明
        size_t s = fread(buf, 1, strlen(msg), fp);
        if (s > 0)
        {
            buf[s] = 0;
            printf("%s", buf);
        }
        if (feof(fp))
        {
            break;
        }
    }
    fclose(fp);
    return 0;
}