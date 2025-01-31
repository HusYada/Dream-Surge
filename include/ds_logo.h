#ifndef DS_LOGO_H
#define DS_LOGO_H

#include "ds_scene.h"

namespace ds {

    class logo : public scene {

        public:
            logo();
            void opening_1();
            [[nodiscard]] bn::optional<scene_select> update() final;
    };
}

#endif