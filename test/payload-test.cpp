#include "test.h"


class Foo
{
public:
	Foo() : test{ false } {}

	inline void bar() { std::cout << "Bar\n"; }

	bool test;
};


int main()
{
	hsp::CollisionSystem cs{};

	Foo payload;

	hsp::BoundingBox a{ &payload };
	a.startCollidingWith = [&a](hsp::BoundingBox* other)
	{
		Foo* p{ static_cast<Foo*>(a.getPayload()) };
		p->bar();
		p->test = true;
	};

	hsp::BoundingBox b{};
	a.width = a.height = b.width = b.height = 1.0f;

	cs.addBox(&a);
	cs.addBox(&b);

	cs.update();

	assert(a.isCollidingWith(&b));
	assert(payload.test);

	return EXIT_SUCCESS;
}
