/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-08-30.  
           
  TIME: 12:25 AM.
*/
#include <iostream>
#include <vector>
using namespace std;

int main1() {
    vector<int> number;
    number.push_back(3);
    cout << "number.capacity(after adding 1)" << number.capacity() << endl;
    number.push_back(4);
    cout << "number.capacity(after adding 2)" << number.capacity() << endl;
    number.push_back(2);
    cout << "number.capacity(after adding 3)" << number.capacity() << endl;
    number.push_back(3);
    cout << "number.capacity(after adding 4)" << number.capacity() << endl;
    number.push_back(4);
    cout << "number.capacity(after adding 5)" << number.capacity() << endl;
    number.push_back(2);
    cout << "number.capacity(after adding 6)" << number.capacity() << endl;


    for (int i = 0; i < number.size(); ++i) {
        std::cout << "Element " << i << ": " << number[i] << std::endl;
    }
    return 0;
}

int main2() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};


	    // Inserting an element at the second position
	    numbers.insert(numbers.begin() + 1, 10);

	    // Erasing the third element
	    numbers.erase(numbers.begin() + 2);

	    // Displaying the elements
	    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        	        std::cout << *it << " ";
        	    }
        std::cout << std::endl;

    // Iterating from the last element to the first
    for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) {
        std::cout << *it << " ";
    }

        // return t/f if mt
    if(numbers.empty()){
        cout << "mt";
    }else{
        cout << "not mt\n";
    }

    // clear the hole container
        numbers.clear();

    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }

        return 0;
    }

int main4() {
    std::vector<int> numbers(5, 100);  // Create a vector with 5 elements, each initialized to 100

    std::cout << "Initial size: " << numbers.size() << std::endl;
    std::cout << "Initial capacity: " << numbers.capacity() << std::endl;

    // Resizing the vector
    numbers.resize(10, 200);  // Resizes the vector to 10 elements, adding 200 to the new positions

    std::cout << "Size after resizing: " << numbers.size() << std::endl;
    std::cout << "Capacity after resizing: " << numbers.capacity() << std::endl;

    // Displaying the elements
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}



int main() {
    std::vector<int> numbers;

    // Add elements to the vector
    for (int i = 0; i < 10; ++i) {
        numbers.push_back(i);
    }

    std::cout << "size orignal: " << numbers.size() << std::endl;

    // Resize the vector to a smaller size


    std::cout << "Capacity after resize: " << numbers.capacity() << std::endl;

    // Request to shrink capacity to fit the size
    numbers.shrink_to_fit();

    std::cout << "Capacity after shrink_to_fit: " << numbers.capacity() << std::endl;

    return 0;
}
