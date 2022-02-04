#include "main.h"

pros::Imu gyro(5);
pros::Imu gyro2(6);

pros::Motor arm(3, MOTOR_GEARSET_36, true, MOTOR_ENCODER_DEGREES);
pros::Motor conveyor(8, MOTOR_GEARSET_6, true, MOTOR_ENCODER_DEGREES);

pros::ADIDigitalOut clamp1('G', true);
pros::ADIDigitalOut leftTilter('E', false);
pros::ADIDigitalOut rightTilter('F', false);
pros::ADIDigitalOut boing('H', true);
