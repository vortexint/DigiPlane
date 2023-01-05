#pragma once

namespace Digiplane {

// ABGRColor_t is a 32-bit unsigned integer that represents a color in the ABGR format.
// The first 8 bits are the alpha channel, the next 8 bits are the blue channel, the next 8 bits are the green channel, and the last 8 bits are the red channel.
typedef struct ABGRColor_t {
    unsigned char r, g, b, a;
} ABGRColor_t;

}
