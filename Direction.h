/**
 * A direction in the plane. As a convenience, directions provide unit vector
 * components (manhattan metric) for both the conventional plane and screen
 * coordinates (y axis reversed).
 * 
 * @author Tom Gibara
 * Ported to C++ by Juha Reunanen
 *
 */

#pragma once

#include <utility>

namespace MarchingSquares {
    struct Direction {
        Direction() : x(0), y(0) {}
        Direction(int x, int y) : x(x), y(y) {}
        int x;
        int y;
    };
    inline
    bool operator== (const Direction& a, const Direction& b) {
        return a.x == b.x && a.y == b.y;
    }
    inline
    Direction operator* (const Direction& direction, int multiplier) {
        return Direction(direction.x * multiplier, direction.y * multiplier);
    }
    inline
    Direction operator+ (const Direction& a, const Direction& b) {
        return Direction(a.x + b.x, a.y + b.y);
    }
    inline
    Direction& operator+= (Direction& a, const Direction& b) {
        a.x += b.x;
        a.y += b.y;
        return a;
    }
    inline
    Direction MakeDirection(int x, int y) { return Direction(x, y); }
    inline
    Direction East()      { return MakeDirection( 1,  0); }
    inline
    Direction Northeast() { return MakeDirection( 1,  1); }
    inline
    Direction North()     { return MakeDirection( 0,  1); }
    inline
    Direction Northwest() { return MakeDirection(-1,  1); }
    inline
    Direction West()      { return MakeDirection(-1,  0); }
    inline
    Direction Southwest() { return MakeDirection(-1, -1); }
    inline
    Direction South()     { return MakeDirection( 0, -1); }
    inline
    Direction Southeast() { return MakeDirection( 1, -1); }
}
