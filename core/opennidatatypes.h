#ifndef SENSORDATATYPES_H
#define SENSORDATATYPES_H

#include "stdint.h"

typedef uint16_t DepthPixel;

typedef struct
{
	/* Red value of this pixel. */
	uint8_t r;
	/* Green value of this pixel. */
	uint8_t g;
	/* Blue value of this pixel. */
	uint8_t b;
} ColorPixel;

typedef struct
{
	// Width of frame
	uint16_t width;
	// Height of frame
	uint16_t height;
} FrameInfo;

#endif