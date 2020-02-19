// Code oil 
TASK task_bump_right {
        PRIORITY = 1;
        AUTOSTART = FALSE;
        ACTIVATION = 1;
        SCHEDULE = FULL;
        EVENT = touch_right;
};

TASK task_bump_left {
        PRIORITY = 1;
        AUTOSTART = FALSE;
        ACTIVATION = 1;
        SCHEDULE = FULL;
        EVENT = touch_left;
};

EVENT touch_right {
      MASK = 0x10;
};

EVENT touch_left {
      MASK = 0x11;
};


// Code C
TASK(task_bump_right)
{
    WaitEvent(touch_right);
    turn_left(20);
    ChainTask(taskmain);
    TerminateTask();
}

TASK(task_bump_left)
{
  WaitEvent(touch_left);
  turn_right(20);
  ChainTask(taskmain);
  TerminateTask();
}


