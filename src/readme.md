# Instructions for android

Use script configure_android_armv7 for automatic configuration, you need to have Qt for Android installed,
you also need to have these paths on your system

* /opt/android-ndk - points to NDK
* /opt/android-sdk - points to SDK
* /opt/android-toolchain

Tested and working versions:

* android-ndk-r10e
* android-sdk-linux_x86-1.6_r1

How to generate toolchain:

```
cd $ANDROID_NDK/build/tools
sudo ./make-standalone-toolchain.sh --ndk-dir=/media/android/android-ndk-r10e/ --install-dir=/opt/android-toolchain --arch=arm --system=linux-x86_64
```


