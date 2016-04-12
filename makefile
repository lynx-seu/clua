#general
CC = g++
RM = rm -rf
CPPFLAGS = -g -O2 -std=c++11 -Ic:/soft/lua/include 
LDFLAGS= c:/soft/lua/lib/lua51.dll

# == END OF USER SETTINGS. NO NEED TO CHANGE ANYTHING BELOW THIS LINE =========

TARGET = t.dll
ALL_O = test.o

all: $(TARGET)

o: $(ALL_O)

$(TARGET): $(ALL_O)
	$(CC) -shared $< $(LDFLAGS) -o $@

clean:
	$(RM) $(TARGET) $(ALL_O)


# list targets that do not create files (but not all makes understand .PHONY)
.PHONY: all $(PLATS) default o a clean

# DO NOT DELETE
test.o: test.cpp
