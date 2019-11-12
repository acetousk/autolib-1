#pragma once

#include "okapi/api.hpp"
#include "autolib/auton/auton.hpp"

namespace autolib{

using namespace okapi;

class Selector{
    public:
    Selector( const Auton &iauton, lv_obj_t * iparent = lv_scr_act() );

    void init( int maxButtonsPerLine = 4 );

    private:
    friend class Auton;
    const Auton auton;

    lv_obj_t * parent;
    lv_btnm_t buttons;

    static const char * __get_btnm_map( const Auton &iauton );
    static lv_res_t __btnm_action(lv_obj_t * btnm, const char * txt);
};

}//autolib
