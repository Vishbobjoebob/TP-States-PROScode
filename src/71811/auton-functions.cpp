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
  while(arm.get_position() <= 100) {
    arm.move_absolute(100,100);
    pros::delay(2);
  }
  pros::delay(200);
  set_drive_pid(drive,4,80,false);
  wait_drive();
  pros::delay(200);
  clampUp();
  set_drive_pid(drive,-4,80,false);
  wait_drive();
  pros::delay(200);
  set_drive_pid(turn, -90, 110);
  wait_drive();
  set_drive_pid(drive, 23, 110, true);
  wait_drive();
  set_drive_pid(turn, -180, 110);
  wait_drive();
  tilterDown();
  set_drive_pid(drive, -139, 110, true);
  wait_drive();
  pros::delay(100);
  tilterUp();
  set_drive_pid(drive, 20, 110, false);
  wait_drive();
  while(arm.get_position() <= 400) {
    arm.move_absolute(400,100);
    pros::delay(2);
  }
  conveyor.move_velocity(600);
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
  set_drive_pid(turn, -31, 110);
  wait_drive();
  set_drive_pid(drive, 64, 110, true);
  wait_drive();
  clampDown();
  set_drive_pid(drive, -64, 110, true);
  wait_drive();
  clampUp();
  set_drive_pid(drive,-9, 110, true);
  wait_drive();
  set_drive_pid(turn,-129,110);
  wait_drive();
  tilterDown();
  pros::delay(500);
  set_drive_pid(drive,-42, 110, true);
  wait_drive();
  tilterUp();
  pros::delay(500);
  set_drive_pid(l_swing, -33, 110);
  wait_drive();
  pros::delay(500);
  set_drive_pid(drive,6,40);
  wait_drive();
  clampDown();
  set_drive_pid(drive,-6, 40);
  wait_drive();
}

void skills() {
  arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  tilterDown();
  clampUp();
  pros::delay(500);
  set_drive_pid(drive, -16, 100, true);
  wait_drive();
  pros::delay(500);
  tilterUp();
  pros::delay(200);
  set_drive_pid(l_swing, 104, 80);
  wait_drive();
  set_drive_pid(drive, 64, 50, true);
  wait_drive();
  pros::delay(700);
  clampDown();
  pros::delay(500);
  while(arm.get_position() <= 400) {
    arm.move_absolute(400,100);
    pros::delay(2);
  }
  pros::delay(500);
  set_drive_pid(turn,120,90);
  wait_drive();
  set_drive_pid(drive, 70, 80, true);
  wait_drive();
  set_drive_pid(turn, 80, 90);
  wait_drive();
  pros::delay(500);
  set_drive_pid(turn, 100, 90);
  wait_drive();
  pros::delay(500);
  clampUp();
  pros::delay(500);
  set_drive_pid(turn, 90, 100);
  wait_drive();
  set_drive_pid(drive, -20, 100);
  wait_drive();
  set_drive_pid(turn, 180, 100);
  wait_drive();
  conveyor.move_velocity(600);
  set_drive_pid(drive, 65, 100, true);
  wait_drive();
  pros::delay(500);
  set_drive_pid(drive, -11, 100, true);
  wait_drive();
  while(arm.get_position() >= 0) {
    arm.move_absolute(0,100);
    pros::delay(2);
  }
  set_drive_pid(turn, 270, 100);
  wait_drive();
  pros::delay(500);
  set_drive_pid(drive, 30, 50, true);
  wait_drive();
  pros::delay(500);
  clampDown();
  while(arm.get_position() <= 350) {
    arm.move_absolute(350,100);
    pros::delay(2);
  }
  set_drive_pid(turn, 300, 90);
  wait_drive();
  set_drive_pid(drive, 60, 90, true);
  wait_drive();
  pros::delay(500);
  clampUp();
  set_drive_pid(drive, -24, 90, true);
  wait_drive();
  while(arm.get_position() >= 0) {
    arm.move_absolute(0,100);
    pros::delay(2);
  }
  set_drive_pid(turn, 405, 90, true);
  wait_drive();
  set_drive_pid(drive, 50, 50, true);
  wait_drive();
  pros::delay(500);
  clampDown();
  pros::delay(500);
  set_drive_pid(drive, 50, 50, true);
  wait_drive();




}
