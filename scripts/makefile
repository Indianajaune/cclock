TARGET   = CCLOCK

CC       = gcc
# compiling flags here
CFLAGS   = -std=gnu2x -Wall -I.

LINKER   = gcc
# linking flags here
LFLAGS   = -Wall -I. -lm

# change these to proper directories where each file should be
SRCDIR   = ../src/main
OBJDIR   = ../src/main
BINDIR   = ../bin

SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm       = rm -f


all : remove $(BINDIR)/alarm $(BINDIR)/chronometer $(BINDIR)/timer $(BINDIR)/statistics $(BINDIR)/monitor $(BINDIR)/main
	@echo "sucessfully assembled"


$(BINDIR)/main: ../src/main/main.o
	@$(LINKER) ../src/main/main.o $(LFLAGS) -o $@
	@echo "Linking complete!"

$(BINDIR)/alarm: ../src/main/alarm.o
	@$(LINKER) ../src/main/alarm.o $(LFLAGS) -o $@
	@echo "Linking complete!"

$(BINDIR)/chronometer: ../src/main/chronometer.o
	@$(LINKER) ../src/main/chronometer.o $(LFLAGS) -o $@
	@echo "Linking complete!"

$(BINDIR)/timer: ../src/main/timer.o
	@$(LINKER) ../src/main/timer.o $(LFLAGS) -o $@
	@echo "Linking complete!"
	
$(BINDIR)/statistics: ../src/main/statistics.o
	@$(LINKER) ../src/main/statistics.o $(LFLAGS) -o $@
	@echo "Linking complete!"
	
$(BINDIR)/monitor: ../src/main/monitor.o
	@$(LINKER) ../src/main/monitor.o $(LFLAGS) -o $@
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

.PHONY: clean
clean:
	@$(rm) $(OBJDIR)/*.o
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	@$(rm) $(BINDIR)/main
	@$(rm) $(BINDIR)/alarm
	@$(rm) $(BINDIR)/chronometer
	@$(rm) $(BINDIR)/timer
	@$(rm) $(BINDIR)/statistics
	@$(rm) $(BINDIR)/monitor
	@echo "Executable removed!"
