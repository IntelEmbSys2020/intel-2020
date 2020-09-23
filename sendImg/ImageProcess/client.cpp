#include <iostream>
#include <stdio.h>
#include <string>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <memory.h>
#include "imgProcess.h"
#include <errno.h>
#define DEST_PORT           8000                    //目标服务器端口
#define DEST_IP_ADDR    "81.68.85.122"     //IP
#define MAX_LEN 60000
using namespace std;
int main()
{
    int socket_fd = socket(AF_INET,SOCK_DGRAM,0);   //创建套接字

    if(socket_fd < 0)   //创建结果检测
    {
        std::cout<<"create socket Error!"<<std::endl;
        exit(1);
    }

    struct sockaddr_in addr_server;     //服务器属性
    int len_addr_server = sizeof(addr_server);
    memset(&addr_server,0,len_addr_server);
    addr_server.sin_addr.s_addr = inet_addr(DEST_IP_ADDR);
    addr_server.sin_family = AF_INET;
    addr_server.sin_port = htons(DEST_PORT);
    
    int sendNum;
    int recvNum;
    char sendBuf[20] = "Are you hearing?";
    char recvBuf[20];
/***new add***/
    imgData* image = new imgData;
    // cout<<"begin imgpro"<<endl;
    int status = imgProcess(image);
    printf("status is %d\n", status);
    //cout<<"end imgpro"<<endl;
    
    // sendNum = image->length;
    // cout<<"assign"<<endl;
    FILE* fp = fopen("image.bmp", "wb");
    if (NULL == fp)
    {
        printf("fopen failed\n");
    }
    cout<<"the len ptr are: "<<&(image->length)<<" the length are: "<<sizeof(image->length)<<endl;
    cout<<"the img ptr are: "<<image->ptr<<" the length are: "<<image->length<<endl;
    fwrite(image->ptr, 1, image->length, fp);
    fclose(fp);
/***new add***/
    //std::cout<<"client send:"<<sendBuf<<std::endl;

    sendNum = sendto(socket_fd,
                        &(image->length),sizeof(image->length),
                        0,
                        (struct sockaddr *)&addr_server,len_addr_server);
    cout<<"sendNum1 is: "<<sendNum<<endl;
    if(sendNum < 0)
    {
        std::cout<<"send Length Error!"<<std::endl;
    }

    char* currPtr = (char*)image->ptr;
    int count = 0;
    int total = image->length/MAX_LEN;
    int remain = image->length%MAX_LEN;
    cout<<"total: "<<total<<endl;
    cout<<"remain: "<<remain<<endl;
    //除法是向下取整，说明总次数是total加１，最后一次单列
    for(count = 0; count < total; count++)
	{
        sendNum = sendto(socket_fd,     //套接字
                        currPtr,MAX_LEN,   //发送数据,每次传送规定的大小
                        0,  //标志位
                        (struct sockaddr *)&addr_server,len_addr_server);   //接收者（服务器）地址
        currPtr += MAX_LEN;
        //cout<<"sendNum2 is: "<<sendNum<<endl;
        //cout<<"currPtr is: "<<currPtr<<endl;
        if(sendNum < 0)
        {
            std::cout<<"send Error!"<<std::endl;
            printf("errno is: %d\n",errno);
        }
	}
    //最后一次 
    sendNum = sendto(socket_fd,
                    currPtr,remain,
                    0,
                    (struct sockaddr *)&addr_server,len_addr_server);
    cout<<"sendNum2 is: "<<sendNum<<endl;
    
    if(sendNum < 0)
    {
        std::cout<<"send Length Error!"<<std::endl;
    }


    // recvNum = recvfrom(socket_fd,
    //                     recvBuf,sizeof(recvBuf),    //接收数据缓存
    //                     0,
    //                     (struct sockaddr *)&addr_server,(socklen_t *)&len_addr_server);
    // if(recvNum < 0)
    // {
    //     std::cout << "recvFrom Error!"<<std::endl;
    //     exit(1);
    // }

    // recvBuf[recvNum] = '\0';
    // std::cout << "client receive "<<recvNum<<" bytes:" <<recvBuf<<std::endl;
    // close(socket_fd);

    return 0;
}
