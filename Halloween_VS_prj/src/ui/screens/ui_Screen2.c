// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: halloween

#include "../ui.h"

void ui_Screen2_screen_init(void)
{
ui_Screen2 = lv_obj_create(NULL);
lv_obj_clear_flag( ui_Screen2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Roller2 = lv_roller_create(ui_Screen2);
lv_roller_set_options( ui_Roller2, "Option 1\nOption 2\nOption 3", LV_ROLLER_MODE_NORMAL );
lv_obj_set_height( ui_Roller2, 100);
lv_obj_set_width( ui_Roller2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_align( ui_Roller2, LV_ALIGN_CENTER );


}