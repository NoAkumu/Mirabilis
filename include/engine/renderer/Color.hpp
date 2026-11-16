#pragma once
#include <cstdint>

// Renderer color class
class Color
{
    
public:
    uint8_t r, g, b;
    uint8_t a = 0xFF;
    /* 
    r: Red 
    g: Green
    b: Blue
    a: Alpha (optional, default = 255)
    */
    Color(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0, uint8_t a = 0xFF) : r(r), g(g), b(b), a(a) {};
    // hex: Hexadecimal code for color
    Color(uint32_t hex) :
        r(hex >> 24 & 0xFF),
        g(hex >> 16 & 0xFF),
        b(hex >> 8 & 0xFF),
        a(hex & 0xFF)
    {};

    operator sf::Color() const{
        return sf::Color(r,g,b,a);
    }
    ~Color() = default;
    
    static const Color Black;
    static const Color White;
    static const Color Red;
    static const Color Green;
    static const Color Blue;
};

inline const Color Color::Black = Color();
inline const Color Color::White = Color(0xFF,0xFF,0xFF);
inline const Color Color::Red = Color(0xFF, 0,0);
inline const Color Color::Green = Color(0, 0xFF,0);
inline const Color Color::Blue = Color(0, 0, 0xFF);