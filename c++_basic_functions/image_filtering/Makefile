CXX = g++
RM = rm

TARGET = main

OBJS = Image.o Filtre.o FiltreAddition.o FiltreMoyenne.o SuiteDeFiltre.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ 
	
%.o: %.cpp
	$(CXX) -c $<

clean: 
	$(RM) -f *.o $(TARGET)