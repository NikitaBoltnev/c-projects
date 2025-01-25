#include <../include/program.h>

void stopwatch(applicationManagement *process) {
  clock_gettime(CLOCK_MONOTONIC, &process->actualTime);
  int seconds = process->actualTime.tv_sec - process->startStopwatch.tv_sec;
  long nanosec = process->actualTime.tv_nsec - process->startStopwatch.tv_nsec;
  if (nanosec < 0) {
    seconds--;
    nanosec += MAX_NANO_SEC;
  }
  nanosec /= 100000000; // обнуляю до десятой доли секунды
  if (seconds == MAX_MIN_AND_SEC) {
    process->min++;
    clock_gettime(CLOCK_MONOTONIC, &process->startStopwatch);
  }
  if (process->min == MAX_MIN_AND_SEC) {
    process->hour++;
    process->min = 0;
  }
  if (process->hour == MAX_HOUR) {
    process->hour = 0;
  }
  process->sec = seconds;
  process->nanoSec = nanosec;
  if (process->step == 2) {
    drawStopwatchAndInterval(process, process->pauseHour, process->pauseMin,
                             process->pauseSec, process->PauseNanoSec);
  } else {
    drawStopwatchAndInterval(process, process->hour, process->min, process->sec,
                             process->nanoSec);
  }
}

void clearingIntervalAndStopwatch(applicationManagement *process) {
  process->hour = 0;
  process->min = 0;
  process->sec = 0;
  process->nanoSec = 0;

  process->pauseHour = 0;
  process->pauseMin = 0;
  process->pauseSec = 0;
  process->PauseNanoSec = 0;

  process->countInteval = 0;

  memset(&process->intervalStopwatch, 0, sizeof(process->intervalStopwatch));
}

void processingPause(applicationManagement *process) {
  struct timespec pauseTime = {0};
  clock_gettime(CLOCK_MONOTONIC, &pauseTime);

  process->elapsedBeforePause.tv_sec =
      pauseTime.tv_sec - process->startStopwatch.tv_sec;
  process->elapsedBeforePause.tv_nsec =
      pauseTime.tv_nsec - process->startStopwatch.tv_nsec;

  if (process->elapsedBeforePause.tv_nsec < 0) {
    process->elapsedBeforePause.tv_sec--;
    process->elapsedBeforePause.tv_nsec += MAX_NANO_SEC;
  }

  process->pauseHour = process->hour;
  process->pauseMin = process->min;
  process->pauseSec = process->sec;
  process->PauseNanoSec = process->nanoSec;

  process->step = 2;
}


void processingContinue(applicationManagement *process) {
  struct timespec currentTime = {0};
  clock_gettime(CLOCK_MONOTONIC, &currentTime);

  process->hour = process->pauseHour;
  process->min = process->pauseMin;
  process->sec = process->pauseSec;
  process->nanoSec = process->PauseNanoSec;

  process->startStopwatch.tv_sec =
      currentTime.tv_sec - process->elapsedBeforePause.tv_sec;
  process->startStopwatch.tv_nsec =
      currentTime.tv_nsec - process->elapsedBeforePause.tv_nsec;

  if (process->startStopwatch.tv_nsec < 0) {
    process->startStopwatch.tv_sec--;
    process->startStopwatch.tv_nsec += MAX_NANO_SEC;
  }

  process->step = 1;
}

void saveInterval(applicationManagement *process, short hour, short min,
                  short sec, short nanoSec) {
  if (process->countInteval % 3 == 1) {
    process->intervalStopwatch.firstHour = hour;
    process->intervalStopwatch.firstMin = min;
    process->intervalStopwatch.firstSec = sec;
    process->intervalStopwatch.firstNanoSec = nanoSec;
  } else if (process->countInteval % 3 == 2) {
    process->intervalStopwatch.secondHour = hour;
    process->intervalStopwatch.secondMin = min;
    process->intervalStopwatch.secondSec = sec;
    process->intervalStopwatch.secondNanoSec = nanoSec;
  } else if (process->countInteval % 3 == 0) {
    process->intervalStopwatch.thirdHour = hour;
    process->intervalStopwatch.thirdMin = min;
    process->intervalStopwatch.thirdSec = sec;
    process->intervalStopwatch.thirdNanoSec = nanoSec;
  }
}