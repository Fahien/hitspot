#include "test.h"

using namespace hitspot;

int main()
{
	CollisionSystem cs;

	BoundingBox a;
	BoundingBox b;
	a.width = a.height = b.width = b.height = 1.0f;

	cs.AddBox(&a);
	cs.AddBox(&b);

	cs.Update();

	assert(a.IsCollidingWith(&b));

	b.x = 1.0f;
	cs.Update();
	assert(!a.IsCollidingWith(&b));

	return EXIT_SUCCESS;
}
