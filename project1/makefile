Project1: Project1.c
	gcc -o Project1 Project1.c
Test: Test1 Test2 Test3 Test4 Test5 Test6
Test1:
	./Project1 1 FEATHER data.txt data.out
Test2:
	./Project1 2 FEATHER data.out data.bak
Test3:
	diff -s data.txt data.bak
Test4:
	./Project1 1 FEATHER data2.txt data2.out
Test5:
	./Project1 2 FEATHER data2.out data2.bak
Test6:
	diff -s data2.txt data2.bak
