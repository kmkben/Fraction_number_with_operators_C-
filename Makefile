SOURCES  =  main.cpp fraction.cpp
OBJECTS  =  $(SOURCES:.cpp=.o)
TARGET   =  fraction
#LIBS     =  $(shell sdl-config --libs) -lGL -lGLU -lglut -lm

all: $(OBJECTS)
	g++ -o $(TARGET) $(OBJECTS) #$LIBS


%o: %cpp
	g++ -o $@ -c $<


x: all
	./$(TARGET)


clean: 
	rm -rf $(OBJECTS)


superclean: clean
	rm -rf $(TARGET)

