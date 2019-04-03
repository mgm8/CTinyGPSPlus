/*
 * c_tiny_gps_plus_raw_degrees.h
 *
 * Based on TinyGPS++ by Mikal Hart.
 *
 * Copyright (C) 2008-2013 Mikal Hart
 * Copyright (C) 2019, Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * This file is part of CTinyGPS++.
 * 
 * CTinyGPS++ is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * CTinyGPS++ is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with CTinyGPS++. If not, see <http://www.gnu.org/licenses/>.
 * 
 */

/**
 * \brief Raw degrees struct definition.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 0.1.0
 * 
 * \date 03/04/2019
 * 
 * \defgroup c_tiny_gps_plus_raw_degrees Raw Degrees
 * \ingroup c_tiny_gps_plus
 * \{
 */

#ifndef C_TINY_GPS_PLUS_RAW_DEGREES_H_
#define C_TINY_GPS_PLUS_RAW_DEGREES_H_

#include <stdbool.h>
#include <stdint.h>

/**
 * \brief Raw degrees.
 */
typedef struct
{
    uint16_t deg;           /**< Degrees value. */
    uint32_t billionths;    /**< . */
    bool negative;          /**< Is negative flag. */
} c_tiny_gps_plus_raw_degrees_t;

/**
 * \brief Initializes a c_tiny_gps_plus_raw_degrees_t structure.
 *
 * \param[in,out] rd is c_tiny_gps_plus_raw_degrees_t structure to initialize.
 *
 * \return None.
 */
void c_tiny_gps_plus_raw_degrees_init(c_tiny_gps_plus_raw_degrees_t *rd);

/**
 * \brief Creates a new raw_degrees_t structure.
 *
 * \return A new raw_degrees_t structure.
 */
c_tiny_gps_plus_raw_degrees_t c_tiny_gps_plus_raw_degrees_gen();

#endif // C_TINY_GPS_PLUS_RAW_DEGREES_H_

//! \} End of c_tiny_gps_plus_raw_degrees group
