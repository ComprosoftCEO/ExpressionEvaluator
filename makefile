# Makefile for expression evaluator
MPC_FILE=calculator.mpc
MAKEFILE = Makefile.$(basename $(MPC_FILE))

# No implicit default rules
.SUFFIXES:


# Default target
.PHONY: all
all: CMD-all



# Also remove the MPC makefile
.PHONY: clean
clean: CMD-clean
	rm -f $(MAKEFILE)



# Pass a command to the recursive makefile
CMD-%:
	@mpc.pl -type make $(MPC_FILE)
	@make --no-print-directory -f $(MAKEFILE) $*

# Pass any target to the recursive makefile
%: CMD-%;

