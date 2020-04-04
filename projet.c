/**
 * @file projet.c
 *
 * @section desc File description
 *
 *
 * @section copyright Copyright
 *
 *
 * @section infos File informations
 *
 * $Date$ mer. févr. 19 10:11:49 CET 2020
 * $Rev$
 * $Author$ 17002843
 * $URL$ /private/student/3/43/17002843/ITR/projet
 */

#include "tpl_os.h"
#include "nxt_motors.h"
#include "ecrobot_interface.h" 
#include "ecrobot_private.h"
#include "motor.h"

int touch_left = 0x11;
int touch_right = 0x10;
int left = 0;
int right = 0;
U8 sonar_sensor = NXT_PORT_S2;
U8 left_bumper_sensor = NXT_PORT_S4;
U8 right_bumper_sensor = NXT_PORT_S1;


////////////////////////

int ABS(int a);

void turn_left(int degree);

void turn_right(int degree);

void go_front(int degree);

void go_back(int degree);

///////////////////////////


FUNC(int, OS_APPL_CODE) main(void)
{   
    StartOS(OSDEFAULTAPPMODE);
    ShutdownOS(E_OK);
    return 0;
}


DeclareTask(turn_right);
DeclareTask(turn_left);
DeclareTask(init);


DeclareTask(turn_back);
DeclareTask(check_sonar);
DeclareTask(checkBumpers);
DeclareTask(goForward);
DeclareTask(culDeSac);

TASK(init)
{
    ecrobot_init_sonar_sensor(sonar_sensor);
    TerminateTask();
}

TASK(goForward)
{
	go_front(30);
	TerminateTask();
}


TASK(checkBumpers)
{
	if (ecrobot_get_touch_sensor(right_bumper_sensor)) //droit
	{
		//Même si les deux touches, c'est pareil -> on tourne à droite, et si on peut pas y aller on fait un demi tour
		ActivateTask(turn_left);

	} else if (ecrobot_get_touch_sensor(left_bumper_sensor)) //gauche
	{
		ActivateTask(turn_right);
	}
	TerminateTask()
}

TASK(turn_right)
{
	turn_left(300);
	ChainTask(sonarcheck);
	TerminateTask();
}

TASK(turn_left)
{
	turn_right(300);
	ChainTask(sonarcheck);
	TerminateTask();
}


TASK(turn_back)
{
	go_back(100);
	turn_right(600);
	TerminateTask();
}

TASK(sonarcheck)
{	
	int value = ecrobot_get_sonar_sensor(sensor);
	if (value < 10)
	{ 
		ChainTask(turn_back);
		ChainTask(culDeSac);
	}
	TerminateTask();
}

TASK(culDeSac)
{
	int value = ecrobot_get_sonar_sensor(sensor);
	if (value < 10)
	{
		CancelAlarm(go_forward); // est-ce que c'est la bonne manière de cancelAlarm ?
		CancelAlarm(bumper_alarm);
		display_string("cul de sac");
		display_update();
	}
	TerminateTaskl
}



ISR(isr_button_start)
{
    ecrobot_status_monitor("isr_button_start");
    
}

ISR(isr_button_stop)
{
    ShutdownOS(E_OK);
}

ISR(isr_button_left)
{
    ecrobot_status_monitor("isr_button_left"); 

}

ISR(isr_button_right)
{
    SetEvent(get_sonar, droite);

}


/* End of file projet.c */
