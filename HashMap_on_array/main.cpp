#include <iostream>
using namespace std;
const int N=5;
int Array[N]={2,3,3,2,5};
//////////////////////////////////
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

///////////////////////////////////
void print_hash_map(int *Hash_map, int n)
{
    for(int i=0; i<n; i++)cout << Hash_map[i] << endl;
}
void reset(int *Hash_map, int m)
{
    for(int i=0; i<m; i++)Hash_map[i]=-1;
}
int Hash(int key, int i)
{
    return ((key+i)%M);
}
void Hash_Insert(int *Hash_map, int key)
{
    int counter=0;
    int i=0;
    while(Hash_map[Hash(key, i)]!=-1)
    {
        i++;
        counter++;
        if(i>=M)i=0;
        if(counter==M)
        {
           // cout << "HashMap overflow!!!" << endl;
            return;
        }
    }
    Hash_map[Hash(key, i)]=key;
}
void Hash_Delete(int *Hash_map, int key)
{
    int counter=0;
    int i=0;
    while(Hash_map[Hash(key, i)]!=key) {
        i++;
        counter++;
        if(i==M)i=0;
        if(counter==M)
        {
            //cout << "This HashMap dont contain this key!!" << endl;
            return;
        }
    }
    Hash_map[Hash(key, i)]=-1;
}
bool Hash_search(int *Hash_map, int key)
{
    int counter=0;
    int i=0;
    while(Hash_map[Hash(key, i)]!=key) {
        i++;
        counter++;
        if(i==M)i=0;
        if(counter==M)
        {
            //cout << "This HashMap dont contain this key!!" << endl;
            return false;
        }
    }
    return true;
}
//////////////////////////////////////////
int find_sum(int *arr, int x, int len)
{
    int counter=0;
    int m=get_next_prime(len);
    int *Hash_map = new int[m];
    reset(Hash_map, m);
    for(int i=0; i<len; i++)
    {
        Hash_Insert(Hash_map, arr[i]);
    }
    for(int i=0; i<len; i++)
    {
        if(Hash_search(Hash_map, x-arr[i]))counter++;
    }
    return counter/2;
}
int main() {
    int *Hash_map = new int[M];
    cout << find_sum(Array,5,N);
    /*reset(Hash_array, M);
    Hash_Insert(Hash_array, 3);
    Hash_Insert(Hash_array, 2);
    Hash_Insert(Hash_array, 1);
    Hash_Insert(Hash_array, 2);
    Hash_Insert(Hash_array, 2);
    print_hash_map(Hash_array, M);
    cout << endl;
    cout << endl;
    cout << endl;
    Hash_Delete(Hash_array,2);
    Hash_Delete(Hash_array,2);
    Hash_Delete(Hash_array,2);
    print_hash_map(Hash_array, M);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << Hash_search(Hash_array, 3) << endl;
    cout << Hash_search(Hash_array, 13);*/
    return 0;
}