// Made by Theophilus Ojukwu II
// program book1.c
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
	int i;
	for(i = 0; i < argc; i++){
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

int main(int argc, char* argv[])
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	char *sql;

	/* Open database */
	rc = sqlite3_open("book.db", &db);
	if(rc){
		fprintf(stderr, "Can't open Database: %s\n", sqlite3_errmsg(db));
		exit(0);
	}else{
		fprintf(stdout, "Opened database successfully\n");
	}

	/* creating SQL statement */
	sql = 	"CREATE TABLE CLASSICS (" \
		"author varchar(128) DEFAULT NULL," \
		"title varchar(128) DEFAULT NULL," \
		"category varchar(16) DEFAULT NULL," \
		"year char(4) DEFAULT NULL, "
		"ibsn char(13) PRIMARY KEY NOT NULL);";
	
	/* execute the SQL statement */
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if(rc != SQLITE_OK){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}else{
		fprintf(stdout, "Table created successfully\n");
	}
	sqlite3_close(db);
	return 0;
}
