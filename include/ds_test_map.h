#ifndef DS_TEST_MAP_H
#define DS_TEST_MAP_H

#include "ds_scene.h"
#include "ds_scene_list.h"
#include "bn_bg_palettes.h"
#include "bn_colors.h"
#include "bn_keypad.h"
#include "bn_regular_bg_ptr.h"
#include "bn_sprite_items_cursor.h"
#include "bn_sprite_items_test_char.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_tiles_ptr.h"
#include "bn_regular_bg_items_test_map_1.h"

#include "bn_regular_bg_builder.h"
#include "bn_regular_bg_ptr.h"
#include "bn_core.h"
#include "bn_regular_bg_map_cell_info.h"

#include "ds_kap.h"

namespace ds::game {

    class test_map : public scene {

        public:
            test_map();
            //test_map(const bn::regular_bg_map_item& map_item);
            [[nodiscard]] bn::optional<scene_select> update() final;

        private:
            int px = 0, py = 0;     // Player XY
            int pxd = 0, pyd = 0;   // Player XY Delay (White Dot)
            int stepd = 2, grv = 2; // Left/Right Step Speed & Gravity

            bn::point leftshadowpos;
            bn::point rghtshadowpos;
            
            //const bn::regular_bg_map_item& map_item;

            bn::sprite_ptr plyr = bn::sprite_items::test_char.create_sprite(0, 0);

            bn::regular_bg_ptr background = bn::regular_bg_items::test_map_1.create_bg(0,8);
            bn::sprite_ptr c_d = bn::sprite_items::cursor.create_sprite(0, 0);
            bn::sprite_ptr c_0 = bn::sprite_items::cursor.create_sprite(-12, -12);
            bn::sprite_ptr c_1 = bn::sprite_items::cursor.create_sprite(-4, -12);
            bn::sprite_ptr c_2 = bn::sprite_items::cursor.create_sprite(4, -12);
            bn::sprite_ptr c_3 = bn::sprite_items::cursor.create_sprite(12, -12);
            bn::sprite_ptr c_4 = bn::sprite_items::cursor.create_sprite(-12, -4);
            bn::sprite_ptr c_5 = bn::sprite_items::cursor.create_sprite(-4, -4);
            bn::sprite_ptr c_6 = bn::sprite_items::cursor.create_sprite(4, -4);
            bn::sprite_ptr c_7 = bn::sprite_items::cursor.create_sprite(12, -4);
            bn::sprite_ptr c_8 = bn::sprite_items::cursor.create_sprite(-12, 4);
            bn::sprite_ptr c_9 = bn::sprite_items::cursor.create_sprite(-4, 4);
            bn::sprite_ptr c_10 = bn::sprite_items::cursor.create_sprite(4, 4);
            bn::sprite_ptr c_11 = bn::sprite_items::cursor.create_sprite(12, 4);
            bn::sprite_ptr c_12 = bn::sprite_items::cursor.create_sprite(-12, 12);
            bn::sprite_ptr c_13 = bn::sprite_items::cursor.create_sprite(-4, 12);
            bn::sprite_ptr c_14 = bn::sprite_items::cursor.create_sprite(4, 12);
            bn::sprite_ptr c_15 = bn::sprite_items::cursor.create_sprite(12, 12);
    };

}

#endif