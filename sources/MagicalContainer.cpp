#include "MagicalContainer.hpp"

namespace ariel {
    MagicalContainer::MagicalContainer()
    {
        this->elements = nullptr;
        this->Size = 0;
        this->primesize = 0;
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
                this->primesize++;
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
            temp = temp->Getnext();
        }
        if(temp->Getdata() < Newelement->Getdata())
        {
            Newelement->SetNext(temp->Getnext());
            Newelement->SetPrev(temp);
            temp->SetNext(Newelement);
        }
        if(temp->Getdata() > Newelement->Getdata())
        {
            if(temp->Getprev() == nullptr)
            {
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
            this->primesize ++;
            // not the first element in the list that is aken car of up top
            // create a new pointer to the prime 
            temp = this->prime;
            //move the pointer to next prime
            while (temp->GetprimeNext() != nullptr && temp->Getdata() < Newelement->Getdata())
            {
                temp = temp->GetprimeNext();
            }
            if(temp->Getdata() < Newelement->Getdata())
            {
                Newelement->SetprimeNext(temp->GetprimeNext());
                Newelement->SetprimePrev(temp);
                temp->SetprimeNext(Newelement);
            }
            if(temp->Getdata() > Newelement->Getdata())
            {
                if(temp->GetprimePrev() == nullptr)
                {
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
        temp = this->elements;
        while (temp->Getnext() != nullptr)
        {
            if(temp != nullptr)
                temp = temp->Getnext();
        }
        if(temp != nullptr)
            this->end = temp;
    }

    void MagicalContainer::removeElement(Node* Todelete)
    {
        // creat a pointer to this so we dont loos it and cand delete it at the end 
        Node* temp = Todelete;
        // if this is the firs element
        if(Todelete->Getprev() == nullptr)
        {
            this->elements = Todelete->Getnext();
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
            if(temp == nullptr)
            {
                throw runtime_error("no element found");
            }
        }
        if(temp->GetisPrime()==true)
        {
            // if this is the firs element
            if(temp->GetprimePrev() == nullptr)
            {
                temp->GetprimeNext()->SetprimePrev(nullptr);
            }
            //if this is the last element 
            else if(temp->GetprimeNext() == nullptr)
            {
                temp->GetprimePrev()->SetprimeNext(nullptr);
            }
            //this is in the middel 
            else
            {
                temp->GetprimePrev()->SetprimeNext(temp->GetprimeNext());
                temp->GetprimeNext()->SetprimePrev(temp->GetprimePrev());
            }
        }
        // if this is the firs element
        if(temp->Getprev() == nullptr)
        {
            this->elements = temp->Getnext();
        }
        //if this is the last element 
        else if(temp->Getnext() == nullptr)
        {
            temp->Getprev()->SetNext(nullptr);
        }
        //this is in the middel 
        else
        {
            temp->Getprev()->SetNext(temp->Getnext());
            temp->Getnext()->SetPrev(temp->Getprev());
        }
        this->Size --;
        delete(temp);
    }
    int MagicalContainer::size() const
    {
        return this->Size;
    }

    // AscendingIterator
    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other)
    {
        if (this != &other)
        {
            this->currentIndex = other.currentIndex;
            this->currentElement = other.currentElement;
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
        this->currentElement = this->currentElement->Getnext();
        return *this;
    }

    int MagicalContainer::AscendingIterator::operator*() const
    {
        return this->currentElement->Getdata();
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
    {
        AscendingIterator temp(container);
        return temp;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
    {
        AscendingIterator temp(container);
        temp.currentElement = nullptr;
        temp.currentIndex = container.size();
        return temp;
    }

    // SideCrossIterator
    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other)
    {
        if (this != &other)
        {
            this->start = other.start;
            this->End = other.End;
            this->FromStart = other.FromStart;
        }
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const
    {
        if(this->start == other.start && this->End == other.End && this->FromStart == other.FromStart)
        {
            return true;
        }
        return false;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const
    {
        return !(*this==other);
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const //fix
    {
        return this->index > other.index;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const //fix
    {
        return this->index < other.index;
    }

    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() 
    {
        this->index++;
        if(container.size()%2 == 1 && this->start == this->End)
        {
            this->start = nullptr;
            this->End = nullptr;
            return *this;
        }
        if(this->FromStart == true)
        {
            // cout << "start" <<endl;
            this->start = this->start->Getnext();
            this->FromStart = false;
        }
        else
        {
            // cout << "end" <<endl;
            this->End = this->End->Getprev();
            this->FromStart = true;
        }
        if(container.size()%2 == 0 && this->start == this->End->Getnext())
        {
            this->start = nullptr;
            this->End = nullptr;
            return *this;
        }
        return *this;
    }

    int MagicalContainer::SideCrossIterator::operator*() const
    {
        if(this->FromStart == true)
        {
            return this->start->Getdata();
        }
        else
        {
            return this->End->Getdata();
        }
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
    {
        SideCrossIterator temp(container);
        return temp;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
    {
        SideCrossIterator temp(container);
        temp.start = nullptr;
        temp.End = nullptr;
        return temp;
    }

    // PrimeIterator
    //hellper function
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
            this->currentIndex = other.currentIndex;
            this->current = other.current;
        }
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const 
    {
        // if(currentIndex == other.currentIndex && this->current->Getdata()== other.current->Getdata())
        // {
        //     return true;
        // }
        // return false;
        return currentIndex == other.currentIndex;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const 
    {
        // return !(*this == other);
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
        currentIndex++;
        this->current = this->current->GetprimeNext();
        return *this;
    }

    int MagicalContainer::PrimeIterator::operator*() const
    {
        return this->current->Getdata();
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
    {
        PrimeIterator temp(container);
        return temp;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
    {
        PrimeIterator temp(container);
        temp.current = nullptr;
        temp.currentIndex = container.primesize;
        return temp;
    }

} // namespace ariel
