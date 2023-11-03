#!/bin/bash


rm -rf ./example/test2_result;
echo "
C-MINUS COMPILATION: test2.cm
	1: ID, name= A
	3: /
	3: *
	4: ID, name= comment
	4: ID, name= test
	4: NUM, val= 2
	6: *
	6: /
	8: ID, name= A
	16: ID, name= B
	21: EOF" >> ./example/test2_result;

if [ -e "./example/test.cm" ]; then
	mv ./example/test.cm ./example/test1.cm;
fi

if [ -e "./example/test_result" ]; then
	mv ./example/test_result ./example/test1_result;
fi

rm -rf ./example/test1_result;
echo "
C-MINUS COMPILATION: test1.cm
	4: reserved word: int
	4: ID, name= gcd
	4: (
	4: reserved word: int
	4: ID, name= u
	4: ,
	4: reserved word: int
	4: ID, name= v
	4: )
	5: {
	6: reserved word: if
	6: (
	6: ID, name= v
	6: ==
	6: NUM, val= 0
	6: )
	6: reserved word: return
	6: ID, name= u
	6: ;
	7: reserved word: else
	7: reserved word: return
	7: ID, name= gcd
	7: (
	7: ID, name= v
	7: ,
	7: ID, name= u
	7: -
	7: ID, name= u
	7: /
	7: ID, name= v
	7: *
	7: ID, name= v
	7: )
	7: ;
	9: }
	11: reserved word: void
	11: ID, name= main
	11: (
	11: reserved word: void
	11: )
	12: {
	13: reserved word: int
	13: ID, name= x
	13: ;
	13: reserved word: int
	13: ID, name= y
	13: ;
	14: ID, name= x
	14: =
	14: ID, name= input
	14: (
	14: )
	14: ;
	14: ID, name= y
	14: =
	14: ID, name= input
	14: (
	14: )
	14: ;
	15: ID, name= output
	15: (
	15: ID, name= gcd
	15: (
	15: ID, name= x
	15: ,
	15: ID, name= y
	15: )
	15: )
	15: ;
	16: }
	17: EOF" >> ./example/test1_result;

echo "TEST CMINUS\n";

for var in 1 2 3 4 5
do
	echo "[CMINUS] >> TEST CASE ${var}";
	rm -rf ./example/test${var}; ./cminus_cimpl ./example/test${var}.cm >> ./example/test${var};
	if [ "`diff ./example/test${var} ./example/test${var}_result`" = "2c2
< C-MINUS COMPILATION: ./example/test${var}.cm
---
> C-MINUS COMPILATION: test${var}.cm" ]; then
		echo "OK...";
	else
		echo "NO...";
	fi
	echo "";
done

echo "\n\nTEST LEX\n";

for var in 1 2 3 4 5
do
	echo "[LEX] >> TEST CASE ${var}";
	rm -rf ./example/test${var}; ./cminus_lex ./example/test${var}.cm >> ./example/test${var};
	if [ "`diff ./example/test${var} ./example/test${var}_result`" = "2c2
< C-MINUS COMPILATION: ./example/test${var}.cm
---
> C-MINUS COMPILATION: test${var}.cm" ]; then
		echo "OK...";
	else
		echo "NO...";
	fi
	echo "";
done
