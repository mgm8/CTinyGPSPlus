/*
 * c_tiny_gps_plus_date.c
 * 
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
 * \brief Date struct implementation.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 0.1.0
 * 
 * \date 03/04/2019
 * 
 * \addtogroup c_tiny_gps_plus_date
 * \{
 */

#include <limits.h>

#include "date.h"

c_tiny_gps_plus_date_t c_tiny_gps_plus_date_init()
{
    c_tiny_gps_plus_date_t date;

    date.valid = false;
    date.updated = false;
    date.date = 0;

    return date;
}

bool c_tiny_gps_plus_date_is_valid(c_tiny_gps_plus_date_t date)
{
    return date.valid;
}

bool c_tiny_gps_plus_date_is_updated(c_tiny_gps_plus_date_t date)
{
    return date.updated;
}

uint32_t c_tiny_gps_plus_date_age(c_tiny_gps_plus_date_t date)
{
    return date.valid ? millis() - date.last_commit_time : (uint32_t)ULONG_MAX;
}

uint32_t c_tiny_gps_plus_date_value(c_tiny_gps_plus_date_t date)
{
    date->updated = false;

    return date->date
}

uint16_t c_tiny_gps_plus_date_year(c_tiny_gps_plus_date_t *date)
{
    date->updated = false;

    uint16_t year = date->date % 100;

    return year + 2000;
}

uint8_t c_tiny_gps_plus_date_month(c_tiny_gps_plus_date_t *date)
{
    date->updated = false;

    return (date->date / 100) % 100;
}

uint8_t c_tiny_gps_plus_date_day(c_tiny_gps_plus_date_t *date)
{
    date->updated = false;

    return date->date / 10000;
}

void c_tiny_gps_plus_date_commit(c_tiny_gps_plus_date_t *date)
{
    date->date = newDate;
    date->last_commit_time = millis();
    date->valid = true;
    date->updated = true;
}

void c_tiny_gps_plus_date_set_date(c_tiny_gps_plus_date_t *date, const char *term)
{
    date->new_date = atol(term);
}

//! \} End of c_tiny_gps_plus_date group
