# ---------------------------------------------------------------------------------------------------------------------
# Project pre-configuration
# ---------------------------------------------------------------------------------------------------------------------
IMPLEMENTATION ?= glfw
ifeq ($(IMPLEMENTATION),glfw)
SRC_EXCLUDE_DIR := implementation/linux
endif
ifeq ($(IMPLEMENTATION),linux)
SRC_EXCLUDE_DIR := implementation/glfw
endif

# ---------------------------------------------------------------------------------------------------------------------
# Project and solution directories
# ---------------------------------------------------------------------------------------------------------------------
# Project
PROJECT_DIR := $(CURDIR)
PROJECT_NAME ?= $(notdir $(patsubst %/,%,$(PROJECT_DIR)))

# Solution
SOLUTION_DIR := $(patsubst %/,%,$(dir $(CURDIR)))
SOLUTION_NAME := $(shell basename $(SOLUTION_DIR))

# ---------------------------------------------------------------------------------------------------------------------
# Compiler commands, flags and directories
# ---------------------------------------------------------------------------------------------------------------------
# Compiler
C_COMPILER ?= gcc
CPP_COMPILER ?= g++
LINKER ?= g++
PLATFORM ?= x64
CONFIGURATION ?= Debug
CPP_STD ?= c++20
C_STD ?= c11
WARNINGS ?= all extra
COMPILER_OUTPUT ?= bin
FORCE_NO_UNDEFINED_SYMBOLS ?= false

# Out directories
INTERMIDIARY_DIR ?= intermidiary/$(PLATFORM)/$(CONFIGURATION)
INTERMIDIARY_ROOT_DIR ?= $(word 1, $(subst /, ,$(INTERMIDIARY_DIR)))
BUILD_DIR ?= build/$(PLATFORM)/$(CONFIGURATION)
BUILD_ROOT_DIR := $(firstword $(subst /, ,$(BUILD_DIR)))

# Definitions, header include, library directory include and library include
DEFINITIONS ?= WINDOW EVENT MOUSE KEYBOARD JOYSTICK
INCLUDE_DIRS ?= $(PROJECT_DIR) $(SOLUTION_DIR)/dependencies/glfw/include
LIBRARY_DIRS ?=
LIBRARIES ?= glfw udev
LD_LIBRARY_PATHS ?= $$ORIGIN

# Output
ifeq ($(filter $(COMPILER_OUTPUT),bin so a),)
$(error COMPILER_OUTPUT=$(COMPILER_OUTPUT) is unsupported. Supported compiler outputs: bin, so, a)
endif
OUTPUT_NAME := $(PROJECT_NAME).$(COMPILER_OUTPUT)
OUTPUT_PATH := $(BUILD_DIR)/$(OUTPUT_NAME)

# Install
INSTALL_PREFIX ?= /usr/local
INSTALL_BINARY_DIR := $(INSTALL_PREFIX)/bin
INSTALL_INCLUDE_DIR := $(INSTALL_PREFIX)/include
INSTALL_LIBRARY_DIR := $(INSTALL_PREFIX)/lib
ifeq ($(PLATFORM),x64)
INSTALL_LIBRARY_DIR := $(INSTALL_PREFIX)/lib64
endif
INSTALL_HEADER_PATHS :=
INSTALL_HEADER_NAMES :=
INSTALL_LIBRARY_PATH := $(INSTALL_LIBRARY_DIR)/$(OUTPUT_NAME)

# Uninstall
UNINSTALL_HEADER_PATHS :=

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

ARG_POSITION_INDEPENDENT_CODE :=
ARG_SHARED :=
ifeq ($(COMPILER_OUTPUT),bin)
# [INFORMATIONAL] Left empty intentionally. I am not aware of any more arguments to pass.
endif
ifeq ($(COMPILER_OUTPUT),so)
ARG_POSITION_INDEPENDENT_CODE := -fPIC
ARG_SHARED := -shared
endif

ifeq ($(filter $(PLATFORM),x32 x64),)
$(error PLATFORM=$(PLATFORM) is unsupported. Supported platforms / architectures: x32 x64)
endif
ARG_PLATFORM :=
ifeq ($(PLATFORM),x32)
ARG_PLATFORM := -m32
endif
ifeq ($(PLATFORM),x64)
ARG_PLATFORM := -m64
endif

ARG_COMMON_FLAGS ?= $(ARG_PLATFORM) $(ARG_OPTIMIZATION) $(ARG_DEBUG_SYMBOLS) $(ARG_WARNINGS)
ARG_COMPILER_FLAGS ?= $(ARG_POSITION_INDEPENDENT_CODE)
ARG_LINKER_FLAG ?= $(ARG_SHARED)

ARG_INCLUDE_DIR := $(addprefix -I,$(INCLUDE_DIRS))
ARG_DEFINITION := $(addprefix -D,$(DEFINITIONS))
ARG_LD_LIBRARY_PATH := -Wl,-rpath,'$(LD_LIBRARY_PATHS)'
ARG_FORCE_NO_UNDEFINED_SYMBOLS :=
ifeq ($(FORCE_NO_UNDEFINED_SYMBOLS),true)
ARG_FORCE_NO_UNDEFINED_SYMBOLS := -Wl,--no-undefined
endif
ARG_LIBRARY_DIR := $(addprefix -L,$(LIBRARY_DIRS))
ARG_LIBRARY := $(addprefix -l,$(LIBRARIES))

# ---------------------------------------------------------------------------------------------------------------------
# SRC
# ---------------------------------------------------------------------------------------------------------------------
# src (leave SRC unassigned)
SRC :=
SRC :=
SRC_EXCLUDE ?=
SRC_EXCLUDE_DIR ?= build install intermidiary exclude
SRC_EXTERNAL ?=
SRC_EXTERNAL_DIR ?=
SRC_EXTERNAL_RELATIVE :=

# find all .c and .cpp files in this project
SRC := $(shell find $(PROJECT_DIR) \( -name "*.c" -o -name "*.cpp" \))
SRC := $(subst $(PROJECT_DIR)/,,$(SRC))
# remove src files specified in SRC_EXCLUDE
ifneq ($(SRC_EXCLUDE),)
SRC := $(filter-out $(SRC_EXCLUDE),$(SRC))
endif
# remove src files specified in SRC_EXCLUDE_DIR
ifneq ($(SRC_EXCLUDE_DIR),)
SRC_EXCLUDE_DIR := $(addsuffix /%,$(SRC_EXCLUDE_DIR))
SRC := $(filter-out $(SRC_EXCLUDE_DIR),$(SRC))
endif
# include src files external to this project specified in SRC_EXTERNAL_DIR
ifneq ($(SRC_EXTERNAL_DIR),)
SRC_EXTERNAL += $(shell find $(SRC_EXTERNAL_DIR) \( -name "*.c" -o -name "*.cpp" \))
SRC_EXTERNAL := $(sort $(SRC_EXTERNAL))
endif
SRC_EXTERNAL_RELATIVE := $(foreach f,$(SRC_EXTERNAL),$(shell realpath --relative-to="$(PROJECT_DIR)" "$(f)"))

# src header files
SRC_HEADER :=
SRC_HEADER :=
SRC_HEADER_EXCLUDE ?=
SRC_HEADER_EXCLUDE_DIR ?= build install intermidiary exclude
SRC_HEADER_EXTERNAL ?=
SRC_HEADER_EXTERNAL_DIR ?=

# find all .h and .hpp files in this project
SRC_HEADER := $(shell find $(PROJECT_DIR) \( -name "*.h" -o -name "*.hpp" \))
SRC_HEADER := $(subst $(PROJECT_DIR)/,,$(SRC_HEADER))
# remove header files specified in SRC_HEADER_EXCLUDE
ifneq ($(SRC_HEADER_EXCLUDE),)
SRC_HEADER := $(filter-out $(SRC_HEADER_EXCLUDE),$(SRC_HEADER))
endif
# remove header files specified in SRC_HEADER_EXCLUDE_DIR
ifneq ($(SRC_HEADER_EXCLUDE_DIR),)
SRC_HEADER_EXCLUDE_DIR := $(addsuffix /%,$(SRC_HEADER_EXCLUDE_DIR))
SRC_HEADER := $(filter-out $(SRC_HEADER_EXCLUDE_DIR),$(SRC_HEADER))
endif
# include header files external to this project specified in SRC_HEADER_EXTERNAL_DIR
ifneq ($(SRC_HEADER_EXTERNAL_DIR),)
SRC_HEADER_EXTERNAL += $(shell find $(SRC_HEADER_EXTERNAL_DIR) \( -name "*.h" -o -name "*.hpp" \))
SRC_HEADER_EXTERNAL := $(sort $(SRC_HEADER_EXTERNAL))
endif
# Headers to install/uninstall if installing/uninstalling a library
INSTALL_HEADER_PATHS := $(patsubst src/%,$(INSTALL_PREFIX)/%,$(SRC_HEADER))
INSTALL_HEADER_NAMES := $(notdir $(INSTALL_HEADER_PATHS))
UNINSTALL_HEADER_PATHS := $(addprefix $(INSTALL_INCLUDE_DIR)/,$(INSTALL_HEADER_NAMES))

# ---------------------------------------------------------------------------------------------------------------------
# Object
# ---------------------------------------------------------------------------------------------------------------------
OBJ := $(SRC:.cpp=.o)
OBJ := $(OBJ:.c=.o)
OBJ := $(addprefix $(INTERMIDIARY_DIR)/,$(OBJ))

OBJ_EXTERNAL := $(patsubst ../%,$(INTERMIDIARY_DIR)/%,$(SRC_EXTERNAL_RELATIVE:.cpp=.o))
OBJ_EXTERNAL := $(OBJ_EXTERNAL:.cpp=.o)
OBJ_EXTERNAL := $(OBJ_EXTERNAL:.c=.o)

# ---------------------------------------------------------------------------------------------------------------------
# Compiler and linker commands
# ---------------------------------------------------------------------------------------------------------------------
COMPILE_C := $(C_COMPILER) $(ARG_C_STD) $(ARG_COMMON_FLAGS) $(ARG_COMPILER_FLAGS) $(ARG_INCLUDE_DIR) $(ARG_DEFINITION) -MMD -MP -c
COMPILE_CPP := $(CPP_COMPILER) $(ARG_CPP_STD) $(ARG_COMMON_FLAGS) $(ARG_COMPILER_FLAGS) $(ARG_INCLUDE_DIR) $(ARG_DEFINITION) -MMD -MP -c
LINK_BINARY := $(LINKER) $(ARG_COMMON_FLAGS) $(OBJ) $(OBJ_EXTERNAL) $(ARG_LINKER_FLAG) $(ARG_INCLUDE_DIR) $(ARG_DEFINITION) $(ARG_LD_LIBRARY_PATH) $(ARG_LIBRARY_DIR) $(ARG_LIBRARY) -o $(OUTPUT_PATH)
LINK_ARCHIVE := ar rcs $(OUTPUT_PATH) $(OBJ)
LINK_SHARED_OBJECT := $(LINKER) $(ARG_COMMON_FLAGS) $(OBJ) $(OBJ_EXTERNAL) $(ARG_LINKER_FLAG) $(ARG_INCLUDE_DIR) $(ARG_DEFINITION) $(ARG_LD_LIBRARY_PATH) $(ARG_FORCE_NO_UNDEFINED_SYMBOLS) -o $(OUTPUT_PATH) $(ARG_LIBRARY_DIR) $(ARG_LIBRARY)

# ---------------------------------------------------------------------------------------------------------------------
# VAR
# ---------------------------------------------------------------------------------------------------------------------
NULL := null
VAR ?= $(NULL)
EMPTY :=
COMMA := ,
SPACE := $(EMPTY) $(EMPTY)
define NEW_LINE


endef
define TAB
	
endef
# ---------------------------------------------------------------------------------------------------------------------
# Build, rebuild, clean, compile, link commands
# ---------------------------------------------------------------------------------------------------------------------
build: $(OUTPUT_PATH)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(INTERMIDIARY_DIR) $(BUILD_ROOT_DIR)/include

.PHONY: clean_build
clean_build:
	rm -rf $(BUILD_ROOT_DIR) $(INTERMIDIARY_ROOT_DIR)

.PHONY: clean_intermidiary
clean_intermidiary:
	rm -rf $(word 1, $(subst /, ,$(INTERMIDIARY_DIR)))

.PHONY: rebuild
rebuild: clean build

# ---------------------------------------------------------------------------------------------------------------------
# Run binary commands
# ---------------------------------------------------------------------------------------------------------------------
.PHONY: run
run: build
ifeq ($(COMPILER_OUTPUT),bin)
	@$(OUTPUT_PATH)
else
	@echo COMPILER_OUTPUT not set to binary.
	@echo COMPILER_OUTPUT == $$COMPILER_OUTPUT
	@echo Aborted command: run
endif

.PHONY: debug
debug: build
ifeq ($(COMPILER_OUTPUT),bin)
	@gdb --args $(OUTPUT_PATH)
else
	@echo COMPILER_OUTPUT not set to binary.
	@echo COMPILER_OUTPUT == $$COMPILER_OUTPUT
	@echo Aborted command: run
endif

# ---------------------------------------------------------------------------------------------------------------------
# Install and uninstall commands
# ---------------------------------------------------------------------------------------------------------------------
.PHONY: install
install: build
	@mkdir -p $(INSTALL_PREFIX)
ifeq ($(COMPILER_OUTPUT),bin)
	@mkdir -p $(INSTALL_BINARY_DIR)
	@cp $(OUTPUT_PATH) $(INSTALL_BINARY_DIR)
else
	@mkdir -p $(INSTALL_LIBRARY_DIR)
	@mkdir -p $(INSTALL_INCLUDE_DIR)
	@cp $(OUTPUT_PATH) $(INSTALL_LIBRARY_DIR)
	@cp $(SRC_HEADER) $(INSTALL_INCLUDE_DIR)
endif

.PHONY: uninstall
uninstall:
ifeq ($(COMPILER_OUTPUT),bin)
	@rm $(INSTALL_BINARY_DIR)/$(OUTPUT_NAME)
else
	@rm $(UNINSTALL_HEADER_PATHS)
	@rm $(INSTALL_LIBRARY_DIR)/$(OUTPUT_NAME)
endif

# ---------------------------------------------------------------------------------------------------------------------
# Print / extract data from Makefile post-evaluation
# ---------------------------------------------------------------------------------------------------------------------
# Print variable and its contents
# sample usage: make print VAR=PROJECT_DIR or 
.PHONY: print_var
print_var:
	$(info $(VAR) = $($(VAR)))
	@echo

# ---------------------------------------------------------------------------------------------------------------------
# Build rules: src, .c, .cpp, .o, .bin, .a, .so
# ---------------------------------------------------------------------------------------------------------------------
# .o rules
# $@ is the target
# $< is the first prerequisite
$(INTERMIDIARY_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(COMPILE_CPP) "$<" -o "$@"
$(INTERMIDIARY_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(COMPILE_C) "$<" -o "$@"

# SRC to OBJ 1:1 rule macro
define COMPILE_TEMPLATE
$2: $1
	@mkdir -p $(dir $2)
	$(if $(filter .c,$(suffix $1)), \
		$(COMPILE_C) $1 -o $2, \
		$(if $(filter .cpp,$(suffix $1)), \
			$(COMPILE_CPP) $1 -o $2, \
			$(error Unsupported file extension: $1) \
		) \
	)
endef

# Generate rules for each SRC and OBJ pair
$(foreach i,$(shell seq 1 $(words $(SRC_EXTERNAL_RELATIVE))), \
	$(eval $(call COMPILE_TEMPLATE, \
		$(word $(i),$(SRC_EXTERNAL_RELATIVE)), \
		$(word $(i),$(OBJ_EXTERNAL)) \
	)) \
)

-include $(OBJ:.o=.d)

# .bin rule
%.bin: $(OBJ) $(OBJ_EXTERNAL)
	@echo Test
	@mkdir -p $(BUILD_DIR)
	$(LINK_BINARY)
	chmod +x $(OUTPUT_PATH)

# .a rule
%.a: $(OBJ) $(OBJ_EXTERNAL)
	@mkdir -p $(BUILD_DIR)
	$(LINK_ARCHIVE)
	@mkdir -p build/include
	@cp $(SRC_HEADER) build/include

# .so rule
%.so: $(OBJ) $(OBJ_EXTERNAL)
	@mkdir -p $(BUILD_DIR)
	$(LINK_SHARED_OBJECT)
	@mkdir -p build/include
	@cp $(SRC_HEADER) build/include

# ---------------------------------------------------------------------------------------------------------------------
# .vscode dir generation
# ---------------------------------------------------------------------------------------------------------------------
_INCLUDE_PATH := $(foreach w,$(INCLUDE_DIRS),"$(w)")
ifneq ($(INCLUDE_DIRS),)
_INCLUDE_PATH := ,$(NEW_LINE)$(TAB)$(TAB)$(TAB)$(TAB)$(_INCLUDE_PATH)
_INCLUDE_PATH := $(subst $(SPACE),$(COMMA)$(NEW_LINE)$(TAB)$(TAB)$(TAB)$(TAB),$(_INCLUDE_PATH))
endif

_DEFINES := $(foreach w,$(DEFINITIONS),"$(w)")
ifneq ($(DEFINITIONS),)
_DEFINES := $(subst $(SPACE),$(COMMA)$(NEW_LINE)$(TAB)$(TAB)$(TAB)$(TAB),$(_DEFINES))
endif
define C_CPP_PROPERTIES
{
	"version": 4,
	"configurations": [
		{
			"name": "Linux-g++",
			"compilerPath": "$(shell which g++)",
			"cStandard": "$(C_STD)",
			"cppStandard": "$(CPP_STD)",
			"intelliSenseMode": "linux-gcc-$(if $(filter x32,$(PLATFORM)),x86,x64)",
			"includePath": [
				"$${workspaceFolder}/**",
				"/usr/include",
				"/usr/local/include"$(_INCLUDE_PATH)
			],
			"defines": [
				$(_DEFINES)
			],
			"browse": {
				"path": [
					"$${workspaceFolder}",
					"/usr/include",
					"/usr/local/include"
				],
				"limitSymbolsToIncludedHeaders": true
			}
		}
	]
}
endef

define LAUNCH
{
	"version": "0.2.0",
	"configurations": [
		{
			"name": "Debug",
			"type": "cppdbg",
			"request": "launch",
			"program": "$${workspaceFolder}/$(OUTPUT_PATH)",
			"args": [],
			"stopAtEntry": false,
			"cwd": "$${workspaceFolder}",
			"environment": [],
			"externalConsole": false,
			"MIMode": "gdb",
			"miDebuggerPath": "$(shell which gdb)",
			"setupCommands": [
				{
					"description": "Enable pretty printing",
					"text": "-enable-pretty-printing",
					"ignoreFailures": true
				}
			],
			"preLaunchTask": "build",
		}
	]
}
endef

define TASKS
{
	"version": "2.0.0",
	"tasks": [
		{
			"label": "build",
			"type": "shell",
			"command": "make",
			"args": [
				"build"
			],
			"group": {
				"kind": "build",
				"isDefault": true
			},
			"problemMatcher": [
				"$$gcc"
			]
		},
		{
			"label": "rebuild",
			"type": "shell",
			"command": "make",
			"args": [
				"rebuild"
			],
			"group": {
				"kind": "build",
				"isDefault": false
			},
			"problemMatcher": [
				"$$gcc"
			]
		},
		{
			"label": "clean",
			"type": "shell",
			"command": "make",
			"args": [
				"clean"
			],
			"problemMatcher": []
		}
	]
}
endef

export C_CPP_PROPERTIES
export LAUNCH
export TASKS
.PHONY: code_dir
code_dir:
	@mkdir -p .vscode
	@echo "$$C_CPP_PROPERTIES" > .vscode/c_cpp_properties.json
	@echo "$$LAUNCH" > .vscode/launch.json
	@echo "$$TASKS" > .vscode/tasks.json
