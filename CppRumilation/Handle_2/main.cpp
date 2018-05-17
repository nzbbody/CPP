#include "handle_2.h"

int main(int argc, char* argv[])
{
	Handle_2 h1(3,4);
	Handle_2 h2(h1);
	h2.SetX(5);
	int dd = h1.GetX();

	return 0;
}

