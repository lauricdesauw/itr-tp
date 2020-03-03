#include "tpl_os.h"
#include "nxt_motors.h"
#include "ecrobot_interface.h" 
#include "ecrobot_private.h"

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

  nxt_motor_set_speed(NXT_PORT_C,100,0);
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