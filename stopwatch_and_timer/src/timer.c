#include <../include/program.h>

void timerCountdown(applicationManagement *process) {
  int hour = 0;
  int min = 0;
  int sec = 0;
  if (process->step == 4) {
    getTimeForTimerAndPause(process, &hour, &min, &sec);
    if (hour == 0 && min == 0 && sec == 0) {
      exitTimer(process);

      process->step = 0;
      pthread_t soundThread;
      pthread_create(&soundThread, NULL, playSoundThread, NULL);
      pthread_detach(soundThread);

    } else {
      printw("|          %02d:%02d:%02d          |\n", hour, min, sec);
    }
  }
  if (process->step == 5) {

    printw("|          %02d:%02d:%02d          |\n", process->pauseHour,
           process->pauseMin, process->pauseSec);
  }
}

void getTimeForTimerAndPause(applicationManagement *process, int *hour,
                             int *min, int *sec) {

  struct timespec now = {0};
  clock_gettime(CLOCK_MONOTONIC, &now);
  long timeNow = process->timerStart.tv_sec - now.tv_sec;
  *hour = timeNow / 3600;
  *min = (timeNow % 3600) / 60;
  *sec = timeNow % 60;
}

void timerSetup(applicationManagement *process) {
  process->step = 3;
  while (process->step == 3) {
    timerSecurity(process);
    int timerControl = getch();
    switch (timerControl) {
    case KEY_UP:
      processingKeyUp(process);
      break;
    case KEY_DOWN:
      processingKeyDown(process);
      break;
    case KEY_LEFT:
      processingKeyLeft(process);
      break;
    case KEY_RIGHT:
      processingKeyRight(process);
      break;
    case 's':
    case 'S':
      startTimer(process);
      break;
    case 'b':
    case 'B':
      exitTimer(process);
      break;
    default:
      break;
    }
  }
}


void exitTimer(applicationManagement *process) {
  process->timeAndComandInTimer.hour = 0;
  process->timeAndComandInTimer.min = 0;
  process->timeAndComandInTimer.sec = 0;
  process->timeAndComandInTimer.position = 0;
  process->timeAndComandInTimer.blinking = 0;

  process->timerStart.tv_sec = 0;
  process->timerStart.tv_nsec = 0;

  process->step = 0;
}


void timerSecurity(applicationManagement *process) {
  if (process->timeAndComandInTimer.hour > 0 ||
      process->timeAndComandInTimer.min > 0 ||
      process->timeAndComandInTimer.sec > 0) {
    process->checkTimer = 1;
  } else {
    process->checkTimer = 0;
  }
}


void processingKeyUp(applicationManagement *process) {
  if (process->timeAndComandInTimer.position == 0) {
    process->timeAndComandInTimer.hour =
        (process->timeAndComandInTimer.hour + 1) % 24;
  }
  if (process->timeAndComandInTimer.position == 1) {
    process->timeAndComandInTimer.min =
        (process->timeAndComandInTimer.min + 1) % 60;
  }
  if (process->timeAndComandInTimer.position == 2) {
    process->timeAndComandInTimer.sec =
        (process->timeAndComandInTimer.sec + 1) % 60;
  }
}


void processingKeyDown(applicationManagement *process) {
  if (process->timeAndComandInTimer.position == 0) {
    process->timeAndComandInTimer.hour =
        (process->timeAndComandInTimer.hour - 1 + 24) % 24;
  }
  if (process->timeAndComandInTimer.position == 1) {
    process->timeAndComandInTimer.min =
        (process->timeAndComandInTimer.min - 1 + 60) % 60;
  }
  if (process->timeAndComandInTimer.position == 2) {
    process->timeAndComandInTimer.sec =
        (process->timeAndComandInTimer.sec - 1 + 60) % 60;
  }
}


void processingKeyLeft(applicationManagement *process) {
  process->timeAndComandInTimer.blinking = 0;
  process->timeAndComandInTimer.position--;
  if (process->timeAndComandInTimer.position < 0) {
    process->timeAndComandInTimer.position = 2;
  }
}


void processingKeyRight(applicationManagement *process) {
  process->timeAndComandInTimer.blinking = 0;
  process->timeAndComandInTimer.position++;
  if (process->timeAndComandInTimer.position > 2) {
    process->timeAndComandInTimer.position = 0;
  }
}


void startTimer(applicationManagement *process) {
  if (process->checkTimer == 1) {
    process->step = 4;
    clock_gettime(CLOCK_MONOTONIC, &process->timerStart);
    process->timerStart.tv_sec += (process->timeAndComandInTimer.hour * 3600) +
                                  (process->timeAndComandInTimer.min * 60) +
                                  process->timeAndComandInTimer.sec;
  }
}


void *playSoundThread(void *arg) {
(void)arg;
  system("aplay musicForTimer/timer.wav");
  return NULL;
}