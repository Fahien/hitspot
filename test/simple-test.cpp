#include "CollisionSystem.h"
#include "BoundingBox.h"
#include <cassert>

namespace hsp = hitspot;

int main()
{
	hsp::CollisionSystem cs{};

	hsp::BoundingBox a{};
	hsp::BoundingBox b{};
	a.width = a.height = b.width = b.height = 1.0f;

	cs.addBox(&a);
	cs.addBox(&b);

	cs.update();

	assert(a.isCollidingWith(&b));

	b.x = 1.0f;
	cs.update();
	assert(!a.isCollidingWith(&b));

	return EXIT_SUCCESS;
}
