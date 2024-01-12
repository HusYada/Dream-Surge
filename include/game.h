#ifndef GAME_H
#define GAME_H
// Butano
#include "bn_bg_palettes.h"
#include "bn_color.h"
#include "bn_core.h"
#include "bn_fixed.h"
#include "bn_keypad.h"
#include "bn_log.h"
#include "bn_math.h"
#include "bn_music_actions.h"
#include "bn_music_items.h"
#include "bn_regular_bg_ptr.h"
#include "bn_sound_items.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_tiles_ptr.h"
// Include
#include "collision.h"
// Sprites
#include "bn_sprite_items_aroha.h"
#include "bn_sprite_items_dot.h"
// Backgrounds
//-------------------------------
#include "bn_regular_bg_items_e3_1.h"
#include "bn_regular_bg_items_e3_2.h"
#include "bn_regular_bg_items_e4_1.h"
#include "bn_regular_bg_items_e4_2.h"
#include "bn_regular_bg_items_e5_1.h"
#include "bn_regular_bg_items_e5_2.h"
#include "bn_regular_bg_items_d5_1.h"
#include "bn_regular_bg_items_d5_2.h"
#include "bn_regular_bg_items_d4_1.h"
#include "bn_regular_bg_items_d4_2.h"
#include "bn_regular_bg_items_d3_1.h"
#include "bn_regular_bg_items_d3_2.h"
#include "bn_regular_bg_items_c3_1.h"
#include "bn_regular_bg_items_c3_2.h"
#include "bn_regular_bg_items_c5_1.h"
#include "bn_regular_bg_items_c5_2.h"
// Player Variables
//-------------------------------
int px = 0; int py = 0; int pw = 8; int ph = 4;
int pa = 0; int pt = 0; int paa = 0;
int grv = 2;bool lslope=false;bool rslope=false;bool jumpanim=false;//bool falling = true;
bool canjump = false;bool jump = false;bool rail = false;
// Level Geometry
int lwx = -120; int lwy = -80; int lww = 1; int lwh = 160;
int rwx =  120; int rwy = -80; int rww = 1; int rwh = 160;
// When calculating geometry co-ordinates:
// Check .xcf for exact co-ords, then if x-120, y-80
// 0-2 = g1; 3-8 = g2;  9-14 = g3; 15-17 = g4;
// 18-21 = g5; 22-28 = g6; 29-32 = g7; 33-35 = g8;
int lx[35]  = {-120, 31, 124,-120,-92,-23,69, 69,120,
			   -120,-61, -61, -12, 45, 78,66,-51,-120,
				120, 65, -28,-120, 
				120, 63, -14, -96,-96,-68,-39,
				-36,  5,   5, 120,
			   -120, 43};
int ly[35]  = {  33, 33, 9  , 9  ,  9, 49,49,-20,-41,
				-45,-14, 8  , 31 ,-31,-80,50, 50, 8,
				 10, 10, 25 , 25 , 
				 23, 23, 15 , 15 ,-56,-25,-43,
				 65, 65, 28 , 28 ,
				 19, 19};

namespace {
	collision ocol;
}
#endif