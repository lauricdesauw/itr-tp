/**
 * @file tp1.c
 *
 * @section desc File description
 *
 *
 * @section copyright Copyright
 *
 *
 * @section infos File informations
 *
 * $Date$ mar. janv. 28 10:27:31 CET 2020
 * $Rev$
 * $Author$ alamdasni
 * $URL$ /private/student/i/ni/alamdasni/Bureau/itr/tp1
 */

#include "tpl_os.h"
#include "nxt_motors.h"
#include "ecrobot_interface.h" 
#include "ecrobot_private.h"

FUNC(int, OS_APPL_CODE) main(void)
{   
    StartOS(OSDEFAULTAPPMODE);
    ShutdownOS(E_OK);
    return 0;
}
DeclareTask(task1);
DeclareTask(task0);
DeclareTask(task2);
DeclareTask(task3);

int haut = 0x00;
int droite = 0x01;
int bas = 0x02;
int gauche = 0x03;

TASK (task0) {
	TaskType id ; 
	GetTaskID(&id) ; 
	display_goto_xy(0, 1);
	display_string("Task");
	display_int(id,1) ;
	display_string (":Hello\n World\n" ) ; 
	ActivateTask( task1 ) ;
	TerminateTask();
}


void PreTaskHook()
{
	
	
}

void PostTaskHook ()  {

	
}

TASK(task1)
{
   
   int time = systick_get_ms() ;
   
   display_int(time,4) ; 
   display_string("ms") ;
   display_update();
   ActivateTask(task2);
   TerminateTask(); 
    
  
} 

int i = 0;
TASK(task2)
{
	WaitEvent(droite);
	display_clear(1);
	display_goto_xy(0, 0);
	display_string("task 2 on event");
	if (i != 0)
	{
		display_goto_xy(0,1);
		display_int(i, 3);
		display_update();
	}
	i++;
	ActivateTask(task3);
	TerminateTask();
}

TASK(task3)
{
	ActivateTask(task2);
	TerminateTask();
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
	SetEvent(task3, gauche);
    //ecrobot_status_monitor("isr_button_left"); 

}

ISR(isr_button_right)
{
	SetEvent(task2, droite);
    //ecrobot_status_monitor("isr_button_right");   

}

/* End of file tp1.c */
