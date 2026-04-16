# Arguments passed from the main Makefile
COMPILE_CPP ?=
COMPILE_C ?=
SRC ?=
OBJS ?=

# Error check: arguments must not be empty
ifeq ($(COMPILE_CPP),)
$(error COMPILE_CPP is empty)
endif
ifeq ($(COMPILE_C),)
$(error COMPILE_C is empty)
endif

# Ensure SRC and OBJS have the same number of elements
ifeq ($(words $(SRC)),$(words $(OBJS)))
else
$(error SRC and OBJS must have the same number of elements)
endif

compile: $(OBJS)

#.PHONY: check
#check:
#	@if [ -z "$(SRC)" ]; then \
#		echo "No source files specified for external src. Skipping build_external_src target."; \
#		exit 0; \
#	fi

# SRC and OBJS 1:1 rule macro
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

# Generate rules for each SRC and OBJS pair
$(foreach i,$(shell seq 1 $(words $(SRC))), \
	$(eval $(call COMPILE_TEMPLATE, \
		$(word $(i),$(SRC)), \
		$(word $(i),$(OBJS)) \
	)) \
)

# Include dependency files
-include $(OBJS:.o=.d)

# Backup
#define COMPILE_TEMPLATE
#$2: $1
#	@mkdir -p $(dir $2)
#	$(COMPILE_CPP) $1 -o $2
#endef
