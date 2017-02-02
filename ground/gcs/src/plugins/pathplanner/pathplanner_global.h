/**
 ******************************************************************************
 * @file       pathplanner_global.h
 * @author     Tau Labs, http://taulabs.org, Copyright (C) 2012-2013
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup Path Planner Plugin
 * @{
 * @brief global include for the library
 *****************************************************************************/
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

#ifndef PATHPLANNER_GLOBAL_H
#define PATHPLANNER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PATHPLANNER_LIBRARY)
#  define PATHPLANNER_EXPORT Q_DECL_EXPORT
#else
#  define PATHPLANNER_EXPORT Q_DECL_IMPORT
#endif

#endif // PATHPLANNER_GLOBAL_H

