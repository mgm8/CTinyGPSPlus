/*
 * c_tiny_gps_plus_date.h
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
 * \brief Date struct definition.
 * 
 * \author Gabriel Mariano Marcelino <gabriel.mm8@gmail.com>
 * 
 * \version 0.1.0
 * 
 * \date 03/04/2019
 * 
 * \defgroup c_tiny_gps_plus_date Date
 * \ingroup c_tiny_gps_plus
 * \{
 */

#ifndef C_TINY_GPS_PLUS_DATE_H_
#define C_TINY_GPS_PLUS_DATE_H_

#include <stdbool.h>
#include <stdint.h>

/**
 * \brief Date structure.
 */
typedef struct
{
    bool valid;                     /**< Is valid flag. */
    bool updated;                   /**< Is updated flag. */
    uint32_t date;                  /**< Date. */
    uint32_t new_date;              /**< New date. */
    uint32_t last_commit_time;      /**< Last commit time stamp. */
} c_tiny_gps_plus_date_t;

/**
 * \brief Initializes a c_tiny_gps_plus_date_t structure.
 *
 * \param[in] date is the c_tiny_gps_plus_date_t structure to initialize.
 *
 * \return None.
 */
void c_tiny_gps_plus_date_init(c_tiny_gps_plus_date_t *date);

/**
 * \brief Creates a c_tiny_gps_plus_date_t structure.
 *
 * \return A new c_tiny_gps_plus_date_t structure.
 */
c_tiny_gps_plus_date_t c_tiny_gps_plus_date_gen();

/**
 * \brief .
 *
 * \param[in] date is the c_tiny_gps_plus_date_t structure to get the "is_valid" flag.
 *
 * \return .
 */
bool c_tiny_gps_plus_date_is_valid(c_tiny_gps_plus_date_t date);

/**
 * \brief .
 *
 * \param[in] date is the c_tiny_gps_plus_date_t structure to get the "is_updated" flag.
 *
 * \return .
 */
bool c_tiny_gps_plus_date_is_updated(c_tiny_gps_plus_date_t date);

/**
 * \brief .
 *
 * \param[in] date is the c_tiny_gps_plus_date_t structure to get the age.
 *
 * \return .
 */
uint32_t c_tiny_gps_plus_date_age(c_tiny_gps_plus_date_t date);

/**
 * \brief .
 *
 * \param[in,out] date
 *
 * \return .
 */
uint32_t c_tiny_gps_plus_date_value(c_tiny_gps_plus_date_t *date);

/**
 * \brief .
 *
 * \param[in] date is the c_tiny_gps_plus_date_t structure to get the year.
 *
 * \return .
 */
uint16_t c_tiny_gps_plus_date_year(c_tiny_gps_plus_date_t *date);

/**
 * \brief .
 *
 * \param[in] date is the c_tiny_gps_plus_date_t structure to get the month.
 *
 * \return .
 */
uint8_t c_tiny_gps_plus_date_month(c_tiny_gps_plus_date_t *date);

/**
 * \brief .
 *
 * \param[in] date is the c_tiny_gps_plus_date_t structure to get the day.
 *
 * \return .
 */
uint8_t c_tiny_gps_plus_date_day(c_tiny_gps_plus_date_t *date);

/**
 * \brief .
 *
 * \param[in,out] date
 *
 * \return None.
 */
void c_tiny_gps_plus_date_commit(c_tiny_gps_plus_date_t *date);

/**
 * \brief .
 *
 * \param[in,out] date
 * \param[in,out] term
 *
 * \return None.
 */
void c_tiny_gps_plus_date_set_date(c_tiny_gps_plus_date_t *date, const char *term);

#endif // C_TINY_GPS_PLUS_DATE_H_

//! \} End of c_tiny_gps_plus_date group
