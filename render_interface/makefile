EXEC=main


all: $(EXEC)

main : main.cpp 
	g++ main.cpp  -o main `pkg-config gtkmm-2.4 --cflags --libs` 


clean :
	rm -f *.o $(EXEC)

