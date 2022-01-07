#include "main.h"


void clampDown() {
  clamp.set_value(true);
}
void clampUp() {
  clamp.set_value(false);
}
void tilterUp() {
  leftTilter.set_value(false);
  rightTilter.set_value(false);
}
void tilterDown() {
  leftTilter.set_value(true);
  rightTilter.set_value(true);
}
int dumpRings() {
  conveyor.move_velocity(600);
  return 1;
}
void createDumpRingTask() {
  pros::Task dump_ring_task(dumpRings);
}
void stopDumpRingTask() {
  //stop task
}

void homeRowAuton() {
  clampUp();
  set_drive_pid(drive, 5, 50, true);
  pros::delay(500);
  clampDown();
  pros::delay(500);
  set_drive_pid(l_swing, -180, 250);
  wait_drive();
  pros::delay(250);
  tilterDown();
  set_drive_pid(drive, -96, 324, true);
  wait_drive();
  tilterUp();
  pros::delay(100);
  createDumpRingTask();
  set_drive_pid(drive, -10, 200, false);
  stopDumpRingTask();
}

void neutralMogoAuton() {
  clampUp();
  set_drive_pid(drive, 62, 300, true);
  wait_drive();
  clampDown();
  set_drive_pid(drive, -40, 300, true);
  wait_drive();
  clampUp();
  set_drive_pid(drive, -20, 300, true);
  wait_drive();
  set_drive_pid(turn, -33, 300);
  wait_drive();
  set_drive_pid(drive, 55, 300, true);
  wait_drive();
  clampDown();
  set_drive_pid(drive, -55, 300, true);
  wait_drive();
  tilterDown();


}
