#ifndef DS_KAP_H
#define DS_KAP_H

#include "ds_scene.h"
#include "ds_scene_list.h"
#include "bn_common.h"
#include "bn_sprite_items_test_char.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_tiles_ptr.h"

namespace ds {
    enum class scene_select;
}

namespace ds::game {
    //enum class scene_type;
    class kap {
        public:
            kap();
            [[nodiscard]] bn::optional<scene_select> update();
        private:
            int px = 30, py = 30;
            //const bn::sprite_item& _body_sprite_item;
            bn::sprite_ptr plyrb = bn::sprite_items::test_char.create_sprite(px, py);

    };
}

#endif