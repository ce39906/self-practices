#include<iostream>
#include<string>
#include<libmemcached/memcached.h>
using namespace std;

int main()
{
    memcached_st* memc;
    memcached_return rc;
    memcached_server_st* servers;
    char value[8191];
    time_t expiration;
    uint32_t flags;

    // connect server
    memc = memcached_create(NULL);
    servers = memcached_server_list_append(NULL,"10.134.86.133",11211,&rc);
    rc = memcached_server_push(memc,servers);
    memcached_server_free(servers);

    // save data
    strcpy(value,"this is the first memcached value");
    rc = memcached_set(memc,"key1",4,value,strlen(value),time_t(0),flags);
    if (rc == MEMCACHED_SUCCESS )
    {
        cout << "Save key key1 success, data is : " << value << endl;
    }

    //get data
    size_t value_length = strlen(value);
    char* result = memcached_get(memc,"key1",4,&value_length,&flags,&rc);
    if (rc == MEMCACHED_SUCCESS)
    {
        cout << "Get key key1 success, value is : " << result << endl;
    }else
    {
        cout<< "Get key key1 error" << endl;
    }
    
    //fetch data
    char return_key[MEMCACHED_MAX_KEY];
    size_t return_key_length;
    char* return_value;
    size_t return_value_length;

    const char* keys[] = {"key1"};
    size_t key_length[] = {4};

    rc = memcached_mget(memc,keys,key_length,1);
    return_value = memcached_fetch(memc,return_key,&return_key_length,&return_value_length,&flags,&rc);
    if (rc == MEMCACHED_SUCCESS)
    {
        cout << "fetch key , return_key:" << return_key << " ,return value : " << return_value<< endl;
    }
    // delete data
    rc = memcached_delete(memc,"key1",4,(time_t)0);
    if (rc == MEMCACHED_SUCCESS)
    {
        cout<< "delete key1 success!" << endl;
    }
    // free
    memcached_free(memc);
    return  0;
}
