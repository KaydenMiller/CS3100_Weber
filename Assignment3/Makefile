all: fileBuilder fileReader 

debug: fileBuilder fileReader
	gcc fileBuilder.c -g -o FileBuilderExc_Debug
	gcc fileReader.c -g -o FileReaderExc_Debug

fileBuilder: fileBuilder.c
	gcc fileBuilder.c -o FileBuilderExc

fileReader: fileReader.c
	gcc fileReader.c -o FileReaderExc

clean:
	@[ -f ./CS3100_WEBER/Assignment3] && rm FileBuilderExc_Debug || true
	@[ -f ./Assignment3] && rm *.o FileBuilderExc || true
