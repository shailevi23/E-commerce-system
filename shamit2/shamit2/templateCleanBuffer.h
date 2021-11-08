#ifndef __TCB_H
#define __TCB_H

#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)

template<class T>
class CleanBuffer
{
private:

public:
	void cleanBuffer();

};

template<class T>
inline void CleanBuffer<T>::cleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}


#endif 
