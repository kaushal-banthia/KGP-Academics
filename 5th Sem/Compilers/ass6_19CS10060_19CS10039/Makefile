test1: tinyC_compiler libmyio.a
	./tinyC_compiler 1 > asgn6_19CS10060_19CS10039_quads1.out
	gcc -c asgn6_19CS10060_19CS10039_1.s
	gcc asgn6_19CS10060_19CS10039_1.o -o test1 -L. -lmyio -no-pie
	./test1
	
	@echo "\n+++++++++++++++++++++ TESTING file 1 DONE!! +++++++++++++++++++++++++++#\n"

test2: tinyC_compiler libmyio.a
	./tinyC_compiler 2 > asgn6_19CS10060_19CS10039_quads2.out
	gcc -c asgn6_19CS10060_19CS10039_2.s
	gcc asgn6_19CS10060_19CS10039_2.o -o test2 -L. -lmyio -no-pie
	./test2
	
	@echo "\n+++++++++++++++++++++ TESTING file 2 DONE!! +++++++++++++++++++++++++++#\n"

test3: tinyC_compiler libmyio.a
	./tinyC_compiler 3 > asgn6_19CS10060_19CS10039_quads3.out
	gcc -c asgn6_19CS10060_19CS10039_3.s
	gcc asgn6_19CS10060_19CS10039_3.o -o test3 -L. -lmyio -no-pie
	./test3
	
	@echo "\n+++++++++++++++++++++ TESTING file 3 DONE!! +++++++++++++++++++++++++++#\n"

test4: tinyC_compiler libmyio.a
	./tinyC_compiler 4 > asgn6_19CS10060_19CS10039_quads4.out
	gcc -c asgn6_19CS10060_19CS10039_4.s
	gcc asgn6_19CS10060_19CS10039_4.o -o test4 -L. -lmyio -no-pie
	./test4
	
	@echo "\n+++++++++++++++++++++ TESTING file 4 DONE!! +++++++++++++++++++++++++++#\n"

test5: tinyC_compiler libmyio.a
	./tinyC_compiler 5 > asgn6_19CS10060_19CS10039_quads5.out
	gcc -c asgn6_19CS10060_19CS10039_5.s
	gcc asgn6_19CS10060_19CS10039_5.o -o test5 -L. -lmyio -no-pie
	./test5
	
	@echo "\n+++++++++++++++++++++ TESTING file 5 DONE!! +++++++++++++++++++++++++++#\n"

test6: tinyC_compiler libmyio.a
	./tinyC_compiler 6 > asgn6_19CS10060_19CS10039_quads6.out
	gcc -c asgn6_19CS10060_19CS10039_6.s
	gcc asgn6_19CS10060_19CS10039_6.o -o test6 -L. -lmyio -no-pie
	./test6
	
	@echo "\n+++++++++++++++++++++ TESTING file 6 DONE!! +++++++++++++++++++++++++++#\n"

libmyio.a:
	gcc -c ass2_19CS10060_19CS10039.c
	ar -rcs libmyio.a ass2_19CS10060_19CS10039.o


tinyC_compiler: lex.yy.o asgn6_19CS10060_19CS10039.tab.o asgn6_19CS10060_19CS10039_translator.o asgn6_19CS10060_19CS10039_target_translator.o
	g++ lex.yy.o asgn6_19CS10060_19CS10039.tab.o asgn6_19CS10060_19CS10039_translator.o \
	asgn6_19CS10060_19CS10039_target_translator.o -lfl -o tinyC_compiler

asgn6_19CS10060_19CS10039_target_translator.o: asgn6_19CS10060_19CS10039_target_translator.cxx
	g++ -c asgn6_19CS10060_19CS10039_target_translator.cxx

asgn6_19CS10060_19CS10039_translator.o: asgn6_19CS10060_19CS10039_translator.cxx asgn6_19CS10060_19CS10039_translator.h
	g++ -c asgn6_19CS10060_19CS10039_translator.h
	g++ -c asgn6_19CS10060_19CS10039_translator.cxx

lex.yy.o: lex.yy.c
	g++ -c lex.yy.c

asgn6_19CS10060_19CS10039.tab.o: asgn6_19CS10060_19CS10039.tab.c
	g++ -c asgn6_19CS10060_19CS10039.tab.c

lex.yy.c: asgn6_19CS10060_19CS10039.l asgn6_19CS10060_19CS10039.tab.h asgn6_19CS10060_19CS10039_translator.h
	flex asgn6_19CS10060_19CS10039.l

asgn6_19CS10060_19CS10039.tab.c: asgn6_19CS10060_19CS10039.y
	bison -dtv asgn6_19CS10060_19CS10039.y -W

asgn6_19CS10060_19CS10039.tab.h: asgn6_19CS10060_19CS10039.y
	bison -dtv asgn6_19CS10060_19CS10039.y -W


	
clean:
	rm lex.yy.c\
	   asgn6_19CS10060_19CS10039.tab.c\
	   asgn6_19CS10060_19CS10039.tab.h\
	   lex.yy.o\
	   asgn6_19CS10060_19CS10039.tab.o\
	   asgn6_19CS10060_19CS10039.output\
	   asgn6_19CS10060_19CS10039_translator.o\
	   tinyC_compiler\
	   asgn6_19CS10060_19CS10039_target_translator.o\
	   asgn6_19CS10060_19CS10039_translator.h.gch\
	   libmyio.a\
	   ass2_19CS10060_19CS10039.o\
	   test1 test2 test3 test3 test4 test5 test6\
	   asgn6_19CS10060_19CS10039_1.o\
	   asgn6_19CS10060_19CS10039_2.o\
	   asgn6_19CS10060_19CS10039_3.o\
	   asgn6_19CS10060_19CS10039_4.o\
	   asgn6_19CS10060_19CS10039_5.o\
	   asgn6_19CS10060_19CS10039_6.o