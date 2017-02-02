/**
  ******************************************************************************
  * @addtogroup PIOS PIOS Core hardware abstraction layer
  * @{
  * @addtogroup PIOS_RESET Reset functions
  * @brief Hardware functions to deal with the reset register
  * @{
  *
  * @file       pios_reset.h
  * @author     Tau Labs, Copyright (C) 2015.
  * @brief      Reset information
  *
  ******************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>
 */

#ifndef PIOS_RESET_PRIV_H
#define PIOS_RESET_PRIV_H

// Private types
enum reboot_flags {
    PIOS_RESET_FLAG_UNDEFINED,            // Undefined reason
    PIOS_RESET_FLAG_BROWNOUT,             // POR/PDR or BOR reset
    PIOS_RESET_FLAG_PIN,                  // Pin reset
    PIOS_RESET_FLAG_POWERON,              // POR/PDR reset
    PIOS_RESET_FLAG_SOFTWARE,             // Software reset
    PIOS_RESET_FLAG_INDEPENDENT_WATCHDOG, // Independent Watchdog reset
    PIOS_RESET_FLAG_WINDOW_WATCHDOG,      // Window Watchdog reset
    PIOS_RESET_FLAG_LOW_POWER,            // Low Power reset
};


void PIOS_RESET_Clear (void);
int16_t PIOS_RESET_GetResetReason (void);

#endif /* PIOS_RESET_PRIV_H */
