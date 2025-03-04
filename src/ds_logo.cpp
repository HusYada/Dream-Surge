#include "ds_logo.h"

namespace ds {

    logo::logo(bn::sprite_text_generator& text_generator) {
        bn::bg_palettes::set_transparent_color(bn::color(0,10,0));
        bn::string<64> middle_text("Made with BUTANO ");
        text_generator.generate(0, 0, middle_text, dialog);
    }

    void logo::opening_1() {
        bn::bg_palettes::set_transparent_color(bn::color(10,10,0));
    }

    bn::optional<scene_select> logo::update() {

        bn::optional<scene_select> scene_switch;
        plyr.set_position(px, 40);

        if(bn::keypad::left_held()) {
            px += 2;
        }

        if(bn::keypad::right_held()) {
            px -= 2;
        }

        if(bn::keypad::a_pressed()) {
            scene_switch = scene_select::TITLE;
        }

        if(bn::keypad::b_pressed()) {
            scene_switch = scene_select::TEST_MAP;
        }

        return scene_switch;
    }
}