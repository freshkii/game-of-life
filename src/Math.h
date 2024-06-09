#pragma once

namespace gol {
    struct Vector2 {
        double x, y; 
        Vector2(double _x, double _y);
    };
    struct Vector3 {
        double x, y, z;
        Vector3(double _x, double _y, double _z);
    };

    Vector2 operator+(Vector2 a, Vector2 b);
    Vector2 operator-(Vector2 a, Vector2 b);

    Vector3 operator+(Vector3 a, Vector3 b);
    Vector3 operator-(Vector3 a, Vector3 b);
}
