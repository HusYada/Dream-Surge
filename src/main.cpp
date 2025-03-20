// Dream Surge by HusYada
#include "game.h"

// #001 - Title
void title() {
    bn::bg_palettes::set_transparent_color(bn::color(0,0,10));
    bn::regular_bg_ptr bg1 = bn::regular_bg_items::test_map_1.create_bg(0,0);

    while(scene == 0){
        //
        bn::core::update();
    }
}

// #999 - Main
int main() {
    bn::core::init();
    //bn::sprite_text_generator score_text(common::variable_8x16_sprite_font);
    //bn::sprite_text_generator level_text(common::variable_8x16_sprite_font);
    //bn::bg_palettes::set_transparent_color(bn::color(0,0,0));

    while(true) {
        title();
        //game(score_text, level_text);
    }
    bn::core::update();
}
