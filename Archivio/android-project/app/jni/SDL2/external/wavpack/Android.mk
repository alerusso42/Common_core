LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := wavpack
LOCAL_SRC_FILES := $(wildcard src/*.c)  # o src/*.c se ci sono sottocartelle
LOCAL_C_INCLUDES := $(LOCAL_PATH)/include

include $(BUILD_STATIC_LIBRARY)
