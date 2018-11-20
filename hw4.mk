

Resultados_hw4.pdf:resultados_hw4.tex grafsODE.pdf grafsODE2.pdf 10grados.pdf 3d2.pdf 3d3.pdf 3d4.pdf 3d5.pdf 3d6.pdf 3d7.pdf 3d8.pdf 3d9.pdf 3d10.pdf
	pdflatex resultados_hw4.tex



grafsODE2.pdf 10grados.pdf grafsODE.pdf 3d2.pdf 3d3.pdf 3d4.pdf  3d5.pdf 3d6.pdf 3d7.pdf 3d8.pdf 3d9.pdf 3d10.pdf:Plots_hw4.py datsODE.txt a.out a2.out ODE.cpp PDE.cpp datsPDE.txt
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
