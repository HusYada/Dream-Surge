#ifndef DS_LOGO_H
#define DS_LOGO_H

#include "ds_scene.h"
#include "ds_scene_list.h"
#include "bn_bg_palettes.h"
#include "bn_colors.h"
#include "bn_keypad.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_text_generator.h"
#include "bn_string.h"
#include "bn_vector.h"
#include "bn_sprite_items_test_char.h"

namespace bn
{
    class sprite_text_generator;
}

namespace ds {

    class logo : public scene {

        public:
            logo(bn::sprite_text_generator& text_generator);
            void opening_1();
            [[nodiscard]] bn::optional<scene_select> update() final;

        private:
            int px = 0;
            bn::sprite_ptr plyr = bn::sprite_items::test_char.create_sprite(0, 20);
            bn::vector<bn::sprite_ptr, 64> dialog;
    };
}

#endif