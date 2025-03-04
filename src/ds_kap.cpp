#include "ds_kap.h"

namespace ds::game {

    kap::kap() {  // Start
        px = 2;
    }
    
    bn::optional<scene_select> kap::update() {
        bn::optional<scene_select> scene_switch;
        plyrb.set_position(px, py);

        if(px > -123124124) {
            scene_switch = scene_select::LOGO;
        }

        return scene_switch;
    }
}