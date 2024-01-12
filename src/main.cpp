// Dream Surge - Area 1
// HusYada

#include "game.h"

void back_test() {
	while(true) {
		bn::core::update();

	}
}

void a1s1() {
	// Variables List
	// ----------------------------------------------------
	px = -40; py = 20; if(bn::music::paused()) { bn::music::resume(); }
	int frame=1; int count=0;
	// Sprites List
	// ----------------------------------------------------
	bn::regular_bg_ptr lv3_e1 = bn::regular_bg_items::e3_1.create_bg(0,0);
	bn::regular_bg_ptr lv3_e2 = bn::regular_bg_items::e3_2.create_bg(0,0);
	bn::sprite_ptr aroha = bn::sprite_items::aroha.create_sprite(px, py);
	// ----------------------------------------------------
	// Z-Axis Configure
	// ----------------------------------------------------
	aroha.put_above();
	// ----------------------------------------------------
	// Update Until -> PX = RW
	// ----------------------------------------------------
	while(!ocol.overlap(px-(pw/2),py-(ph/2),pw,ph,rwx,rwy,rww,rwh)) {
		count++;
		if(frame==1&&count>30){frame=2;count=0;}
		if(frame==2&&count>30){frame=1;count=0;}
		if(frame==1){lv3_e2.put_above();}
		if(frame==2){lv3_e1.put_above();}
		// Collision Variables
		int pls = px-(pw/2); int prs = px+(pw/2); 
		int pts = py-(ph/2); int pbs = py+(ph/2);
		// ----------------------------------------------------
		// Player Input
		// ----------------------------------------------------
		if(bn::keypad::left_held() && !ocol.overlap(
			pls,pts,pw,ph,lwx+36,lwy,lww,lwh)) { 
			px-=1; aroha.set_horizontal_flip(true);
			// Player Walking Animation
				if(canjump){
				if(pa<18){pt++;}
				if(pt>2) {pa++;pt=0;}
				if(pa==17){pa=0;}
				aroha.set_tiles(bn::sprite_items::aroha.tiles_item().create_tiles(pa));
			}
		}
		if(bn::keypad::right_held() && !ocol.overlap(
			pls,pts,pw,ph,rwx,rwy,rww,rwh)) { 
			px+=1; aroha.set_horizontal_flip(false); 
			if(lslope) { py-=1; }
			// Player Walking Animation
			if(canjump){
				if(pa<18) { paa++;}
				if(paa>2) { pa++; paa=0;}
				if(pa==17){ pa=0;}
				aroha.set_tiles(bn::sprite_items::aroha.tiles_item().create_tiles(pa));
			}
		}
		if(bn::keypad::a_pressed() && !rail && canjump) { 
			jump = true; pt=0; pa=18; 
			bn::sound_items::c5piano.play(0.4); 
		}
		// ----------------------------------------------------
		// Gravity Check
		// ----------------------------------------------------
		if(jump) {
			canjump = false;
			grv = -2;
			pt++;
			jumpanim = true;
			if(pt>20) { jump = false; pt=0;}
		}
		if(jumpanim) {
			if(pa>17&&pa<35){paa++;}
			if(paa>2) { pa++; paa=0;}
			if(pa==35){ jumpanim = false;pa=0;}
			aroha.set_tiles(bn::sprite_items::aroha.tiles_item().create_tiles(pa));
		}
		// ----------------------------------------------------
		// Collision
		// ----------------------------------------------------
		// Flat Surface
		if(ocol.overlap(pls,pts,pw,ph, lx[0], ly[0], ocol.distx(lx[0],lx[1]), 2)&&!jump) {
			grv=0;canjump = true;
		} else { if(!lslope && !jump) { grv=2; }}
		// Slope Surface
		if(ocol.lineLine(prs,pts,prs,pbs, lx[1], ly[1], lx[2], ly[2])) {
			lslope=true;canjump = true;
		} else { lslope = false; }
		if(lslope&&!jump) { grv=0; }
		// ----------------------------------------------------
		// Position Update
		// ----------------------------------------------------
		py += grv;
		aroha.set_position(px,py-12);
		// ----------------------------------------------------
		// Brightness Update
		// ----------------------------------------------------
		bn::fixed brightness = bn::bg_palettes::brightness();
		if(bn::keypad::l_held()) { bn::bg_palettes::set_brightness(bn::max(brightness - 0.01, bn::fixed(0))); }
        else if(bn::keypad::r_held()) { bn::bg_palettes::set_brightness(bn::min(brightness + 0.01, bn::fixed(1))); }
		// ----------------------------------------------------
		bn::core::update();
	}
}

void a1s2() {
	// Variables List
	// ----------------------------------------------------
	px = -100; py = 9; lslope=false; //bn::music::pause();
	int frame=1; int count=0;
	// Sprites List
	// ----------------------------------------------------
	bn::regular_bg_ptr lv3_e1 = bn::regular_bg_items::e4_1.create_bg(0,0);
	bn::regular_bg_ptr lv3_e2 = bn::regular_bg_items::e4_2.create_bg(0,0);
	bn::sprite_ptr aroha = bn::sprite_items::aroha.create_sprite(px, py);
	// ----------------------------------------------------
	// Z-Axis Configure
	// ----------------------------------------------------
	aroha.put_above();
	// ----------------------------------------------------
	// Update Until -> PX = RW
	// ----------------------------------------------------
	while(!ocol.overlap(px-(pw/2),py-(ph/2),pw,ph,rwx,rwy,rww,rwh)) {
		count++;
		if(frame==1&&count>30){frame=2;count=0;}
		if(frame==2&&count>30){frame=1;count=0;}
		if(frame==1){lv3_e2.put_above();}
		if(frame==2){lv3_e1.put_above();}
		//if(frame==3){lv3_e2.put_above();}
		// Collision Variables
		int pls = px-(pw/2); int prs = px+(pw/2); 
		int pts = py-(ph/2); int pbs = py+(ph/2);
		// ----------------------------------------------------
		// Player Input
		// ----------------------------------------------------
		if(bn::keypad::left_held() && !ocol.overlap(
			pls,pts,pw,ph,lwx,lwy,lww,lwh)) { 
			px-=1; aroha.set_horizontal_flip(true);
			if(rslope) { py-=2; }
			// Player Walking Animation
				if(canjump){
				if(pa<18){pt++;}
				if(pt>2) {pa++;pt=0;}
				if(pa==17){pa=0;}
				aroha.set_tiles(bn::sprite_items::aroha.tiles_item().create_tiles(pa));
			}
		}
		if(bn::keypad::right_held() &&
			  (!ocol.overlap(pls,pts,pw,ph,rwx,rwy,rww,rwh)
			&& !ocol.overlap(pls,pts,pw,ph, lx[7], ly[7], 4, 200))) { 
			px+=1; aroha.set_horizontal_flip(false); 
			if(lslope) { py-=1; }
			// Player Walking Animation
			if(canjump){
				if(pa<18) { paa++;}
				if(paa>2) { pa++; paa=0;}
				if(pa==17){ pa=0;}
				aroha.set_tiles(bn::sprite_items::aroha.tiles_item().create_tiles(pa));
			}
		}
		if(bn::keypad::a_pressed() && !rail && canjump) { 
			jump = true; 
			pt=0; 
			pa=18; 
			bn::sound_items::c5piano.play(0.4); 
		}
		if(bn::keypad::b_pressed()) { rail=true; pa = 36; bn::sound_items::c5piano.play(0.4);}
		if(pa == 53) { pa = 0; }
		// ----------------------------------------------------
		// Gravity Check
		// ----------------------------------------------------
		if(jump) {
			canjump = false;
			grv = -2;
			pt++;
			jumpanim = true;
			if(pt>20) { jump = false; pt=0;}
		}
		if(jumpanim) {
			if(pa>17&&pa<35){paa++;}
			if(paa>2) { pa++; paa=0;}
			if(pa==35){ jumpanim = false;pa=0;}
			aroha.set_tiles(bn::sprite_items::aroha.tiles_item().create_tiles(pa));
		}
		if(rail) {
			if(ocol.overlap(pls-4,pts,pw+8,ph, lx[7], ly[7], 4, 200)) {
				grv = -4;
				pa++;		
				if(ocol.overlap(pls-4,pts,pw+8,ph, lx[7], ly[7], 1, 1)){py = py - 20;}
			} else {
				rail = false;
				pa = 0;
			}
			aroha.set_tiles(bn::sprite_items::aroha.tiles_item().create_tiles(pa));
		}
		// ----------------------------------------------------
		// Collision
		// ----------------------------------------------------
		// Flat Surface
		if(ocol.overlap(pls,pts,pw,ph, lx[3], ly[3], ocol.distx(lx[3],lx[4]), 2)&&!jump&&!rail) {
			grv=0;canjump = true;
		} else if(ocol.overlap(pls,pts,pw,ph, lx[5], ly[5], ocol.distx(lx[5],lx[6]), 2)&&!jump&&!rail) {
			grv=0;canjump = true;
		} else { if(!rslope && !jump&&!rail) { grv=2; }}
		// Right Slope Surface
		if(ocol.lineLine(prs,pts,prs,pbs, lx[4], ly[4], lx[5], ly[5])) {
			rslope=true;canjump = true;
		} else { rslope = false; }
		if(rslope&&!jump&&!rail) { grv=0; }
		// Left Slope Surface
		if(ocol.lineLine(prs,pts,prs,pbs, lx[7], ly[7], lx[8], ly[8])) {
			lslope=true;canjump = true;
		} else { lslope = false; }
		if(lslope&&!jump&&!rail) { grv=0; }
		// ----------------------------------------------------
		// Position Update
		// ----------------------------------------------------
		py += grv;
		aroha.set_position(px,py-12);
		// ----------------------------------------------------
		// Brightness Update
		// ----------------------------------------------------
		bn::fixed brightness = bn::bg_palettes::brightness();
		if(bn::keypad::l_held()) { bn::bg_palettes::set_brightness(bn::max(brightness - 0.01, bn::fixed(0))); }
        else if(bn::keypad::r_held()) { bn::bg_palettes::set_brightness(bn::min(brightness + 0.01, bn::fixed(1))); }
		// ----------------------------------------------------
		bn::core::update();
	}
}

void a1s3() {
	// Variables List
	// ----------------------------------------------------
	px = -100; py = ly[9]-3; rslope=true; lslope=false; //bn::music::pause();
	int frame=1; int count=0;
	// Sprites List
	// ----------------------------------------------------
	bn::regular_bg_ptr lv3_e1 = bn::regular_bg_items::e5_1.create_bg(0,0);
	bn::regular_bg_ptr lv3_e2 = bn::regular_bg_items::e5_2.create_bg(0,0);
	bn::sprite_ptr aroha = bn::sprite_items::aroha.create_sprite(px, py);
	// ----------------------------------------------------
	// Z-Axis Configure
	// ----------------------------------------------------
	aroha.put_above();
	// ----------------------------------------------------
	// Update Until -> PX = UH
	// ----------------------------------------------------
	while(!ocol.overlap(px-(pw/2),py-(ph/2),pw,ph,lwx+120,lwy,120,1)) {
		count++;
		if(frame==1&&count>30){frame=2;count=0;}
		if(frame==2&&count>30){frame=1;count=0;}
		//if(frame==3&&count>30){frame=1;count=0;}
		if(frame==1){lv3_e2.put_above();}
		if(frame==2){lv3_e1.put_above();}
		// Collision Variables
		int pls = px-(pw/2); int prs = px+(pw/2); 
		int pts = py-(ph/2); int pbs = py+(ph/2);
		// ----------------------------------------------------
		// Player Input
		// ----------------------------------------------------
		if(bn::keypad::left_held() && !ocol.overlap(
			pls,pts,pw,ph,lwx,lwy,lww,lwh)
			&& !ocol.overlap(pls,pts,pw,ph, lx[10]-4, ly[10], 4, 200)) { 
			px-=1; aroha.set_horizontal_flip(true);
			if(rslope) { py-=1; }
			// Player Walking Animation
				if(canjump){
				if(pa<18){pt++;}
				if(pt>2) {pa++;pt=0;}
				if(pa==17){pa=0;}
				aroha.set_tiles(bn::sprite_items::aroha.tiles_item().create_tiles(pa));
			}
		}
		if(bn::keypad::right_held() &&
			  (!ocol.overlap(pls,pts,pw,ph,rwx,rwy,rww,rwh))) { 
			px+=1; aroha.set_horizontal_flip(false); 
			if(lslope) { py-=2; }
			// Player Walking Animation
			if(canjump){
				if(pa<18) { paa++;}
				if(paa>2) { pa++; paa=0;}
				if(pa==17){ pa=0;}
				aroha.set_tiles(bn::sprite_items::aroha.tiles_item().create_tiles(pa));
			}
		}
		if(bn::keypad::a_pressed() && !rail && canjump) { 
			jump = true; 
			pt=0; 
			pa=18; 
			bn::sound_items::c5piano.play(0.4); 
		}
		if(bn::keypad::b_pressed()) { rail=true; pa = 36; bn::sound_items::c5piano.play(0.4);}
		if(pa == 53) { pa = 0; }
		// ----------------------------------------------------
		// Gravity Check
		// ----------------------------------------------------
		if(jump) {
			canjump = false;
			grv = -2;
			pt++;
			jumpanim = true;
			if(pt>20) { jump = false; pt=0;}
		}
		if(jumpanim) {
			if(pa>17&&pa<35){paa++;}
			if(paa>2) { pa++; paa=0;}
			if(pa==35){ jumpanim = false;pa=0;}
			aroha.set_tiles(bn::sprite_items::aroha.tiles_item().create_tiles(pa));
		}
		// ----------------------------------------------------
		// Collision
		// ----------------------------------------------------
		// Right Slope Surface
		if(ocol.lineLine(prs,pts,prs,pbs, lx[9], ly[9], lx[10], ly[10])
		|| ocol.lineLine(prs,pts,prs,pbs, lx[11], ly[11], lx[12], ly[12])) {
			rslope=true;canjump = true;
		} else { rslope = false; }
		if(rslope&&!jump&&!rail) { grv=0; }
		// Left Slope Surface
		if(ocol.lineLine(prs,pts,prs,pbs, lx[12], ly[12], lx[13], ly[13])
		|| ocol.lineLine(prs,pts,prs,pbs, lx[13], ly[13], lx[14], ly[14])) {
			lslope=true;canjump = true;
		} else { lslope = false; }
		if(lslope&&!jump&&!rail) { grv=0; }
		if(!lslope && !rslope && !jump && !rail) { grv=2; }
		if(ocol.overlap(px-(pw/2),py-(ph/2),pw,ph,lwx,80,240,1)) { 
			px = -100; py = ly[9]-3; rslope=true; lslope=false;
		}
		// ----------------------------------------------------
		// Position Update
		// ----------------------------------------------------
		py += grv;
		aroha.set_position(px,py-12);
		// ----------------------------------------------------
		// Brightness Update
		// ----------------------------------------------------
		bn::fixed brightness = bn::bg_palettes::brightness();
		if(bn::keypad::l_held()) { bn::bg_palettes::set_brightness(bn::max(brightness - 0.01, bn::fixed(0))); }
        else if(bn::keypad::r_held()) { bn::bg_palettes::set_brightness(bn::min(brightness + 0.01, bn::fixed(1))); }
		// ----------------------------------------------------
		bn::core::update();
	}
}

void a1s4() {
	// Variables List
	// ----------------------------------------------------
	int lx18 = 70; int ly18 = 80; int lx19 = 232-120; int ly19 = 126-80;
	px = lx18+10; py = ly18-10; rslope=true; lslope=false; bn::music::pause();
	int frame=1; int count=0;
	// Sprites List
	// ----------------------------------------------------
	bn::regular_bg_ptr lv3_e1 = bn::regular_bg_items::d5_1.create_bg(0,0);
	bn::regular_bg_ptr lv3_e2 = bn::regular_bg_items::d5_2.create_bg(0,0);
	bn::sprite_ptr aroha = bn::sprite_items::aroha.create_sprite(px, py);
	// ----------------------------------------------------
	// Z-Axis Configure
	// ----------------------------------------------------
	aroha.put_above();
	// ----------------------------------------------------
	// Update Until -> PX = UH
	// ----------------------------------------------------
	while(!ocol.overlap(px-(pw/2),py-(ph/2),pw,ph,lwx,lwy,1,160)) {
		count++;
		if(frame==1&&count>30){frame=2;count=0;}
		if(frame==2&&count>30){frame=1;count=0;}
		//if(frame==3&&count>30){frame=1;count=0;}
		if(frame==1){lv3_e2.put_above();}
		if(frame==2){lv3_e1.put_above();}
		// Collision Variables
		int pls = px-(pw/2); int prs = px+(pw/2); 
		int pts = py-(ph/2); int pbs = py+(ph/2);
		// ----------------------------------------------------
		// Player Input
		// ----------------------------------------------------
		if(bn::keypad::left_held() && !ocol.overlap(
			pls,pts,pw,ph,lwx,lwy,lww,lwh)) { 
			px-=1; aroha.set_horizontal_flip(true);
			if(rslope) { py-=1; }
			// Player Walking Animation
				if(canjump){
				if(pa<18){pt++;}
				if(pt>2) {pa++;pt=0;}
				if(pa==17){pa=0;}
				aroha.set_tiles(bn::sprite_items::aroha.tiles_item().create_tiles(pa));
			}
		}
		if(bn::keypad::right_held() &&
			  (!ocol.overlap(pls,pts,pw,ph,rwx-10,rwy,rww,rwh))) { 
			px+=1; aroha.set_horizontal_flip(false); 
			if(lslope) { py-=2; }
			// Player Walking Animation
			if(canjump){
				if(pa<18) { paa++;}
				if(paa>2) { pa++; paa=0;}
				if(pa==17){ pa=0;}
				aroha.set_tiles(bn::sprite_items::aroha.tiles_item().create_tiles(pa));
			}
		}
		if(bn::keypad::a_pressed() && !rail && canjump) { 
			jump = true; 
			pt=0; 
			pa=18; 
			bn::sound_items::c5piano.play(0.4); 
		}
		if(pa == 53) { pa = 0; }
		// ----------------------------------------------------
		// Gravity Check
		// ----------------------------------------------------
		if(jump) {
			canjump = false;
			grv = -2;
			pt++;
			jumpanim = true;
			if(pt>20) { jump = false; pt=0;}
		}
		if(jumpanim) {
			if(pa>17&&pa<35){paa++;}
			if(paa>2) { pa++; paa=0;}
			if(pa==35){ jumpanim = false;pa=0;}
			aroha.set_tiles(bn::sprite_items::aroha.tiles_item().create_tiles(pa));
		}
		// ----------------------------------------------------
		// Collision
		// ----------------------------------------------------
		// Flat Surface
		if(ocol.overlap(pls,pts,pw,ph, lx[16], ly[16], ocol.distx(lx[16],lx[15]), 2)&&!jump&&!rail) {
			grv=0;canjump = true;
		} else { if(!rslope && !lslope && !jump && !rail) { grv=2; }}
		// Right Slope Surface
		if(ocol.lineLine(prs,pts,prs,pbs, lx[17], ly[17], lx[16], ly[16])) {
			rslope=true;canjump = true;
		} else { rslope = false; }
		if(rslope&&!jump&&!rail) { grv=0; }
		// Left Slope Surface
		if(ocol.lineLine(prs,pts,prs,pbs, lx18, ly18, lx19, ly19)) {
			lslope=true;canjump = true;
		} else { lslope = false; }
		if(lslope&&!jump&&!rail) { grv=0; }
		// Fall under level
		if(ocol.overlap(px-(pw/2),py-(ph/2),pw,ph,lwx,80,240,1)) { 
			px = lx18+10; py = ly18-30;
		}
		// ----------------------------------------------------
		// Position Update
		// ----------------------------------------------------
		py += grv;
		aroha.set_position(px,py-12);
		// ----------------------------------------------------
		// Brightness Update
		// ----------------------------------------------------
		bn::fixed brightness = bn::bg_palettes::brightness();
		if(bn::keypad::l_held()) { bn::bg_palettes::set_brightness(bn::max(brightness - 0.01, bn::fixed(0))); }
        else if(bn::keypad::r_held()) { bn::bg_palettes::set_brightness(bn::min(brightness + 0.01, bn::fixed(1))); }
		// ----------------------------------------------------
		bn::core::update();
	}
}

void a1s5() {
	// Variables List
	// ----------------------------------------------------
	px = lx[18]; py = ly[18]-10; rslope=false; lslope=false; //bn::music::pause();
	int frame=1; int count=0;
	// Sprites List
	// ----------------------------------------------------
	bn::regular_bg_ptr lv3_e1 = bn::regular_bg_items::d4_1.create_bg(0,0);
	bn::regular_bg_ptr lv3_e2 = bn::regular_bg_items::d4_2.create_bg(0,0);
	bn::sprite_ptr aroha = bn::sprite_items::aroha.create_sprite(px, py);
	// ----------------------------------------------------
	// Z-Axis Configure
	// ----------------------------------------------------
	aroha.put_above();
	// ----------------------------------------------------
	// Update Until -> PX = UH
	// ----------------------------------------------------
	while(!ocol.overlap(px-(pw/2),py-(ph/2),pw,ph,lwx,lwy,1,160)) {
		count++;
		if(frame==1&&count>30){frame=2;count=0;}
		if(frame==2&&count>30){frame=1;count=0;}
		//if(frame==3&&count>30){frame=1;count=0;}
		if(frame==1){lv3_e2.put_above();}
		if(frame==2){lv3_e1.put_above();}
		// Collision Variables
		int pls = px-(pw/2); //int prs = px+(pw/2); 
		int pts = py-(ph/2); //int pbs = py+(ph/2);
		// ----------------------------------------------------
		// Player Input
		// ----------------------------------------------------
		if(bn::keypad::left_held() && !ocol.overlap(
			pls,pts,pw,ph,lwx,lwy,lww,lwh)) { 
			px-=1; aroha.set_horizontal_flip(true);
			if(rslope) { py-=1; }
			// Player Walking Animation
				if(canjump){
				if(pa<18){pt++;}
				if(pt>2) {pa++;pt=0;}
				if(pa==17){pa=0;}
				aroha.set_tiles(bn::sprite_items::aroha.tiles_item().create_tiles(pa));
			}
		}
		if(bn::keypad::right_held() &&
			  (!ocol.overlap(pls,pts,pw,ph,rwx,rwy,rww,rwh))) { 
			px+=1; aroha.set_horizontal_flip(false); 
			if(lslope) { py-=2; }
			// Player Walking Animation
			if(canjump){
				if(pa<18) { paa++;}
				if(paa>2) { pa++; paa=0;}
				if(pa==17){ pa=0;}
				aroha.set_tiles(bn::sprite_items::aroha.tiles_item().create_tiles(pa));
			}
		}
		if(bn::keypad::a_pressed() && !rail && canjump) { 
			jump = true; 
			pt=0; 
			pa=18; 
			bn::sound_items::c5piano.play(0.4); 
		}
		if(pa == 53) { pa = 0; }
		// ----------------------------------------------------
		// Gravity Check
		// ----------------------------------------------------
		if(jump) {
			if(bn::keypad::left_held() && px<lx[19]+5 && px>lx[20]-15) { px-=4; }
			if(bn::keypad::right_held() && px<lx[19]+15 && px>lx[20]-5) { px+=4; }
			canjump = false;
			grv = -2;
			pt++;
			jumpanim = true;
			if(pt>20) { jump = false; pt=0;}
		}
		if(jumpanim) {
			if(pa>17&&pa<35){paa++;}
			if(paa>2) { pa++; paa=0;}
			if(pa==35){ jumpanim = false;pa=0;}
			aroha.set_tiles(bn::sprite_items::aroha.tiles_item().create_tiles(pa));
		}
		// ----------------------------------------------------
		// Collision
		// ----------------------------------------------------
		// Flat Surface
		if((ocol.overlap(pls,pts,pw,ph, lx[19], ly[19], ocol.distx(lx[18],lx[19]), 2)
		||  ocol.overlap(pls,pts,pw,ph, lx[21], ly[21], ocol.distx(lx[20],lx[21]), 2))&&!jump) {
			grv=0;canjump = true;
		} else { if(!rslope && !lslope && !jump && !rail) { grv=2; }}
		// Fall under level
		if(ocol.overlap(px-(pw/2),py-(ph/2),pw,ph,lwx-40,80,320,1)) { 
			px = lx[18]; py = ly[18]-10;
		}
		// ----------------------------------------------------
		// Position Update
		// ----------------------------------------------------
		py += grv;
		aroha.set_position(px,py-12);
		// ----------------------------------------------------
		// Brightness Update
		// ----------------------------------------------------
		bn::fixed brightness = bn::bg_palettes::brightness();
		if(bn::keypad::l_held()) { bn::bg_palettes::set_brightness(bn::max(brightness - 0.01, bn::fixed(0))); }
        else if(bn::keypad::r_held()) { bn::bg_palettes::set_brightness(bn::min(brightness + 0.01, bn::fixed(1))); }
		// ----------------------------------------------------
		bn::core::update();
	}
}

void a1s6() {
	// Variables List
	// ----------------------------------------------------
	px = lx[22]-2; py = ly[22]-20; rslope=false; lslope=false; //bn::music::pause();
	int frame=1; int count=0;
	// Sprites List
	// ----------------------------------------------------
	bn::regular_bg_ptr lv3_e1 = bn::regular_bg_items::d3_1.create_bg(0,0);
	bn::regular_bg_ptr lv3_e2 = bn::regular_bg_items::d3_2.create_bg(0,0);
	bn::sprite_ptr aroha = bn::sprite_items::aroha.create_sprite(px, py);
	// ----------------------------------------------------
	// Z-Axis Configure
	// ----------------------------------------------------
	aroha.put_above();
	// ----------------------------------------------------
	// Update Until -> PX = UH
	// ----------------------------------------------------
	while(!ocol.overlap(px-(pw/2),py-(ph/2),pw,ph,lx[27],lwy,ocol.distx(lx[27],lx[28]),1)) {
		count++;
		if(frame==1&&count>30){frame=2;count=0;}
		if(frame==2&&count>30){frame=1;count=0;}
		//if(frame==3&&count>30){frame=1;count=0;}
		if(frame==1){lv3_e2.put_above();}
		if(frame==2){lv3_e1.put_above();}
		// Collision Variables
		int pls = px-(pw/2); int prs = px+(pw/2); 
		int pts = py-(ph/2); int pbs = py+(ph/2);
		// ----------------------------------------------------
		// Player Input
		// ----------------------------------------------------
		if(bn::keypad::left_held() && !ocol.overlap(
			pls,pts,pw,ph,lx[26],lwy,lww,lwh)) { 
			px-=1; aroha.set_horizontal_flip(true);
			if(rslope) { py-=1; }
			// Player Walking Animation
				if(canjump){
				if(pa<18){pt++;}
				if(pt>2) {pa++;pt=0;}
				if(pa==17){pa=0;}
				aroha.set_tiles(bn::sprite_items::aroha.tiles_item().create_tiles(pa));
			}
		}
		if(bn::keypad::right_held() &&
			  (!ocol.overlap(pls,pts,pw,ph,rwx,rwy,rww,rwh)
			&& !ocol.overlap(pls,pts,pw,ph, lx[28]-2, rwy, 1, ocol.distx(lx[28],lwy)))) { 
			px+=1; aroha.set_horizontal_flip(false);
			if(lslope) { py-=2; }
			// Player Walking Animation
			if(canjump){
				if(pa<18) { paa++;}
				if(paa>2) { pa++; paa=0;}
				if(pa==17){ pa=0;}
				aroha.set_tiles(bn::sprite_items::aroha.tiles_item().create_tiles(pa));
			}
		}
		if(bn::keypad::a_pressed() && !rail && canjump) { 
			jump = true; 
			pt=0; 
			pa=18; 
			bn::sound_items::c5piano.play(0.4); 
		}
		if(bn::keypad::b_pressed()) { rail=true; pa = 36; bn::sound_items::c5piano.play(0.4);}
		if(pa == 53) { pa = 0; }
		// ----------------------------------------------------
		// Gravity Check
		// ----------------------------------------------------
		if(jump) {
			canjump = false;
			grv = -2;
			if(bn::keypad::left_held() && px<lx[23]+5 && px>lx[24]-15) { px-=2; }
			if(bn::keypad::right_held() && px<lx[23]+15 && px>lx[24]-5) { px+=2; }
			pt++;
			jumpanim = true;
			if(pt>20) { jump = false; pt=0;}
		}
		if(jumpanim) {
			if(pa>17&&pa<35){paa++;}
			if(paa>2) { pa++; paa=0;}
			if(pa==35){ jumpanim = false;pa=0;}
			aroha.set_tiles(bn::sprite_items::aroha.tiles_item().create_tiles(pa));
		}
		if(rail) {
			if(ocol.overlap(pls-4,pts,pw+8,ph, lx[26], ly[26]-10, 1, 200)) {
				grv = -4;
				pa++;		
				if(ocol.overlap(pls-4,pts,pw+8,ph, lx[7], ly[7], 1, 1)){py = py - 20;}
			} else {
				rail = false;
				pa = 0;
			}
			aroha.set_tiles(bn::sprite_items::aroha.tiles_item().create_tiles(pa));
		}
		// ----------------------------------------------------
		// Collision
		// ----------------------------------------------------
		// Flat Surface
		if((ocol.overlap(pls,pts,pw,ph, lx[23], ly[23], ocol.distx(lx[22],lx[23]), 2)
		||  ocol.overlap(pls,pts,pw,ph, lx[25], ly[25], ocol.distx(lx[24],lx[25]), 2))&&!jump&&!rail) {
			grv=0;canjump = true;
		} else { if(!lslope && !jump && !rail) { grv=2; }}
		// Left Slope Surface
		if(ocol.lineLine(prs,pts,prs,pbs, lx[28], ly[28], lx[27], ly[27])) {
			lslope=true;canjump = true;
		} else { lslope = false; }
		if(lslope&&!jump&&!rail) { grv=0; }
		// Fall under level
		if(ocol.overlap(px-(pw/2),py-(ph/2),pw,ph,lwx,80,240,1)) { 
			px = lx[22]-2; py = ly[22]-40;
		}
		// ----------------------------------------------------
		// Position Update
		// ----------------------------------------------------
		py += grv;
		aroha.set_position(px,py-12);
		// ----------------------------------------------------
		// Brightness Update
		// ----------------------------------------------------
		bn::fixed brightness = bn::bg_palettes::brightness();
		if(bn::keypad::l_held()) { bn::bg_palettes::set_brightness(bn::max(brightness - 0.01, bn::fixed(0))); }
        else if(bn::keypad::r_held()) { bn::bg_palettes::set_brightness(bn::min(brightness + 0.01, bn::fixed(1))); }
		// ----------------------------------------------------
		bn::core::update();
	}
}

void a1s7() {
	// Variables List
	// ----------------------------------------------------
	px = lx[29]-5; py = ly[29]-10; rslope=false; lslope=false; //bn::music::pause();
	int frame=1; int count=0;
	// Sprites List
	// ----------------------------------------------------
	bn::regular_bg_ptr lv3_e1 = bn::regular_bg_items::c3_1.create_bg(0,0);
	bn::regular_bg_ptr lv3_e2 = bn::regular_bg_items::c3_2.create_bg(0,0);
	bn::sprite_ptr aroha = bn::sprite_items::aroha.create_sprite(px, py);
	// ----------------------------------------------------
	// Z-Axis Configure
	// ----------------------------------------------------
	aroha.put_above();
	// ----------------------------------------------------
	// Update Until -> PX = UH
	// ----------------------------------------------------
	while(!ocol.overlap(px-(pw/2),py-(ph/2),pw,ph,rwx,rwy,1,rwh)) {
		count++;
		if(frame==1&&count>30){frame=2;count=0;}
		if(frame==2&&count>30){frame=1;count=0;}
		//if(frame==3&&count>30){frame=1;count=0;}
		if(frame==1){lv3_e2.put_above();}
		if(frame==2){lv3_e1.put_above();}
		// Collision Variables
		int pls = px-(pw/2); //int prs = px+(pw/2); 
		int pts = py-(ph/2); //int pbs = py+(ph/2);
		// ----------------------------------------------------
		// Player Input
		// ----------------------------------------------------
		if(bn::keypad::left_held() && !ocol.overlap(
			pls,pts,pw,ph,lwx,lwy,lww,lwh)) { 
			px-=1; aroha.set_horizontal_flip(true);
			if(rslope) { py-=1; }
			// Player Walking Animation
				if(canjump){
				if(pa<18){pt++;}
				if(pt>2) {pa++;pt=0;}
				if(pa==17){pa=0;}
				aroha.set_tiles(bn::sprite_items::aroha.tiles_item().create_tiles(pa));
			}
		}
		if(bn::keypad::right_held() &&
			  (!ocol.overlap(pls,pts,pw,ph,rwx,rwy,rww,rwh)
			&& !ocol.overlap(pls,pts,pw,ph,lx[31],ly[31]+2,rww,ocol.distx(ly[30], ly[31])))) { 
			px+=1; aroha.set_horizontal_flip(false); 
			if(lslope) { py-=2; }
			// Player Walking Animation
			if(canjump){
				if(pa<18) { paa++;}
				if(paa>2) { pa++; paa=0;}
				if(pa==17){ pa=0;}
				aroha.set_tiles(bn::sprite_items::aroha.tiles_item().create_tiles(pa));
			}
		}
		if(bn::keypad::a_pressed() && !rail && canjump) { 
			jump = true; 
			pt=0; 
			pa=18; 
			bn::sound_items::c5piano.play(0.4); 
		}
		if(bn::keypad::b_pressed()) { rail=true; pa = 36; bn::sound_items::c5piano.play(0.4);}
		if(pa == 53) { pa = 0; }
		// ----------------------------------------------------
		// Gravity Check
		// ----------------------------------------------------
		if(jump) {
			canjump = false;
			grv = -2;
			pt++;
			jumpanim = true;
			if(pt>20) { jump = false; pt=0;}
		}
		if(jumpanim) {
			if(pa>17&&pa<35){paa++;}
			if(paa>2) { pa++; paa=0;}
			if(pa==35){ jumpanim = false;pa=0;}
			aroha.set_tiles(bn::sprite_items::aroha.tiles_item().create_tiles(pa));
		}
		if(rail) {
			if(ocol.overlap(pls-4,pts,pw+8,ph, lx[31],ly[31]+2,rww,ocol.distx(ly[30], ly[31]))) {
				grv = -4;
				pa++;		
				if(ocol.overlap(pls-4,pts,pw+8,ph, lx[7], ly[7], 1, 1)){py = py - 20;}
			} else {
				rail = false;
				pa = 0;
			}
			aroha.set_tiles(bn::sprite_items::aroha.tiles_item().create_tiles(pa));
		}
		// ----------------------------------------------------
		// Collision
		// ----------------------------------------------------
		// Flat Surface
		if((ocol.overlap(pls,pts,pw,ph, lx[29], ly[29], ocol.distx(lx[30],lx[29]), 2)
		||  ocol.overlap(pls,pts,pw,ph, lx[31], ly[31], ocol.distx(lx[32],lx[31]), 2))&&!jump) {
			grv=0;canjump = true;
		} else { if(!rslope && !lslope && !jump && !rail) { grv=2; }}
		// Fall under level
		if(ocol.overlap(px-(pw/2),py-(ph/2),pw,ph,lwx-40,80,320,1)) { 
			px = lx[29]+8; py = ly[29]-12;
		}
		// ----------------------------------------------------
		// Position Update
		// ----------------------------------------------------
		py += grv;
		aroha.set_position(px,py-12);
		// ----------------------------------------------------
		// Brightness Update
		// ----------------------------------------------------
		bn::fixed brightness = bn::bg_palettes::brightness();
		if(bn::keypad::l_held()) { bn::bg_palettes::set_brightness(bn::max(brightness - 0.01, bn::fixed(0))); }
        else if(bn::keypad::r_held()) { bn::bg_palettes::set_brightness(bn::min(brightness + 0.01, bn::fixed(1))); }
		// ----------------------------------------------------
		bn::core::update();
	}
}

void a1s8() {
	// Variables List
	// ----------------------------------------------------
	px = -110; py = ly[33]-10;
	int frame=1; int count=0;
	// Sprites List
	// ----------------------------------------------------
	bn::regular_bg_ptr lv3_e1 = bn::regular_bg_items::c5_1.create_bg(0,0);
	bn::regular_bg_ptr lv3_e2 = bn::regular_bg_items::c5_2.create_bg(0,0);
	bn::sprite_ptr aroha = bn::sprite_items::aroha.create_sprite(px, py);
	// ----------------------------------------------------
	// Z-Axis Configure
	// ----------------------------------------------------
	aroha.put_above();
	// ----------------------------------------------------
	// Update Until -> PX = UH
	// ----------------------------------------------------
	while(!ocol.overlap(px-(pw/2),py-(ph/2),pw,ph,lwx,80,240,1)) {
		count++;
		if(frame==1&&count>30){frame=2;count=0;}
		if(frame==2&&count>30){frame=1;count=0;}
		//if(frame==3&&count>30){frame=1;count=0;}
		if(frame==1){lv3_e2.put_above();}
		if(frame==2){lv3_e1.put_above();}
		//if(frame==3){lv3_e2.put_above();}
		// Collision Variables
		int pls = px-(pw/2); //int prs = px+(pw/2); 
		int pts = py-(ph/2); //int pbs = py+(ph/2);
		// ----------------------------------------------------
		// Player Input
		// ----------------------------------------------------
		if(bn::keypad::left_held() && !ocol.overlap(
			pls,pts,pw,ph,lwx,lwy,lww,lwh)) { 
			px-=1; aroha.set_horizontal_flip(true);
			// Player Walking Animation
				if(canjump){
				if(pa<18){pt++;}
				if(pt>2) {pa++;pt=0;}
				if(pa==17){pa=0;}
				aroha.set_tiles(bn::sprite_items::aroha.tiles_item().create_tiles(pa));
			}
		}
		if(bn::keypad::right_held() &&
			  (!ocol.overlap(pls,pts,pw,ph,rwx,rwy,rww,rwh))) { 
			px+=1; aroha.set_horizontal_flip(false); 
			// Player Walking Animation
			if(canjump){
				if(pa<18) { paa++;}
				if(paa>2) { pa++; paa=0;}
				if(pa==17){ pa=0;}
				aroha.set_tiles(bn::sprite_items::aroha.tiles_item().create_tiles(pa));
			}
		}
		if(bn::keypad::a_pressed() && !rail && canjump) { 
			jump = true; 
			pt=0; 
			pa=18; 
			bn::sound_items::c5piano.play(0.4); 
		}
		if(bn::keypad::b_pressed()) { rail=true; pa = 36; bn::sound_items::c5piano.play(0.4);}
		if(pa == 53) { pa = 0; }
		// ----------------------------------------------------
		// Gravity Check
		// ----------------------------------------------------
		if(jump) {
			canjump = false;
			grv = -2;
			pt++;
			jumpanim = true;
			if(pt>20) { jump = false; pt=0;}
		}
		if(jumpanim) {
			if(pa>17&&pa<35){paa++;}
			if(paa>2) { pa++; paa=0;}
			if(pa==35){ jumpanim = false;pa=0;}
			aroha.set_tiles(bn::sprite_items::aroha.tiles_item().create_tiles(pa));
		}
		// ----------------------------------------------------
		// Collision
		// ----------------------------------------------------
		// Flat Surface
		if(ocol.overlap(pls,pts,pw,ph, lx[33], ly[33], ocol.distx(lx[33],lx[34]), 2)&&!jump) {
			grv=0;canjump = true;
		} else { if(!lslope && !jump) { grv=2; }}
		// ----------------------------------------------------
		// Position Update
		// ----------------------------------------------------
		py += grv;
		aroha.set_position(px,py-12);
		// ----------------------------------------------------
		// Brightness Update
		// ----------------------------------------------------
		bn::fixed brightness = bn::bg_palettes::brightness();
		if(bn::keypad::l_held()) { bn::bg_palettes::set_brightness(bn::max(brightness - 0.01, bn::fixed(0))); }
        else if(bn::keypad::r_held()) { bn::bg_palettes::set_brightness(bn::min(brightness + 0.01, bn::fixed(1))); }
		// ----------------------------------------------------
		bn::core::update();
	}
}

int main() {
    bn::core::init();
    bn::bg_palettes::set_transparent_color(bn::color(0));
    bn::music_items::breeze.play(0.8);
    a1s1(); bn::core::update();
    a1s2(); bn::core::update();
    a1s3(); bn::core::update();
    a1s4(); bn::core::update();
    a1s5(); bn::core::update();
    a1s6(); bn::core::update();
    a1s7(); bn::core::update();
    a1s8(); bn::core::update();
}
