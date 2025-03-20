// Dream Surge by HusYada
#ifndef GAME_H
#define GAME_H

// All Includes (dunno if i need all this)
#include "bn_affine_bg_ptr.h"
#include "bn_affine_bg_builder.h"
#include "bn_affine_bg_actions.h"
#include "bn_affine_bg_attributes.h"
#include "bn_affine_bg_mat_attributes.h"
#include "bn_affine_bg_animate_actions.h"
#include "bn_affine_bg_attributes_hbe_ptr.h"
#include "bn_affine_bg_pivot_position_hbe_ptr.h"
#include "bn_affine_bg_mat_attributes_hbe_ptr.h"
#include "bn_bg_palettes.h"
#include "bn_bg_palette_actions.h"
#include "bn_blending.h"
#include "bn_camera_actions.h"
#include "bn_color.h"
#include "bn_colors.h"
#include "bn_config_audio.h"
#include "bn_core.h"
#include "bn_display.h"
#include "bn_fixed_point.h"
#include "bn_format.h"
#include "bn_keypad.h"
#include "bn_log.h"
#include "bn_math.h"
//#include "bn_music.h"
//#include "bn_music_items.h"
#include "bn_rect_window.h"
#include "bn_regular_bg_builder.h"
#include "bn_regular_bg_map_cell_info.h"
#include "bn_regular_bg_ptr.h"
//#include "bn_sound_actions.h"
//#include "bn_sound_items.h"
#include "bn_sprite_palette_actions.h"
#include "bn_sprite_palettes_actions.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_text_generator.h"
#include "bn_sprite_tiles_ptr.h"
#include "bn_string.h"
#include "bn_time.h"
#include "bn_unique_ptr.h"
#include "common_info.h"
#include "common_variable_8x16_sprite_font.h"
#include "load_attributes.h"
// Sprites
#include "bn_sprite_items_cursor.h"
// Backgrounds
// #include "bn_affine_bg_items_abc.h"
#include "bn_regular_bg_items_test_map_1.h"
// Include
//#include "collision.h"
// Variables
int scene = 0;		// Very Important, see Scene List tab


namespace {
	//collision ocol;
}

#endif