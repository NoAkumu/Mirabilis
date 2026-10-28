#pragma once
#include <SFML/Graphics.hpp>

class Vector2 {
    public:
        float x, y;
        Vector2() : x(0), y(0) {};
        Vector2(float x, float y) : x(x), y(y) {};
        Vector2(sf::Vector2f vec) : x(vec.x), y(vec.y) {};
        Vector2(sf::Vector2i vec) : x(vec.x), y(vec.y) {};
        Vector2(sf::Vector2u vec) : x(vec.x), y(vec.y) {};
        
        operator sf::Vector2f() const {
            return sf::Vector2f({x,y});
        }
        operator sf::Vector2i() const {
            return sf::Vector2i({x,y});
        }
        operator sf::Vector2u() const {
            return sf::Vector2u({x,y});
        }
        Vector2 operator+(const Vector2 &v2) const {
            return Vector2(x+v2.x, y+v2.y);
        }
        Vector2& operator+=(const Vector2 &v2) {
            x += v2.x;
            y += v2.y;
            return *this;
        }
        Vector2 operator-(const Vector2 &v2) const {
            return Vector2(x-v2.x, y-v2.y);
        }
        Vector2& operator-=(const Vector2 &v2) {
            x -= v2.x;
            y -= v2.y;
            return *this;
        }
        Vector2 operator*(float Scalar) const {
            return Vector2(x* Scalar, y*Scalar);
        }
        Vector2 operator*(Vector2 Scalar) const {
            return Vector2(x* Scalar.x, y*Scalar.y);
        }
        Vector2& operator*=(float Scalar) {
            x *= Scalar;
            y *= Scalar;
            return *this;
        }
        Vector2 operator/(float Scalar) const {
            return Vector2(x/Scalar, y/Scalar);
        }
        bool operator!=(const Vector2 &v2) const {
            return x != v2.x || y != v2.y;
        }
        float dot(const Vector2& vec) const {
            return x * vec.x + y * vec.y;
        }
        float length() const {
            return std::sqrt(std::pow(x,2)+std::pow(y,2));
        }
        Vector2 normalized() const {
            return length() ? Vector2(x,y)/length() : Vector2();
        }
};