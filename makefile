#directories
SOURCEDIR = src
BUILDDIR = build

#variables
APPNAME = main.exe
DEBUG = -g
FLAGS = -IC:/proggraming/glad/include -IC:/proggraming/SDL2-2.26.2/include -IC:/proggraming/glm -LC:/proggraming/SDL2-2.26.2/lib \
-Wall -Wl,-subsystem,console -lmingw32 -lSDL2main -lSDL2
ARGS =
THIRD_PARTY = C:/proggraming/glad/src/glad.o
ECHO = @
PROGRESS = true


SOURCEFOLDERS = $(shell find $(SOURCEDIR) -type d)
BUILDFOLDERS = $(foreach folder,$(SOURCEFOLDERS),$(subst $(SOURCEDIR),$(BUILDDIR),$(folder)))
$(foreach folder,$(BUILDFOLDERS),$(shell mkdir -p $(folder)))

SOURCES = $(foreach folder,$(SOURCEFOLDERS),$(wildcard $(folder)/*.cpp))
INCLUDES = $(foreach folder,$(SOURCEFOLDERS),$(addprefix -I,$(folder)))
INCLUDEFILES = $(foreach folder,$(SOURCEFOLDERS),$(wildcard $(folder)/*.hpp))
OBJS = $(foreach file,$(SOURCES),$(file:$(SOURCEDIR)/%.cpp=$(BUILDDIR)/%.o))

run: compile
	$(ECHO)if [ $(PROGRESS) == "true" ]; then \
    echo Run!; \
  fi; \
	$(BUILDDIR)/$(APPNAME) $(ARGS)

runDebug: compile
	gdb --args $(BUILDDIR)/$(APPNAME) $(ARGS)

compile: $(OBJS)
	$(ECHO)g++ $(DEBUG) $(THIRD_PARTY) $(OBJS) -o $(BUILDDIR)/$(APPNAME) $(INCLUDES) $(FLAGS); \
	if [ $(PROGRESS) == "true" ]; then \
    echo Compiled!; \
  fi

define generateRules
$(1:$(SOURCEDIR)/%.cpp=$(BUILDDIR)/%.o): $1 $(INCLUDEFILES)
	$(ECHO)if [ $(PROGRESS) == "true" ]; then \
    echo Compiling $(notdir $(1))...; \
  fi; \
	g++ $(DEBUG) -c $$< -o $$@ $(INCLUDES) $(FLAGS)

endef
$(foreach src,$(SOURCES),$(eval $(call generateRules,$(src))))

clean:
	$(ECHO)rm -r -f $(BUILDDIR)