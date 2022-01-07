#include "main.h"

bool manual = false;

bool toggle = false;
bool latch = false;

bool toggle1 = false;
bool latch1 = false;

bool toggle2 = false;
bool latch2 = false;

bool toggle3 = false;
bool latch3 = false;

int armControl() {
  if (manual == false) {
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      arm.move_absolute(400, 100);
    }
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
      arm.move_absolute(0, 100);
    }
  }
  else {
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      arm.move_velocity(100) ;
    }

    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
      arm.move_velocity(-100) ;
    }
    else {
      arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      arm.move_velocity(0);
    }
  }
  return 1;
}


int conveyorControl() {
  if (toggle){
    conveyor.move_velocity(600);
  } else {
    conveyor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    conveyor.move_velocity(0);
  }

  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
    if(!latch){ //flip the toggle one time and set the latch
      toggle = !toggle;
      latch = true;
    }
  } else {
    //Once the BumperA is released then then release the latch too
    latch = false;
  }

  pros::delay(20);

  return 1;

}

int clampControl() {
  if (toggle1){
    clamp.set_value(false);
  } else {
    clamp.set_value(true);
  }

  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)) {
    if(!latch1){
      toggle1 = !toggle1;
      latch1 = true;
    }
  } else {
    latch1 = false;
  }

  pros::delay(20);

  return 1;

}

int tilterControl() {
  if (toggle2){
    leftTilter.set_value(true);
    rightTilter.set_value(true);
  } else {
    leftTilter.set_value(false);
    rightTilter.set_value(false);
  }

  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
    if(!latch2){
      toggle2 = !toggle2;
      latch2 = true;
    }
  } else {
    latch2 = false;
  }

  pros::delay(20);

  return 1;
}

int manualControl() {
  if (toggle3){
    manual=true;
  } else {
    manual=false;
  }

  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
    if(!latch3){
      toggle3 = !toggle3;
      latch3 = true;
    }
  } else {
    latch3 = false;
  }

  pros::delay(20);

  return 1;
}

void resetEncoders() {
  arm.set_zero_position(arm.get_position());
}
