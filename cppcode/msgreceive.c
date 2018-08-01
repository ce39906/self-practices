#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/msg.h>
#include <iostream>

using namespace std;
struct msg_st
{
    long int msg_type;
    char text[BUFSIZ];
};

int main()
{
    int running = 1;
    int msgid = -1;
    struct msg_st data;
    long int msgtype = 0;
    //create msg queue
    msgid = msgget((key_t)1234, 0666| IPC_CREAT);
    if(msgid == -1)
    {
        cout << "create msg queue failed"<< endl;        
    }
    while(running)
    {
        if (msgrcv(msgid, (void*)&data, BUFSIZ, msgtype, 0)== -1)
        {
            cout << "msgrcv faild with errno"<< errno <<endl;
        }
        cout << "your write: "<<data.text;
        if(strncmp(data.text,"end", 3) == 0)
            running = 0;
    }
    // del msg queue
    if(msgctl(msgid, IPC_RMID, 0) == -1)
    {
        cout << "del msg queue failed" <<endl;
        exit(EXIT_FAILURE);
    }
    return 0;
}
