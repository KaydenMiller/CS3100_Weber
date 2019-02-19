all: fileBuilder fileReader HW3

debug: fileBuilder.c fileReader.c HW3_Debug
	gcc fileBuilder.c -g -o FileBuilder_Debug.exe
	gcc fileReader.c -g -o FileReader_Debug.exe

fileBuilder: fileBuilder.c
	gcc fileBuilder.c -o FileBuilder.exe

fileReader: fileReader.c
	gcc fileReader.c -o FileReader.exe

HW3: HW3.c minmax.c fileBuilder
	gcc HW3.c -o HW3.exe
	gcc minmax.c -o minmax.exe
	./FileBuilder.exe

HW3_Debug: HW3.c minmax.c fileBuilder
	gcc -g HW3.c -o HW3_debug.exe
	gcc -g minmax.c -o minmax_debug.exe
	./FileBuilder.exe

clean:
	@echo cleaning...
	@[ -f ./?*.exe ] && rm *.exe || true
	@[ -f ./*.txt ] && rm *.txt || true