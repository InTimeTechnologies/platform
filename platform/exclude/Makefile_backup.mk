# ---------------------------------------------------------------------------------------------------------------------
# TO-DO
# - call sort after every variable gets a new entry. It is possible to have duplicated entries in SRC and EXTERNAL_SRC
# - test Makefile_external;_src.mk
# - g++ -S file.cpp           // Output: human readable assembly code
# - g++ -E file.cpp -o file.1 // Output: preprocessed source (.i or .ii)
# ---------------------------------------------------------------------------------------------------------------------

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
COMPILER_OUTPUT ?= binary
FORCE_NO_UNDEFINED_SYMBOLDS ?= true
POSITION_INDEPENDENT_CODE ?= true

# Out directories
INTERMIDIARY_DIR ?= intermidiary/$(PLATFORM)/$(CONFIGURATION)
BUILD_DIR ?= build/$(PLATFORM)/$(CONFIGURATION)

# Definitions, header include, library directory include and library include
DEFINITIONS ?= STB_IMAGE_IMPLEMENTATION _CRT_SECURE_NO_WARNINGS STB_IMAGE_WRITE_IMPLEMENTATION WINDOW EVENT MOUSE KEYBOARD JOYSTICK
INCLUDE_DIRS ?= "$(PROJECT_DIR)" "$(SOLUTION_DIR)/dependencies/glfw/include"
LIBRARY_DIRS ?=
LIBRARIES ?= glfw
LIBRARY_DEPENDENCY_DIRS ?=
LD_LIBRARY_PATH ?= $$ORIGIN

# ---------------------------------------------------------------------------------------------------------------------
# Compiler and linker arguments
# ---------------------------------------------------------------------------------------------------------------------
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
# Debug arguments: -g -O0 -Wall -Wextra
# Release arguments: -O2 -DNDEBUG -Wall -Wextra
# Profiling: -pg -O2

ARG_POSITION_INDEPENDENT_CODE :=
ARG_SHARED :=
ifeq ($(COMPILER_OUTPUT),binary)
# [INFORMATIONAL] Left empty intentionally. I am not aware of any more arguments to pass.
endif
ifeq ($(POSITION_INDEPENDENT_CODE),true)
ARG_POSITION_INDEPENDENT_CODE := -fPIC
endif
ifeq ($(COMPILER_OUTPUT),shared_object)
ARG_POSITION_INDEPENDENT_CODE := -fPIC
ARG_SHARED := -shared
endif

ARG_COMMON_FLAGS ?= $(ARG_WARNINGS) $(ARG_OPTIMIZATION) $(ARG_DEBUG_SYMBOLS)
ARG_COMPILER_FLAGS ?= $(ARG_POSITION_INDEPENDENT_CODE)
ARG_LINKER_FLAGS ?= $(ARG_SHARED)

ARG_INCLUDE_DIRS := -I,$(INCLUDE_DIRS)
ARG_DEFINITIONS := $(addprefix -D,$(DEFINITIONS))
ARG_LD_LIBRARY_PATHS := -Wl,-rpath,'$(LD_LIBRARY_PATH)'
ARG_FORCE_NO_UNDEFINED_SYMBOLDS :=
ifeq ($(FORCE_NO_UNDEFINED_SYMBOLDS),true)
ARG_FORCE_NO_UNDEFINED_SYMBOLDS := -Wl,--no-undefined
endif
ARG_LIBRARY_DIRS := $(addprefix -L,$(LIBRARY_DIRS))
ARG_LIBRARIES := $(addprefix -l,$(LIBRARIES))

# ---------------------------------------------------------------------------------------------------------------------
# Output file path
# ---------------------------------------------------------------------------------------------------------------------
OUTPUT_PATH :=
ifeq ($(COMPILER_OUTPUT),binary)
OUTPUT_PATH := $(BUILD_DIR)/$(PROJECT_NAME).bin
endif
ifeq ($(COMPILER_OUTPUT),shared_object)
OUTPUT_PATH := $(BUILD_DIR)/lib$(PROJECT_NAME).so
endif
ifeq ($(COMPILER_OUTPUT),archive)
OUTPUT_PATH := $(BUILD_DIR)/lib$(PROJECT_NAME).a
ifeq ($(POSITION_INDEPENDENT_CODE),true)
OUTPUT_PATH := $(BUILD_DIR)/lib$(PROJECT_NAME)_pic.a
endif
endif

# ---------------------------------------------------------------------------------------------------------------------
# SRC
# ---------------------------------------------------------------------------------------------------------------------
# src
SRC := $(shell find $(PROJECT_DIR) \( -name "*.c" -o -name "*.cpp" \))
SRC := $(subst $(PROJECT_DIR)/,,$(SRC))
# src files excluded from build (relative to PROJECT_DIR)
SRC_EXCLUDED_DIR ?= implementation/
SRC_EXCLUDED ?=
SRC_FORCED_DIR_INCLUSION ?= implementation/glfw/
SRC_FORCED_SRC_INCLUSION ?=

# remove specified src files
ifneq ($(SRC_EXCLUDED),)
SRC := $(filter-out $(SRC_EXCLUDED),$(SRC))
endif
# remove src files within excluded directories
ifneq ($(SRC_EXCLUDED_DIR),)
SRC := $(filter-out $(SRC_EXCLUDED_DIR)%,$(SRC))
endif
# include src files within src force included dir
ifneq ($(SRC_FORCED_DIR_INCLUSION),)
SRC := $(SRC) $(shell find $(SRC_FORCED_DIR_INCLUSION) \( -name "*.c" -o -name "*.cpp" \))
endif
# include src files within src force included
ifneq ($(SRC_FORCED_SRC_INCLUSION),)
SRC := $(SRC) $(sort $(SRC_FORCED_SRC_INCLUSION))
endif

# external src files
SRC_EXTERNAL_DIR ?=
SRC_EXTERNAL ?=
ifneq ($(SRC_EXTERNAL_DIR),)
SRC_EXTERNAL := $(SRC_EXTERNAL) $(shell find $(SRC_EXTERNAL_DIR) \( -name "*.c" -o -name "*.cpp" \))
SRC_EXTERNAL := $(sort $(SRC_EXTERNAL))
endif

# ---------------------------------------------------------------------------------------------------------------------
# Object
# ---------------------------------------------------------------------------------------------------------------------
OBJS := $(SRC:.cpp=.o)
OBJS := $(OBJS:.c=.o)
OBJS := $(addprefix $(INTERMIDIARY_DIR)/,$(OBJS))

OBJS_EXTERNAL :=
ifneq ($(SRC_EXTERNAL),)
OBJS_EXTERNAL := $(INTERMIDIARY_DIR)/$(notdir $(SRC_EXTERNAL:.cpp=.o))
endif

# ---------------------------------------------------------------------------------------------------------------------
# Compiler and linker commands
# ---------------------------------------------------------------------------------------------------------------------
COMPILE_C := $(PLATFORM)-$(COMPILER) $(ARG_C_STD) $(ARG_COMMON_FLAGS) $(ARG_COMPILER_FLAGS) $(addprefix -I,$(INCLUDE_DIRS)) $(addprefix -D,$(DEFINITIONS)) -MMD -MP -c
COMPILE_CPP := $(PLATFORM)-$(COMPILER) $(ARG_CPP_STD) $(ARG_COMMON_FLAGS) $(ARG_COMPILER_FLAGS) $(addprefix -I,$(INCLUDE_DIRS)) $(addprefix -D,$(DEFINITIONS)) -MMD -MP -c
LINK_CPP :=
ifeq ($(COMPILER_OUTPUT),binary)
LINK_CPP := $(PLATFORM)-$(COMPILER) $(ARG_COMMON_FLAGS) $(OBJS) $(OBJS_EXTERNAL) $(ARG_LINKER_FLAGS) $(addprefix -I,$(INCLUDE_DIRS)) $(addprefix -D,$(DEFINITIONS)) $(ARG_LD_LIBRARY_PATHS) $(ARG_LIBRARY_DIRS) $(ARG_LIBRARIES) -o $(OUTPUT_PATH)
endif
ifeq ($(COMPILER_OUTPUT),shared_object)
LINK_CPP := $(PLATFORM)-$(COMPILER) $(ARG_COMMON_FLAGS) $(OBJS) $(OBJS_EXTERNAL) $(ARG_LINKER_FLAGS) $(addprefix -I,$(INCLUDE_DIRS)) $(addprefix -D,$(DEFINITIONS)) $(ARG_LD_LIBRARY_PATHS) $(ARG_FORCE_NO_UNDEFINED_SYMBOLDS) -o $(OUTPUT_PATH) $(ARG_LIBRARY_DIRS) $(ARG_LIBRARIES)
endif
ifeq ($(COMPILER_OUTPUT),archive)
LINK_CPP := ar rcs $(OUTPUT_PATH) $(OBJS)
endif

# g++ ... -Wl,-rpath,'$ORIGIN'

# LINK_CPP := $(PLATFORM)-$(COMPILER) \
#     $(ARG_COMMON_FLAGS) \
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
	$(LINK_CPP)
ifeq ($(COMPILER_OUTPUT),binary)
	chmod +x $(OUTPUT_PATH)
endif

build_external_src:
	@echo Building external src
	$(MAKE) -f Makefile_external_src.mk COMPILE_CPP="$(COMPILE_CPP)" COMPILE_C="$(COMPILE_C)" SRC="$(SRC_EXTERNAL)" OBJS="$(OBJS_EXTERNAL)"
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

# Print variable and its contents
# example usage: make print VAR=PROJECT_DIR
.PHONY: print_var
print_var:
	$(info $(VAR) = $($(VAR)))
	@echo

#@echo $(VAR) = $($(VAR))
#@echo --------------------
#@printf '%s\n' '$($(VAR))'

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
