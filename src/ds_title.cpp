#include "ds_title.h"

#include "bn_bg_palettes.h"
#include "bn_colors.h"
#include "ds_scene_list.h"

namespace ds {

    title::title() {
        bn::bg_palettes::set_transparent_color(bn::color(0,0,10));
    }
    
    bn::optional<scene_select> title::update() {

        bn::optional<scene_select> scene_switch;

        return scene_switch;
    }
}