#ifndef HST_BOUNDINGBOX_H
#define HST_BOUNDINGBOX_H

#include <vector>
#include <functional>
#include "MathSpot.h"

namespace mst = mathspot;


namespace hitspot
{

class BoundingBox : public mst::Rectangle
{
public:
	BoundingBox();

	/// Returns the current collisions
	const std::vector<const BoundingBox*>& getCollisions() const { return mCollisions; }

	/// Adds a Box to the collision list
	void addCollision(const BoundingBox*);

	/// Removes a Box from the collision list
	void removeCollision(const BoundingBox*);

	/// Tests whether a Box is in the collisions list
	bool isCollidingWith(const BoundingBox* box) const;

	std::function<void(BoundingBox* box)> startCollidingWith;
	std::function<void(BoundingBox* box)> collidingWith;
	std::function<void(BoundingBox* box)> endCollidingWith;

private:
	std::vector<const BoundingBox*> mCollisions;
};

}

#endif // HST_BOUNDINGBOX_H
