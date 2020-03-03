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

int touch_left = 0x11;
int touch_right = 0x10;
int left = 0;
int right = 0;
U8 sensor = NXT_PORT_S2;

int println(char* str)
{
  static int c = 0;

  if (c == 0)
    {display_clear(1);}
    
  display_goto_xy(0,c);
  display_string(str[c]); 
  c++;

  if( c == 8)
    {c = 0;}

  return c; 
}


int nb_digit(int i)
{
  
  return 4;
}

void print(char** str, int nb, int* to_print)
{
  int c = 0, column = 0, int_count = 0, tmp = 0, line = 0;
  char curr_str[17];
  curr_str[16] = '\0';
  for(int i=0; i < nb; i++)
    {
      while(str[i][c] != '\0')
	{
	  
	  if(str[i][c] == '%')
	    {
	      
	      tmp = nb_digit(to_print[int_count]);
	      if (column + tmp > 15)
		{
		  
		  line = println(curr_str);
		  column = tmp;
		  line++; 
		}
	      else
		{
		  column += tmp;
		}
	      display_goto_xy(line, column);
	      display_int(to_print[int_count], tmp); 
	    }
	  else
	    {
	      curr_str[c] = str[i][c]; 
	    }


	  c++;
	  column++; 
	  if (column ==16)
	    {
	      line = println(curr_str);
	      column = 0;
	      line++; 
	    }

	  
	}
    }
}

////////////////////////

int ABS(int a)
{
  if(a > 0)
    return a;
  return -a;
}

void turn_left(int degree)
{
  // get the counts of the motor
  int left_motor_old = nxt_motor_get_count(NXT_PORT_C);
  int right_motor_old = nxt_motor_get_count(NXT_PORT_A);
  
  //set the speed in negative for the left wheel

  nxt_motor_set_speed(NXT_PORT_C,-100,0);
  nxt_motor_set_speed(NXT_PORT_A,100,0);


  int left_motor,right_motor;

  //set the speed positive for the right wheel
  do
    {
      left_motor = nxt_motor_get_count(NXT_PORT_C);
      right_motor = nxt_motor_get_count(NXT_PORT_A);
      
    }while( (ABS(left_motor_old - left_motor) < degree) & (ABS(right_motor_old - right_motor) < degree));
	    
  // when he have rotate enough, set the speed at 0 for both
  nxt_motor_set_speed(NXT_PORT_C,0,1);
  nxt_motor_set_speed(NXT_PORT_A,0,1);

}

void turn_right(int degree)
{
 // get the counts of the motor
  int left_motor_old = nxt_motor_get_count(NXT_PORT_C);
  int right_motor_old = nxt_motor_get_count(NXT_PORT_A);
  
  //set the speed in negative for the left wheel

  nxt_motor_set_speed(NXT_PORT_C,100,0);
  nxt_motor_set_speed(NXT_PORT_A,-100,0);


  int left_motor,right_motor;

  //set the speed positive for the right wheel
  do
    {
      left_motor = nxt_motor_get_count(NXT_PORT_C);
      right_motor = nxt_motor_get_count(NXT_PORT_A);
      
    }while( (ABS(left_motor_old - left_motor) < degree) & (ABS(right_motor_old - right_motor) < degree));
	    
  // when he have rotate enough, set the speed at 0 for both
  nxt_motor_set_speed(NXT_PORT_C,0,1);
  nxt_motor_set_speed(NXT_PORT_A,0,1);
}

void go_front(int degree)
{
   // get the counts of the motor
  int left_motor_old = nxt_motor_get_count(NXT_PORT_C);
  int right_motor_old = nxt_motor_get_count(NXT_PORT_A);
  
  //set the speed in negative for the left wheel

  nxt_motor_set_speed(NXT_PORT_C,80,0);
  nxt_motor_set_speed(NXT_PORT_A,80,0);


  int left_motor,right_motor;

  //set the speed positive for the right wheel
  do
    {
      left_motor = nxt_motor_get_count(NXT_PORT_C);
      right_motor = nxt_motor_get_count(NXT_PORT_A);
      
    }while( (ABS(left_motor_old - left_motor) < degree) & (ABS(right_motor_old - right_motor) < degree));
	    
  // when he have rotate enough, set the speed at 0 for both
  nxt_motor_set_speed(NXT_PORT_C,0,1);
  nxt_motor_set_speed(NXT_PORT_A,0,1);
  }

void go_back(int degree)
{
 // get the counts of the motor
  int left_motor_old = nxt_motor_get_count(NXT_PORT_C);
  int right_motor_old = nxt_motor_get_count(NXT_PORT_A);
  
  //set the speed in negative for the left wheel

  nxt_motor_set_speed(NXT_PORT_C,-100,0);
  nxt_motor_set_speed(NXT_PORT_A,-100,0);


  int left_motor,right_motor;

  //set the speed positive for the right wheel
  do
    {
      left_motor = nxt_motor_get_count(NXT_PORT_C);
      right_motor = nxt_motor_get_count(NXT_PORT_A);
      
    }while( (ABS(left_motor_old - left_motor) < degree) & (ABS(right_motor_old - right_motor) < degree));
	    
  // when he have rotate enough, set the speed at 0 for both
  nxt_motor_set_speed(NXT_PORT_C,0,1);
  nxt_motor_set_speed(NXT_PORT_A,0,1);
}

///////////////////////////


FUNC(int, OS_APPL_CODE) main(void)
{   
    StartOS(OSDEFAULTAPPMODE);
    ShutdownOS(E_OK);
    return 0;
}

int ABS(int a);
void turn_left(int degree);

DeclareTask(taskmain);

DeclareTask(task_bump_right);
DeclareTask(task_bump_left);
DeclareTask(task_bump_both);
DeclareTask(task_sonar);

DeclareTask(init);



int gauche = 0x00;
int droite = 0x01;

DeclareTask(activate_sonar);
DeclareTask(get_sonar);

TASK(init)
{
    display_clear(1);
    ecrobot_init_sonar_sensor(sensor);
    println("Sensor activated");
    display_update();
    ActivateTask(taskmain);
    TerminateTask();
}


TASK(taskmain)
{
  if (ecrobot_get_touch_sensor(NXT_PORT_S1)) //droit
  {
    if (ecrobot_get_touch_sensor(NXT_PORT_S4)) //gauche + droit
    {
      ActivateTask(task_bump_both);
    } else
    {
      ActivateTask(task_bump_right);
    }
    
  } else if (ecrobot_get_touch_sensor(NXT_PORT_S4)) //gauche
  {
    ActivateTask(task_bump_left);
  }

  int valueSonar = ecrobot_get_sonar_sensor(sensor);
  if (valueSonar < 10 && valueSonar > 0)
  {
    ActivateTask(task_sonar);
  }

  go_front(30);
  ChainTask(taskmain);
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


/* End of file projet.c */


TASK(task_bump_right)
{
    turn_left(300);
    right = 0;
    left = 1;
    ChainTask(taskmain);
    TerminateTask();
}

TASK(task_bump_left)
{
  turn_right(300);
  right = 1;
  left = 0;
  ChainTask(taskmain);
  TerminateTask();
}


TASK(task_bump_both)
{
  go_back(500);
  turn_right(300);

  right = 1;
  left = 0;
  //si mur encore tourner gauche sinon on fait demi-tour

  int value = ecrobot_get_sonar_sensor(sensor);
  if (value < 10)
  { 
    right = 0;
    left = 1;
    turn_left(600);
  }
  ChainTask(taskmain);
  TerminateTask();
}


TASK(task_sonar)
{
  go_back(500);
  turn_left(300);

  right = 1;
  left = 0;
  //si mur encore tourner gauche sinon on fait demi-tour

  for(int i = 0; i < 5; i++)
  {
    go_back(10);
    go_front(10);
  }

  int value = ecrobot_get_sonar_sensor(sensor);
  if (value < 10)
  { 
    right = 0;
    left = 1;
    turn_right(600);
  }
  ChainTask(taskmain);
  TerminateTask();
}
