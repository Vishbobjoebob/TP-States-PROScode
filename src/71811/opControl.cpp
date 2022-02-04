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

bool toggle4 = false;
bool latch4 = false;

bool toggle5 = false;
bool latch5 = false;

int armControl() {
  if (manual == false) {
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
      arm.move_absolute(375, 100);
    }
    else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
      arm.move_absolute(-30, 100);
    }
    else if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
      arm.move_absolute(420, 100);
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
    conveyor.move_velocity(-200);
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
    clamp1.set_value(false);
  } else {
    clamp1.set_value(true);
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

int boingControl() {
  if (toggle4){
    boing.set_value(false);
  } else {
    boing.set_value(true);
  }

  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
    if(!latch4){
      toggle4 = !toggle4;
      latch4 = true;
    }
  } else {
    latch4 = false;
  }

  pros::delay(20);

  return 1;

}

int coastControl() {
  if (toggle5){
    chassis.set_drive_brake(MOTOR_BRAKE_HOLD);
    conveyor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    conveyor.move_velocity(0);
  } else {
    chassis.set_drive_brake(MOTOR_BRAKE_COAST);
  }

  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
    if(!latch5){
      toggle5 = !toggle5;
      latch5 = true;
    }
  } else {
    latch5 = false;
  }

  pros::delay(20);

  return 1;
}



void resetEncoders() {
  arm.set_zero_position(arm.get_position());
}
