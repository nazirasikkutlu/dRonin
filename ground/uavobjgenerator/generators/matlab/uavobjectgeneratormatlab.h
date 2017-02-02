/**
 ******************************************************************************
 *
 * @file       uavobjectgeneratormatlab.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 * @brief      produce matlab code for uavobjects
 *
 * @see        The GNU Public License (GPL) Version 3
 *
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

#ifndef UAVOBJECTGENERATORMATLAB_H
#define UAVOBJECTGENERATORMATLAB_H

#include "../generator_common.h"

class UAVObjectGeneratorMatlab
{
public:
    bool generate(UAVObjectParser* gen,QString templatepath,QString outputpath);

private:
    bool process_object(ObjectInfo* info, int numBytes);
    QString matlabInstantiationCode;
    QString matlabSwitchCode;
    QString matlabCleanupCode;
    QString matlabAllocationCode;
    QString matlabSaveObjectsCode;
    QString matlabExportCsvCode;
    QStringList fieldTypeStrMatlab;
    QStringList fieldSizeStrMatlab;

};

#endif
