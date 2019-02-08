all: fileBuilder fileReader

debug: fileBuilder.c fileReader.c
	gcc fileBuilder.c -g -o FileBuilderExc_Debug
	gcc fileReader.c -g -o FileReaderExc_Debug

fileBuilder: fileBuilder.c
	gcc fileBuilder.c -o FileBuilderExc

fileReader: fileReader.c
	gcc fileReader.c -o FileReaderExc

clean:
	@echo cleaning...
	@[ -f ./FileBuilderExc ] && rm FileBuilderExc || true
	@[ -f ./FileBuilderExc_Debug ] && rm FileBuilderExc_Debug || true
	@[ -f ./FileReaderExc ] && rm FileReaderExc || true
	@[ -f ./FileReaderExc_Debug ] && rm FileReaderExc_Debug || true
	@[ -f ./*.txt ] && rm *.txt || true