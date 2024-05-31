#pragma once

template <typename T>
void	Iter(T *arr, int len, void (*f) (T &))
{
	for (int i = 0; i < len; i++)
	{
		f(arr[i]);
	}
}