#include <iostream>
#include "integerarray.h"


int main()
{
	const int size_arr = 10;//size_arr=0
	
	IntegerArray array(size_arr);

	for (int i{ 0 }; i < array.getLength(); ++i)//array.getLength() -- i < 15
		array[i] = i + 1;

	array.insertBefore(20, 10); //array.insertBefore(20, 15)

	array.remove(8); //array.remove(15)

	array.insertAtEnd(30);

	array.insertAtBeginning(40);

	for (int i{ 0 }; i < array.getLength(); ++i)
		std::cout << array[i] << "  ";
	std::cout << "\n";

	return 0;
}

