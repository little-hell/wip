/*
 * Copyright(C) 1993-1996 Id Software, Inc.
 * Copyright(C) 2005-2014 Simon Howard
 * Copyright(C) 2023 Joshua Murphy
 *
 * This file is part of Little Hell.
 *
 * Little Hell is free software: you can redistribute it and/or modify it under the terms of the GNU
 * General Public License as published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * Little Hell is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without
 * even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with Little Hell.
 * If not, see https://www.gnu.org/licenses/
 */

#ifndef __SLEEP__
#define __SLEEP__

/**
 * @defgroup SleepAPI Sleep (Developer API)
 * @ingroup System
 * This subgroup contains all Windows-specific functions.
 */


/** @ingroup SleepAPI
 *  @brief Cross-platform sleep() function
 *  @param seconds The amount of time to sleep in seconds
 */
void system_sleep(unsigned int seconds);

#endif

