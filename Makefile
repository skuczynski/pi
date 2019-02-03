PROJECTNAME=pi

CXX=g++
CXXFLAGS=-std=c++17 -Wall -Wextra -Wpedantic -Werror
LDFLAGS=-lpthread

SRCDIR=src
OBJDIR=obj
DIRS=$(SRCDIR) $(OBJDIR)
SRC=$(wildcard $(SRCDIR)/*.cpp)
OBJ=$(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRC))
INC=-I$(SRCDIR)
DEPS=$(OBJ:.o=.d)

.PHONY: $(PROJECTNAME) clean

$(PROJECTNAME): $(DIRS) $(OBJ)
	@echo Creating $(PROJECTNAME) binary from $<
	@$(CXX) $(CXXFLAGS) $(OBJ) $(LDFLAGS) -o $@
	@echo Building binary done!

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@echo [$(CXX)]: Compiling source $<
	@$(CXX) -c -MMD $(CXXFLAGS) $(INC) $< -o $@

$(DIRS):
	@echo Creating directories
	@mkdir -p $(DIRS)

clean:
	@echo Cleaning...
	@rm -rf $(OBJDIR)
	@rm -f $(PROJECTNAME)

-include $(DEPS)
