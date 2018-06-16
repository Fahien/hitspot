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
			BoundingBox* other{ mBoxes[j] };
			bool isColliding{ box->IsCollidingWith(other) };

			if (box->intersects(other))
			{
				if (!isColliding)
				{
					box->AddCollision(other);
					other->AddCollision(box);
					if (box->fStartCollidingWith)
					{
						box->fStartCollidingWith(other);
					}
					if (other->fStartCollidingWith)
					{
						other->fStartCollidingWith(box);
					}
				}

				if (box->fCollidingWith)
				{
					box->fCollidingWith(other);
				}
				if (other->fCollidingWith)
				{
					other->fCollidingWith(box);
				}
			}
			else
			{
				if (isColliding)
				{
					box->RemoveCollision(other);
					other->RemoveCollision(box);
					if (box->fEndCollidingWith)
					{
						box->fEndCollidingWith(other);
					}
					if (other->fEndCollidingWith)
					{
						other->fEndCollidingWith(box);
					}
				}
			}
		}
	}
}
