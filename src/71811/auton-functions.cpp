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
void armUp() {
  arm.move_absolute(400, 100);
}
void armDown() {
  arm.move_absolute(0,100);
}
int armUpTask() {
  pros:: Task arm_up_task(armUp);
  return 1;
}
int armDownTask() {
  pros:: Task arm_down_task(armDown);
  return 1;
}
void stopArmUpTask() {
  arm_up_task().suspend();
}
void stopArmDownTask() {
  arm_down_task().suspend();
}
int dumpRings() {
  conveyor.move_velocity(600);
  return 1;
}
void createDumpRingTask() {
  pros::Task dump_ring_task(dumpRings);
}
void stopDumpRingTask() {
  dump_ring_task().suspend();
}

void homeRowAuton() {
  clampUp();
  pros::delay(500);
  set_drive_pid(drive, 8, 50, true);
  pros::delay(500);
  clampDown();
  pros::delay(500);
  set_drive_pid(turn, -90, 250);
  wait_drive();
  set_drive_pid(drive, 29, 324, true);
  wait_drive();
  set_drive_pid(turn, -180, 250);
  wait_drive();
  tilterDown();
  set_drive_pid(drive, -123, 324, true);
  wait_drive();
  pros::delay(100);
  set_drive_pid(drive, 15, 200, false);
  wait_drive();
}

void neutralMogoAuton() {
  arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  clampUp();
  set_drive_pid(drive, 54, 110, true);
  wait_drive();
  clampDown();
  set_drive_pid(drive, -39, 110, true);
  wait_drive();
  clampUp();
  set_drive_pid(drive, -21, 110, true);
  wait_drive();
  set_drive_pid(turn, -34, 110);
  wait_drive();
  set_drive_pid(drive, 63, 110, true);
  wait_drive();
  clampDown();
  set_drive_pid(drive, -63, 110, true);
  wait_drive();
  clampUp();
  set_drive_pid(drive,-7, 110, true);
  wait_drive();
  set_drive_pid(turn,-129,110);
  wait_drive();
  tilterDown();
  pros::delay(500);
  set_drive_pid(drive,-38, 110, true);
  wait_drive();
  tilterUp();
  set_drive_pid(drive, 20, 110);
  wait_drive();
}

void skills() {

}
