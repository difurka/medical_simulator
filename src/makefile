
.PHONY: build pro

all: pro

build:
	# rm -rf build
	# mkdir build
	cd build && cmake ../medical_simulator/ && cmake --build .
	build/medical_simulator

pro:
	cd ms_pro && qmake -o Makefile ms_pro.pro && make && ./ms_pro


clean:
	rm -rf build-ms_pro-Desktop_Qt_5_12_12_GCC_64bit-Debug
	rm -rf ./ms_pro/main.o ./ms_pro/.qmake.stash 
	rm -rf ./ms_pro/ui_mainwindow.h ./ms_pro/moc* ./ms_pro/*.o
	rm -rf ./ms_pro/ms_pro ./ms_pro/*.user ./ms_pro/Makefile
	rm -rf ./medical_simulator/CMakeLists.txt.user