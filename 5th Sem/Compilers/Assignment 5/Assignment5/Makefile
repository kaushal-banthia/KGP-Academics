
all: a.out
	
	./a.out < asgn5_19CS10060_19CS10039_test1.c > asgn5_19CS10060_19CS10039_quads1.out
	./a.out < asgn5_19CS10060_19CS10039_test2.c > asgn5_19CS10060_19CS10039_quads2.out
	./a.out < asgn5_19CS10060_19CS10039_test3.c > asgn5_19CS10060_19CS10039_quads3.out
	./a.out < asgn5_19CS10060_19CS10039_test4.c > asgn5_19CS10060_19CS10039_quads4.out
	./a.out < asgn5_19CS10060_19CS10039_test5.c > asgn5_19CS10060_19CS10039_quads5.out
	./a.out < asgn5_19CS10060_19CS10039_test6.c > asgn5_19CS10060_19CS10039_quads6.out
	@echo "\n DONE !!\n"
	


a.out: lex.yy.o asgn5_19CS10060_19CS10039.tab.o asgn5_19CS10060_19CS10039_translator.o
	g++ lex.yy.o asgn5_19CS10060_19CS10039.tab.o asgn5_19CS10060_19CS10039_translator.o -lfl

asgn5_19CS10060_19CS10039_translator.o: asgn5_19CS10060_19CS10039_translator.cxx asgn5_19CS10060_19CS10039_translator.h
	g++ -c asgn5_19CS10060_19CS10039_translator.h
	g++ -c asgn5_19CS10060_19CS10039_translator.cxx

lex.yy.o: lex.yy.c
	g++ -c lex.yy.c

asgn5_19CS10060_19CS10039.tab.o: asgn5_19CS10060_19CS10039.tab.c
	g++ -c asgn5_19CS10060_19CS10039.tab.c

lex.yy.c: asgn5_19CS10060_19CS10039.l asgn5_19CS10060_19CS10039.tab.h asgn5_19CS10060_19CS10039_translator.h
	flex asgn5_19CS10060_19CS10039.l

asgn5_19CS10060_19CS10039.tab.c: asgn5_19CS10060_19CS10039.y
	bison -dtv asgn5_19CS10060_19CS10039.y -W

asgn5_19CS10060_19CS10039.tab.h: asgn5_19CS10060_19CS10039.y
	bison -dtv asgn5_19CS10060_19CS10039.y -W

clean:
	rm lex.yy.c asgn5_19CS10060_19CS10039.tab.c asgn5_19CS10060_19CS10039.tab.h lex.yy.o asgn5_19CS10060_19CS10039.tab.o asgn5_19CS10060_19CS10039_translator.o a.out asgn5_19CS10060_19CS10039_translator.h.gch