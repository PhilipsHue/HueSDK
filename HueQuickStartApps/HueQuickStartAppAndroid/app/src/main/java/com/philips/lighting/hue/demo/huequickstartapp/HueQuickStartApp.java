package com.philips.lighting.hue.demo.huequickstartapp;

import android.app.Application;

import com.philips.lighting.hue.sdk.wrapper.HueLog;
import com.philips.lighting.hue.sdk.wrapper.Persistence;

public class HueQuickStartApp extends Application {

    static {
        // Load the huesdk native library before calling any SDK method
        System.loadLibrary("huesdk");
    }

    @Override
    public void onCreate() {
        super.onCreate();

        // Configure the storage location and log level for the Hue SDK
        Persistence.setStorageLocation(getFilesDir().getAbsolutePath(), "HueQuickStart");
        HueLog.setConsoleLogLevel(HueLog.LogLevel.INFO);
    }
}
