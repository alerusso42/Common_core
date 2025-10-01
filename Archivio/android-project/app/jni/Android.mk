LOCAL_PATH := $(call my-dir)

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

# --- SDL_image ---

SDL_IMAGE_LOCAL_PATH := $(call my-dir)


# Enable this if you want PNG and JPG support with minimal dependencies
USE_STBIMAGE ?= true

# The additional formats below require downloading third party dependencies,
# using the external/download.sh script.

# Enable this if you want to support loading AVIF images
# The library path should be a relative path to this directory.
SUPPORT_AVIF ?= false
AVIF_LIBRARY_PATH := external/libavif
DAV1D_LIBRARY_PATH := external/dav1d

# Enable this if you want to support loading JPEG images using libjpeg
# The library path should be a relative path to this directory.
SUPPORT_JPG ?= false
SUPPORT_SAVE_JPG ?= true
JPG_LIBRARY_PATH := external/jpeg

# Enable this if you want to support loading JPEG-XL images
# The library path should be a relative path to this directory.
SUPPORT_JXL ?= false
JXL_LIBRARY_PATH := external/libjxl

# Enable this if you want to support loading PNG images using libpng
# The library path should be a relative path to this directory.
SUPPORT_PNG ?= false
SUPPORT_SAVE_PNG ?= true
PNG_LIBRARY_PATH := external/libpng

# Enable this if you want to support loading WebP images
# The library path should be a relative path to this directory.
SUPPORT_WEBP ?= false
WEBP_LIBRARY_PATH := external/libwebp


# Build the library
ifeq ($(SUPPORT_AVIF),true)
    include $(SDL_IMAGE_LOCAL_PATH)/$(AVIF_LIBRARY_PATH)/Android.mk
    include $(SDL_IMAGE_LOCAL_PATH)/$(DAV1D_LIBRARY_PATH)/Android.mk
endif

# Build the library
ifeq ($(SUPPORT_JPG),true)
    include $(SDL_IMAGE_LOCAL_PATH)/$(JPG_LIBRARY_PATH)/Android.mk
endif

# Build the library
ifeq ($(SUPPORT_JXL),true)
    include $(SDL_IMAGE_LOCAL_PATH)/$(JXL_LIBRARY_PATH)/Android.mk
endif

# Build the library
ifeq ($(SUPPORT_PNG),true)
    include $(SDL_IMAGE_LOCAL_PATH)/$(PNG_LIBRARY_PATH)/Android.mk
endif

# Build the library
ifeq ($(SUPPORT_WEBP),true)
    include $(SDL_IMAGE_LOCAL_PATH)/$(WEBP_LIBRARY_PATH)/Android.mk
endif


# Restore local path
LOCAL_PATH := $(SDL_IMAGE_LOCAL_PATH)

include $(CLEAR_VARS)

LOCAL_MODULE := SDL2_image
SDL_IMAGE_PATH := "$(LOCAL_PATH)/SDL2/image/"

LOCAL_SRC_FILES :=  $(addprefix $(SDL_IMAGE_PATH), \
    src/IMG.c           \
    src/IMG_avif.c      \
    src/IMG_bmp.c       \
    src/IMG_gif.c       \
    src/IMG_jpg.c       \
    src/IMG_jxl.c       \
    src/IMG_lbm.c       \
    src/IMG_pcx.c       \
    src/IMG_png.c       \
    src/IMG_pnm.c       \
    src/IMG_qoi.c       \
    src/IMG_stb.c       \
    src/IMG_svg.c       \
    src/IMG_tga.c       \
    src/IMG_tif.c       \
    src/IMG_webp.c      \
    src/IMG_WIC.c       \
    src/IMG_xcf.c       \
    src/IMG_xpm.c.arm   \
    src/IMG_xv.c)

LOCAL_C_INCLUDES += $(SDL_IMAGE_PATH)/include
LOCAL_CFLAGS := -DLOAD_BMP -DLOAD_GIF -DLOAD_LBM -DLOAD_PCX -DLOAD_PNM \
                -DLOAD_SVG -DLOAD_TGA -DLOAD_XCF -DLOAD_XPM -DLOAD_XV  \
                -DLOAD_QOI
LOCAL_LDLIBS :=
LOCAL_STATIC_LIBRARIES :=
LOCAL_SHARED_LIBRARIES := SDL2

ifeq ($(USE_STBIMAGE),true)
    LOCAL_CFLAGS += -DLOAD_JPG -DLOAD_PNG -DUSE_STBIMAGE
endif

ifeq ($(SUPPORT_AVIF),true)
    LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(AVIF_LIBRARY_PATH)/include
    LOCAL_CFLAGS += -DLOAD_AVIF
    LOCAL_STATIC_LIBRARIES += avif
    LOCAL_WHOLE_STATIC_LIBRARIES += dav1d dav1d-8bit dav1d-16bit
endif

ifeq ($(SUPPORT_JPG),true)
    LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(JPG_LIBRARY_PATH)              \
                        $(LOCAL_PATH)/$(JPG_LIBRARY_PATH)/android
    LOCAL_CFLAGS += -DLOAD_JPG
    LOCAL_STATIC_LIBRARIES += jpeg
ifeq ($(SUPPORT_SAVE_JPG),true)
    LOCAL_CFLAGS += -DSDL_IMAGE_SAVE_JPG=1
else
    LOCAL_CFLAGS += -DSDL_IMAGE_SAVE_JPG=0
endif
endif

ifeq ($(SUPPORT_JXL),true)
    LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(JXL_LIBRARY_PATH)/lib/include \
                        $(LOCAL_PATH)/$(JXL_LIBRARY_PATH)/android
    LOCAL_CFLAGS += -DLOAD_JXL
    LOCAL_STATIC_LIBRARIES += jxl
endif

ifeq ($(SUPPORT_PNG),true)
    LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(PNG_LIBRARY_PATH)             \
                        $(LOCAL_PATH)/$(PNG_LIBRARY_PATH)/android
    LOCAL_CFLAGS += -DLOAD_PNG
    LOCAL_STATIC_LIBRARIES += png
    LOCAL_LDLIBS += -lz
ifeq ($(SUPPORT_SAVE_PNG),true)
    LOCAL_CFLAGS += -DSDL_IMAGE_SAVE_PNG=1
else
    LOCAL_CFLAGS += -DSDL_IMAGE_SAVE_PNG=0
endif
endif

ifeq ($(SUPPORT_WEBP),true)
    LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(WEBP_LIBRARY_PATH)/src
    LOCAL_CFLAGS += -DLOAD_WEBP
    LOCAL_STATIC_LIBRARIES += webpdemux
    LOCAL_STATIC_LIBRARIES += webp
endif

LOCAL_EXPORT_C_INCLUDES += $(SDL_IMAGE_PATH)/include

include $(BUILD_SHARED_LIBRARY)

###########################
#
# SDL2_image static library
#
###########################

LOCAL_MODULE := SDL2_image_static

LOCAL_MODULE_FILENAME := libSDL2_image

LOCAL_LDLIBS :=
LOCAL_EXPORT_LDLIBS :=

include $(BUILD_STATIC_LIBRARY)

# --- SDL_mixer ---

# Save the local path
SDL_MIXER_LOCAL_PATH := $(call my-dir)

# Enable this if you want to support loading WAV music
SUPPORT_WAV ?= true

# Enable this if you want to support loading FLAC music via dr_flac
SUPPORT_FLAC_DRFLAC ?= true

# Enable this if you want to support loading FLAC music with libFLAC
SUPPORT_FLAC_LIBFLAC ?= false
FLAC_LIBRARY_PATH := external/flac

# Enable this if you want to support loading OGG Vorbis music via stb_vorbis
SUPPORT_OGG_STB ?= true

# Enable this if you want to support loading OGG Vorbis music via Tremor
SUPPORT_OGG ?= false
OGG_LIBRARY_PATH := external/ogg
VORBIS_LIBRARY_PATH := external/tremor

# Enable this if you want to support loading MP3 music via MINIMP3
SUPPORT_MP3_MINIMP3 ?= true

# Enable this if you want to support loading MP3 music via MPG123
SUPPORT_MP3_MPG123 ?= false
MPG123_LIBRARY_PATH := external/mpg123

# Enable this if you want to support loading WavPack music via libwavpack
SUPPORT_WAVPACK ?= true
WAVPACK_LIBRARY_PATH := external/wavpack

# Enable this if you want to support loading music via libgme
SUPPORT_GME ?= false
GME_LIBRARY_PATH := external/libgme

# Enable this if you want to support loading MOD music via XMP-lite
SUPPORT_MOD_XMP ?= false
XMP_LIBRARY_PATH := external/libxmp

# Enable this if you want to support TiMidity
SUPPORT_MID_TIMIDITY ?= false
TIMIDITY_LIBRARY_PATH := src/codecs/timidity


# Build the library
ifeq ($(SUPPORT_FLAC_LIBFLAC),true)
    include $(SDL_MIXER_LOCAL_PATH)/$(FLAC_LIBRARY_PATH)/Android.mk
endif

# Build the library
ifeq ($(SUPPORT_OGG),true)
    include $(SDL_MIXER_LOCAL_PATH)/$(OGG_LIBRARY_PATH)/Android.mk
    include $(SDL_MIXER_LOCAL_PATH)/$(VORBIS_LIBRARY_PATH)/Android.mk
endif

# Build the library
ifeq ($(SUPPORT_MP3_MPG123),true)
    include $(SDL_MIXER_LOCAL_PATH)/$(MPG123_LIBRARY_PATH)/Android.mk
endif

# Build the library
ifeq ($(SUPPORT_WAVPACK),true)
    include $(SDL_MIXER_LOCAL_PATH)/$(WAVPACK_LIBRARY_PATH)/Android.mk
endif

# Build the library
ifeq ($(SUPPORT_GME),true)
    include $(SDL_MIXER_LOCAL_PATH)/$(GME_LIBRARY_PATH)/Android.mk
endif

# Build the library
ifeq ($(SUPPORT_MOD_XMP),true)
    include $(SDL_MIXER_LOCAL_PATH)/$(XMP_LIBRARY_PATH)/Android.mk
endif

# Build the library
ifeq ($(SUPPORT_MID_TIMIDITY),true)
    include $(SDL_MIXER_LOCAL_PATH)/$(TIMIDITY_LIBRARY_PATH)/Android.mk
endif


# Restore local path
LOCAL_PATH := $(SDL_MIXER_LOCAL_PATH)

include $(CLEAR_VARS)

LOCAL_MODULE := SDL2_mixer
SDL_MIXER_PATH := $(LOCAL_PATH)/"SDL2/mixer/"
LOCAL_C_INCLUDES :=                                     \
    $(SDL_MIXER_PATH)/include                               \
    $(SDL_MIXER_PATH)/src/                                  \
    $(SDL_MIXER_PATH)/src/codecs                            \

LOCAL_SRC_FILES :=                                      \
    $(subst $(SDL_MIXER_PATH)/,,                            \
    $(wildcard $(SDL_MIXER_PATH)/src/*.c)                   \
    $(wildcard $(SDL_MIXER_PATH)/src/codecs/*.c)            \
    )

LOCAL_CFLAGS :=
LOCAL_LDLIBS :=
LOCAL_STATIC_LIBRARIES :=
LOCAL_SHARED_LIBRARIES := SDL2

ifeq ($(SUPPORT_WAV),true)
    LOCAL_CFLAGS += -DMUSIC_WAV
endif

ifeq ($(SUPPORT_FLAC_DRFLAC),true)
    LOCAL_CFLAGS += -DMUSIC_FLAC_DRFLAC
endif

ifeq ($(SUPPORT_FLAC_LIBFLAC),true)
    LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(FLAC_LIBRARY_PATH)/include
    LOCAL_CFLAGS += -DMUSIC_FLAC_LIBFLAC
    LOCAL_STATIC_LIBRARIES += libFLAC
endif

ifeq ($(SUPPORT_OGG_STB),true)
    LOCAL_CFLAGS += -DMUSIC_OGG -DOGG_USE_STB
endif

ifeq ($(SUPPORT_OGG),true)
    LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(OGG_LIBRARY_PATH)/include
    LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(VORBIS_LIBRARY_PATH)
    LOCAL_CFLAGS += -DMUSIC_OGG -DOGG_USE_TREMOR -DOGG_HEADER="<ivorbisfile.h>"
    LOCAL_STATIC_LIBRARIES += ogg vorbisidec
endif

ifeq ($(SUPPORT_MP3_MINIMP3),true)
    LOCAL_CFLAGS += -DMUSIC_MP3_MINIMP3
endif

# This needs to be a shared library to comply with the LGPL license
ifeq ($(SUPPORT_MP3_MPG123),true)
    LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(MPG123_LIBRARY_PATH)/android
    LOCAL_CFLAGS += -DMUSIC_MP3_MPG123
    LOCAL_SHARED_LIBRARIES += mpg123
endif

ifeq ($(SUPPORT_WAVPACK),true)
    LOCAL_CFLAGS += -DMUSIC_WAVPACK -DMUSIC_WAVPACK_DSD -DWAVPACK_HEADER=\"../external/wavpack/include/wavpack.h\"
    LOCAL_STATIC_LIBRARIES += wavpack
endif

ifeq ($(SUPPORT_GME),true)
    LOCAL_CFLAGS += -DMUSIC_GME
    LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(GME_LIBRARY_PATH)
    LOCAL_STATIC_LIBRARIES += libgme
endif

ifeq ($(SUPPORT_MOD_XMP),true)
    LOCAL_CFLAGS += -DMUSIC_MOD_XMP -DLIBXMP_HEADER=\"../external/libxmp/include/xmp.h\"
    LOCAL_STATIC_LIBRARIES += xmp
endif

ifeq ($(SUPPORT_MID_TIMIDITY),true)
    LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(TIMIDITY_LIBRARY_PATH)
    LOCAL_CFLAGS += -DMUSIC_MID_TIMIDITY
    LOCAL_STATIC_LIBRARIES += timidity
endif

LOCAL_EXPORT_C_INCLUDES += $($(SDL_MIXER_PATH))/include

include $(BUILD_SHARED_LIBRARY)

###########################
#
# SDL2_mixer static library
#
###########################

LOCAL_MODULE := SDL2_mixer_static

LOCAL_MODULE_FILENAME := libSDL2_mixer

LOCAL_LDLIBS :=
LOCAL_EXPORT_LDLIBS :=

include $(BUILD_STATIC_LIBRARY)



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
PROJ_PATH	:= ../src/
LOCAL_SRC_FILES := 	$(addprefix $(PROJ_PATH), \
					main.c \
					utils/file.c \
					utils/debug.c)
LOCAL_C_INCLUDES := $(LOCAL_PATH)/SDL2/include \
                     $(LOCAL_PATH)/SDL2/image/include \
                     $(LOCAL_PATH)/SDL2/mixer/include \
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
