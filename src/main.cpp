// Dream Surge by HusYada

#include "bn_core.h"
#include "bn_unique_ptr.h"
#include "ds_scene.h"
#include "ds_scene_list.h"
#include "ds_logo.h"
#include "ds_title.h"

int main() {

    bn::core::init();
    bn::unique_ptr<ds::scene> scene(new ds::logo());
    bn::optional<ds::scene_select> next_scene = ds::scene_select::LOGO;
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
                        scene.reset(new ds::logo());
                        break;

                    case ds::scene_select::TITLE:
                        scene.reset(new ds::title());
                        break;

                    default:
                        BN_ERROR("Invalid next scene: ", int(*next_scene));
                        break;
                }
            }
        }
    }
}