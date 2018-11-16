#include "main.h"
#include "functions.h"


void initialize() {
	lv_obj_t * scr = lv_obj_create(NULL, NULL);
	lv_scr_load(scr);
	lv_obj_t * btn1 = lv_btn_create(scr, NULL);
	lv_obj_set_size(btn1, 150, 100);

	lv_obj_t * label1 = lv_label_create(btn1, NULL);
	lv_label_set_text(label1, "Left");
	lv_label_set_style(label1, & lv_style_plain_color);
}

void disabled() {

}

void competition_initialize() {

}
