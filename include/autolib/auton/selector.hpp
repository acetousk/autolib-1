#pragma once

#include "display/lvgl.h"
#include "okapi/api.hpp"
#include "autolib/auton/auton.hpp"

namespace autolib{

using namespace okapi;

class Selector{
    public:
    Selector( const std::shared_ptr<Auton> &iauton, lv_obj_t * iparent = lv_scr_act() );

    void init( int maxButtonsPerLine = 4 );
    void toggle( const std::string &istr );
    void run();

    private:
    const std::shared_ptr<Auton> auton;

    const char * btnm_map;    
    lv_obj_t * parent;
    lv_obj_t * buttons;

    int __string_to_id( const char * str );
    const char * __id_to_string( const int &id );

    const char * __get_btnm_map( int maxButtonsPerLine );

    static lv_res_t __btnm_action( lv_obj_t * btnm, const char * txt );
};

}//autolib
