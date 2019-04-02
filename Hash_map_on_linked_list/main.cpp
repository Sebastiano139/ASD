#include <iostream>
using namespace std;
const int N=5;
int Array[N]={2,7,3,4,5};
struct node
{
    int val;
    node *next;
};
//////////////////////////////////////////////
bool check_prime(int x)
{
    if(x==2)return true;
    if(x<2 || x%2==0)return false;
    for(int i=3; i<=sqrt(x); i+=2)
    {
        if(x%i==0)return false;
    }
    return true;
}
int get_next_prime(int x)
{
    if(check_prime(x))return x;
    while(!check_prime(x++));
    return x;
}
const int M = get_next_prime(N);
///////////////////////////////////////////////
node ** array_of_hash = new node *[M];
void reset_tab(node ** tab, int x)
{
    for(int i=0; i<N; i++)tab[i]= nullptr;
}
void insert_to_sorted_list(node *&list, int key)
{
    node *tmp, *q;
    node *p = new node;
    p->next=nullptr;
    p->val=key;
    if(list==nullptr || key<list->val)
    {
        p->next=list;
        list=p;
    }
    else
    {
        q = list;
        tmp = list;
        while(tmp!=nullptr && key>tmp->val)
        {
            q=tmp;
            tmp=tmp->next;
        }
        p->next=q->next;
        q->next=p;
    }
}
void print_list(node **array_of_hash, int x)
{
    for(int i=0; i<x; i++)
    {
        cout << "LIST " << i << " :" << endl;
        node * tmp = array_of_hash[i];
        if(tmp==nullptr)cout << "List is empty" << endl;
        while(tmp!=NULL)
        {
            cout << tmp->val << endl;
            tmp=tmp->next;
        }
    }
}
//////////////////////////////////////
int Hash(int k)
{
    return k%M;
}
void insert_to_array_of_hash(node **array_of_hash, int key)
{
    insert_to_sorted_list(array_of_hash[Hash(key)], key);
}
bool search_key(node **array_of_hash, int key)
{
    int index=Hash(key);
    node * tmp = array_of_hash[index];
    while(tmp!=nullptr && tmp->val<key)
    {
        tmp = tmp->next;
    }
    if(tmp==nullptr || tmp->val!=key)return false;
    else return true;
}
void delete_key(node **array_of_hash, int key)
{
    int index=Hash(key);
    node * p = array_of_hash[index];
    node * q = p;
    if(p->val==key)
    {
        p=p->next;
        array_of_hash[index]=p;
        return;
    }
    while(p!=nullptr && p->val<key)
    {
        q=p;
        p=p->next;
    }
    q->next=p->next;
    p->next= nullptr;
    delete p;
}
//////////////////////////////////////
int main() {
    reset_tab(array_of_hash,M);
    for(int i=0; i<N; i++)
    {
        insert_to_array_of_hash(array_of_hash,Array[i]);
    }
    print_list(array_of_hash,M);
    //cout << search_key(array_of_hash, 1);
    delete_key(array_of_hash,2);
    delete_key(array_of_hash,7);
    print_list(array_of_hash,M);
    return 0;
}