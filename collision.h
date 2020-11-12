#ifndef COLLISION_INCLUDED
#define COLLISION_INCLUDED

#include "datatypes.h"

CollisionPlane* collisionPlaneNew(IntVector size);
void collisionPlaneClear(CollisionPlane* plane);
int collisionPlaneCheck(CollisionPlane* plane, CollisionShape* shape, IntVector position);
void collisionPlaneWrite(CollisionPlane* plane, IntVector position, int id);
void collisionPlaneDraw(CollisionPlane* plane, CollisionShape* shape, IntVector position, int id);
int collisionPlaneRead(CollisionPlane* plane, IntVector position);

CollisionShape* collisionShapeNew(int length, IntVector* coordinates);

#endif // COLLISION_INCLUDED
