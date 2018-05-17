#include "handle_1.h"

int main(int argc, char* argv[])
{
	Handle_1 h1(3,4);
	Handle_1 h2(h1);
	h2.SetX(5);
	int dd = h1.GetX();

	return 0;
}

