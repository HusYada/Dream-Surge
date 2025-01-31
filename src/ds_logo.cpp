#include "ds_logo.h"

#include "bn_bg_palettes.h"
#include "bn_colors.h"
#include "bn_keypad.h"
#include "ds_scene_list.h"

namespace ds {

    logo::logo() {
        bn::bg_palettes::set_transparent_color(bn::color(0,10,0));
    }

    void logo::opening_1() {
        bn::bg_palettes::set_transparent_color(bn::color(10,10,0));
    }

    bn::optional<scene_select> logo::update() {

        bn::optional<scene_select> scene_switch;

        if(bn::keypad::a_pressed()) {
            scene_switch = scene_select::TITLE;
        }

        return scene_switch;
    }
}