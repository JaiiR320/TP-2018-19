/**
 * \file main.h
 *
 * Contains common definitions and header files used throughout your PROS
 * project.
 *
 * Copyright (c) 2017-2018, Purdue University ACM SIGBots.
 * All rights reserved.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

/**
 * If defined, some commonly used enums will have preprocessor macros which give
 * a shorter,
 * more convenient naming pattern. If this isn't desired, simply comment the
 * following line out
 *
 * For instance, E_CONTROLLER_MASTER has a shorter name: CONTROLLER_MASTER.
 * E_CONTROLLER_MASTER
 * is pedantically correct within the PROS styleguide, but not convienent for
 * most student
 * programmers.
 */
#define PROS_USE_SIMPLE_NAMES

/**
 * If defined, C++ literals will be available for use.
 *
 * For instance, you can do `4_m = 50` to set motor 4's target velocity to 50
 */

#define PROS_USE_LITERALS

#include "api.h"
#include "pros/apix.h"
#include "display/lvgl.h"

extern Controller master;

extern Motor left_drive;
extern Motor right_drive;

extern Motor left_lift;
extern Motor right_lift;

extern Motor flywheel_mtr;

extern Motor intake_mtr;

extern Motor cap_flip_mtr;

void driveSpeed(int left, int right, int side);

void driveSet(int left, int right, int speed);

void driveTurn(int degrees);

void liftSpeed(int left, int right);

void liftSet(int pos, int speed);

void flyWheelSet();

void capFlip(int speed);




/**
 * If you find doing pros::Motor() to be tedious and you'd prefer just to do
 * Motor,
 * you can use the namespace with the following commented out line.
 *
 * IMPORTANT: Only the okapi or pros namespace may be used, not both
 * concurrently!
 *            The okapi namespace will export all symbols inside the pros
 * namespace.
 */
using namespace pros;
// using namespace okapi;

/**
 * You should add more #includes here
 */

//#include "okapi/api.hpp"
//#include "pros/api_legacy.h"

#ifdef __cplusplus
/**
 * You can add C++-only headers here
 */
//#include <iostream>

#include "functions.h"


#endif

#endif  // _PROS_MAIN_H_
