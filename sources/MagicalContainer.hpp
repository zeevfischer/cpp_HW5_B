
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
        Node* end;
        int Size;
        int primesize;

    public:
        MagicalContainer();
        ~MagicalContainer();
        void addElement(int element);
        void removeElement(Node* element);
        void removeElement(int element);
        int size() const;  

        //for test 
        Node* getend()
        {
            return this->end;
        }
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
        
        ////////////////////////////////tidy
        // Copy constructor
        MagicalContainer(const MagicalContainer& other)
            : elements(nullptr), prime(nullptr), end(nullptr), Size(0), primesize(0) {
            *this = other;
        }

        // Copy assignment operator
        MagicalContainer& operator=(const MagicalContainer& other) {
            if (this != &other) 
            {
                this->elements = other.elements;
                this->Size = other.Size;
                this->prime = other.prime;
                this->primesize = other.primesize;
                this->end = other.end;   
            }
            return *this;
        }

        // Move constructor
        MagicalContainer(MagicalContainer&& other) noexcept
            : elements(other.elements), prime(other.prime), end(other.end), Size(other.Size), primesize(other.primesize) {
            // Reset other's data
            other.elements = nullptr;
            other.prime = nullptr;
            other.end = nullptr;
            other.Size = 0;
            other.primesize = 0;
        }

        // Move assignment operator
        MagicalContainer& operator=(MagicalContainer&& other) noexcept 
        {
            if (this != &other) {
                // Clear current data
                delete[] elements;
                delete[] prime;
                delete[] end;

                // Move other's data
                elements = other.elements;
                prime = other.prime;
                end = other.end;
                Size = other.Size;
                primesize = other.primesize;

                // Reset other's data
                other.elements = nullptr;
                other.prime = nullptr;
                other.end = nullptr;
                other.Size = 0;
                other.primesize = 0;
            }

            return *this;
        }
        ////////////////////////////////tidy

    class AscendingIterator {
    private:
        const MagicalContainer& container;
        Node* currentElement;
        int currentIndex;

    public:
        //Default constructor
        AscendingIterator(const MagicalContainer& cont)
            : container(cont), currentIndex(0) , currentElement(cont.elements)
        {
        }
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
        /////////////////////tidy
        // Move constructor
        AscendingIterator(AscendingIterator&& other) noexcept
            : container(other.container), currentElement(other.currentElement), currentIndex(other.currentIndex) {
            // Reset other's data
            other.currentElement = nullptr;
            other.currentIndex = 0;
        }

        // Move assignment operator
        AscendingIterator& operator=(AscendingIterator&& other)noexcept
        {
            if (this != &other) {
                // Move other's data
                currentElement = other.currentElement;
                currentIndex = other.currentIndex;

                // Reset other's data
                other.currentElement = nullptr;
                other.currentIndex = 0;
            }

            return *this;
        }
        /////////////////////tidy
    };

    class SideCrossIterator {
    private:
        const MagicalContainer& container;
        Node* start = nullptr;
        Node* End = nullptr;
        bool FromStart = true;
        int index = 0;

    public:
        //Default constructor
        SideCrossIterator(const MagicalContainer& cont, unsigned long int index = 0)
            : container(cont) ,start(cont.elements),End(cont.end) {}
        //Destructor
        ~SideCrossIterator(){};

        // Copy constructor
        SideCrossIterator(const SideCrossIterator& other)
            : container(other.container), start(other.container.elements),End(other.container.end),FromStart(other.FromStart), index(other.index){}

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
        ////////////tidy
        // Move constructor
        SideCrossIterator(SideCrossIterator&& other)noexcept
            : container(other.container), start(other.start), End(other.End), FromStart(other.FromStart), index(other.index) {
            // Reset other's data
            other.start = nullptr;
            other.End = nullptr;
            other.FromStart = true;
            other.index = 0;
        }

        // Move assignment operator
        SideCrossIterator& operator=(SideCrossIterator&& other) noexcept {
            if (this != &other) {
                // Move other's data
                start = other.start;
                End = other.End;
                FromStart = other.FromStart;
                index = other.index;

                // Reset other's data
                other.start = nullptr;
                other.End = nullptr;
                other.FromStart = true;
                other.index = 0;
            }

            return *this;
        }
        ////////////tidy
    };

    class PrimeIterator {
    private:
        const MagicalContainer& container;
        Node* current;
        int currentIndex;

        bool isPrime(int num) const;

    public:
        //Default constructor
        PrimeIterator(const MagicalContainer& cont, int index = 0)
            : container(cont), currentIndex(index),current(container.prime){
        }
        //Destructor
        ~PrimeIterator(){};

        // Copy constructor
        PrimeIterator(const PrimeIterator& other)
            : container(other.container), currentIndex(other.currentIndex), current(other.current){}
        
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
        //////////////////tidy
        // Move constructor
        PrimeIterator(PrimeIterator&& other)noexcept
            : container(other.container), current(other.current), currentIndex(other.currentIndex) {
            // Reset other's data
            other.current = nullptr;
            other.currentIndex = 0;
        }

        // Move assignment operator
        PrimeIterator& operator=(PrimeIterator&& other) noexcept{
            if (this != &other) {
                // Move other's data
                current = other.current;
                currentIndex = other.currentIndex;

                // Reset other's data
                other.current = nullptr;
                other.currentIndex = 0;
            }

            return *this;
        }
        //////////////////tidy
    };
};
}
#endif  // MAGICAL_CONTAINER_HPP