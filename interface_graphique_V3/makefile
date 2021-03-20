EXEC=main


all: $(EXEC)

main : main.cpp fenetre.cpp
	g++ main.cpp fenetre.cpp -o main `pkg-config gtkmm-2.4 --cflags --libs` 


clean :
	rm -f *.o $(EXEC)

rmproper : 

	rm -f $(EXEC) *.o 

