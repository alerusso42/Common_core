LOCAL_PATH := $(call my-dir)

############################
# First: Your Game Module
############################
include $(CLEAR_VARS)

LOCAL_MODULE := main

LOCAL_C_INCLUDES := $(LOCAL_PATH)/includes

# Add all your C sources here
LOCAL_SRC_FILES := \
    srcs/main.c \
    srcs/engine/animation.c srcs/engine/map_render.c \
    srcs/SDL/init.c srcs/SDL/input.c srcs/SDL/loop.c srcs/SDL/quit.c \
    srcs/IA/bfs.c srcs/IA/bfs_draw.c srcs/IA/bfs_utils.c srcs/IA/move_enemy.c srcs/IA/triggered.c \
    srcs/map/get_map.c \
    srcs/utils/error.c srcs/utils/files.c srcs/utils/map.c srcs/utils/map2.c srcs/utils/math.c srcs/utils/matrix.c \
	srcs/utils/mem.c srcs/utils/move.c srcs/utils/random.c srcs/utils/set_entity.c srcs/utils/sound.c srcs/utils/time.c \
    srcs/debug/map.c

# You can use wildcards too (NDK supports them)
# But safer and more portable to list files manually

LOCAL_STATIC_LIBRARIES := daftlib

LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -llog -landroid

include $(BUILD_SHARED_LIBRARY)

############################
# Then: Link your static lib
############################
include $(CLEAR_VARS)

LOCAL_MODULE := daftlib
LOCAL_SRC_FILES := daft/daft.a
include $(PREBUILT_STATIC_LIBRARY)
