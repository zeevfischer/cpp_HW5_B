
#ifndef MAGICAL_CONTAINER_HPP
#define MAGICAL_CONTAINER_HPP
#include <iostream>
#include <vector>
#include <cmath>
#include "Node.hpp"

using namespace std;
namespace ariel
{
    class MagicalContainer {
    private:
        Node* elements;
        Node* prime;
        unsigned long int Size;

    public:
        MagicalContainer();
        ~MagicalContainer();
        void addElement(int element);
        void removeElement(Node* element);
        void removeElement(int element);
        unsigned long int size() const;    
        //for test 
        Node* getelements()
        {
            return this->elements;
        }
        Node* getPrimeElements()
        {
            return this->elements;
        }
        void setelements(Node* elements)
        {
            this->elements = elements;
        }
        //for test

    class AscendingIterator {
    private:
        const MagicalContainer& container;
        Node* currentElement;
        unsigned long int currentIndex;

    public:
        //Default constructor
        AscendingIterator(const MagicalContainer& contt, unsigned long int index = 0)
            : container(contt), currentIndex(index) , currentElement(contt.elements) {}
        //Destructor
        ~AscendingIterator(){};

        // Copy constructor
        AscendingIterator(const AscendingIterator& other)
            : container(other.container), currentIndex(other.currentIndex) , currentElement(other.currentElement){}

       // Assignment operator "=" 
        AscendingIterator& operator=(const AscendingIterator& other);

        // Equality comparison (operator==)
        bool operator==(const AscendingIterator& other) const;

        // Inequality comparison (operator!=)
        bool operator!=(const AscendingIterator& other) const;

        // Greater than comparison (operator>)
        bool operator>(const AscendingIterator& other) const;
            
        // Less than comparison (operator<)
        bool operator<(const AscendingIterator& other) const;

        // Pre-increment operator (operator++)
        AscendingIterator& operator++();

        // Dereference operator (operator*)
        int operator*() const;

        AscendingIterator begin();
        AscendingIterator end();
    };

    class SideCrossIterator {
    private:
        const MagicalContainer& container;
        unsigned long int currentIndex;
        bool moveFromStart;

    public:
        //Default constructor
        SideCrossIterator(const MagicalContainer& cont, unsigned long int index = 0, bool start = true)
            : container(cont), currentIndex(index), moveFromStart(start) {}
        //Destructor
        ~SideCrossIterator(){};

        // Copy constructor
        SideCrossIterator(const SideCrossIterator& other)
            : container(other.container), currentIndex(other.currentIndex), moveFromStart(other.moveFromStart) {}

        // Assignment operator "="
            SideCrossIterator& operator=(const SideCrossIterator& other);

        // Equality comparison (operator==)
        bool operator==(const SideCrossIterator& other) const;

        // Inequality comparison (operator!=)
        bool operator!=(const SideCrossIterator& other) const;

        // Greater than comparison (operator>)
        bool operator>(const SideCrossIterator& other) const;
            
        // Less than comparison (operator<)
        bool operator<(const SideCrossIterator& other) const;

        // Pre-increment operator (operator++)
        SideCrossIterator& operator++();

        // Dereference operator (operator*)
        int operator*() const;

        SideCrossIterator begin();
        SideCrossIterator end();
    };

    class PrimeIterator {
    private:
        const MagicalContainer& container;
        unsigned long int currentIndex;

        bool isPrime(int num) const;

    public:
        //Default constructor
        PrimeIterator(const MagicalContainer& cont, unsigned long int index = 0)
            : container(cont), currentIndex(index){
        }
        //Destructor
        ~PrimeIterator(){};

        // Copy constructor
        PrimeIterator(const PrimeIterator& other)
            : container(other.container), currentIndex(other.currentIndex) {}
        
        // Assignment operator "="
            PrimeIterator& operator=(const PrimeIterator& other);

        // Equality comparison (operator==)
        bool operator==(const PrimeIterator& other) const;

        // Inequality comparison (operator!=)
        bool operator!=(const PrimeIterator& other) const;

        // Greater than comparison (operator>)
        bool operator>(const PrimeIterator& other) const;
            
        // Less than comparison (operator<)
        bool operator<(const PrimeIterator& other) const;

        // Pre-increment operator (operator++)
        PrimeIterator& operator++();

        // Dereference operator (operator*)
        int operator*() const;

        PrimeIterator begin();
        PrimeIterator end();
    };
};
}
#endif  // MAGICAL_CONTAINER_HPP