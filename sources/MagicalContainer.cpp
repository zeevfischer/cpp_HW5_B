#include "MagicalContainer.hpp"

namespace ariel {
    MagicalContainer::MagicalContainer()
    {
        this->elements = nullptr;
        this->Size = 0;
    }
    MagicalContainer::~MagicalContainer()
    {
        while (this->elements->Getnext() != nullptr)
        {
            this->elements = this->elements->Getnext();
            delete(this->elements->Getprev());
        }
        delete(this->elements);
        
    }
    void MagicalContainer::addElement(int element)
    {
        //now element 
        Node* Newelement = new Node(element);
        //if this is the first element in the list
        if(this->elements == nullptr)
        {
            if(Newelement->GetisPrime() == true && this->prime == nullptr)
            {
                this->prime = Newelement;
            }
            this->elements = Newelement; 
            this->Size++;
            return;
        }
        // not the first element in the list
        // create a new pointer to the elements 
        Node* temp = this->elements;
        //move the pointer 
        while (temp->Getnext() != nullptr && temp->Getdata() < Newelement->Getdata())
        {
            // cout << "moved" << endl;
            temp = temp->Getnext();
        }
        // cout << "temp: " << temp->Getdata() << endl;
        if(temp->Getdata() < Newelement->Getdata())
        {
            // cout << "adding after temp" <<endl; 
            Newelement->SetNext(temp->Getnext());
            Newelement->SetPrev(temp);
            temp->SetNext(Newelement);
        }
        if(temp->Getdata() > Newelement->Getdata())
        {
            // cout << "adding befor temp" <<endl; 
            if(temp->Getprev() == nullptr)
            {
                // cout << "change root" <<endl;
                this->elements = Newelement;
            }
            if(temp->Getprev() != nullptr)
            {
                temp->Getprev()->SetNext(Newelement);
            }
            Newelement->SetNext(temp);
            Newelement->SetPrev(temp->Getprev());
            temp->SetPrev(Newelement);
        }
        this->Size++;
        //if Newelement is prime 
        if(Newelement->GetisPrime() == true)
        {
            cout << "prime" << endl;
            // not the first element in the list that is aken car of up top
            // create a new pointer to the prime 
            temp = this->prime;
            //move the pointer to next prime
            while (temp->GetprimeNext() != nullptr && temp->Getdata() < Newelement->Getdata())
            {
                cout << "moved" << endl;
                temp = temp->GetprimeNext();
            }
            if(temp->Getdata() < Newelement->Getdata())
            {
                cout << "adding after temp" <<endl; 
                Newelement->SetprimeNext(temp->GetprimeNext());
                Newelement->SetprimePrev(temp);
                temp->SetprimeNext(Newelement);
            }
            if(temp->Getdata() > Newelement->Getdata())
            {
                cout << "adding befor temp" <<endl; 
                if(temp->GetprimePrev() == nullptr)
                {
                    cout << "changed root" <<endl;
                    this->prime = Newelement;
                }
                if(temp->GetprimePrev() != nullptr)
                {
                    temp->GetprimePrev()->SetprimeNext(Newelement);
                }
                Newelement->SetprimeNext(temp);
                Newelement->SetprimePrev(temp->GetprimePrev());
                temp->SetprimePrev(Newelement);
            }
        }
    }

    void MagicalContainer::removeElement(Node* Todelete)
    {
        // creat a pointer to this so we dont loos it and cand delete it at the end 
        Node* temp = Todelete;
        // if this is the firs element
        if(Todelete->Getprev() == nullptr)
        {
            Todelete->Getnext()->SetPrev(nullptr);
        }
        //if this is the last element 
        else if(Todelete->Getnext() == nullptr)
        {
            Todelete->Getnext()->SetNext(nullptr);
        }
        //this is in the middel 
        else
        {
            Todelete->Getprev()->SetNext(Todelete->Getnext());
            Todelete->Getnext()->SetPrev(Todelete->Getprev());
        }
        delete(temp);
    }
    void MagicalContainer::removeElement(int Todelete)
    {
        // creat a pointer to this so we dont loos it and cand delete it at the end 
        Node* temp = this->elements;
        while(temp->Getdata() != Todelete)
        {
            temp = temp->Getnext();
        }
        // if this is the firs element
        if(temp->Getprev() == nullptr)
        {
            temp->Getnext()->SetPrev(nullptr);
        }
        //if this is the last element 
        else if(temp->Getnext() == nullptr)
        {
            temp->Getnext()->SetNext(nullptr);
        }
        //this is in the middel 
        else
        {
            temp->Getprev()->SetNext(temp->Getnext());
            temp->Getnext()->SetPrev(temp->Getprev());
        }
        delete(temp);
    }
    unsigned long int MagicalContainer::size() const
    {
        return this->Size;
    }

    // AscendingIterator
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other)
    {
        if (this != &other)
        {
            currentIndex = other.currentIndex;
        }
        return *this;
    }
    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const
    {
        return currentIndex == other.currentIndex;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const
    {
        return currentIndex != other.currentIndex;
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const
    {
        return currentIndex > other.currentIndex;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const
    {
        return currentIndex < other.currentIndex;
    }

    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++()
    {
        ++currentIndex;
        return *this;
    }

    int MagicalContainer::AscendingIterator::operator*() const
    {
        return this->currentElement->Getdata();
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
    {
        return AscendingIterator(container, 0);
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
    {
        // return AscendingIterator(container, this->container.size());
        return AscendingIterator(container, this->container.size());
    }

    // SideCrossIterator
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other)
    {
        if (this != &other) {
            currentIndex = other.currentIndex;
        }
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const
    {
        return currentIndex == other.currentIndex;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const
    {
        return currentIndex != other.currentIndex;
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const
    {
        return currentIndex > other.currentIndex;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const
    {
        return currentIndex < other.currentIndex;
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() 
    {
        if (moveFromStart)
        {
            if (currentIndex < container.size() - 1)
            {
                currentIndex += 2;
            }
            else
            {
                currentIndex = 1;
            }
        } 
        else 
        {
            if (currentIndex > 0)
            {
                currentIndex -= 2;
            }
            else
            {
                currentIndex = container.size() - 2;
            }
        }
        return *this;
    }

    int MagicalContainer::SideCrossIterator::operator*() const
    {
        return 0;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
    {
        return SideCrossIterator(container, 0, true);
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
    {
        // if (container.size() % 2 == 0)
        // {
        //     return SideCrossIterator(container, container.size() - 1, true);
        // }
        // else
        // {
        //     return SideCrossIterator(container, container.size() - 2, false);
        // }
        return SideCrossIterator(container, 0, true);
    }

    // PrimeIterator

    bool MagicalContainer::PrimeIterator::isPrime(int num) const 
    {
        if (num < 2)
            return false;
        for (int i = 2; i <= sqrt(num); ++i) {
            if (num % i == 0)
                return false;
        }
        return true;
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other)
    {
        if (this != &other) {
            currentIndex = other.currentIndex;
        }
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const 
    {
        return currentIndex == other.currentIndex;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const 
    {
        return currentIndex != other.currentIndex;
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const 
    {
        return currentIndex > other.currentIndex;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const 
    {
        return currentIndex < other.currentIndex;
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() 
    {
        return *this;
    }

    int MagicalContainer::PrimeIterator::operator*() const
    {
        return 0;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
    {
        unsigned long int index = 0;
        return PrimeIterator(container, index);
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
    {
        return PrimeIterator(container, container.size());
    }

} // namespace ariel
