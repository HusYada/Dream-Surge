// Dream Surge by HusYada

#include "bn_core.h"
#include "bn_unique_ptr.h"
#include "ds_scene.h"
#include "ds_scene_list.h"
#include "ds_logo.h"
#include "ds_title.h"
#include "ds_test_map.h"
#include "common_info.h"
#include "common_variable_8x16_sprite_font.h"
#include "load_attributes.h"

int main() {

    //bn::regular_bg_map_item& map_item2 = bn::regular_bg_items::test_map_1.map_item();

    bn::core::init();
    bn::sprite_text_generator texty(common::variable_8x16_sprite_font);
    texty.set_bg_priority(1);
    //bn::unique_ptr<ds::scene> scene(new ds::logo(texty));
    bn::unique_ptr<ds::scene> scene(new ds::game::test_map());
    //bn::optional<ds::scene_select> next_scene = ds::scene_select::LOGO;
    bn::optional<ds::scene_select> next_scene = ds::scene_select::TEST_MAP;
    int wait_frames = 0;

    while(true) {

        if(scene) {
            next_scene = scene->update();
        }

        bn::core::update();

        if(next_scene) {

            if(scene) {
                scene.reset();
                wait_frames = 2;
            }

            --wait_frames;

            if(!wait_frames)  {

                switch(*next_scene) {

                    case ds::scene_select::LOGO:
                        scene.reset(new ds::logo(texty));
                        break;

                    case ds::scene_select::TITLE:
                        scene.reset(new ds::title());
                        break;

                    case ds::scene_select::TEST_MAP:
                        scene.reset(new ds::game::test_map());
                        break;

                    default:
                        BN_ERROR("Invalid next scene: ", int(*next_scene));
                        break;
                }
            }
        }
    }
}