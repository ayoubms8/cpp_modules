#pragma once
#include <cstddef>
#include <exception>

template <typename T>
class Array
{
private:
	T *data;
	unsigned int _n;
public:
	Array();
	Array(unsigned int n);
	Array(Array const &copy);
	Array	&operator=(Array const &copy);
	T		&operator[](unsigned int n);
	int		size();
	~Array();
};

template <typename T>
Array<T>::Array()
{
	this->data = NULL;
	_n = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	data = new T[n];
	_n = n;
}

template <typename T>
Array<T>::Array(Array const &copy)
{
	*this = copy;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &copy)
{
	if (this != &copy)
	{
		if (data)
			delete [] data;
		data = new T[copy.size()];
		for (int i = 0; i < copy.size(); i++)
			data[i] = copy.data[i];
		_n = copy._n;
	}
}

template <typename T>
T &Array<T>::operator[](unsigned int n)
{
	if (n >= _n)
		throw std::exception();
	return (this->data[n]) ;
}

template <typename T>
int	Array<T>::size()
{
	return _n;
}

template <typename T>
Array<T>::~Array()
{
	if (data)
		delete [] data;
}