// Code oil 


int touch_left = 0x11;
int touch_right = 0x10;

DeclareTask(task_bump_right);
DeclareTask(task_bump_left);
DeclareTask(task_bump_both);


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

TASK task_bump_both {
        PRIORITY = 1;
        AUTOSTART = FALSE;
        ACTIVATION = 1;
        SCHEDULE = FULL;
};

// Code C

int touch_left = 0x11;
int touch_right = 0x10;

DeclareTask(task_bump_right);
DeclareTask(task_bump_left);
DeclareTask(task_bump_both);

TASK(task_bump_right)
{
    turn_left(100);
    ChainTask(taskmain);
    TerminateTask();
}

TASK(task_bump_left)
{
  turn_right(100);
  ChainTask(taskmain);
  TerminateTask();
}


TASK(task_bump_both)
{
  go_back(150);
  turn_right(100);
  ChainTask(taskmain);
  TerminateTask();
}







