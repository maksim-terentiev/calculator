.PHONY: all help run clean reset

#Ignore errors
.IGNORE: clean reset

GCCOPT= -Wall

all: calculator translator

# удаление файлов *.o
clean:
	rm -v calculator.o translator.o stack.o
reset: clean
	rm -v calculator translator

help:
	@echo "all   - cкомпилировать обе программы"
	@echo "help  - вывод справки"
	@echo "run   - запустить в виде конвейера"
	@echo "clean - удалить временные файлы компиляции"
	@echo "reset - удалить скомпилированные программы и объектные файлы,"
	@echo "        оставив исходники"

run: all
	@echo "Run both programs"
	./translator | ./calculator

stack.o: stack.h stack.c
	gcc $(GCCOPT) -c -o stack.o stack.c
translator.o: stack.h translator.c
	gcc $(GCCOPT) -c -o translator.o translator.c
calculator.o: stack.h calculator.c
	gcc $(GCCOPT) -c -o calculator.o calculator.c

translator: stack.o translator.o
	gcc $(GCCOPT) -o translator stack.o translator.o
calculator: stack.o calculator.o
	gcc $(GCCOPT) -o calculator stack.o calculator.o
