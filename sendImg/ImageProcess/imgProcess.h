#ifndef _IMG_PROCESS_H_

#define _IMG_PROCESS_H_

#include <iostream>


typedef struct imgData
{
    int length;
    void * ptr;
}imgData;


int imgProcess(imgData *);


#endif // !_IMG_PROCESS_H_
