all:
	gcc book0.c -o book0 -l sqlite3
	gcc book1.c -o book1 -l sqlite3
	cc -o a4p1Server a4p1Server.c -lnsl -lpthread
	gcc a4p1Client1.c -o a4p1Client
	gcc a4p1Client2.c -o a4p1Client2
	gcc a4Client3.c -o a4p1Client3

