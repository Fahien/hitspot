#ifndef HST_COLLISIONSYSTEM_H_
#define HST_COLLISIONSYSTEM_H_

#include <vector>

namespace hitspot
{

class BoundingBox;

class CollisionSystem
{
public:
	/// Adds a BoundingBox to the system
	void AddBox(BoundingBox* box) { mBoxes.push_back(box); }

	/// Updates the system
	void Update();

private:
	std::vector<BoundingBox*> mBoxes;
};

}

#endif // HST_COLLISIONSYSTEM_H_
