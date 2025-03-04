#include "ds_test_map.h"

namespace ds::game {

    test_map::test_map() {  // Start
    //test_map::test_map(const bn::regular_bg_map_item& map_item) {  // Start    

        bn::bg_palettes::set_transparent_color(bn::color(10,0,10));
        c_0.set_tiles(bn::sprite_items::cursor.tiles_item().create_tiles(2));
        c_1.set_tiles(bn::sprite_items::cursor.tiles_item().create_tiles(2));
        c_2.set_tiles(bn::sprite_items::cursor.tiles_item().create_tiles(2));
        c_3.set_tiles(bn::sprite_items::cursor.tiles_item().create_tiles(2));
        c_4.set_tiles(bn::sprite_items::cursor.tiles_item().create_tiles(2));
        c_5.set_tiles(bn::sprite_items::cursor.tiles_item().create_tiles(2));
        c_6.set_tiles(bn::sprite_items::cursor.tiles_item().create_tiles(2));
        c_7.set_tiles(bn::sprite_items::cursor.tiles_item().create_tiles(2));
        c_8.set_tiles(bn::sprite_items::cursor.tiles_item().create_tiles(2));
        c_9.set_tiles(bn::sprite_items::cursor.tiles_item().create_tiles(2));
        c_10.set_tiles(bn::sprite_items::cursor.tiles_item().create_tiles(2));
        c_11.set_tiles(bn::sprite_items::cursor.tiles_item().create_tiles(2));
        c_12.set_tiles(bn::sprite_items::cursor.tiles_item().create_tiles(2));
        c_13.set_tiles(bn::sprite_items::cursor.tiles_item().create_tiles(2));
        c_14.set_tiles(bn::sprite_items::cursor.tiles_item().create_tiles(2));
        c_15.set_tiles(bn::sprite_items::cursor.tiles_item().create_tiles(2));

        //map_item = bn::regular_bg_items::test_map_1.map_item();

        leftshadowpos.set_x(255);
        leftshadowpos.set_y(255);
        rghtshadowpos.set_x(255);
        rghtshadowpos.set_y(256);
    }
    
    bn::optional<scene_select> test_map::update() {

        //bn::point newleftshadowpos = leftshadowpos;
        //bn::point newrghtshadowpos = rghtshadowpos;

        bn::optional<scene_select> scene_switch;

        //kap::update();

        plyr.set_position(pxd+px, pyd+py);
        c_d.set_position(pxd, pyd);
        c_0.set_position(px+-12, py+-12);
        c_1.set_position(px+-4, py+-12);
        c_2.set_position(px+4, py+-12);
        c_3.set_position(px+12, py+-12);
        c_4.set_position(px+-12, py+-4);
        c_5.set_position(px+-4, py+-4);
        c_6.set_position(px+4, py+-4);
        c_7.set_position(px+12, py+-4);
        c_8.set_position(px+-12, py+4);
        c_9.set_position(px+-4, py+4);
        c_10.set_position(px+4, py+4);
        c_11.set_position(px+12, py+4);
        c_12.set_position(px+-12, py+12);
        c_13.set_position(px+-4, py+12);
        c_14.set_position(px+4, py+12);
        c_15.set_position(px+12, py+12);

        if(bn::keypad::left_held()) {
            pxd--;
        }

        if(bn::keypad::right_held()) {
            pxd++;
        }

        if(bn::keypad::up_pressed()) {
            py -= 8;
        }

        if(bn::keypad::down_held()) {
            pyd++;
        }

        if(pxd < -4) {
            px -= 8;
            pxd = 0;
        }
        if(pxd > 4) {
            px += 8;
            pxd = 0;
        }
        if(pyd < -4) {
            py -= 8;
            pyd = 0;
        }
        if(pyd > 4) {
            py += 8;
            pyd = 0;
        }

        // -------------------------------------------------------------------------------------------------------
        // Main Tile Collision
        // -------------------------------------------------------------------------------------------------------
        //bn::regular_bg_map_cell plyr_map_cell1 = map_item.cell(newleftshadowpos);
        //bn::regular_bg_map_cell plyr_map_cell2 = map_item.cell(newrghtshadowpos);
        // int plyr_tile_index1 = bn::regular_bg_map_cell_info(plyr_map_cell1).tile_index();
        // int plyr_tile_index2 = bn::regular_bg_map_cell_info(plyr_map_cell2).tile_index();

        // bn::fixed plyr_sprite_x = (leftshadowpos.x() * 8) - (map_item.dimensions().width() * 4) + 4;
        // bn::fixed plyr_sprite_y = (leftshadowpos.y() * 8) - (map_item.dimensions().height() * 4) + 4;
        // plyr_left_shadow.set_position(plyr_sprite_x, plyr_sprite_y);
        // plyr_rght_shadow.set_position(plyr_sprite_x + 8, plyr_sprite_y);

        // plyr_pixel.set_position(scrollx, scrolly);
        // camera.set_x(plyr_sprite_x + scrollx + 4);
        // camera.set_y(plyr_sprite_y + scrolly - 28);

        // for(int i = 0; i < valid_map_cells_length; i++)
        // {
        //     for(int j = 0; j < valid_map_cells_length; j++)
        //     {
        //         if(plyr_tile_index1 == bn::regular_bg_map_cell_info(valid_map_cells[i]).tile_index()
        //         && plyr_tile_index2 == bn::regular_bg_map_cell_info(valid_map_cells[j]).tile_index())
        //         {
        //             leftshadowpos = newleftshadowpos;
        //             rghtshadowpos = newrghtshadowpos;
        //         }
        //     }
        // }

        if(bn::keypad::select_pressed()) {
            scene_switch = scene_select::LOGO;
        }

        return scene_switch;
    }
}