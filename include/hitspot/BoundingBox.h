#ifndef HST_BOUNDINGBOX_H_
#define HST_BOUNDINGBOX_H_

#include <vector>
#include <functional>
#include "mathspot/Math.h"

namespace mst = mathspot;


namespace hitspot
{

class BoundingBox : public mst::Rectangle
{
public:
	BoundingBox();
	BoundingBox(void* payload);

	/// Returns the payload
	void* GetPayload() { return mPayload; }

	/// Sets the payload
	void SetPayload(void* payload) { mPayload = payload; }

	/// Returns the current collisions
	const std::vector<const BoundingBox*>& GetCollisions() const { return mCollisions; }

	/// Adds a Box to the collision list
	void AddCollision(const BoundingBox*);

	/// Removes a Box from the collision list
	void RemoveCollision(const BoundingBox*);

	/// Tests whether a Box is in the collisions list
	bool IsCollidingWith(const BoundingBox* box) const;

	std::function<void(BoundingBox* box)> fStartCollidingWith;
	std::function<void(BoundingBox* box)> fCollidingWith;
	std::function<void(BoundingBox* box)> fEndCollidingWith;

private:
	void* mPayload;
	std::vector<const BoundingBox*> mCollisions;
};

}

#endif // HST_BOUNDINGBOX_H_
