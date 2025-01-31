#ifndef DS_SCENE_H
#define DS_SCENE_H

#include "bn_optional.h"

namespace ds {

    enum class scene_select;

    class scene {

        public:
            virtual ~scene() = default;
            [[nodiscard]] virtual bn::optional<scene_select> update() = 0;

        protected:
            scene() = default;
    };
}

#endif