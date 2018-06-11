#include "hitspot/BoundingBox.h"

using namespace hitspot;


BoundingBox::BoundingBox()
	: mPayload{ nullptr }
	, mCollisions{}
{}


BoundingBox::BoundingBox(void* payload)
	: mPayload{ payload }
	, mCollisions{}
{}


bool BoundingBox::IsCollidingWith(const BoundingBox* box) const
{
	for (const BoundingBox* b : mCollisions)
	{
		if (box == b)
		{
			return true;
		}
	}
	return false;
}


void BoundingBox::AddCollision(const BoundingBox* box)
{
	mCollisions.push_back(box);
}


void BoundingBox::RemoveCollision(const BoundingBox* box)
{
	for (size_t i{ 0 }; i < mCollisions.size(); ++i)
	{
		if (mCollisions[i] == box)
		{
			mCollisions.erase(mCollisions.begin() + i);
			return;
		}
	}
}
