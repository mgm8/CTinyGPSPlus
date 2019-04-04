/*
 * c_tiny_gps_plus_location.h
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
 * \brief Location struct definition.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 0.1.0
 * 
 * \date 03/04/2019
 * 
 * \defgroup c_tiny_gps_plus_location Location
 * \ingroup c_tiny_gps_plus
 * \{
 */

#ifndef C_TINY_GPS_PLUS_LOCATION_H_
#define C_TINY_GPS_PLUS_LOCATION_H_

#include <stdbool.h>
#include <stdint.h>

/**
 * \brief Location structure (latitude and longitude).
 */
typedef struct
{
    bool valid;                         /**< Is valid flasg. */
    bool updated;                       /**< Is updated flag. */
    raw_degrees_t raw_lat_data;         /**< Raw latitude data. */
    raw_degrees_t raw_lng_data;         /**< Raw longitude data. */
    raw_degrees_t raw_new_lat_data;     /**< Raw new latitude data. */
    raw_degrees_t raw_new_lng_data;     /**< Raw new longitude data. */
    uint32_t last_commit_time;          /**< Last commit time stamp. */
} c_tiny_gps_plus_location_t;

/**
 * \brief Initializes a c_tiny_gps_plus_location_t structure.
 *
 * \param[in,out] location c_tiny_gps_plus_location_t is structure to initialize.
 *
 * \return None.
 */
void c_tiny_gps_plus_location_init(c_tiny_gps_plus_location_t *location);

/**
 * \brief Creates a new c_tiny_gps_plus_location_t structure.
 *
 * \return A new c_tiny_gps_plus_location_t structure.
 */
c_tiny_gps_plus_location_t c_tiny_gps_plus_location_gen();

/**
 * \brief Verifies if a given location has valid data.
 *
 * \param[in] location is the c_tiny_gps_plus_location_t structure to verify if its data is valid.
 *
 * \return TRUE/FALSE if the current location data is valid.
 */
bool c_tiny_gps_plus_location_is_valid(c_tiny_gps_plus_location_t location);

/**
 * \brief Verifies if a given location has a updated data.
 *
 * \param[in] location is the c_tiny_gps_plus_location_t structure to verify if its data is updated.
 *
 * \return TRUE/FALSE if the current location data is updated.
 */
bool c_tiny_gps_plus_location_is_updated(c_tiny_gps_plus_location_t location);

/**
 * \brief .
 *
 * \param[in] location 
 *
 * \return .
 */
uint32_t c_tiny_gps_plus_location_age(c_tiny_gps_plus_location_t location);

/**
 * \brief .
 *
 * \param[in,out] location 
 *
 * \return .
 */
c_tiny_gps_plus_raw_degrees_t c_tiny_gps_plus_location_raw_lat(c_tiny_gps_plus_location_t *location);

/**
 * \brief .
 *
 * \param[in,out] location 
 *
 * \return .
 */
c_tiny_gps_plus_raw_degrees_t c_tiny_gps_plus_location_raw_lng(c_tiny_gps_plus_location_t *location);

/**
 * \brief Gets the latitude of a location structure.
 *
 * \param[in,out] location is the c_tiny_gps_plus_location_t to get the latitude.
 *
 * \return The laitude of a given location.
 */
double c_tiny_gps_plus_location_lat(c_tiny_gps_plus_location_t *location);

/**
 * \brief Gets the longitude of a location structure.
 *
 * \param[in,out] location is the c_tiny_gps_plus_location_t to get the longitude.
 *
 * \return The longitude of a given location.
 */
double c_tiny_gps_plus_location_lng(c_tiny_gps_plus_location_t *location);

/**
 * \brief .
 *
 * \param[in,out] location 
 *
 * \return None.
 */
void c_tiny_gps_plus_location_commit(c_tiny_gps_plus_location_t *location);

/**
 * \brief Sets the latitude of a location structure.
 *
 * \param[in,out] location is a c_tiny_gps_plus_location_t structure to set the latitude.
 * \param[in,out] term 
 *
 * \return None.
 */
void c_tiny_gps_plus_location_set_latitude(c_tiny_gps_plus_location_t *location, const char *term);

/**
 * \brief Sets the longitude of a location structure.
 *
 * \param[in,out] location is a c_tiny_gps_plus_location_t structure to set the longitude.
 * \param[in,out] term 
 *
 * \return None.
 */
void c_tiny_gps_plus_location_set_longitude(c_tiny_gps_plus_location_t *location, const char *term);

#endif // C_TINY_GPS_PLUS_LOCATION_H_

//! \} End of c_tiny_gps_plus_location group
