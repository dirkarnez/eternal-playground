#include "mapbox/eternal.hpp"
#include <string>
#include <map>
#include <unordered_map>
#include <limits>

struct Color {
    constexpr inline Color() {
    }
    constexpr inline Color(unsigned char r_, unsigned char g_, unsigned char b_, float a_)
        : r(r_), g(g_), b(b_), a(a_ > 1 ? 1 : a_ < 0 ? 0 : a_) {
    }
    unsigned char r = 0, g = 0, b = 0;
    float a = 1.0f;

    constexpr bool operator==(const Color& rhs) const {
        return r == rhs.r && g == rhs.g && b == rhs.b &&
               (a >= rhs.a ? a - rhs.a : rhs.a - a) < std::numeric_limits<float>::epsilon();
    }
};

MAPBOX_ETERNAL_CONSTEXPR const auto colors = mapbox::eternal::map<mapbox::eternal::string, Color>({
    { "green", { 0, 128, 0, 1 } },
    { "yellow", { 255, 255, 0, 1 } }
});

#include <iostream>

int main() {
    static_assert(colors.find("green")->second == Color(0, 128, 0, 1));
    return 0;
}