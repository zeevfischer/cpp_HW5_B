#include "doctest.h"
#include "sources/MagicalContainer.hpp"
using namespace ariel;

TEST_CASE("MagicalContainer AscendingIterator") {
    MagicalContainer container;

    SUBCASE("Empty Container") {
        CHECK(container.size() == 0);

        // Test begin() and end()
        MagicalContainer::AscendingIterator ascIt(container);
        MagicalContainer::AscendingIterator ascEnd(container);

        // Iterator should be equal to end() for an empty container
        CHECK(ascIt == ascEnd);
    }

    SUBCASE("Non-empty Container") {
        // Add elements to the container
        container.addElement(5);
        container.addElement(2);
        container.addElement(8);
        container.addElement(3);

        // Test size()
        CHECK(container.size() == 4);

        // Test begin() and end()
        MagicalContainer::AscendingIterator ascIt(container);
        MagicalContainer::AscendingIterator ascEnd(container);

        // Iterate over the container using AscendingIterator
        int expected[] = {2, 3, 5, 8};
        int index = 0;
        while (ascIt != ascEnd) {
            CHECK(*ascIt == expected[index]);
            ++ascIt;
            ++index;
        }
        CHECK(index == 4);
    }
}

TEST_CASE("MagicalContainer SideCrossIterator") {
    MagicalContainer container;

    SUBCASE("Empty Container") {
        CHECK(container.size() == 0);

        // Test begin() and end()
        MagicalContainer::SideCrossIterator crossIt(container);
        MagicalContainer::SideCrossIterator crossEnd(container);

        // Iterator should be equal to end() for an empty container
        CHECK(crossIt == crossEnd);
    }

    SUBCASE("Non-empty Container") {
        // Add elements to the container
        container.addElement(5);
        container.addElement(2);
        container.addElement(8);
        container.addElement(3);
        container.addElement(7);

        // Test size()
        CHECK(container.size() == 5);

        // Test begin() and end()
        MagicalContainer::SideCrossIterator crossIt(container);
        MagicalContainer::SideCrossIterator crossEnd(container);

        // Iterate over the container using SideCrossIterator
        int expected[] = {5, 8, 3, 2, 7};
        int index = 0;
        while (crossIt != crossEnd) {
            CHECK(*crossIt == expected[index]);
            ++crossIt;
            ++index;
        }
        CHECK(index == 5);
    }
}

TEST_CASE("MagicalContainer PrimeIterator") {
    MagicalContainer container;

    SUBCASE("Empty Container") {
        CHECK(container.size() == 0);

        // Test begin() and end()
        MagicalContainer::PrimeIterator primeIt(container);
        MagicalContainer::PrimeIterator primeEnd(container);

        // Iterator should be equal to end() for an empty container
        CHECK(primeIt == primeEnd);
    }

    SUBCASE("Non-empty Container") {
        // Add elements to the container
        container.addElement(5);
        container.addElement(2);
        container.addElement(8);
        container.addElement(3);
        container.addElement(7);

        // Test size()
        CHECK(container.size() == 5);

        // Test begin() and end()
        MagicalContainer::PrimeIterator primeIt(container);
        MagicalContainer::PrimeIterator primeEnd(container);

        // Iterate over the container using PrimeIterator
        int expected[] = {2, 5, 7};
        int index = 0;
        while (primeIt != primeEnd) {
            CHECK(*primeIt == expected[index]);
            ++primeIt;
            ++index;
        }
        CHECK(index == 3);
    }
}


using namespace ariel;

TEST_CASE("MagicalContainer AscendingIterator") {
    MagicalContainer container;

    SUBCASE("Empty Container") {
        CHECK(container.size() == 0);

        // Test begin() and end()
        MagicalContainer::AscendingIterator ascIt(container);
        MagicalContainer::AscendingIterator ascEnd(container);

        // Iterator should be equal to end() for an empty container
        CHECK(ascIt == ascEnd);
    }

    SUBCASE("Non-empty Container") {
        // Add elements to the container
        container.addElement(5);
        container.addElement(2);
        container.addElement(8);
        container.addElement(3);

        // Test size()
        CHECK(container.size() == 4);

        // Test begin() and end()
        MagicalContainer::AscendingIterator ascIt(container);
        MagicalContainer::AscendingIterator ascEnd(container);

        // Iterate over the container using AscendingIterator
        int expected[] = {2, 3, 5, 8};
        int index = 0;
        while (ascIt != ascEnd) {
            CHECK(*ascIt == expected[index]);
            ++ascIt;
            ++index;
        }
        CHECK(index == 4);
    }
}

TEST_CASE("MagicalContainer SideCrossIterator") {
    MagicalContainer container;

    SUBCASE("Empty Container") {
        CHECK(container.size() == 0);

        // Test begin() and end()
        MagicalContainer::SideCrossIterator crossIt(container);
        MagicalContainer::SideCrossIterator crossEnd(container);

        // Iterator should be equal to end() for an empty container
        CHECK(crossIt == crossEnd);
    }

    SUBCASE("Non-empty Container") {
        // Add elements to the container
        container.addElement(5);
        container.addElement(2);
        container.addElement(8);
        container.addElement(3);
        container.addElement(7);

        // Test size()
        CHECK(container.size() == 5);

        // Test begin() and end()
        MagicalContainer::SideCrossIterator crossIt(container);
        MagicalContainer::SideCrossIterator crossEnd(container);

        // Iterate over the container using SideCrossIterator
        int expected[] = {5, 8, 3, 2, 7};
        int index = 0;
        while (crossIt != crossEnd) {
            CHECK(*crossIt == expected[index]);
            ++crossIt;
            ++index;
        }
        CHECK(index == 5);
    }
}

TEST_CASE("MagicalContainer PrimeIterator") {
    MagicalContainer container;

    SUBCASE("Empty Container") {
        CHECK(container.size() == 0);

        // Test begin() and end()
        MagicalContainer::PrimeIterator primeIt(container);
        MagicalContainer::PrimeIterator primeEnd(container);

        // Iterator should be equal to end() for an empty container
        CHECK(primeIt == primeEnd);
    }

    SUBCASE("Non-empty Container") {
        // Add elements to the container
        container.addElement(5);
        container.addElement(2);
        container.addElement(8);
        container.addElement(3);
        container.addElement(7);

        // Test size()
        CHECK(container.size() == 5);

        // Test begin() and end()
        MagicalContainer::PrimeIterator primeIt(container);
        MagicalContainer::PrimeIterator primeEnd(container);

        // Iterate over the container using PrimeIterator
        int expected[] = {2, 5, 7};
        int index = 0;
        while (primeIt != primeEnd) {
            CHECK(*primeIt == expected[index]);
            ++primeIt;
            ++index;
        }
        CHECK(index == 3);
    }
}
// Test case for comparing iterators from the same container
TEST_CASE("Comparing iterators from the same container") {
    MagicalContainer container;
    for (int i = 0; i < 10; ++i) {
        container.addElement(i + 1);
    }

    SUBCASE("Comparing AscendingIterator with itself") {
        MagicalContainer::AscendingIterator it1(container);
        MagicalContainer::AscendingIterator it2(container);
        CHECK(it1 == it2);
        CHECK(!(it1 != it2));
        CHECK(!(it1 < it2));
        CHECK(!(it1 > it2));
    }

    SUBCASE("Comparing SideCrossIterator with itself") {
        MagicalContainer::SideCrossIterator it1(container);
        MagicalContainer::SideCrossIterator it2(container);
        CHECK(it1 == it2);
        CHECK(!(it1 != it2));
        CHECK(!(it1 < it2));
        CHECK(!(it1 > it2));
    }

    SUBCASE("Comparing PrimeIterator with itself") {
        MagicalContainer::PrimeIterator it1(container);
        MagicalContainer::PrimeIterator it2(container);
        CHECK(it1 == it2);
        CHECK(!(it1 != it2));
        CHECK(!(it1 < it2));
        CHECK(!(it1 > it2));
    }
}
