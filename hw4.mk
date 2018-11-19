

Resultados_hw4.pdf:resultados_hw4.tex grafsODE.pdf
	pdflatex resultados_hw4.tex

grafsODE.pdf:Plots_hw4.py datsODE.txt a.out a2.out ODE.cpp PDE.cpp datsPDE.txt
	python Plots_hw4.py

datsODE.txt:datsODE.out
	./datsODE.out>datsODE.txt

datsPDE.txt:datsPDE.out
	./datsPDE.out>>datsODE.txt

datsPDE.out: a2.out
	mv a2.out datsPDE.out

a2.out:PDE.cpp
	g++ -o a2.out PDE.cpp

datsODE.out:a.out
	mv a.out datsODE.out

a.out: ODE.cpp
	g++ ODE.cpp 
