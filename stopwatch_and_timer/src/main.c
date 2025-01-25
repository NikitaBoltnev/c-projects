#include <../include/program.h>

int main() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  startProgram();
  endwin();
  return 0;
}


void startProgram() {
  struct timespec sleepTime = {0};
  sleepTime.tv_nsec = 100000000; // 0.1 сек
  applicationManagement process = {0};
  pthread_t input_thread = {0};
  pthread_create(&input_thread, NULL, userInput, &process);

  while (process.step != 6) {
    clearingTerminalAndSleep(&sleepTime);
    staticPartInterface();
    сlockForStaticPartInterface(&process);
    if (process.step == 0) {
      startInterfaceComand(&process);

    } else if (process.step == 1 || process.step == 2) {
      interfaceForStopwatcAndComand(&process);
    } else if (process.step > 2 && process.step < 6) {
      interfaceForTimerAndComand(&process);
    }
    refresh();
  }
}

void clearingTerminalAndSleep(struct timespec *sleepTime) {
  nanosleep(sleepTime, NULL);
  clear();
}

void *userInput(void *tempProcess) {
  applicationManagement *process = (applicationManagement *)tempProcess;
  char input = 0;
  while (process->step != 6) {
    input = getch();
    processingUserInput(process, input);
  }
  return NULL;
}

void processingUserInput(applicationManagement *process, char input) {
  switch (input) {
  case 'q':
  case 'Q':
    processingQuit(process);
    break;
  case 's':
  case 'S':
    processingStartStopwatchAndStopTimer(process);
    break;
  case 'r':
  case 'R':
    processingRestart(process);
    break;
  case 'b':
  case 'B':
    processingBack(process);
    break;
  case 'p':
  case 'P':
    callingPause(process);
    break;
  case 'c':
  case 'C':
    callingContinue(process);
    break;
  case 'i':
  case 'I':
    processingInterval(process);
    break;
  case 't':
  case 'T':
    openTimer(process);
    break;
  default:
    break;
  }
}

void processingQuit(applicationManagement *process) {
  if (process->step == 0) {
    process->step = 6;
  }
}

void processingStartStopwatchAndStopTimer(applicationManagement *process) {
  if (process->step == 0) {
    process->step = 1;
    clock_gettime(CLOCK_MONOTONIC, &process->startStopwatch);
  }
  if (process->step == 4) {

    int hour = 0;
    int min = 0;
    int sec = 0;

    getTimeForTimerAndPause(process, &hour, &min, &sec);
    process->pauseHour = hour;
    process->pauseMin = min;
    process->pauseSec = sec;
    process->step = 5;
  }
}

void processingRestart(applicationManagement *process) {
  if (process->step == 1 || process->step == 2) {
    clearingIntervalAndStopwatch(process);
    if (process->step == 2) {
      process->step = 1;
    }
    clock_gettime(CLOCK_MONOTONIC, &process->startStopwatch);
  }
  if (process->step == 4 || process->step == 5) {
    exitTimer(process);
    timerSetup(process);
  }
}

void processingBack(applicationManagement *process) {
  if (process->step != 0) {
    if (process->step == 1 || process->step == 2) {
      clearingIntervalAndStopwatch(process);
    } else if (process->step == 4 || process->step == 5) {
      exitTimer(process);
    }
    process->step = 0;
  }
}

void callingPause(applicationManagement *process) {
  if (process->step == 1) {
    processingPause(process);
  }
}

void callingContinue(applicationManagement *process) {
  if (process->step == 2) {
    processingContinue(process);
  }
}


void processingInterval(applicationManagement *process) {
  if (process->step == 1 || process->step == 2) {
    process->countInteval++;
    short hour = (process->step == 2) ? process->pauseHour : process->hour;
    short min = (process->step == 2) ? process->pauseMin : process->min;
    short sec = (process->step == 2) ? process->pauseSec : process->sec;
    short nanoSec =
        (process->step == 2) ? process->PauseNanoSec : process->nanoSec;
    saveInterval(process, hour, min, sec, nanoSec);
  }
}

void openTimer(applicationManagement *process) {
  if (process->step == 0) {
    timerSetup(process);
  }
}

