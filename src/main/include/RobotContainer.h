/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Command.h>
#include <frc/Joystick.h>
#include <frc/XboxController.h>

#include "commands/ExampleCommand.h"
#include "commands/DefaultDrive.h"
#include "commands/AlignTarget.h"
#include "commands/ManualShooter.h"
#include "subsystems/ExampleSubsystem.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/Shooter.h" 
#include "subsystems/Intake.h"
#include "subsystems/ColorSensor.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();
  frc2::Command* GetTeleopCommand();

 private:
  /* --- Controls --- */
  frc::Joystick m_joystick;
  frc::XboxController m_xboxController;

  /* --- Subsystems --- */
  Drivetrain m_drivetrain;
  Shooter m_shooter;
  Intake m_intake;
  ColorSensor m_colorSensor;

  /* --- Commands --- */
  DefaultDrive m_defaultDrive;
  ManualShooter m_manualShooter;
  AlignTarget m_alignTarget;

  void ConfigureButtonBindings();
};
