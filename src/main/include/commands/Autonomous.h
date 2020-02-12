/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/SequentialCommandGroup.h>

class Drivetrain;
class Intake;
class Arduino;
class Shooter;

class Autonomous
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 Autonomous> {
public:
  Autonomous(Drivetrain *drivetrain, Intake *intake, Arduino *arduino, Shooter *s);

private:
};

class Autonomous2
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 Autonomous> {
public:
  Autonomous2(Drivetrain *drivetrain, Intake *intake, Arduino *arduino, Shooter *s);

private:
};