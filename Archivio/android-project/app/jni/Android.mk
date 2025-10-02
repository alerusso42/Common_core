LOCAL_PATH := $(call my-dir)
JNI_PATH = $(LOCAL_PATH)

# --- SDL2 shared library ---
include $(CLEAR_VARS)
LOCAL_MODULE := SDL2
LOCAL_LDLIBS := -llog -landroid -lOpenSLES -lGLESv1_CM -lGLESv2
LOCAL_CFLAGS += -DGL_GLEXT_PROTOTYPES
LOCAL_SRC_FILES := \
	$(subst $(LOCAL_PATH)/,, \
	$(wildcard $(LOCAL_PATH)/src/*.c) \
	$(wildcard $(LOCAL_PATH)/src/audio/*.c) \
	$(wildcard $(LOCAL_PATH)/src/audio/android/*.c) \
	$(wildcard $(LOCAL_PATH)/src/audio/dummy/*.c) \
	$(wildcard $(LOCAL_PATH)/src/audio/aaudio/*.c) \
	$(wildcard $(LOCAL_PATH)/src/audio/openslES/*.c) \
	$(LOCAL_PATH)/src/atomic/SDL_atomic.c.arm \
	$(LOCAL_PATH)/src/atomic/SDL_spinlock.c.arm \
	$(wildcard $(LOCAL_PATH)/src/core/android/*.c) \
	$(wildcard $(LOCAL_PATH)/src/cpuinfo/*.c) \
	$(wildcard $(LOCAL_PATH)/src/dynapi/*.c) \
	$(wildcard $(LOCAL_PATH)/src/events/*.c) \
	$(wildcard $(LOCAL_PATH)/src/file/*.c) \
	$(wildcard $(LOCAL_PATH)/src/haptic/*.c) \
	$(wildcard $(LOCAL_PATH)/src/haptic/android/*.c) \
	$(wildcard $(LOCAL_PATH)/src/hidapi/*.c) \
	$(wildcard $(LOCAL_PATH)/src/hidapi/android/*.cpp) \
	$(wildcard $(LOCAL_PATH)/src/joystick/*.c) \
	$(wildcard $(LOCAL_PATH)/src/joystick/android/*.c) \
	$(wildcard $(LOCAL_PATH)/src/joystick/dummy/*.c) \
	$(wildcard $(LOCAL_PATH)/src/joystick/hidapi/*.c) \
	$(wildcard $(LOCAL_PATH)/src/joystick/virtual/*.c) \
	$(wildcard $(LOCAL_PATH)/src/loadso/dlopen/*.c) \
	$(wildcard $(LOCAL_PATH)/src/locale/*.c) \
	$(wildcard $(LOCAL_PATH)/src/locale/android/*.c) \
	$(wildcard $(LOCAL_PATH)/src/misc/*.c) \
	$(wildcard $(LOCAL_PATH)/src/misc/android/*.c) \
	$(wildcard $(LOCAL_PATH)/src/power/*.c) \
	$(wildcard $(LOCAL_PATH)/src/power/android/*.c) \
	$(wildcard $(LOCAL_PATH)/src/filesystem/android/*.c) \
	$(wildcard $(LOCAL_PATH)/src/sensor/*.c) \
	$(wildcard $(LOCAL_PATH)/src/sensor/android/*.c) \
	$(wildcard $(LOCAL_PATH)/src/render/*.c) \
	$(wildcard $(LOCAL_PATH)/src/render/*/*.c) \
	$(wildcard $(LOCAL_PATH)/src/stdlib/*.c) \
	$(wildcard $(LOCAL_PATH)/src/thread/*.c) \
	$(wildcard $(LOCAL_PATH)/src/thread/pthread/*.c) \
	$(wildcard $(LOCAL_PATH)/src/timer/*.c) \
	$(wildcard $(LOCAL_PATH)/src/timer/unix/*.c) \
	$(wildcard $(LOCAL_PATH)/src/video/*.c) \
	$(wildcard $(LOCAL_PATH)/src/video/android/*.c) \
	$(wildcard $(LOCAL_PATH)/src/video/yuv2rgb/*.c) \
	$(wildcard $(LOCAL_PATH)/src/test/*.c))

LOCAL_C_INCLUDES := $(LOCAL_PATH)/SDL2/include
LOCAL_STATIC_LIBRARIES := cpufeatures
LOCAL_LDLIBS := -llog -landroid -lOpenSLES -lGLESv1_CM -lGLESv2
include $(BUILD_SHARED_LIBRARY)

# SDL2_image
#include /home/alerusso/Common_core/Archivio/android-project/app/jni/SDL_image/Android.mk

# SDL2_mixer
#include /home/alerusso/Common_core/Archivio/android-project/app/jni/SDL_mixer/Android.mk

TEMP := $(LOCAL_PATH)
include $(LOCAL_PATH)/SDL_image/Android.mk
LOCAL_PATH := $(TEMP)
include $(LOCAL_PATH)/SDL_mixer/Android.mk
LOCAL_PATH := $(TEMP)

# --- libdaft ---
include $(CLEAR_VARS)
LOCAL_MODULE := libdaft

# Tutti i sorgenti .c nelle cartelle specificate
DAFT_PATH := $(LOCAL_PATH)/../src/program
LOCAL_SRC_FILES := \
    $(wildcard $(DAFT_PATH)/Libft/*.c) \
    $(wildcard $(DAFT_PATH)/daft_src/*.c) \
    $(wildcard $(DAFT_PATH)/prep_src/*.c)

# Include headers (aggiungi qui se ne hai di dedicati)
LOCAL_C_INCLUDES := \
    $(LOCAL_PATH)/SDL2/include \
    $(DAFT_PATH)/Libft \
    $(DAFT_PATH)/daft_src \
    $(DAFT_PATH)/prep_src \
	$(DAFT_PATH)/../

include $(BUILD_STATIC_LIBRARY)


# --- main ---
include $(CLEAR_VARS)
LOCAL_MODULE := main
PROJ_PATH := ../src/srcs/

# Tutti i sorgenti del Pacman
LOCAL_SRC_FILES := $(addprefix $(PROJ_PATH), \
main.c \
utils/error.c utils/android_input.c  utils/map.c   utils/math.c    utils/mem.c   utils/random.c      utils/sound.c \
utils/files.c  utils/map2.c  utils/matrix.c  utils/move.c  utils/set_entity.c  utils/time.c \
SDL/init.c  SDL/input.c  SDL/loop.c  SDL/quit.c \
engine/animations.c  engine/map_render.c \
IA/bfs.c  IA/bfs_draw.c  IA/bfs_utils.c  IA/move_enemy.c  IA/move_types.c  IA/triggered.c \
map/get_map.c \
debug/map.c debug/android.c)
$(info $(LOCAL_SRC_FILES))

# Include headers
LOCAL_C_INCLUDES := \
    $(LOCAL_PATH)/SDL2/include \
    $(LOCAL_PATH)/SDL_image/include \
    $(LOCAL_PATH)/SDL_mixer/include \
    $(PROJ_PATH)/../includes \
    $(PROJ_PATH)/../includes/media \
    $(DAFT_PATH)/../../
LOCAL_STATIC_LIBRARIES := libdaft
LOCAL_SHARED_LIBRARIES := SDL2 SDL2_image SDL2_mixer
LOCAL_LDLIBS := -llog -landroid -lOpenSLES -lGLESv1_CM -lGLESv2
include $(BUILD_SHARED_LIBRARY)

# --- cpufeatures ---
include $(CLEAR_VARS)
LOCAL_MODULE    := cpufeatures
LOCAL_LDLIBS := -llog -landroid -lOpenSLES -lGLESv1_CM -lGLESv2
LOCAL_SRC_FILES := 3rdparty/cpufeatures/cpu-features.c
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/3rdparty/cpufeatures
include $(BUILD_STATIC_LIBRARY)
