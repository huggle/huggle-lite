# Instructions for android

Use script configure_droid for automatic configuration, you need to have Qt for Android installed,
you also need to have these paths on your system

* /opt/android-ndk - points to NDK
* /opt/android-sdk - points to SDK
* /opt/android-toolchain

Tested and working versions:

* android-ndk-r10e
* android-sdk - latest with tools 19.1.0
* Qt 5.6.3

How to generate toolchain:

```
cd $ANDROID_NDK/build/tools
sudo ./make-standalone-toolchain.sh --ndk-dir=/media/android/android-ndk-r10e/ --install-dir=/opt/android-toolchain --arch=arm --system=linux-x86_64
```

# Issues

You must have JDK installed and its path in JAVA_HOME environment variable, otherwise you are fucked, you also may have to update build.gradle and replace
compileSdkVersion to version 19 otherwise it won't build.

# Installing apk to device

```
# List devices
adb devices

# Upload the apk file
adb -s device_id push android_armv7_debug/build/outputs/apk/android_armv7_debug-debug.apk /data/local/tmp/org.wikimedia.HuggleLite

# Install it
adb -s device_id shell pm install -t -r "/data/local/tmp/org.wikimedia.HuggleLite"
```
