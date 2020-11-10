#include "collision.h"
#include "datatypes.h"
#include <stdlib.h>

CollisionPlane* collisionPlaneNew(IntVector size) {
    CollisionPlane* plane = calloc(1, sizeof(CollisionPlane));
    plane->size = size;
    plane->plane = calloc(size.x * size.y, sizeof(int));
    return plane;
}

void collisionPlaneClear(CollisionPlane* plane) {
    free(plane->plane);
    plane->plane = calloc(plane->size.x * plane->size.y, sizeof(int));
}
