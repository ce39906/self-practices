#include<iostream>
#include<map>
using namespace std;

template <class K,class V>
class Node
{
  public:
    Node(K k,V v) 
      : key(k), value(v), prev(NULL), next(NULL)
    {
    }
    
    Node()
    {
    }
    
    K key;
    V value;
    Node* prev;
    Node* next;
};

template <class K ,class V>
class Lru
{
  public:
    Lru(int capacity)
    {
        head = new Node<K,V>;
        tail = new Node<K,V>;
        head->next = tail;
        head->prev = NULL;
        tail->next = NULL;
        tail->prev = head;
        size = 0;
        this->capacity = capacity;
        cache.clear();
    };

    ~Lru()
    {
        typename map<K,Node<K,V>* >::iterator it = cache.begin();
        for(;it!=cache.end();++it)
        {
            if (it->second)
            {
                delete it->second;
                it->second = NULL;
            }
        }
        cache.clear();
        while(head)
        {
            Node<K,V>* temp = head->next;
            delete head;
            head = temp;
        }
    };
  private:
    
    int size;
    int capacity;
    map<K,Node<K,V>*> cache;
    Node<K,V>* head;
    Node<K,V>* tail;
    
    void attach(Node<K,V>* node)
    {
        Node<K,V>* temp = head->next;
        head->next = node;
        node->next = temp;
        node->prev = head;
        temp->prev = node;
    }

    void detach(Node<K,V>* node)
    {
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }

  public:
    
    void Put(K key ,V value)
    {
        //insert
        if (cache.find(key) == cache.end())
        {
            //not full
            if (this->size != this->capacity)
            {
                Node<K,V>* data = new Node<K,V>(key,value); 
                attach(data);
                cache.insert(make_pair(key,data));
                this->size++;
            }
            else
            {
                Node<K,V>* temp = tail->prev;
                cache.erase(temp->key);
                detach(tail->prev);
                Node<K,V>* data = new Node<K,V>(key,value); 
                attach(data);
                cache.insert(make_pair(key,data));
            }
        }
        else //update
        {
            Node<K,V>* data = cache[key];
            detach(data);
            delete data;
            data = new Node<K,V>(key,value);
            cache[key] = data;
            attach(data);
        }
    }

    V Get(K key)
    {
        //find
        if (cache.find(key) != cache.end())
        {
            Node<K,V>* data = cache[key];
            detach(data);
            attach(data);
            return data->value;
        }else // not find
        {
            return V();
        }
    }
};

