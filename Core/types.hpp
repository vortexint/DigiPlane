#ifndef DIGIPLANE_TYPES_HPP
#define DIGIPLANE_TYPES_HPP

namespace Digiplane {

// ABGRColor_t is a 32-bit unsigned integer that represents a color in the ABGR format.
// The first 8 bits are the alpha channel, the next 8 bits are the blue channel, the next 8 bits are the green channel, and the last 8 bits are the red channel.
typedef struct ABGRColor_t {
    unsigned char r, g, b, a;
} ABGRColor_t;

// Vector3_t
typedef struct Vector3_t {
    float x, y, z;
    Vector3_t operator+(const Vector3_t& other) { return Vector3_t { x + other.x, y + other.y, z + other.z }; }
    Vector3_t& operator+=(const Vector3_t& other) { return *this = *this + other; }
    Vector3_t operator-(const Vector3_t& other) { return Vector3_t { x - other.x, y - other.y, z - other.z }; }
    Vector3_t& operator-=(const Vector3_t& other) { return *this = *this - other; }
} Vector3_t;

typedef struct Quaternion_t {
    float x, y, z, w;
    Quaternion_t operator*(const Quaternion_t& other) {
        return Quaternion_t {
            w * other.x + x * other.w + y * other.z - z * other.y,
            w * other.y + y * other.w + z * other.x - x * other.z,
            w * other.z + z * other.w + x * other.y - y * other.x,
            w * other.w - x * other.x - y * other.y - z * other.z
        };
    }
    Quaternion_t& operator*=(const Quaternion_t& other) { return *this = *this * other; }
} Quaternion_t;

// Position, rotation and scale of an object.
struct Transform {
    Vector3_t position;
    Quaternion_t rotation;
    Vector3_t scale;
};

// Velocity of an object
struct Velocity {
    Vector3_t velocity;
};

}

#endif