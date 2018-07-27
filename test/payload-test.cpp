#include "test.h"

using namespace hitspot;

class Foo
{
public:
	Foo() : test{ false } {}

	inline void bar() { std::cout << "Bar\n"; }

	bool test;
};


int main()
{
	CollisionSystem cs;

	Foo payload;

	BoundingBox a{ &payload };
	a.fStartCollidingWith = [&a](BoundingBox* other)
	{
		Foo* p{ reinterpret_cast<Foo*>(a.GetPayload()) };
		p->bar();
		p->test = true;
	};

	BoundingBox b;
	a.width = a.height = b.width = b.height = 1.0f;

	cs.AddBox(&a);
	cs.AddBox(&b);

	cs.Update();

	assert(a.IsCollidingWith(&b));
	assert(payload.test);

	return EXIT_SUCCESS;
}
