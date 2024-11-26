# Project: Grand Adventure OOP
# Makefile created by Dev-C++ 4.9.9.2

CPP  = clang++ -D__DEBUG__
CC   = clang -D__DEBUG__
#WINDRES = windres.exe
#RES  = Grand_Adventure_OOP_private.res
OBJ  = .objs/Globals.o .objs/main.o .objs/combat.o .objs/Player.o .objs/Monster.o .objs/Mastermind.o #$(RES)
LINKOBJ  = .objs/Globals.o .objs/main.o .objs/combat.o .objs/Player.o .objs/Monster.o .objs/Mastermind.o #$(RES)
LIBS =  -L"/opt/homebrew/Cellar/ncurses/6.5/lib" -L"/usr/local/lib/" -L"../FMOD/api/core/lib" ../FMOD/api/core/lib/libfmod.dylib  -g3 
INCS =  -I"/usr/local/include"  -I"../FMOD/api/core/inc" 
CXXINCS =  -I"/opt/homebrew/Cellar/ncurses/6.5/include" -I"/usr/local/include" -I"../FMOD/api/core/inc" 
BIN  = "GA Release/Grand Adventure"
CXXFLAGS = $(CXXINCS) -std=c++20 -O3 -g3  #-traditional-cpp -g3
CFLAGS = $(INCS)  -g3 #-traditional-cpp -g3
RM = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before "GA Release/Grand Adventure" all-after


clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o "GA Release/Grand Adventure" $(LIBS) -rpath .

.objs/Globals.o: Globals.cpp
	$(CPP) -c Globals.cpp -o .objs/Globals.o $(CXXFLAGS)

.objs/main.o: main.cpp
	$(CPP) -c main.cpp -o .objs/main.o $(CXXFLAGS)

.objs/combat.o: combat.cpp
	$(CPP) -c combat.cpp -o .objs/combat.o $(CXXFLAGS)

.objs/Player.o: Player.cpp
	$(CPP) -c Player.cpp -o .objs/Player.o $(CXXFLAGS)

.objs/Monster.o: Monster.cpp
	$(CPP) -c Monster.cpp -o .objs/Monster.o $(CXXFLAGS)

.objs/Mastermind.o: Mastermind.cpp
	$(CPP) -c Mastermind.cpp -o .objs/Mastermind.o $(CXXFLAGS)

#Grand_Adventure_OOP_private.res: Grand_Adventure_OOP_private.rc 
#	$(WINDRES) -i Grand_Adventure_OOP_private.rc --input-format=rc -o Grand_Adventure_OOP_private.res -O coff 
