#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <pthread.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_MIN_AND_SEC 60
#define MAX_HOUR 24
#define MAX_NANO_SEC 1000000000L
struct interval {
  short firstHour;
  short firstMin;
  short firstSec;
  short firstNanoSec;

  short secondHour;
  short secondMin;
  short secondSec;
  short secondNanoSec;

  short thirdHour;
  short thirdMin;
  short thirdSec;
  short thirdNanoSec;
};

struct timer {
  short hour;
  short min;
  short sec;
  short position;
  int blinking;
};

typedef struct {
  short step;
  short hour;
  short min;
  short sec;
  short nanoSec;
  short pauseHour;
  short pauseMin;
  short pauseSec;
  short PauseNanoSec;
  struct timespec startStopwatch;
  struct timespec actualTime;
  int countInteval;
  struct interval intervalStopwatch;
  struct timespec elapsedBeforePause;
  struct timer timeAndComandInTimer;
  struct timespec timerStart;
  int checkTimer;
} applicationManagement;

void startProgram();
void clearingTerminalAndSleep(struct timespec *sleepTime);
void staticPartInterface();
void drawEmptySpace(int i);
void startInterfaceComand();
void сlockForStaticPartInterface();
void interfaceForStopwatcAndComand(applicationManagement *process);
void *userInput(void *tempProcess);
void stopwatch(applicationManagement *process);
void drawStopwatchAndInterval(applicationManagement *process, short hour,
                              short min, short sec, short nanoSec);
void clearingIntervalAndStopwatch(applicationManagement *process);
void processingPause(applicationManagement *process);
void processingContinue(applicationManagement *process);
void saveInterval(applicationManagement *process, short hour, short min,
                  short sec, short nanoSec);
void interfaceForTimerAndComand(applicationManagement *process);
void settingTimer(applicationManagement *process);
void timerCountdown(applicationManagement *process);
void getTimeForTimerAndPause(applicationManagement *process, int *hour,
                             int *min, int *sec);
void exitTimer(applicationManagement *process);
void timerSetup(applicationManagement *process);
void *playSoundThread(void *arg);
void processingPause(applicationManagement *process);
void processingContinue(applicationManagement *process);
void processingKeyUp(applicationManagement *process);
void processingKeyDown(applicationManagement *process);
void processingKeyLeft(applicationManagement *process);
void processingKeyRight(applicationManagement *process);
void startTimer(applicationManagement *process);
void timerSecurity(applicationManagement *process);
void processingUserInput(applicationManagement *process, char input);
void processingQuit(applicationManagement *process);
void processingStartStopwatchAndStopTimer(applicationManagement *process);
void processingRestart(applicationManagement *process);
void processingBack(applicationManagement *process);
void callingPause(applicationManagement *process);
void callingContinue(applicationManagement *process);
void processingInterval(applicationManagement *process);
void openTimer(applicationManagement *process);
