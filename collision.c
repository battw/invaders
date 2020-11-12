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

int collisionPlaneCheck(CollisionPlane* plane, CollisionShape* shape, IntVector position) {
    int collisionId = -1;
    for (int i = 0; i < shape->length; ++i) {
        IntVector readPosition = {position.x + shape->coordinates[i].x, position.y + shape->coordinates[i].y};
        collisionId = collisionPlaneRead(plane, readPosition);
        if (collisionId >= 0) break;
    }
    return collisionId;
}

void collisionPlaneWrite(CollisionPlane* plane, IntVector position, int id) {
    if (position.x < 0 || position.y < 0 || position.x >= plane->size.x || position.y >= plane->size.y)
        return;
    int index = plane->size.x * position.y + position.x;
    plane->plane[index] = id + 1;
}

void collisionPlaneDraw(CollisionPlane* plane, CollisionShape* shape, IntVector position, int id) {
    for (int i = 0; i < shape->length; i++) {
        IntVector writePosition = {position.x + shape->coordinates[i].x, position.y + shape->coordinates[i].y};
        collisionPlaneWrite(plane, writePosition, id);
    }
}

/** Returns the id of the collision shape at the given position. */
int collisionPlaneRead(CollisionPlane* plane, IntVector position) {
    if (position.x < 0 || position.y < 0 || position.x >= plane->size.x || position.y >= plane->size.y)
        return -1;
    int index = plane->size.x * position.y + position.x;
    return plane->plane[index] - 1;
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
