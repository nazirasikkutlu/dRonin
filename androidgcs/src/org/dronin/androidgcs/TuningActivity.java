/**
 ******************************************************************************
 * @file       TuningActivity.java
 * @author     Tau Labs, http://taulabs.org, Copyright (C) 2012-2013
 * @brief      The activity for tuning the stabilization parameters
 * @see        The GNU Public License (GPL) Version 3
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

package org.dronin.androidgcs;

import org.dronin.androidgcs.drawer.NavDrawerActivityConfiguration;
import org.dronin.androidgcs.util.SmartSave;
import org.dronin.androidgcs.views.ScrollBarView;
import org.dronin.uavtalk.UAVDataObject;

import android.os.Bundle;
import android.util.Log;
import android.view.WindowManager;
import android.widget.Button;

public class TuningActivity extends ObjectManagerActivity {
	private final String TAG = TuningActivity.class.getSimpleName();

	private final boolean DEBUG = false;

	private SmartSave smartSave;

	/** Called when the activity is first created. */
	@Override
	public void onCreate(Bundle savedInstanceState) {
		getWindow().setSoftInputMode(WindowManager.LayoutParams.SOFT_INPUT_STATE_HIDDEN);

		super.onCreate(savedInstanceState);
	}
	
	@Override
	protected NavDrawerActivityConfiguration getNavDrawerConfiguration() {
		NavDrawerActivityConfiguration navDrawer = getDefaultNavDrawerConfiguration();
		navDrawer.setMainLayout(R.layout.tuning);
		return navDrawer;
	}
	
	@Override
	void onConnected() {
		super.onConnected();

		if (DEBUG) Log.d(TAG, "onConnected()");

		// Subscribe to updates from ManualControlCommand and show the values for crude feedback
		UAVDataObject stabilizationSettings = (UAVDataObject) objMngr.getObject("StabilizationSettings");
		
		// Stabilization settings not found so tuning will not work
		if (stabilizationSettings == null)
			return;

		smartSave = new SmartSave(objMngr, this,
				stabilizationSettings,
				(Button) findViewById(R.id.saveBtn),
				(Button) findViewById(R.id.applyBtn),
				(Button) findViewById(R.id.loadBtn));

		smartSave.addControlMapping((ScrollBarView) findViewById(R.id.rollRateKp), "RollRatePID", 0);
		smartSave.addControlMapping((ScrollBarView) findViewById(R.id.rollRateKi), "RollRatePID", 1);
		smartSave.addControlMapping((ScrollBarView) findViewById(R.id.rollRateKd), "RollRatePID", 2);
		smartSave.addControlMapping((ScrollBarView) findViewById(R.id.pitchRateKp), "PitchRatePID", 0);
		smartSave.addControlMapping((ScrollBarView) findViewById(R.id.pitchRateKi), "PitchRatePID", 1);
		smartSave.addControlMapping((ScrollBarView) findViewById(R.id.pitchRateKd), "PitchRatePID", 2);
		smartSave.addControlMapping((ScrollBarView) findViewById(R.id.yawRateKp), "YawRatePID", 0);
		smartSave.addControlMapping((ScrollBarView) findViewById(R.id.yawRateKi), "YawRatePID", 1);
		smartSave.addControlMapping((ScrollBarView) findViewById(R.id.yawRateKd), "YawRatePID", 2);
		smartSave.addControlMapping((ScrollBarView) findViewById(R.id.rollKp), "RollPI", 0);
		smartSave.addControlMapping((ScrollBarView) findViewById(R.id.pitchKp), "PitchPI", 0);
		smartSave.fetchSettings(); // Robustly request an update of the settings
		smartSave.refreshSettingsDisplay();
	}

}
