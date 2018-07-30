#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<sys/msg.h>
#include <iostream>

using namespace std;
const int MAX_TEXT = 512;
struct msg_st
{
    long int msg_type;
    char text[MAX_TEXT];
};

int main()
{
    int running = 1;
    struct msg_st data;
    char buffer[BUFSIZ];
    int msgid = -1;
    msgid = msgget((key_t)1234,0666 | IPC_CREAT);
    if(msgid == -1)
    {
        cout <<"msgget failed with error"<<endl;
        return -1;
    }
    while(running)
    {
        cout << "Enter some text: ";
        fgets(buffer,BUFSIZ,stdin);
        data.msg_type = 1;
        strcpy(data.text,buffer);
        if(msgsnd(msgid,(void*)&data,MAX_TEXT,0) == -1)
        {
            cout << "msgsnd faild" << endl;
            return -1;
        }
        if(strncmp(buffer,"end",3) == 0)
            running = 0;
        sleep(1);
    }

    return 0;
}
