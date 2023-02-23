#include "integerarray.h"
#include <iostream>
#include <stdexcept>

IntegerArray::IntegerArray(int length) :_length(length)
{
	try
	{
		if (length <= 0)
			throw std::invalid_argument(" length array <= 0 ");
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught: " << e.what() << "\n";
	};

	if (length > 0)
		_data = new int[length] {};

}
IntegerArray::~IntegerArray()
{
	delete[] _data;
}
void IntegerArray::erase()
{
	delete[] _data;
	_data = nullptr;
	_length = 0;
}
int& IntegerArray::operator[](int index)
{

	try
	{
		if ((0 > index) || (index > _length))
		{
			throw std::out_of_range(" index out of range [] ");
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught: " << e.what() << "\n";
		//std:cout << " index " << index << "\n";

	};

	return _data[index];
}
int IntegerArray::getLength() const
{
	return _length;
}
void IntegerArray::reallocate(int newLength)
{
	void erase();
	if (newLength <= 0)
		return;
	_data = new int[newLength];
	_length = newLength;
}
void IntegerArray::resize(int newLength)
{
	if (newLength == _length)
		return;
	if (newLength <= 0)
	{
		erase();
		return;
	}
	int* data{ new int[newLength] };

	if (_length > 0)
	{
		int elementsToCopy{ (newLength > _length) ? _length : newLength };
		for (int index{ 0 }; index < elementsToCopy; ++index) data[index] = _data[index];
	}
	delete[] _data;
	_data = data;
	_length = newLength;
}
IntegerArray::IntegerArray(const IntegerArray& a)
{
	reallocate(a.getLength());
	for (int index{ 0 }; index < _length; ++index)
		_data[index] = a._data[index];
}

IntegerArray& IntegerArray::operator=(const IntegerArray& a)
{
	if (&a == this)
		return *this;
	IntegerArray::reallocate(a.getLength());
	for (int index{ 0 }; index < _length; ++index)
		_data[index] = a._data[index];
	return *this;
}
void IntegerArray::insertBefore(int value, int index)
{
	try
	{
		if ((0 > index) || (index > _length))
			throw std::out_of_range(" insertBefore - index out of range ");
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught: " << e.what() << "\n";
	}


	int* data{ new int[_length + 1] };
	for (int before{ 0 }; before < index; ++before)
		data[before] = _data[before];
	data[index] = value;

	for (int after{ index }; after < _length; ++after)
		data[after + 1] = _data[after];
	delete[] _data;
	_data = data;
	++_length;
}
void IntegerArray::remove(int index)
{
	try
	{
		 if ((0 > index) || (index > _length))
			throw std::out_of_range(" remove - index out of range ");
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught: " << e.what() << "\n";
	};
	if (_length == 1)
	{
		erase();
		return;
	}
	int* data{ new int[_length - 1]
	};
	for (int before{ 0 }; before < index; ++before) data[before] = _data[before];
	for (int after{ index + 1 }; after < _length; ++after) data[after - 1] = _data[after];
	delete[] _data;
	_data = data;
	--_length;
}
void IntegerArray::insertAtBeginning(int value)
{
	insertBefore(value, 0);
}
void IntegerArray::insertAtEnd(int value)
{
	insertBefore(value, _length);
}