#ifndef COLLISION_INCLUDED
#define COLLISION_INCLUDED

#include "datatypes.h"

CollisionPlane* collisionPlaneNew(IntVector size);
void collisionPlaneClear(CollisionPlane* plane);
void collisionPlaneWrite(CollisionPlane* plane, int x, int y, int id);
int collisionPlaneRead(CollisionPlane* plane, int x, int y);

CollisionShape* collisionShapeNew(int length, IntVector* coordinates);

#endif // COLLISION_INCLUDED
