#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node* next;
    Node* prev;

    bool isPrime;
    // if isPrime == true 
    Node* PrimeNext;
    Node* PrimePrev;
    
public:
    Node(int data);
    bool Prime(int data);
    void print();
    //setters
    void Setdata(int data);
    void SetNext(Node* next);
    void SetPrev(Node* prev);
    void SetisPrime(bool isprime);
    void SetprimeNext(Node* primeNext);
    void SetprimePrev(Node* primePrev);
    //getters
    int Getdata();
    Node* Getnext();
    Node* Getprev(); 
    bool GetisPrime();
    Node* GetprimeNext();
    Node* GetprimePrev();
};
#endif 