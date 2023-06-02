#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    int index;
    Node* next;
    Node* prev;

    bool isPrime;
    // if isPrime == true 
    int primeIndex;
    Node* PrimeNext;
    Node* PrimePrev;
    
public:
    Node(int data);
    bool Prime(int data);
    //setters
    void Setdata(int data);
    void Setindex(int index);
    void SetNext(Node* next);
    void SexPrev(Node* prev);
    void SetisPrime(bool isprime);
    void SetprimeIndex(int primeIndex);
    void SetprimeNext(Node* primeNext);
    void SetprimePrev(Node* primePrev);
    //getters
    int Getdata();
    int Getindex();
    Node* Getnext();
    Node* Getprev();
    bool GetisPrime();
    int GetprimeIndex();
    Node* GetprimeNext();
    Node* GetprimePrev();
};
#endif 