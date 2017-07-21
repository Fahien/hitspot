#ifndef HST_COLLISIONSYSTEM_H
#define HST_COLLISIONSYSTEM_H

#include <vector>

namespace hitspot
{

class BoundingBox;

class CollisionSystem
{
public:
	inline void addBox(BoundingBox* box) { mBoxes.push_back(box); }

	void update();

private:
	std::vector<BoundingBox*> mBoxes;
};

}

#endif // HST_COLLISIONSYSTEM_H
