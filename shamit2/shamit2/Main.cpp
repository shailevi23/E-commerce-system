#include "Manager.h"

/*
Shai Levi - 204124234
*/

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


int main()
{
	string nameFile = "users.txt";
	Manager m(nameFile);
	m.run();
}
