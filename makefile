GXX = g++
GXXFLAGS = -std=c++11

TARGET := bibliothekOrganizer

all : $(TARGET)
$(TARGET): main.cpp bibl.o user.o
	$(GXX) $(GXXFLAGS) -o $(TARGET) main.cpp *.o

bibl.o: bibl.cpp bibl.h user.o
	$(GXX) $(GXXFLAGS) -c bibl.cpp user.o

user.o: user.cpp user.h
	$(GXX) $(GXXFLAGS) -c user.cpp
clean:
	$(RM) *.o


