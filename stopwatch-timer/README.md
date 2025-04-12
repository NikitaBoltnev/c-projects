Stopwatch and Timer Implementation Project

## Interface:
- Real-time updating clock display.
- Users can launch either the stopwatch or timer from the interface.

## Stopwatch:
- Features a real-time updating clock.
- Precision up to tenths of a second.
- Can count time up to 23 hours, 59 minutes, and 59 seconds. Upon reaching this limit, the time resets to 00:00:00.0 and continues counting.
- Automatically starts when entering the stopwatch section.
- Includes pause/resume functionality.
- Supports lap timing with storage for 3 consecutive laps. When recording a 4th lap, the oldest lap is replaced (FIFO system).
- Allows complete reset (time values and laps) without returning to the main menu.
- All functionality works both during operation and while paused.
- Option to return to the main menu is available at any stage.

## Timer:
- Features a real-time updating clock.
- 1-second precision.
- Configurable time up to 23 hours, 59 minutes, and 59 seconds.
- Navigation/configuration using arrow keys (up/down/left/right).
- Cyclic interface prevents exceeding time boundaries.
- Safety feature: timer cannot start with zero time set.
- Current selection (hours/minutes/seconds) blinks during configuration for better UX.
- After starting, users can pause, restart, or reconfigure time without exiting to main menu.
- When reaching 00:00:00, automatically returns to main menu and plays an alert melody (stored in musicForTimer folder, Linux-compatible implementation).
- Option to return to main menu is available at any stage.

## General Information:
- Built using Makefile.
- Can be launched via make run.
- Uses English keyboard layout for controls.