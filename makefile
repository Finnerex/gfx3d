# ----------------------------
# Makefile Options
# ----------------------------

NAME = GFX3D
ICON = icon.png
DESCRIPTION = "CE C Toolchain Demo"
COMPRESSED = NO
ARCHIVED = NO

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
