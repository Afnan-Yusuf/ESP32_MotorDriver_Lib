// MotorController.cpp

#include <Arduino.h>
#include "ESP32_MotorDriver.h"

MotorController::MotorController(int leftForward, int leftBackward, int rightForward, int rightBackward)
{
  motLF = leftForward;
  motLB = leftBackward;
  motRF = rightForward;
  motRB = rightBackward;
}

void MotorController::initialize()
{
  ledcSetup(mrfc, freqm, resolution); // pwm channel and frequency and resolution setup
  ledcSetup(mrbc, freqm, resolution);
  ledcSetup(mlfc, freqm, resolution);
  ledcSetup(mlbc, freqm, resolution);
  ledcAttachPin(motRF, mrfc); // attach motor pins pwm channels
  ledcAttachPin(motRB, mrbc);
  ledcAttachPin(motLF, mlfc);
  ledcAttachPin(motLB, mlbc);
  ledcWrite(mrfc, 0); // write all pwmm channel 0
  ledcWrite(mrbc, 0);
  ledcWrite(mlfc, 0);
  ledcWrite(mlbc, 0);
}

void MotorController::stop()
{
  ledcWrite(mrfc, 0);
  ledcWrite(mrbc, 0);
  ledcWrite(mlfc, 0);
  ledcWrite(mlbc, 0);
}

void MotorController::forward(int speed)
{
  ledcWrite(mrfc, speed);
  ledcWrite(mrbc, 0);
  ledcWrite(mlfc, speed);
  ledcWrite(mlbc, 0);
}

void MotorController::backward(int speed)
{
  ledcWrite(mrfc, 0);
  ledcWrite(mrbc, speed);
  ledcWrite(mlfc, 0);
  ledcWrite(mlbc, speed);
}

void MotorController::turnLeft(int speed)
{
  ledcWrite(mrfc, speed);
  ledcWrite(mrbc, 0);
  ledcWrite(mlfc, 0);
  ledcWrite(mlbc, speed);
}

void MotorController::turnRight(int speed)
{
  ledcWrite(mrfc, 0);
  ledcWrite(mrbc, speed);
  ledcWrite(mlfc, speed);
  ledcWrite(mlbc, 0);
}

void MotorController::leftMotorForward(int speed)
{
  ledcWrite(mlfc, speed);
  ledcWrite(mlbc, 0);
}

void MotorController::leftMotorBackward(int speed)
{
  ledcWrite(mlfc, 0);
  ledcWrite(mlbc, speed);
}

void MotorController::rightMotorForward(int speed)  
{
  ledcWrite(mrfc, speed);
  ledcWrite(mrbc, 0);
}

void MotorController::rightMotorBackward(int speed)
{
  ledcWrite(mrfc, 0);
  ledcWrite(mrbc, speed);
}

void MotorController::setFrequency(int pwmFrequency)
{
  freqm = pwmFrequency;
}

void MotorController::setResolution(int pwmResolution)
{
  resolution = pwmResolution;
}