#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "gba.h"
#include "font.h"

// A blank tile.
const uint8_t blank_tile[64] = {
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
};

const uint8_t plane_1[64] = {
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 5, 5, 5,
	0, 0, 0, 0, 0, 0, 0, 5,
	5, 5, 5, 5, 5, 5, 5, 5,
	0, 5, 5, 5, 5, 5, 5, 4,
	0, 0, 0, 0, 0, 5, 5, 5,
};

const uint8_t plane_2[64] = {
	0, 0, 0, 0, 0, 5, 5, 5,
	0, 0, 0, 0, 0, 0, 0, 5,
	0, 0, 0, 0, 0, 0, 5, 5,
	5, 5, 5, 0, 0, 0, 5, 5,
	0, 0, 0, 0, 0, 0, 5, 5,
	5, 5, 5, 5, 5, 5, 5, 5,
	4, 5, 5, 5, 5, 5, 5, 5,
	5, 5, 5, 5, 5, 5, 5, 5,
}; 

const uint8_t plane_3[64] = {
	5, 5, 5, 0, 0, 0, 0, 0,
	5, 0, 0, 0, 0, 0, 0, 0,
	5, 5, 0, 0, 0, 0, 0, 0,
	5, 5, 0, 0, 0, 5, 5, 5,
	5, 5, 0, 0, 0, 0, 0, 0,
	5, 5, 5, 5, 5, 5, 5, 5,
	5, 5, 5, 5, 5, 5, 5, 4,
	5, 5, 5, 5, 5, 5, 5, 5,
}; 

const uint8_t plane_4[64] = {
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	5, 5, 5, 0, 0, 0, 0, 0,
	5, 0, 0, 0, 0, 0, 0, 0,
	5, 5, 5, 5, 5, 5, 5, 5,
	4, 5, 5, 5, 5, 5, 5, 0,
	5, 5, 5, 0, 0, 0, 0, 0,
}; 

const uint8_t plane_5[64] = {
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
}; 

const uint8_t plane_6[64] = {
	5, 5, 5, 5, 5, 5, 5, 5,
	0, 0, 0, 0, 0, 0, 5, 5,
	0, 0, 0, 0, 0, 0, 5, 5,
	0, 0, 0, 0, 0, 0, 0, 5,
	0, 0, 0, 0, 0, 0, 0, 5,
	0, 0, 0, 0, 0, 0, 0, 5,
	0, 0, 0, 0, 0, 0, 5, 5,
	0, 0, 0, 0, 0, 5, 5, 5,
}; 

const uint8_t plane_7[64] = {
	5, 5, 5, 5, 5, 5, 5, 5,
	5, 5, 0, 0, 0, 0, 0, 0,
	5, 5, 0, 0, 0, 0, 0, 0,
	5, 0, 0, 0, 0, 0, 0, 0,
	5, 0, 0, 0, 0, 0, 0, 0,
	5, 0, 0, 0, 0, 0, 0, 0,
	5, 5, 0, 0, 0, 0, 0, 0,
	5, 5, 5, 0, 0, 0, 0, 0,
}; 

const uint8_t plane_8[64] = {
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
}; 

// ---------------------------------------------------- END OF PLAYER --------------------------------------------------------

// ------------------------------------------------------- Enemy 1 ---------------------------------------------------------------
const uint8_t enemy1_1[64] = {
	0, 0, 0, 0, 7, 7, 7, 7,
	0, 0, 0, 0, 0, 0, 7, 7,
	0, 0, 0, 0, 0, 0, 0, 7,
	0, 0, 0, 0, 0, 0, 0, 7,
	0, 0, 0, 0, 0, 0, 7, 7,
	0, 0, 0, 0, 0, 0, 7, 7,
	0, 0, 0, 0, 0, 0, 7, 7,
	0, 0, 0, 0, 7, 7, 7, 7,
}; 

const uint8_t enemy1_2[64] = {
	7, 7, 7, 7, 0, 0, 0, 0,
	7, 7, 0, 0, 0, 0, 0, 0,
	7, 0, 0, 0, 0, 0, 0, 0,
	7, 0, 0, 0, 0, 0, 0, 0,
	7, 7, 0, 0, 0, 0, 0, 0,
	7, 7, 0, 0, 0, 0, 0, 0,
	7, 7, 0, 0, 0, 0, 0, 0,
	7, 7, 7, 7, 0, 0, 0, 0,
}; 

const uint8_t enemy1_3[64] = {
	0, 0, 0, 0, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7,
	0, 0, 0, 0, 0, 0, 7, 7,
	0, 0, 0, 0, 0, 0, 7, 7,
	0, 0, 0, 0, 0, 0, 0, 7,
	0, 0, 0, 0, 0, 7, 7, 7,
	0, 0, 0, 0, 0, 0, 0, 7,
}; 

const uint8_t enemy1_4[64] = {
	7, 7, 7, 7, 0, 0, 0, 0,
	7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 0, 0, 0, 0, 0, 0,
	7, 7, 0, 0, 0, 0, 0, 0,
	7, 0, 0, 0, 0, 0, 0, 0,
	7, 7, 7, 0, 0, 0, 0, 0,
	7, 0, 0, 0, 0, 0, 0, 0,
}; 

// ----------------------------------------------------------------------- Enemy 2 ----------------------------------------------
const uint8_t enemy1_5[64] = {
	0, 0, 0, 8, 8, 8, 8, 8,
	0, 0, 0, 8, 8, 8, 8, 8,
	0, 0, 0, 0, 0, 0, 8, 8,
	0, 0, 0, 0, 0, 0, 8, 8,
	0, 0, 0, 0, 0, 0, 8, 8,
	0, 0, 0, 0, 0, 0, 8, 8,
	0, 0, 0, 0, 0, 0, 8, 8,
	8, 8, 8, 8, 8, 8, 8, 8,
}; 

const uint8_t enemy1_6[64] = {
	8, 8, 8, 8, 8, 0, 0, 0,
	8, 8, 8, 8, 8, 0, 0, 0,
	8, 8, 0, 0, 0, 0, 0, 0,
	8, 8, 0, 0, 0, 0, 0, 0,
	8, 8, 0, 0, 0, 0, 0, 0,
	8, 8, 0, 0, 0, 0, 0, 0,
	8, 8, 0, 0, 0, 0, 0, 0,
	8, 8, 8, 8, 8, 8, 8, 8,
}; 

const uint8_t enemy1_7[64] = {
	8, 8, 8, 8, 8, 8, 8, 8,
	8, 8, 8, 8, 8, 8, 8, 8,
	8, 8, 8, 8, 8, 8, 8, 8,
	8, 8, 8, 8, 8, 8, 8, 8,
	8, 0, 0, 0, 0, 8, 8, 8,
	0, 0, 0, 0, 0, 8, 8, 8,
	0, 0, 0, 0, 0, 0, 0, 8,
	0, 0, 0, 0, 0, 8, 8, 8,
}; 

const uint8_t enemy1_8[64] = {
	8, 8, 8, 8, 8, 8, 8, 8,
	8, 8, 8, 8, 8, 8, 8, 8,
	8, 8, 8, 8, 8, 8, 8, 8,
	8, 8, 8, 8, 8, 8, 8, 8,
	8, 8, 8, 0, 0, 0, 0, 8,
	8, 8, 8, 0, 0, 0, 0, 0,
	8, 0, 0, 0, 0, 0, 0, 0,
	8, 8, 8, 0, 0, 0, 0, 0,
}; 

// --------------------------------------------------------------------- Enemy 3 ------------------------------------------------
const uint8_t enemy1_9[64] = {
	0, 0, 0, 0, 3, 3, 3, 3,
	0, 0, 0, 0, 0, 0, 3, 3,
	0, 0, 0, 0, 0, 0, 0, 3,
	0, 0, 0, 0, 0, 0, 0, 3,
	0, 0, 0, 0, 0, 0, 3, 3,
	0, 0, 0, 0, 0, 0, 3, 3,
	0, 0, 0, 0, 0, 0, 3, 3,
	0, 0, 0, 0, 3, 3, 3, 3,
}; 

const uint8_t enemy1_10[64] = {
	3, 3, 3, 3, 0, 0, 0, 0,
	3, 3, 0, 0, 0, 0, 0, 0,
	3, 0, 0, 0, 0, 0, 0, 0,
	3, 0, 0, 0, 0, 0, 0, 0,
	3, 3, 0, 0, 0, 0, 0, 0,
	3, 3, 0, 0, 0, 0, 0, 0,
	3, 3, 0, 0, 0, 0, 0, 0,
	3, 3, 3, 3, 0, 0, 0, 0,
}; 

const uint8_t enemy1_11[64] = {
	0, 0, 0, 0, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	0, 0, 3, 3, 0, 0, 3, 3,
	0, 3, 3, 3, 3, 0, 3, 3,
	0, 0, 0, 0, 0, 0, 0, 3,
	0, 0, 0, 0, 0, 3, 3, 3,
	0, 0, 0, 0, 0, 0, 0, 3,
}; 

const uint8_t enemy1_12[64] = {
	3, 3, 3, 3, 0, 0, 0, 0,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 0, 0, 3, 3, 0, 0,
	3, 3, 0, 3, 3, 3, 3, 0,
	3, 0, 0, 0, 0, 0, 0, 0,
	3, 3, 3, 0, 0, 0, 0, 0,
	3, 0, 0, 0, 0, 0, 0, 0,
}; 

//  -------------------------------------------------------------------------- Enemy 4 -------------------------------------------
const uint8_t enemy1_13[64] = {
	0, 0, 0, 5, 5, 5, 5, 5,
	0, 0, 0, 5, 5, 5, 5, 5,
	0, 0, 0, 0, 0, 0, 5, 5,
	0, 0, 0, 0, 0, 0, 5, 5,
	0, 0, 0, 0, 0, 0, 5, 5,
	0, 0, 0, 0, 0, 0, 5, 5,
	0, 0, 0, 0, 0, 0, 5, 5,
	5, 5, 5, 5, 5, 5, 5, 5,
}; 

const uint8_t enemy1_14[64] = {
	5, 5, 5, 5, 5, 0, 0, 0,
	5, 5, 5, 5, 5, 0, 0, 0,
	5, 5, 0, 0, 0, 0, 0, 0,
	5, 5, 0, 0, 0, 0, 0, 0,
	5, 5, 0, 0, 0, 0, 0, 0,
	5, 5, 0, 0, 0, 0, 0, 0,
	5, 5, 0, 0, 0, 0, 0, 0,
	5, 5, 5, 5, 5, 5, 5, 5,
}; 

const uint8_t enemy1_15[64] = {
	5, 5, 5, 5, 5, 5, 5, 5,
	5, 5, 5, 5, 5, 5, 5, 5,
	5, 5, 5, 5, 5, 5, 5, 5,
	5, 5, 5, 5, 5, 5, 5, 5,
	5, 0, 0, 0, 0, 5, 5, 5,
	0, 0, 0, 0, 0, 5, 5, 5,
	0, 0, 0, 0, 0, 0, 0, 5,
	0, 0, 0, 0, 0, 5, 5, 5,
}; 

const uint8_t enemy1_16[64] = {
	5, 5, 5, 5, 5, 5, 5, 5,
	5, 5, 5, 5, 5, 5, 5, 5,
	5, 5, 5, 5, 5, 5, 5, 5,
	5, 5, 5, 5, 5, 5, 5, 5,
	5, 5, 5, 0, 0, 0, 0, 5,
	5, 5, 5, 0, 0, 0, 0, 0,
	5, 0, 0, 0, 0, 0, 0, 0,
	5, 5, 5, 0, 0, 0, 0, 0,
}; 

//  -------------------------------------------------------------------------- Enemy 5 -------------------------------------------
const uint8_t enemy1_17[64] = {
	0, 0, 0, 0, 6, 6, 6, 6,
	0, 0, 0, 0, 0, 0, 6, 6,
	0, 0, 0, 0, 0, 0, 0, 6,
	0, 0, 0, 0, 0, 0, 0, 6,
	0, 0, 0, 0, 0, 0, 6, 6,
	0, 0, 0, 0, 0, 0, 6, 6,
	0, 0, 0, 0, 0, 0, 6, 6,
	0, 0, 0, 0, 6, 6, 6, 6,
}; 

const uint8_t enemy1_18[64] = {
	6, 6, 6, 6, 0, 0, 0, 0,
	6, 6, 0, 0, 0, 0, 0, 0,
	6, 0, 0, 0, 0, 0, 0, 0,
	6, 0, 0, 0, 0, 0, 0, 0,
	6, 6, 0, 0, 0, 0, 0, 0,
	6, 6, 0, 0, 0, 0, 0, 0,
	6, 6, 0, 0, 0, 0, 0, 0,
	6, 6, 6, 6, 0, 0, 0, 0,
}; 

const uint8_t enemy1_19[64] = {
	0, 0, 0, 0, 6, 6, 6, 6,
	6, 6, 6, 6, 6, 6, 6, 6,
	6, 6, 6, 6, 6, 6, 6, 6,
	0, 0, 0, 0, 0, 0, 6, 6,
	0, 0, 0, 0, 0, 0, 6, 6,
	0, 0, 0, 0, 0, 0, 0, 6,
	0, 0, 0, 0, 0, 6, 6, 6,
	0, 0, 0, 0, 0, 0, 0, 6,
}; 

const uint8_t enemy1_20[64] = {
	6, 6, 6, 6, 0, 0, 0, 0,
	6, 6, 6, 6, 6, 6, 6, 6,
	6, 6, 6, 6, 6, 6, 6, 6,
	6, 6, 0, 0, 0, 0, 0, 0,
	6, 6, 0, 0, 0, 0, 0, 0,
	6, 0, 0, 0, 0, 0, 0, 0,
	6, 6, 6, 0, 0, 0, 0, 0,
	6, 0, 0, 0, 0, 0, 0, 0,
}; 

// ------------------------------------------------------------END OF ENEMIES--------------------------------------------

const uint8_t test_full_tile[64] = {
	5, 5, 5, 5, 5, 5, 5, 5,
	5, 5, 5, 5, 5, 5, 5, 5,
	5, 5, 5, 5, 5, 5, 5, 5,
	5, 5, 5, 5, 5, 5, 5, 5,
	5, 5, 5, 5, 5, 5, 5, 5,
	5, 5, 5, 5, 5, 5, 5, 5,
	5, 5, 5, 5, 5, 5, 5, 5,
	5, 5, 5, 5, 5, 5, 5, 5,
};

const uint8_t bullet_tile[64] = {
	3, 0, 0, 0, 0, 0, 0, 0,
	3, 0, 0, 0, 0, 0, 0, 0,
	3, 0, 0, 0, 0, 0, 0, 0,
	3, 0, 0, 0, 0, 0, 0, 0,
	3, 0, 0, 0, 0, 0, 0, 0,
	3, 0, 0, 0, 0, 0, 0, 0,
	3, 0, 0, 0, 0, 0, 0, 0,
	3, 0, 0, 0, 0, 0, 0, 0,
};


const uint8_t sky_tile[64] = {
	2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2,
};

// A little fluffy cloud.
const uint8_t cloud_tile[64] = {
	2, 3, 2, 3, 2, 3, 2, 3,
	3, 2, 3, 2, 3, 2, 3, 2,
	2, 3, 2, 3, 2, 3, 2, 3,
	3, 2, 3, 2, 3, 2, 3, 2,
	2, 3, 2, 3, 2, 3, 2, 3,
	3, 2, 3, 2, 3, 2, 3, 2,
	2, 3, 2, 3, 2, 3, 2, 3,
	3, 2, 3, 2, 3, 2, 3, 2,
};

// function prototypes
void DrawText(bool bold, int x, int y, const char string[]); 
void InstructionsMenu();
void GameOver();
void Win();

class Enemy
{
	public:
		int x_pos;
		int y_pos;
		int object_number;
		int tile_id;
		bool visible;


		// Functions
		void Initialise()
		{
			SetObject(object_number,
					  ATTR0_SHAPE(0) | ATTR0_8BPP | ATTR0_REG | ATTR0_Y(y_pos),
					  ATTR1_SIZE(1) | ATTR1_X(x_pos),
					  ATTR2_ID8(tile_id));
			visible = true;
		}
		
		void Kill()
		{
			SetObject(object_number,
					  ATTR0_SHAPE(0) | ATTR0_8BPP | ATTR0_REG | ATTR0_Y(y_pos) | ATTR0_HIDE,
					  ATTR1_SIZE(1) | ATTR1_X(x_pos),
					  ATTR2_ID8(tile_id));
			visible = false;
		}
}; 

class Player
{
	public:
		int x_pos;
		int y_pos;

		// Functions
		void Initialise()
		{
			SetObject(0,
					  ATTR0_SHAPE(1) | ATTR0_8BPP | ATTR0_REG | ATTR0_Y(y_pos),
					  ATTR1_SIZE(2) | ATTR1_X(x_pos),
					  ATTR2_ID8(1));			
		}
		
		void Kill()
		{
			SetObject(0,
					  ATTR0_SHAPE(1) | ATTR0_8BPP | ATTR0_REG | ATTR0_Y(y_pos) | ATTR0_HIDE,
					  ATTR1_SIZE(2) | ATTR1_X(x_pos),
					  ATTR2_ID8(1));
		}
}; 

class Bullet
{
	public:
		int x_pos;
		int y_pos;
		bool visible;
		bool engaged;

		// Functions
		void Initialise()
		{
			SetObject(1,
					  ATTR0_SHAPE(0) | ATTR0_8BPP | ATTR0_REG | ATTR0_Y(y_pos),
					  ATTR1_SIZE(0) | ATTR1_X(x_pos),
					  ATTR2_ID8(10));	
			visible = true;
		}
		
		void Hide()
		{
			SetObject(1,
					  ATTR0_SHAPE(0) | ATTR0_8BPP | ATTR0_REG | ATTR0_Y(y_pos) | ATTR0_HIDE,
					  ATTR1_SIZE(0) | ATTR1_X(x_pos),
					  ATTR2_ID8(10));
			visible = false;
		}
}; 

int main()
{	
	// Set display options.
	// DCNT_MODE0 sets mode 0, which provides four tiled backgrounds.
	// DCNT_OBJ enables objects.
	// DCNT_OBJ_1D make object tiles mapped in 1D (which makes life easier).
	REG_DISPCNT = DCNT_MODE0 | DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ | DCNT_OBJ_1D;
	
	// Set background 0 options. (closest)
	REG_BG0CNT = BG_CBB(3) | BG_SBB(31) | BG_8BPP | BG_REG_32x32;
	REG_BG0HOFS = 0;
	REG_BG0VOFS = 0;
	
	// Set background 1 options.
	REG_BG1CNT = BG_CBB(2) | BG_SBB(30) | BG_8BPP | BG_REG_32x32;
	REG_BG1HOFS = 0;
	REG_BG1VOFS = 0;
	
	// Set background 2 options.
	REG_BG2CNT = BG_CBB(1) | BG_SBB(29) | BG_8BPP | BG_REG_32x32;
	REG_BG2HOFS = 0;
	REG_BG2VOFS = 0;
	
	// Set background 3 options. (fartest)
	REG_BG3CNT = BG_CBB(0) | BG_SBB(28) | BG_8BPP | BG_REG_32x32;
	REG_BG3HOFS = 0;
	REG_BG3VOFS = 0;
	
	// Set up the palette.
	SetPaletteBG(0, RGB(0, 0, 0)); // black
	SetPaletteBG(1, RGB(31, 31, 31)); // white
	SetPaletteBG(2, RGB(20, 20, 31)); // pale blue (sky)
	SetPaletteBG(3, RGB(25, 25, 25)); // grey (cloud)
	SetPaletteBG(4, RGB(20, 10, 0)); // brown (brick)
	SetPaletteBG(5, RGB(0, 0, 0)); // black
	
	// Set up the object palette.
	SetPaletteObj(0, RGB(0, 0, 0)); // black (but actually transparent)
	SetPaletteObj(1, RGB(0, 0, 0)); // black
	SetPaletteObj(2, RGB(31, 31, 31)); // white
	SetPaletteObj(3, RGB(31, 31, 0)); // yellow
	SetPaletteObj(4, RGB(31, 0, 0)); // red
	SetPaletteObj(5, RGB(0, 29, 0)); // green
	SetPaletteObj(6, RGB(0, 11, 0)); // dark green	
	SetPaletteObj(7, RGB(15, 1, 10)); // strange
	SetPaletteObj(8, RGB(5, 5, 25)); // strange		
	
	// -------------------------------------------------------- LOADS -----------------------------------------------------------
		
	LoadTile8(0, 1, blank_tile);
	LoadTile8(1, 1, blank_tile);
	LoadTile8(2, 1, blank_tile);
	LoadTile8(3, 1, blank_tile);
		
	LoadTile8(4, 1, plane_1);
	LoadTile8(4, 2, plane_2);
	LoadTile8(4, 3, plane_3);
	LoadTile8(4, 4, plane_4);	
	LoadTile8(4, 5, plane_5);
	LoadTile8(4, 6, plane_6);
	LoadTile8(4, 7, plane_7);
	LoadTile8(4, 8, plane_8); 
	
	LoadTile8(4, 10, bullet_tile);
	
	LoadTile8(0, 3, test_full_tile);
	
	// Load the characters
	for (int i=0; i<=127; i++) 
	{		
		LoadTile8(1, i, font_bold[i]);
		LoadTile8(1, i + 128, font_medium[i]);
	}
	
	// -------------------------------------------------------- MENU -----------------------------------------------------------
	int pointer_y = 10;
	int menu_row_counter = 0;
	uint16_t prevButtons;
		
	while (true)
	{
		DrawText(true, 2, 5, "A E R O   I N V A S I O N");
		DrawText(false, 4, 10, "Press start to begin");
			
		DrawText(false, 2, 10, ">");
		DrawText(false, 25, 10, "<");
				
		if ((REG_P1 & KEY_START) == 0) break;
		WaitVSync();
	}
	
	// -------------------------------------------------------- END OF MENU -----------------------------------------------------------

	for (int y = 0; y <= 19; y++) for (int x = 0; x <= 29; x++) SetTile(28, x, y, 1); // fill 28 with blanks
	for (int y = 0; y <= 19; y++) for (int x = 0; x <= 29; x++) SetTile(29, x, y, 0); // fill 29 with 0s
	for (int y = 0; y <= 19; y++) for (int x = 0; x <= 29; x++) DrawText(false, x, y, " ");	
	
	LoadTile8(4, 10, bullet_tile);
	
	LoadTile8(4, 11, enemy1_1);
	LoadTile8(4, 12, enemy1_2);
	LoadTile8(4, 13, enemy1_3);
	LoadTile8(4, 14, enemy1_4);
	LoadTile8(4, 15, enemy1_5);
	LoadTile8(4, 16, enemy1_6);
	LoadTile8(4, 17, enemy1_7);
	LoadTile8(4, 18, enemy1_8);
	LoadTile8(4, 19, enemy1_9);
	LoadTile8(4, 20, enemy1_10);
	LoadTile8(4, 21, enemy1_11);
	LoadTile8(4, 22, enemy1_12);
	LoadTile8(4, 23, enemy1_13);
	LoadTile8(4, 24, enemy1_14);
	LoadTile8(4, 25, enemy1_15);
	LoadTile8(4, 26, enemy1_16);
	LoadTile8(4, 27, enemy1_17);
	LoadTile8(4, 28, enemy1_18);
	LoadTile8(4, 29, enemy1_19);
	LoadTile8(4, 30, enemy1_20);	
	
	LoadTile8(0, 2, cloud_tile);
	LoadTile8(0, 3, sky_tile);
	
	// Draw sky
	for (int y = 0; y <= 32; ++y) for (int x = 0; x <= 32; ++x) SetTile(28, x, y, 3);
	
	// Draw clouds
	for (int i=0; i<=20; i++)
	{
		int x=rand()%32, y=rand()%32;
		for (int j=x; j<=x+4l; j++) SetTile(28, j, y, 2);
	}	
	
	// clear the second farthest screen with blanks (again!!)
	for (int y = 0; y <= 19; y++) for (int x = 0; x <= 29; x++) SetTile(29, x, y, 0);
	
	// define player
	Player player;
	player.x_pos = 100;
	player.y_pos = 140;
	player.Initialise();
	
	// define bullet
	Bullet bullet;
	bullet.x_pos = 100;
	bullet.y_pos = 140;
	bullet.visible = false;
	bullet.engaged = false;
	bullet.Initialise();
	
	// define enemies (this whole thing is one wave)
	Enemy enemy_array[50]; 
	for (int i=1; i<=9; i++)
	{
		enemy_array[i].x_pos = i*21 + 5;
		enemy_array[i].y_pos = 1;
		enemy_array[i].object_number = i + 1;
		enemy_array[i].tile_id = 11;
		enemy_array[i].Initialise();

		enemy_array[i+9].x_pos = i*21 + 5;
		enemy_array[i+9].y_pos = 1;
		enemy_array[i+9].tile_id = 11;
		enemy_array[i+9].object_number = i + 10;
		
		enemy_array[i+18].x_pos = i*21 + 5;
		enemy_array[i+18].y_pos = 1;
		enemy_array[i+18].tile_id = 11;
		enemy_array[i+18].object_number = i + 19;
		
		enemy_array[i+27].x_pos = i*21 + 5;
		enemy_array[i+27].y_pos = 1;
		enemy_array[i+27].tile_id = 11;
		enemy_array[i+27].object_number = i + 28;
		
		enemy_array[i+36].x_pos = i*21 + 5;
		enemy_array[i+36].y_pos = 1;
		enemy_array[i+36].tile_id = 11;
		enemy_array[i+36].object_number = i + 37;
	}		
		
	int V_1 = 0;
	int counter = 1;
	int rows_passed = 0;
	int waves_passed = 0; 	
	
	// LEVEL 1
	while (true)
	{		
		for (int j=1; j<=45; j++)
		{
			if (enemy_array[j].visible)
			{
				if ((bullet.y_pos >= (enemy_array[j].y_pos)) && (bullet.y_pos <= (enemy_array[j].y_pos + 15)) && (bullet.x_pos >= (enemy_array[j].x_pos)) && (bullet.x_pos <= (enemy_array[j].x_pos + 15)))	
				{
					enemy_array[j].Kill();
					bullet.y_pos = 140;
					SetObjectY(1, bullet.y_pos);
					bullet.x_pos = player.x_pos;
					SetObjectX(1, bullet.x_pos);
					bullet.engaged = false;
				}
				if ((enemy_array[j].y_pos + 16) >= SCREEN_HEIGHT - 5)
				{
					GameOver();
				}
			
			}
		}
		
		if (bullet.engaged)
		{
			bullet.Initialise();
			bullet.y_pos -= 5;
			SetObjectY(1, bullet.y_pos);		
		}
		if (bullet.y_pos < 1)
		{
			bullet.y_pos = 140;
			SetObjectY(1, bullet.y_pos);
			bullet.x_pos = player.x_pos;
			SetObjectX(1, bullet.x_pos);
			bullet.engaged = false;
		}
			
		if (((REG_P1 & KEY_A) == 0) && (!bullet.engaged)) 
		{
			bullet.y_pos = 140;
			SetObjectY(1, bullet.y_pos);
			bullet.x_pos = player.x_pos;		
			SetObjectX(1, bullet.x_pos);			
			bullet.engaged = true;
		}
		if (((REG_P1 & KEY_LEFT) == 0) && (player.x_pos >= 1)) 
		{
			player.x_pos--;
			SetObjectX(0, player.x_pos);
			if (!bullet.engaged)
			{
				bullet.x_pos--;
				SetObjectX(1, bullet.x_pos);
			}			
		}
		if (((REG_P1 & KEY_RIGHT) == 0) && (player.x_pos <= SCREEN_WIDTH-10)) 
		{
			player.x_pos++;
			SetObjectX(0, player.x_pos);
			if (!bullet.engaged)
			{
				bullet.x_pos++;
				SetObjectX(1, bullet.x_pos);
			}		
		}
		
		V_1--;
		REG_BG3VOFS = V_1;
		
		if (counter % 30 == 0)
		{
			for (int i=1; i<=9; i++)
			{
				if (enemy_array[i].visible)
				{
					enemy_array[i].y_pos += 3;
					SetObjectY(i + 1, enemy_array[i].y_pos);
				}
				if (enemy_array[i + 9].visible)
				{
					enemy_array[i + 9].y_pos += 3;
					SetObjectY(i + 10, enemy_array[i + 9].y_pos);					
				}
				if (enemy_array[i + 18].visible)
				{
					enemy_array[i + 18].y_pos += 3;
					SetObjectY(i + 19, enemy_array[i + 18].y_pos);					
				}
				if (enemy_array[i + 27].visible)
				{
					enemy_array[i + 27].y_pos += 3;
					SetObjectY(i + 28, enemy_array[i + 27].y_pos);					
				}
				if (enemy_array[i + 36].visible)
				{
					enemy_array[i + 36].y_pos += 3;
					SetObjectY(i + 37, enemy_array[i + 36].y_pos);					
				}
			}	
		}
	
		if (counter == 250)
		{
			for (int i=1; i<=9; i++)
			{
				enemy_array[i+9].Initialise();		
			}		
		}
		
		if (counter == 500)
		{
			for (int i=1; i<=9; i++)
			{
				enemy_array[i+18].Initialise();		
			}		
		}	
		
		if (counter == 750)
		{
			for (int i=1; i<=9; i++)
			{
				enemy_array[i+27].Initialise();		
			}		
		}		
		if (counter == 1000)
		{
			for (int i=1; i<=9; i++)
			{
				enemy_array[i+36].Initialise();		
			}		
		}
		
		if (counter == 1800)
		{
			counter = 0;
			waves_passed++;
			for (int i=1; i<=45; i++)
			{				
				enemy_array[i].y_pos = 1;
				enemy_array[i].tile_id += 4;
				enemy_array[i].Kill();
			}			
			for(int i=1; i<=9; i++)
			{	
				enemy_array[i].y_pos = 1;
				enemy_array[i].Initialise();
			}
		}
		
		if (!bullet.engaged) bullet.Hide();
		
		if (waves_passed >= 2) break;
		
		counter++;
		WaitVSync();
		UpdateObjects();
	}	
	
	for (int y = 0; y <= 32; y++) for (int x = 0; x <= 32; x++) SetTile(28, x, y, 1);
	for (int y = 0; y <= 32; y++) for (int x = 0; x <= 32; x++) SetTile(29, x, y, 0); //black
	ClearObjects();
	DrawText(true, 10, 5, "Level 2");
	
	counter = 0;
	while (counter < 100)
	{
		WaitVSync();
		counter++;
	}
	
	for (int y = 0; y <= 31; y++) for (int x = 0; x <= 31; x++) SetTile(28, x, y, 1);
	for (int y = 0; y <= 31; y++) for (int x = 0; x <= 31; x++) SetTile(29, x, y, 1); //black
	for (int y = 0; y <= 31; y++) for (int x = 0; x <= 31; x++) DrawText(false, x, y, " ");
	
	// clear the second farthest screen with blanks (again!!)
	for (int y = 0; y <= 31; y++) for (int x = 0; x <= 31; x++) SetTile(29, x, y, 0);
	
	// Draw sky
	for (int y = 0; y <= 31; ++y) for (int x = 0; x <= 31; ++x) SetTile(28, x, y, 3);
	
	// Draw clouds
	for (int i=0; i<=20; i++)
	{
		int x=rand()%32, y=rand()%32;
		for (int j=x; j<=x+4l; j++) SetTile(28, j, y, 2);
	}
	
	player.x_pos = 100;
	player.y_pos = 140;
	player.Initialise();
	
	// define bullet
	bullet.x_pos = 100;
	bullet.y_pos = 140;
	bullet.visible = false;
	bullet.engaged = false;
	bullet.Initialise();
		
	counter = 0;
	
	for (int i=1; i<=45; i++)
	{				
		enemy_array[i].tile_id = 19;
	}		
	waves_passed = 0;
	
	// LEVEL 2
	while (true)
	{		
		for (int j=1; j<=45; j++)
		{
			if (enemy_array[j].visible)
			{
				if ((bullet.y_pos >= (enemy_array[j].y_pos)) && (bullet.y_pos <= (enemy_array[j].y_pos + 15)) && (bullet.x_pos >= (enemy_array[j].x_pos)) && (bullet.x_pos <= (enemy_array[j].x_pos + 15)))	
				{
					enemy_array[j].Kill();
					bullet.y_pos = 140;
					SetObjectY(1, bullet.y_pos);
					bullet.x_pos = player.x_pos;
					SetObjectX(1, bullet.x_pos);
					bullet.engaged = false;
				}
				if ((enemy_array[j].y_pos + 16) >= (SCREEN_HEIGHT + 40))
				{
					GameOver();
				}
			}
		}
		
		if (bullet.engaged)
		{
			bullet.Initialise();
			bullet.y_pos -= 5;
			SetObjectY(1, bullet.y_pos);		
		}
		if (bullet.y_pos < 1)
		{
			bullet.y_pos = 140;
			SetObjectY(1, bullet.y_pos);
			bullet.x_pos = player.x_pos;
			SetObjectX(1, bullet.x_pos);
			bullet.engaged = false;
		}
			
		if (((REG_P1 & KEY_A) == 0) && (!bullet.engaged)) 
		{
			bullet.y_pos = 140;
			SetObjectY(1, bullet.y_pos);
			bullet.x_pos = player.x_pos;		
			SetObjectX(1, bullet.x_pos);			
			bullet.engaged = true;
		}
		if (((REG_P1 & KEY_LEFT) == 0) && (player.x_pos >= 1)) 
		{
			player.x_pos--;
			SetObjectX(0, player.x_pos);
			if (!bullet.engaged)
			{
				bullet.x_pos--;
				SetObjectX(1, bullet.x_pos);
			}			
		}
		if (((REG_P1 & KEY_RIGHT) == 0) && (player.x_pos <= SCREEN_WIDTH-10)) 
		{
			player.x_pos++;
			SetObjectX(0, player.x_pos);
			if (!bullet.engaged)
			{
				bullet.x_pos++;
				SetObjectX(1, bullet.x_pos);
			}		
		}
		
		V_1--;
		REG_BG3VOFS = V_1;
		
		if (counter % 30 == 0)
		{
			for (int i=1; i<=9; i++)
			{
				if (enemy_array[i].visible)
				{
					enemy_array[i].y_pos += 5;
					SetObjectY(i + 1, enemy_array[i].y_pos);
				}
				if (enemy_array[i + 9].visible)
				{
					enemy_array[i + 9].y_pos += 5;
					SetObjectY(i + 10, enemy_array[i + 9].y_pos);					
				}
				if (enemy_array[i + 18].visible)
				{
					enemy_array[i + 18].y_pos += 5;
					SetObjectY(i + 19, enemy_array[i + 18].y_pos);					
				}
				if (enemy_array[i + 27].visible)
				{
					enemy_array[i + 27].y_pos += 5;
					SetObjectY(i + 28, enemy_array[i + 27].y_pos);					
				}
				if (enemy_array[i + 36].visible)
				{
					enemy_array[i + 36].y_pos += 5;
					SetObjectY(i + 37, enemy_array[i + 36].y_pos);					
				}
			}	
		}
	
		if (counter == 150)
		{
			for (int i=1; i<=9; i++)
			{
				enemy_array[i+9].Initialise();		
			}		
		}
		
		if (counter == 300)
		{
			for (int i=1; i<=9; i++)
			{
				enemy_array[i+18].Initialise();		
			}		
		}	
		
		if (counter == 450)
		{
			for (int i=1; i<=9; i++)
			{
				enemy_array[i+27].Initialise();		
			}		
		}		
		if (counter == 1000)
		{
			for (int i=1; i<=9; i++)
			{
				enemy_array[i+36].Initialise();		
			}		
		}
		
		if (counter == 1800)
		{
			counter = 0;
			waves_passed++;
			for (int i=1; i<=45; i++)
			{				
				enemy_array[i].y_pos = 1;
				enemy_array[i].tile_id += 4;
				enemy_array[i].Kill();
			}			
			for(int i=1; i<=9; i++)
			{	
				enemy_array[i].y_pos = 1;
				enemy_array[i].Initialise();
			}
		}
		
		if (!bullet.engaged) bullet.Hide();
		
		if (waves_passed >= 3) Win();
						
		counter++;
		WaitVSync();
		UpdateObjects();
	}	
	
		counter++;
		WaitVSync();
		UpdateObjects();
	}

void DrawText(bool bold, int x, int y, const char string[])
{
	int i=0;
	do 
	{
		if (bold) SetTile(29, x, y, string[i]);
		else SetTile(29, x, y, string[i] + 128);
		i++;
		x++;
	}
	while (string[i] != '\0');
}
void GameOver()
{
	for (int y = 0; y <= 31; y++) for (int x = 0; x <= 31; x++) SetTile(28, x, y, 1);
	for (int y = 0; y <= 31; y++) for (int x = 0; x <= 31; x++) SetTile(29, x, y, 0); //black
	ClearObjects();
	//ClearScreen8(0);
	DrawText(true, 10, 5, "GAME OVER");
	
	while (true)
	{
		WaitVSync();
	}
}
void Win()
{
	for (int y = 0; y <= 31; y++) for (int x = 0; x <= 31; x++) SetTile(28, x, y, 1);
	for (int y = 0; y <= 31; y++) for (int x = 0; x <= 31; x++) SetTile(29, x, y, 0); //black
	ClearObjects();
	//ClearScreen8(0);
	DrawText(true, 6, 5, "CONGRATULATIONS!");
	DrawText(true, 4, 10, "You've defeated all");
	DrawText(true, 5, 12, "enemy planes");
	
	while (true)
	{
		WaitVSync();
	}
}
	
void InstructionsMenu()
{
	ClearObjects();
	ClearScreen8(0);
	
	// Load the characters
	for (int i=0; i<=127; i++) 
	{
		
		LoadTile8(0, i, font_bold[i]);
		LoadTile8(0, i + 128, font_medium[i]);
	} 
	LoadTile8(1, 1, blank_tile);
		
	while (true)
	{
		DrawText(false, 22, 10, "Gauss");
	}

}
