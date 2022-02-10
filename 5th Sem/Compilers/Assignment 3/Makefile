test: a.out ass3_19CS10060_19CS10039_test.c
		./a.out ass3_19CS10060_19CS10039_test.c >output.txt

a.out:	lex.yy.c
		gcc lex.yy.c -lfl

lex.yy.c:	ass3_19CS10060_19CS10039.l ass3_19CS10060_19CS10039.c
		flex ass3_19CS10060_19CS10039.l ass3_19CS10060_19CS10039.c

clean:
		rm a.out lex.yy.c