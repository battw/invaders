#ifndef INCLUDED_COLLISION
#define INCLUDED_COLLISION

#include "datatypes.h"


CollisionPlane* collisionPlaneNew(IntVector size);

void collisionPlaneClear(CollisionPlane* plane);

#endif // INCLUDED_COLLISION
