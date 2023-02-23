#pragma once
class IntegerArray
{
public:
	IntegerArray() = default;
	IntegerArray(int length);
	IntegerArray(const IntegerArray& a);
	~IntegerArray();

	IntegerArray& operator=(const IntegerArray& a);
	void erase();//�������� �������
	int& operator[](int index);
	int getLength() const;//������
	void reallocate(int newLength);//��������� ������ �������� ��������� �������
	void resize(int newLength);//��������� ������ ���������� ��������� �������
	void insertBefore(int value, int index);//������� �������� value �����   index ��������
	void remove(int index);//�������� �������� index
	void insertAtBeginning(int value);//������� 1 ��������
	void insertAtEnd(int value);//������� ���������� ��������

private:
	int _length{};
	int* _data{};
};
