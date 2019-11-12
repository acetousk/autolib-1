#include "autolib/auton/selector.hpp"

namespace autolib{

Selector::Selector( const std::shared_ptr<Auton> &iauton, lv_obj_t * iparent ):
        auton(iauton), parent(iparent){}

void Selector::init( int maxButtonsPerLine ){
    btnm_map = __get_btnm_map( maxButtonsPerLine );

    buttons = lv_btnm_create(parent, NULL);
    lv_btnm_set_map( buttons, &btnm_map );
    lv_btnm_set_action( buttons, __btnm_action );
}

void Selector::toggle( const std::string &istr ){
    const char * str = istr.c_str();
    int id = __string_to_id( str );
    int toggled = lv_btnm_get_toggled(buttons);
    if( toggled != id ){
        lv_btnm_set_toggle(buttons, false, toggled);
        lv_btnm_set_toggle(buttons, true, id);
    }else{
        printf("Selector toggle: istr already toggled.\n");
    }
}

int Selector::__string_to_id( const char * str ){
    int i = 0;
    for (auto &[key, value] : auton->routines) {
        i++;
        if( key.c_str() == str ){
            return i;    
        }
    }
    printf("Selector __string_to_id: string not found in map.\n");
}

const char * Selector::__id_to_string( const int &id ){
    int i = 0;
    for (auto &[key, value] : auton->routines) {
        i++;
        if( id == i ){
            return key.c_str();  
        }
    }
    printf("Selector __id_to_string: id not found in map.\n");
}

const char * Selector::__get_btnm_map( int maxButtonsPerLine ){
    std::string map;

    int i = 0;
    for (auto &[key, value] : auton->routines) {
        i++;
    }
    int cnt = i;
    int lineCnt = 0;
    i = 0;

    //*thanks theo @ 7842F
    for (auto &[key, value]: auton->routines) {
        i++;
        lineCnt++;
        if( lineCnt > maxButtonsPerLine ){
            lineCnt = 0;
            map.append(key);
            map.append( "\n" );
        }else if( i == cnt ){
            map.append(key);
            map.append( "" );
        }else{
            map.append(key);
        }
    }//*/

    auto out = map.c_str();
    printf("Selector __btnm_get_action: generated btnm map\n %s", out );

    return out;
}

lv_res_t Selector::__btnm_action(lv_obj_t * btnm, const char * txt ){

    return LV_RES_OK;
}

}//autolib
