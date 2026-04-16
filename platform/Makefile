# ---------------------------------------------------------------------------------------------------------------------
# Project and solution directories
# ---------------------------------------------------------------------------------------------------------------------
# Project
PROJECT_DIR := $(CURDIR)
PROJECT_NAME := $(notdir $(patsubst %/,%,$(PROJECT_DIR)))

# Solution
SOLUTION_DIR := $(patsubst %/,%,$(dir $(CURDIR)))
SOLUTION_NAME := $(shell basename $(SOLUTION_DIR))

# ---------------------------------------------------------------------------------------------------------------------
# Compiler commands, flags and directories
# ---------------------------------------------------------------------------------------------------------------------
# Compiler
COMPILER ?= g++-15
PLATFORM ?= $(shell $(COMPILER) -dumpmachine)
CONFIGURATION ?= Debug
CPP_STD ?= c++20
C_STD ?= c11
WARNINGS ?= all extra

# Out directories
INTERMIDIARY_DIR ?= intermidiary/$(PLATFORM)/$(CONFIGURATION)
BUILD_DIR ?= build/$(PLATFORM)/$(CONFIGURATION)

# Definitions, header include, library directory include and library include
DEFINITIONS ?= STB_IMAGE_IMPLEMENTATION _CRT_SECURE_NO_WARNINGS STB_IMAGE_WRITE_IMPLEMENTATION WINDOW EVENT MOUSE KEYBOARD JOYSTICK GLFW_WINDOW GLFW_EVENT GLFW_MOUSE GLFW_KEYBOARD GLFW_JOYSTICK
INCLUDE_DIRS ?= "$(PROJECT_DIR)" "$(SOLUTION_DIR)/dependencies/glfw/include"
LIBRARY_DIRS ?= "$(SOLUTION_DIR)/dependencies/glfw/build/lib"
LIBRARIES ?= glfw
LD_LIBRARY_PATH ?= $$ORIGIN

# Output
OUTPUT_NAME ?= $(PROJECT_NAME).bin
OUTPUT_PATH := $(BUILD_DIR)/$(OUTPUT_NAME)

# Compiler arguments
ARG_CPP_STD := $(addprefix -std=,$(CPP_STD))
ARG_C_STD := $(addprefix -std=,$(C_STD))
ARG_WARNINGS := $(addprefix -W,$(WARNINGS))
ARG_DEBUG_SYMBOLS :=
ARG_OPTIMIZATION :=
ifeq ($(CONFIGURATION),Debug)
ARG_DEBUG_SYMBOLS := -g
ARG_OPTIMIZATION := -O0
else ifeq ($(CONFIGURATION),Release)
ARG_OPTIMIZATION := -O2 -DNDEBUG
endif
ARG_FLAGS ?= $(ARG_WARNINGS) $(ARG_OPTIMIZATION) $(ARG_DEBUG_SYMBOLS)

ARG_INCLUDE_DIRS := -I,$(INCLUDE_DIRS)
ARG_DEFINITIONS := $(addprefix -D,$(DEFINITIONS))
ARG_LIBRARY_DIRS := $(addprefix -L,$(LIBRARY_DIRS))
ARG_LD_LIBRARY_PATHS := -Wl,-rpath,'$(LD_LIBRARY_PATH)'
ARG_LIBRARIES := $(addprefix -l,$(LIBRARIES))

# COMPILE_CPP := $(PLATFORM)-$(COMPILER) $(ARG_FLAGS) $(addprefix -I,$(INCLUDE_DIRS)) $(addprefix -D,$(DEFINITIONS)) $(addprefix -L,$(LIBRARY_DIRS)) $(addprefix -l,$(LIBRARIES)) -MMD -MP -c
# CXX_LINK := $(PLATFORM)-$(COMPILER) $(ARG_FLAGS) $(OBJS) $(OBJS_EXTERNAL) $(addprefix -I,$(INCLUDE_DIRS)) $(addprefix -D,$(DEFINITIONS)) $(addprefix -L,$(LIBRARY_DIRS)) $(ARG_LD_LIBRARY_PATHS) $(addprefix -l,$(LIBRARIES)) -o


# Debug arguments: -g -O0 -Wall -Wextra
# Release arguments: -O2 -DNDEBUG -Wall -Wextra
# Profiling: -pg -O2


# ---------------------------------------------------------------------------------------------------------------------
# SRC
# ---------------------------------------------------------------------------------------------------------------------
# src
SRC := $(shell find $(PROJECT_DIR) \( -name "*.c" -o -name "*.cpp" \))
SRC := $(subst $(PROJECT_DIR)/,,$(SRC))
# remove specified src files
ifneq ($(SRC_EXCLUDED),)
SRC := $(filter-out $(SRC_EXCLUDED),$(SRC))
endif
# remove src files within excluded directories
ifneq ($(SRC_EXCLUDED_DIR),)
SRC := $(filter-out $(SRC_EXCLUDED_DIR)%,$(SRC))
endif
SRC_DEPENDENCIES_DIR := $(PROJECT_DIR)/src_dependencies
# src files excluded from build (relative to PROJECT_DIR)
SRC_EXCLUDED_DIR ?=
SRC_EXCLUDED ?=
# external src files
SRC_EXTERNAL_DIR ?=
SRC_EXTERNAL ?=
ifneq ($(SRC_EXTERNAL_DIR),)
SRC_EXTERNAL := $(SRC_EXTERNAL) $(shell find $(SRC_EXTERNAL_DIR) \( -name "*.c" -o -name "*.cpp" \))
endif
SRC_EXTERNAL := $(sort $(SRC_EXTERNAL))

# ---------------------------------------------------------------------------------------------------------------------
# Object
# ---------------------------------------------------------------------------------------------------------------------
# project objects
OBJS := $(SRC:.cpp=.o)
OBJS := $(OBJS:.c=.o)
OBJS := $(addprefix $(INTERMIDIARY_DIR)/,$(OBJS))
# external objects
OBJS_EXTERNAL := 
ifneq ($(SRC_EXTERNAL),)
OBJS_EXTERNAL := $(INTERMIDIARY_DIR)/$(notdir $(SRC_EXTERNAL:.cpp=.o))
endif

# ---------------------------------------------------------------------------------------------------------------------
# Compiler commands
# ---------------------------------------------------------------------------------------------------------------------
# Compile and link commands
COMPILE_C := $(PLATFORM)-$(COMPILER) $(ARG_C_STD) $(ARG_FLAGS) $(addprefix -I,$(INCLUDE_DIRS)) $(addprefix -D,$(DEFINITIONS)) $(addprefix -L,$(LIBRARY_DIRS)) $(addprefix -l,$(LIBRARIES)) -MMD -MP -c
COMPILE_CPP := $(PLATFORM)-$(COMPILER) $(ARG_CPP_STD) $(ARG_FLAGS) $(addprefix -I,$(INCLUDE_DIRS)) $(addprefix -D,$(DEFINITIONS)) $(addprefix -L,$(LIBRARY_DIRS)) $(addprefix -l,$(LIBRARIES)) -MMD -MP -c
CXX_LINK := $(PLATFORM)-$(COMPILER) $(ARG_FLAGS) $(OBJS) $(OBJS_EXTERNAL) $(addprefix -I,$(INCLUDE_DIRS)) $(addprefix -D,$(DEFINITIONS)) $(addprefix -L,$(LIBRARY_DIRS)) $(ARG_LD_LIBRARY_PATHS) $(addprefix -l,$(LIBRARIES)) -o
# g++ ... -Wl,-rpath,'$ORIGIN'

# CXX_LINK := $(PLATFORM)-$(COMPILER) \
#     $(ARG_FLAGS) \
#     $(OBJS) $(OBJS_EXTERNAL) \
#     $(addprefix -I,$(INCLUDE_DIRS)) \
#     $(addprefix -D,$(DEFINITIONS)) \
#     $(addprefix -L,$(LIBRARY_DIRS)) \
#     -Wl,-rpath,'$$ORIGIN' \
#     $(addprefix -l,$(LIBRARIES)) \
#     -o

# LD_LIBRARY_PATH
# RPATH / RUNPATH (this flag)
# System paths


# ---------------------------------------------------------------------------------------------------------------------
# VAR
# ---------------------------------------------------------------------------------------------------------------------
NULL := null
TEST := $(NULL)
VAR ?= $(NULL)

# ---------------------------------------------------------------------------------------------------------------------
# Build, rebuild, clean commands
# ---------------------------------------------------------------------------------------------------------------------
build: $(OBJS) build_external_src
	@mkdir -p $(BUILD_DIR)
	@echo Linking
	$(CXX_LINK) $(OUTPUT_PATH)
	chmod +x $(OUTPUT_PATH)
build_external_src:
	@echo Building external src
	$(MAKE) -f makefiles/external_src.mk COMPILE_CPP="$(COMPILE_CPP)" COMPILE_C="$(COMPILE_C)" SRC="$(SRC_EXTERNAL)" OBJS="$(OBJS_EXTERNAL)"
	@echo Finished building external src
-include $(OBJS:.o=.d)

.PHONY: clean
clean:
	rm -rf $(word 1, $(subst /, ,$(BUILD_DIR))) $(word 1, $(subst /, ,$(INTERMIDIARY_DIR)))

.PHONY: rebuild
rebuild: clean build

# $@ is the target
# $< is the first prerequisite
$(INTERMIDIARY_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(COMPILE_CPP) "$<" -o "$@"
$(INTERMIDIARY_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(COMPILE_C) "$<" -o "$@"

$(SRC_DEPENDENCIES_DIR)/%.d: %.cpp
	@echo "$<" "$@"

# Make links to .so files
.PHONY: link_to_so_files
link_to_so_files:
	@echo "making links to local .so files."

# Print variable and its contents
# example usage: make print VAR=PROJECT_DIR
.PHONY: print_var
print_var:
	$(info $(VAR) = $($(VAR)))
	@echo done

#@echo $(VAR) = $($(VAR))
#@echo --------------------
#@printf '%s\n' '$($(VAR))'

#.PHONY test
#test:
#	@echo 

# ---------------------------------------------------------------------------------------------------------------------
# Print Makefile variables
# ---------------------------------------------------------------------------------------------------------------------
.PHONY: print_output_path
print_output_path:
	@echo $(OUTPUT_PATH)

.PHONY: print_build_dir
print_build_dir:
	@echo $(BUILD_DIR)

.PHONY: print_platform
print_platform:
	@echo $(PLATFORM)

.PHONY: print_configuration
print_configuration:
	@echo $(CONFIGURATION)

# ---------------------------------------------------------------------------------------------------------------------
# Run binary commands
# ---------------------------------------------------------------------------------------------------------------------
.PHONY: run
run: build
	@$(OUTPUT_PATH)

.PHONY: debug
debug: build
	@echo "Debugging $(OUTPUT_PATH)"
	@gdb --args $(OUTPUT_PATH)
