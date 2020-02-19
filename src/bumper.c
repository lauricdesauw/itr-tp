// Code oil 


int touch_left = 0x11;
int touch_right = 0x10;

DeclareTask(task_bump_right);
DeclareTask(task_bump_left);



TASK task_bump_right {
        PRIORITY = 1;
        AUTOSTART = FALSE;
        ACTIVATION = 1;
        SCHEDULE = FULL;
};

TASK task_bump_left {
        PRIORITY = 1;
        AUTOSTART = FALSE;
        ACTIVATION = 1;
        SCHEDULE = FULL;
};


// Code C
TASK(task_bump_right)
{
    turn_left(40);
    ChainTask(taskmain);
    TerminateTask();
}

TASK(task_bump_left)
{
  turn_right(40);
  ChainTask(taskmain);
  TerminateTask();
}







