#pragma once
class IntegerArray
{
public:
	IntegerArray() = default;
	IntegerArray(int length);
	IntegerArray(const IntegerArray& a);
	~IntegerArray();

	IntegerArray& operator=(const IntegerArray& a);
	int& operator[](int index);
	void erase();//удаление массива
	int getLength() const;//размер
	void reallocate(int newLength);//изменение размер удаление элементов массива
	void resize(int newLength);//изменение размер сохранение элементов массива
	void insertBefore(int value, int index);//вставка элемента value перед   index позицией
	void remove(int index);//удаление элемента index
	void insertAtBeginning(int value);//вставка 1 элемента
	void insertAtEnd(int value);//вставка последнего элемента

private:
	int _length{};
	int* _data{};
};
