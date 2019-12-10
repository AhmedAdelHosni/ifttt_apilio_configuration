#include "Defined_Types.h"

//u8 applet_is_sunset;  // To be handled in IFTTT by Weather Undergound applet
//u8 applet_is_sunrise; // To be handled in IFTTT by Weather Undergound applet

#define APPLET(name, room, action) room
#define NA 0

enum applets{
    WYZE,
    WEATHER_UNDERGOUNDS,
    GOOGLE_ASSISTANT,
    APILIO,
    SMART_LIFE
};

enum rooms {
    MASTER,
    DRESSING,
    LIVING
};

enum time_date{
    SUNSET,
    SUNRISE,
    TIME
};

enum applet_action {
    GET_MOTION,
    SET_LIGHT,
    GET_EVENT
};


/* ifttt events */
enum apilio_iftt_events {
    iftt_turn_on_living_light,
    iftt_turn_on_master_light,
    iftt_turn_on_dressing_light
};
/* End of ifttt events */


/* Apilio Variables */
bool_T enable_living_light_by_motion; // To be defined in Apilio as boolean
bool_T enable_master_light_by_motion; // To be defined in Apilio as boolean
bool_T enable_dressing_light_by_motion; // To be defined in Apilio as boolean
/* End of Apilio Variables */

/* * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * IFTTT applets * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * */

void IFTT_APP(void)
{
    if(APPLET(WEATHER_UNDERGOUNDS, NA, SUNSET) == TRUE) enable_living_light_by_motion = TRUE;
    if(APPLET(WEATHER_UNDERGOUNDS, NA, SUNSET) == TRUE) enable_master_light_by_motion = TRUE;
    if(APPLET(WEATHER_UNDERGOUNDS, NA, SUNSET) == TRUE) enable_dressing_light_by_motion = TRUE;

    if(APPLET(WEATHER_UNDERGOUNDS, NA, SUNRISE) == TRUE) enable_living_light_by_motion = FALSE;
    if(APPLET(WEATHER_UNDERGOUNDS, 12 /*AM */, TIME) == TRUE) enable_master_light_by_motion = FALSE;

    if(APPLET(WYZE, LIVING, GET_MOTION)   == TRUE) { /* apilio_living_light_by_motion_condition */   }
    if(APPLET(WYZE, MASTER, GET_MOTION)   == TRUE) { /* apilio_master_light_by_motion_condition */   }
    if(APPLET(WYZE, DRESSING, GET_MOTION) == TRUE) { /* apilio_dressing_light_by_motion_condition */ }
    
    if(APPLET(APILIO, iftt_turn_on_living_light, GET_EVENT) == TRUE) { APPLET(SMART_LIFE, LIVING, SET_LIGHT); }
    if(APPLET(APILIO, iftt_turn_on_master_light, GET_EVENT) == TRUE) { APPLET(SMART_LIFE, MASTER, SET_LIGHT); }
    if(APPLET(APILIO, iftt_turn_on_dressing_light, GET_EVENT) == TRUE) { APPLET(SMART_LIFE, DRESSING, SET_LIGHT); }


}

void APILIO_APP(void)
{
    if((enable_living_light_by_motion == TRUE)) // apilio_living_light_condition
    {
       // iftt_turn_on_living_light;
    }
    
    if((enable_living_light_by_motion == TRUE)) // apilio_living_light_condition
    {
       // iftt_turn_on_living_light;
    }
}


/* 
 if((APPLET(WYZE, LIVING)   == TRUE)) living_motion_status = TRUE;
    if((APPLET(WYZE, MASTER)   == TRUE)) living_motion_status = TRUE;
    if((APPLET(WYZE, DRESSING) == TRUE)) living_motion_status = TRUE;

    if((enable_living_light_by_motion == TRUE) && (living_motion_status == TRUE)) // living_light_condition
    {
        iftt_turn_on_living_light();
    }
    if((enable_master_light_by_motion == TRUE) && (living_motion_status == TRUE))
    {
        iftt_turn_on_master_light();
    }
    if((enable_dressing_light_by_motion == TRUE) && (living_motion_status == TRUE))
    {
        iftt_turn_on_dressing_light();
    }
    */
