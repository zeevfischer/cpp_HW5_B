#include "Node.hpp"
#include <iostream>
#include <cmath>
using namespace std;

Node::Node(int data)
{
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;

    this->isPrime = this->Prime(data);
    this->PrimeNext = nullptr;
    this->PrimePrev = nullptr;
}
void Node::print()
{
    cout << "data: " << this->data << endl;
    cout << "is prime: " << this->isPrime << endl; 
}
bool Node::Prime(int data)
{
    if (data <= 1)
    {
        return false;  // Numbers less than or equal to 1 are not prime
    }
    if(data == 2)
    {
        return true;
    }
    int sqrtNumber = static_cast<int>(sqrt(data));
    for (int i = 2; i <= sqrtNumber; ++i)
    {
        if (data % i == 0) {
            return false;  // Divisible by a number other than 1 and itself
        }
    }
    return true;  // Number is prime
}
//setters
void Node::Setdata(int data)
{
    this->data = data;
}
void Node::SetNext(Node* next)
{
    this->next = next;
}
void Node::SetPrev(Node* prev)
{
    this->prev = prev;
}
void Node::SetisPrime(bool isprime)
{
    this->isPrime = isprime;
}
void Node::SetprimeNext(Node* primeNext)
{
    this->PrimeNext = primeNext;
}
void Node::SetprimePrev(Node* primePrev)
{
    this->PrimePrev = primePrev;
}
//getters
int Node::Getdata()
{
    return this->data;
}
Node* Node::Getnext()
{
    return this->next;
}
Node* Node::Getprev()
{
    return this->prev;
}
bool Node::GetisPrime()
{
    return this->isPrime;
}
Node* Node::GetprimeNext()
{
    return this->PrimeNext;
}
Node* Node::GetprimePrev()
{
    return this->PrimePrev;
}
