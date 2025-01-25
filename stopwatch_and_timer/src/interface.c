#include <../include/program.h>

void staticPartInterface() {
  printw("______________________________\n");
  printw("|This is timer and stopwatch!|\n");
  printw("|   Current time: ");
}

void сlockForStaticPartInterface() {
  time_t actualTime = 0;
  time(&actualTime);
  struct tm *now = localtime(&actualTime);
  printw("%02d:%02d:%02d   |\n", now->tm_hour, now->tm_min, now->tm_sec);
}

void startInterfaceComand() {
  drawEmptySpace(12);
  printw("|   Start the stopwatch: s   |\n");
  printw("|     Start the timer: t     |\n");
  printw("|       To turn off: q       |\n");
  printw("|____________________________|\n");
}

void drawEmptySpace(int i) {
  for (int j = 0; j < i; j++) {
    printw("|                            |\n");
  }
}

void interfaceForStopwatcAndComand(applicationManagement *process) {
  drawEmptySpace(1);
  printw("|         stopwatch:         |\n");
  stopwatch(process);
  drawEmptySpace(2);
  if (process->step == 1) {
    printw("|          Pause: p          |\n");
  } else {
    printw("|         Continue: c        |\n");
  }
  printw("|        Interval: i         |\n");
  printw("|  Restart the stopwatch: r  |\n");
  printw("|         Go back: b         |\n");
  printw("|____________________________|\n");
}


void drawStopwatchAndInterval(applicationManagement *process, short hour,
                              short min, short sec, short nanoSec) {
  printw("|         %02d:%02d:%02d:%d         |\n", hour, min, sec, nanoSec);
  drawEmptySpace(2);
  printw("|          interval:         |\n");
  printw("|      1: %02d:%02d:%02d:%d         |\n",
         process->intervalStopwatch.firstHour,
         process->intervalStopwatch.firstMin,
         process->intervalStopwatch.firstSec,
         process->intervalStopwatch.firstNanoSec);
  printw("|      2: %02d:%02d:%02d:%d         |\n",
         process->intervalStopwatch.secondHour,
         process->intervalStopwatch.secondMin,
         process->intervalStopwatch.secondSec,
         process->intervalStopwatch.secondNanoSec);
  printw("|      3: %02d:%02d:%02d:%d         |\n",
         process->intervalStopwatch.thirdHour,
         process->intervalStopwatch.thirdMin,
         process->intervalStopwatch.thirdSec,
         process->intervalStopwatch.thirdNanoSec);
}

void interfaceForTimerAndComand(applicationManagement *process) {
  drawEmptySpace(3);
  printw("|           timer:           |\n");
  if (process->step == 3) {
    settingTimer(process);

  } else {
    timerCountdown(process);
  }

  drawEmptySpace(7);

  if (process->step == 3) {
    printw("|   Use arrows to set time   |\n");
    printw("|          Start: s          |\n");
  }
  if (process->step == 4) {
    printw("|           Stop: s          |\n");
    printw("|    Restart the timer: r    |\n");
  }
  if (process->step == 5) {
    drawEmptySpace(1);
    printw("|    Restart the timer: r    |\n");
  }

  if (process->step == 0) {
    drawEmptySpace(3);
  }
  printw("|         Go back: b         |\n");
  printw("|____________________________|\n");
}

void settingTimer(applicationManagement *process) {
  process->timeAndComandInTimer.blinking++;
  if (process->timeAndComandInTimer.position == 0) {
    if (process->timeAndComandInTimer.blinking % 6 == 0) {

      printw("|          **:%02d:%02d          |\n",
             process->timeAndComandInTimer.min,
             process->timeAndComandInTimer.sec);
    } else {
      printw("|          %02d:%02d:%02d          |\n",
             process->timeAndComandInTimer.hour,
             process->timeAndComandInTimer.min,
             process->timeAndComandInTimer.sec);
    }
  }

  if (process->timeAndComandInTimer.position == 1) {
    if (process->timeAndComandInTimer.blinking % 6 == 0) {

      printw("|          %02d:**:%02d          |\n",
             process->timeAndComandInTimer.hour,
             process->timeAndComandInTimer.sec);
    } else {
      printw("|          %02d:%02d:%02d          |\n",
             process->timeAndComandInTimer.hour,
             process->timeAndComandInTimer.min,
             process->timeAndComandInTimer.sec);
    }
  }
  if (process->timeAndComandInTimer.position == 2) {
    if (process->timeAndComandInTimer.blinking % 6 == 0) {
      printw("|          %02d:%02d:**          |\n",
             process->timeAndComandInTimer.hour,
             process->timeAndComandInTimer.min);
    } else {
      printw("|          %02d:%02d:%02d          |\n",
             process->timeAndComandInTimer.hour,
             process->timeAndComandInTimer.min,
             process->timeAndComandInTimer.sec);
    }
  }
}
