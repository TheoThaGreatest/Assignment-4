// Made by Theophilus Ojukwu II
// Program book0.c

#include <stdio.h>
#include <sqlite3.h>

int main(int argc, char* argv[])
{
	sqlite3 *db;
	char *errMsg = 0;
	int rc;

	rc = sqlite3_open("book.db", &db);

	if(rc)
	{
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	} else {
		fprintf(stderr, "Opened database!\n");
	}
	sqlite3_close(db);

	return(0);
}
