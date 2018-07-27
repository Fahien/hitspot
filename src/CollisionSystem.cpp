#include "hitspot/BoundingBox.h"
#include "hitspot/CollisionSystem.h"

using namespace hitspot;


void CollisionSystem::Update()
{
	for (size_t i{ 0 }; i < mBoxes.size(); ++i)
	{
		BoundingBox* box{ mBoxes[i] };

		for (size_t j{ i + 1 }; j < mBoxes.size(); ++j)
		{
			BoundingBox* otherBox{ mBoxes[j] };
			bool isColliding{ box->IsCollidingWith(otherBox) };

			if (box->Intersects(otherBox))
			{
				if (!isColliding)
				{
					box->AddCollision(otherBox);
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
					box->RemoveCollision(otherBox);
					if (box->endCollidingWith)
					{
						box->endCollidingWith(otherBox);
					}
				}
			}
		}
	}
}
