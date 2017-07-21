#include "CollisionSystem.h"
#include "BoundingBox.h"

namespace hst = hitspot;


void hst::CollisionSystem::update()
{
	for (size_t i{ 0 }; i < mBoxes.size(); ++i)
	{
		hst::BoundingBox* box{ mBoxes[i] };

		for (size_t j{ i + 1 }; j < mBoxes.size(); ++j)
		{
			hst::BoundingBox* otherBox{ mBoxes[j] };
			bool isColliding{ box->isCollidingWith(otherBox) };

			if (box->intersects(otherBox))
			{
				if (!isColliding)
				{
					box->addCollision(otherBox);
					if (box->startCollidingWith)
					{
						box->startCollidingWith(otherBox);
					}
				}
				if (box->collidingWith)
				{
					box->collidingWith(otherBox);
				}
			}
			else
			{
				if (isColliding)
				{
					box->removeCollision(otherBox);
					if (box->endCollidingWith)
					{
						box->endCollidingWith(otherBox);
					}
				}
			}
		}
	}
}
