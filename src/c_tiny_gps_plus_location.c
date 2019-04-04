/*
 * c_tiny_gps_plus_location.c
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
 * \brief Location struct implementation.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 0.1.0
 * 
 * \date 03/04/2019
 * 
 * \addtogroup c_tiny_gps_plus_location
 * \{
 */

#include <limits.h>

#include "c_tiny_gps_plus_location.h"

void c_tiny_gps_plus_location_init(c_tiny_gps_plus_location_t *location);
{
    location->valid = false;

    location->updated = false;
}

c_tiny_gps_plus_location_t c_tiny_gps_plus_location_gen()
{
    c_tiny_gps_plus_location_t location;

    location.valid = false;

    location.updated = false;

    return location;
}

bool c_tiny_gps_plus_location_is_valid(c_tiny_gps_plus_location_t location)
{
    return location.valid;
}

bool c_tiny_gps_plus_location_is_updated(c_tiny_gps_plus_location_t location)
{
    return location.updated;
}

uint32_t c_tiny_gps_plus_location_age(c_tiny_gps_plus_location_t location)
{
    return location.valid ? millis() - location.last_commit_time : (uint32_t)ULONG_MAX;
}

c_tiny_gps_plus_raw_degrees_t c_tiny_gps_plus_location_raw_lat(c_tiny_gps_plus_location_t *location)
{
    location->updated = false;

    return location->raw_lat_data;
}

c_tiny_gps_plus_raw_degrees_t c_tiny_gps_plus_location_raw_lng(c_tiny_gps_plus_location_t *location)
{
    location->updated = false;

    return location->raw_lng_data;
}

double c_tiny_gps_plus_location_lat(c_tiny_gps_plus_location_t *location)
{
    location->updated = false;

    double ret = location->raw_lat_data.deg + location->raw_lat_data.billionths / 1000000000.0;

    return location->raw_lat_data.negative ? -ret : ret;
}

double c_tiny_gps_plus_location_lng(c_tiny_gps_plus_location_t *location)
{
    location->updated = false;

    double ret = location->raw_lng_data.deg + location->raw_lng_data.billionths / 1000000000.0;

    return location->raw_lng_data.negative ? -ret : ret;
}

void c_tiny_gps_plus_location_commit(c_tiny_gps_plus_location_t *location)
{
    location->raw_lat_data = location->raw_new_lat_data;
    location->raw_lng_data = location->raw_new_lng_data;
    location->last_commit_time = millis();
    location->valid = true;
    location->updated = true;
}

void c_tiny_gps_plus_location_set_latitude(c_tiny_gps_plus_location_t *location, const char *term)
{
    TinyGPSPlus::parseDegrees(term, location->raw_new_lat_data);
}

void c_tiny_gps_plus_location_set_longitude(c_tiny_gps_plus_location_t *location, const char *term)
{
    TinyGPSPlus::parseDegrees(term, location->raw_new_lng_data);
}

//! \} End of c_tiny_gps_plus_location group
