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

void collisionPlaneWrite(CollisionPlane* plane, int x, int y, int id) {
    if (x < 0 || y < 0 || x >= plane->size.x || y >= plane->size.y)
        return;
    int index = plane->size.x * y + x;
    plane->plane[index] = id;
}

int collisionPlaneRead(CollisionPlane* plane, int x, int y) {
    if (x < 0 || y < 0 || x >= plane->size.x || y >= plane->size.y)
        return -1;
    int index = plane->size.x * y + x;
    return plane->plane[index];
}

CollisionShape* collisionShapeNew(int length, IntVector* coordinates) {
    CollisionShape* shape = calloc(1, sizeof(CollisionShape));
    shape->length = length;
    shape->coordinates = calloc(length, sizeof(IntVector));
    for (int i = 0; i < length; i++) {
        shape->coordinates[i] = coordinates[i];
    }
    return shape;
}
