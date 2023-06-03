#include <iostream>
#include "sources/MagicalContainer.hpp"

using namespace ariel;
int main() {
    // Create a MagicalContainer and add some elements
    MagicalContainer container;
    cout << "adding 17" << endl;
    container.addElement(17);
    cout << "added 17" << endl;
    cout << "adding 2" << endl;
    container.addElement(2);
    cout << "added 2" << endl;
    cout << "adding 25" << endl;
    container.addElement(25);
    cout << "added 25" << endl;
    cout << "adding 9" << endl;
    container.addElement(9);
    cout << "added 9" << endl;
    cout << "adding 3" << endl;
    container.addElement(3);
    cout << "added 3" << endl;
    
    cout << endl;
    for(int i=0;i<container.size();i++)
    {
        container.getelements()->print();
        if(container.getelements()->Getnext() != nullptr)
            container.setelements(container.getelements()->Getnext());
    }
    // // Print container size
    // std::cout << "Size of container: " << container.size() << std::endl;

    // // Use AscendingIterator to display elements in ascending order
    // std::cout << "Elements in ascending order:\n";
    // MagicalContainer::AscendingIterator ascIter(container);
    // for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
    //     std::cout << *it << ' ';   // 2 3 9 17 25
    // }
    // std::cout << std::endl;

    // // Use DescendingIterator to display elements in descending order
    // std::cout << "Elements in cross order:\n";
    // MagicalContainer::SideCrossIterator crossIter(container);
    // for (auto it = crossIter.begin(); it != crossIter.end(); ++it) {
    //     std::cout << *it << ' ';  // 2 25 3 17 9
    // }
    // std::cout << std::endl;

    // // Use PrimeIterator to display prime numbers only
    // std::cout << "Prime numbers:\n";
    // MagicalContainer::PrimeIterator primeIter(container);
    // for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
    //     std::cout << *it << ' ';  // 2 3 17 
    // }
    // std::cout << std::endl;

    // // Remove an element from the container and display the size
    // container.removeElement(9);
    // std::cout << "Size of container after removing an element: " << container.size() << std::endl;

    return 0;
}
