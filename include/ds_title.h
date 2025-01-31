#ifndef DS_TITLE_H
#define DS_TITLE_H

#include "ds_scene.h"

namespace ds {

    class title : public scene {

        public:
            title();
            [[nodiscard]] bn::optional<scene_select> update() final;
    };

}

#endif