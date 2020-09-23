#include <iostream>
#include <string>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>

#define server_port 8000    //宏定义服务器对外开放端口

int main()
{
    int socket_fd = socket(AF_INET,SOCK_DGRAM,0);   //创建UDP套接字

    if(socket_fd < 0)   //创建套接字错误
    {        
        std::cout<<"create socket Error!"<<std::endl;
        exit(1);
    }

    struct sockaddr_in addr_server;     //服务器属性
    int len_addr_server = sizeof(addr_server);                                //属性结构体长度
    memset(&addr_server,0,sizeof(struct sockaddr_in));      //默认数据填充0
    addr_server.sin_family = AF_INET;                                             //IPV4地址类型
    // addr_server.sin_family = AF_INET6;                                          //IPV6地址类型
    addr_server.sin_port    = htons(server_port);                       //端口设置导入
    addr_server.sin_addr.s_addr = htonl(INADDR_ANY);        //自动获取IP地址

    //绑定socket，也就是启动服务
    if( bind( socket_fd,
                        (struct sockaddr * )&addr_server,
                        sizeof(addr_server) )
             < 0  )
    {
        std::cout <<"bind error!"<<std::endl;
        exit(1);
    }

    int recv_num;       //接收数量
    int send_num;       //发送数量
    char send_buf[20] = "JRY UDP!";     //发送缓冲
    char recv_buf[20];                                  //接收缓冲，注意按需调整缓冲池大小

    struct sockaddr_in cache_addr_client;     //客户端属性存储

    while (1)
    {
        std::cout<<"server wait:"<<std::endl;

        //注意这是阻塞性接口！
        recv_num = recvfrom(socket_fd,              //套接字
                            recv_buf,sizeof(recv_buf),          //接收缓冲设置
                            0,                          //接收标志
                            (struct sockaddr *)&cache_addr_client,(socklen_t *)&len_addr_server);     //客户端属性缓冲设置

        if(recv_num < 0)        //接收结果判断，错误是-1
        {
            std::cout<<"recvform error!"<<std::endl;
            exit(1);
        }

        recv_buf[recv_num] = '\0'; 

        std::cout<<"server receive "<<recv_num<<"Bytes: "<<recv_buf<<std::endl;

        

        send_num = sendto(socket_fd,    //套接字
                                    send_buf,strlen(send_buf),  //发送数据
                                    0,      //标志位
                                    (struct sockaddr *) & cache_addr_client,len_addr_server);   //发送目标属性

        if(send_num < 0)    //发送结果判断，错误是-1
        {
            std::cout<<"sendto error!"<<std::endl;
            exit(1);
        }
    }

    close(socket_fd);   //关闭套接字

    return 0;
}
