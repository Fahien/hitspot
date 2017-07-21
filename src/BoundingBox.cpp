#include "BoundingBox.h"

namespace hst = hitspot;


hst::BoundingBox::BoundingBox()
	: mCollisions{}
{}


bool hst::BoundingBox::isCollidingWith(const hst::BoundingBox* box) const
{
	for (const hst::BoundingBox* b : mCollisions)
	{
		if (box == b)
		{
			return true;
		}
	}
	return false;
}


void hst::BoundingBox::addCollision(const hst::BoundingBox* box)
{
	mCollisions.push_back(box);
}


void hst::BoundingBox::removeCollision(const hst::BoundingBox* box)
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
