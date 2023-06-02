#include "MagicalContainer.hpp"

namespace ariel {

    void MagicalContainer::addElement(int element)
    {
    }

    void MagicalContainer::removeElement(int element)
    {
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
        return 0;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
    {
        return AscendingIterator(container, 0);
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
    {
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
