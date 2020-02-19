#include "tpl_os.h"
#include "nxt_motors.h"
#include "ecrobot_interface.h" 
#include "ecrobot_private.h"
#include "display.h"

int gauche = 0x00;
int droite = 0x01;

U8 sensor = NXT_PORT_S2;

DeclareTask(activate_sonar);
DeclareTask(get_sonar);

TASK(activate_sonar)
{
    display_clear(1);
    ecrobot_init_sonar_sensor(sensor);
    println("Sensor activated");
    display_update();
    ActivateTask(get_sonar);
    TerminateTask();
}

TASK(get_sonar) //manually
{
    WaitEvent(droite);
    display_clear(1);
    int value = ecrobot_get_sonar_sensor(sensor);
    char* oui = "%";
    println("Mesure de distance : ");
    print(&oui, 1, &value);
    display_update();
    ChainTask(get_sonar);
    TerminateTask();
}

ISR(isr_button_right)
{
    SetEvent(get_sonar, droite);

}

/*
TASK activate_sonar {
        PRIORITY = 1;
        AUTOSTART = TRUE { APPMODE = std; };
        ACTIVATION = 1;
        SCHEDULE = FULL;
    };   
    
    TASK get_sonar {
        PRIORITY = 1;
        AUTOSTART = FALSE;
        ACTIVATION = 1;
        SCHEDULE = FULL;
        EVENT = droite;
    };   

    EVENT droite {
        MASK = 0x01;
    };
*/