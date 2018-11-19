



grafsODE.pdf:grafica.py datsODE.txt
	python grafica.py

datsODE.txt:datsODE.out
	./datsODE.out>datsODE.txt

datsODE.out:a.out
	mv a.out datsODE.out

a.out: ODE.cpp
	g++ ODE.cpp 
