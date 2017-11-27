GXX = g++
GXXFLAGS = -std=c++11

TARGET := bibliothekOrganizer

all : $(TARGET)

$(TARGET): main.cpp bibl.o user.o book.o
	$(GXX) $(GXXFLAGS) -o $(TARGET) main.cpp *.o

bibl.o: bibl.cpp bibl.h user.o book.o
	$(GXX) $(GXXFLAGS) -c bibl.cpp user.o book.o

user.o: user.cpp user.h book.o
	$(GXX) $(GXXFLAGS) -c user.cpp book.o

book.o: book.cpp book.h
	$(GXX) $(GXXFLAGS) -c book.cpp

clean:
	$(RM) *.o


