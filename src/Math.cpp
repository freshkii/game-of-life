#include "Math.h"

namespace gol {

    Vector2::Vector2(double _x, double _y): x(_x), y(_y) {
    }

    Vector2 operator+(Vector2 a, Vector2 b) {
        return Vector2(a.x + b.x, a.y + b.y);
    }

    Vector2 operator-(Vector2 a, Vector2 b) {
        return Vector2(a.x - b.x, a.y - b.y);
    }

    Vector3::Vector3(double _x, double _y, double _z): x(_x), y(_y), z(_z) {}

    Vector3 operator+(Vector3 a, Vector3 b) {
        return Vector3(a.x + b.x, a.y + b.y, a.z + b.z);
    }

    Vector3 operator-(Vector3 a, Vector3 b) {
        return Vector3(a.x - b.x, a.y - b.y, a.z - b.z);
    }
}
