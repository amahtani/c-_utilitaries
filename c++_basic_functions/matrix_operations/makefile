
CXX = g++
RM = rm

LIBS = -lstdc++

TARGET = main

OBJS = Vecteur.o Matrice.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LIBS)
	
%.o: %.cpp
	$(CXX) -c $<

clean: 
	$(RM) -f *.o $(TARGET)