CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		Loopop.o

LIBS =

TARGET =	Loopop

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
