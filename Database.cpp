#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "sqlite3.h"
#include <string>
using namespace std;

/*CREATE QUERY*/
int main(int argc, char** argv)
{
		sqlite3* DB;
		std::string sql = "CREATE TABLE Stats("  \
			"ID               INT              PRIMARY   KEY," \
			"NAME             TEXT             NOT NULL," \
			"coinCount        INT              NULL," \
			"heath            NUMERIC(10)      NOT NULL," \
			"potion           NUMERIC(10)      NULL," \
			"level            NUMERIC(10)      NULL);";
		int exit = 0;
		exit = sqlite3_open("Game.db", &DB);
		char* messaggeError;
		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

		if (exit != SQLITE_OK) {
			std::cerr << "Error Create Table" << std::endl;
			sqlite3_free(messaggeError);
		}
		else
			std::cout << "Table created Successfully" << std::endl;
		sqlite3_close(DB);
		return (0);
}


/*INSERT QUERY*/
static int callback(void* data, int argc, char** argv, char** azColName)
{
	int i;
	fprintf(stderr, "%s: ", (const char*)data);

	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}

	printf("\n");
	return 0;
}

int main(int argc, char** argv)
{
	sqlite3* DB;
	char* messaggeError;
	int exit = sqlite3_open("Game.db", &DB);
	string query = "SELECT * FROM Stats;";

	cout << "STATE OF TABLE BEFORE INSERT" << endl;

	sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

	string sql("INSERT INTO Stats VALUES(1, 'STEVE', 5, 100, 0, 3);");

	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
	if (exit != SQLITE_OK) {
		std::cerr << "Error Insert" << std::endl;
		sqlite3_free(messaggeError);
	}
	else
		std::cout << "Records created Successfully!" << std::endl;

	cout << "STATE OF TABLE AFTER INSERT" << endl;

	sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);


	sqlite3_close(DB);
	
	return (0);
}







//code that didn't work//


/*int main()
{
	/*sqlite3 *db;
	int statusOfOpen = sqlite3_open(":memory:", &db);

	if (statusOfOpen == SQLITE_OK)
	{
		cout << "Successfully opened the database" << endl;

		sqlite3_stmt* myStatement;
		int statusOfPrep = sqlite3_prepare_v2(db, "CREATE TABLE IF NOT EXISTS Stats (ID INTEGER PRIMARY KEY, name TEXT, coinCount INT, health NUMERIC(10), potion NUMERIC(10), level NUMERIC(10))", -1, &myStatement, NULL);

		if (statusOfPrep == SQLITE_OK)
		{
			int statusOfStep = sqlite3_step(myStatement);

			if (statusOfStep == SQLITE_DONE)
			{
				cout << "Successfully created the the Students table" << endl;
			}
			else
			{
				cout << "Problem creating the Students table" << endl;
			}

			sqlite3_finalize(myStatement);
		}
		else
		{
			cout << "Problem creating a prepared statement" << endl;
		}

		string name;

		cout << "Enter in a first: ";
		cin >> first;
		int health = 100;
		int potion = 0;
		int level = 0;
		int coinCount = 0;

		statusOfPrep = sqlite3_prepare_v2(db, "INSERT INTO Students (ID, name, coinCount, health, potion, level) VALUES (?, ?, ?, ?, ?)", -1, &myStatement, NULL);

		sqlite3_bind_text(myStatement, 1, name.c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_text(myStatement, 2, coinCount.c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_text(myStatement, 3, health.c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_text(myStatement, 4, potion.c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_text(myStatement, 5, level.c_str(), -1, SQLITE_STATIC);

		if (statusOfPrep == SQLITE_OK)
		{
			int statusOfStep = sqlite3_step(myStatement);

			if (statusOfStep == SQLITE_DONE)
			{
				cout << "Successfully inserted into the database" << endl;
			}
			else
			{
				cout << "Problem inserting into the database" << endl;
			}

			sqlite3_finalize(myStatement);
		}
		else
		{
			cout << "Problem creating a prepared statement" << endl;
		}

		statusOfPrep = sqlite3_prepare_v2(db, "SELECT * FROM Stats", -1, &myStatement, NULL);

		if (statusOfPrep == SQLITE_OK)
		{
			int statusOfStep = sqlite3_step(myStatement);

			while (statusOfStep == SQLITE_ROW)
			{
				int id = sqlite3_column_int(myStatement, 0);
				first = (char*)sqlite3_column_text(myStatement, 1);
				last = (char*)sqlite3_column_text(myStatement, 2);

				cout << "ID: " << ID << endl;
				cout << "Name: " << name << endl;
				cout << "Coins: " << coinCount << endl;
				cout << "Health: " << health << endl;
				cout << "Level: " << level << endl;
				cout << "Potions: " << potion << endl;

				statusOfStep = sqlite3_step(myStatement);
			}

			sqlite3_finalize(myStatement);
		}
		else
		{
			cout << "Problem creating a prepared st" << endl;
		}
	else //could not open the database
	{
		cout << "couldn't open the database" << endl;
	}

	return 0;*/
	/*sqlite3 *db;
	sqlite3_stmt * st;
	string sql3;

	string name;
	cout << "Enter your name:\n";
	cin >> name;
	int health = 100;
	int potion = 0;
	int level = 0;
	int coinCount = 0;

	sql3 = "CREATE TABLE Stats("  \
	"ID               INT              PRIMARY   KEY," \
	"NAME             TEXT             NOT NULL," \
	"coinCount        INT              NULL," \
	"heath            NUMERIC(10)      NOT NULL," \
	"potion           NUMERIC(10)      NULL," \
	"level            NUMERIC(10)      NULL);";

	string sql = "INSERT INTO Stats(ID, name, coinCount, health, potion, level) VALUES (?, ?, ?, ?, ?);";

	if (sqlite3_open("pw.db", &db) == SQLITE_OK)
	{
		sqlite3_prepare(db, sql.c_str(), -1, &st, NULL);
		sqlite3_bind_text(st, 1, name.c_str(), name.length(), SQLITE_TRANSIENT);
		sqlite3_bind_text(st, 2, health.c_str(), health.length(), SQLITE_TRANSIENT);
		sqlite3_bind_text(st, 3, potion.c_str(), potion.length(), SQLITE_TRANSIENT);
		sqlite3_step(st);
	}

}*/




/*static int callback(void *data, int argc, char **argv, char **azColName) {
	int i;
	fprintf(stderr, "%s: ", (const char*)data);

	for (i = 0; i < argc; i++) {
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
	const char* data = "Callback function called";
	/* Open database */
	/*rc = sqlite3_open("Game.db", &db);
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		exit(0);
	}
	else {
		fprintf(stderr, "Opened database successfully\n");
	}
	int ID = 0;
	int health = 100;
	int potion = 1;
	int coinCount = 3;
	int level = 5;
	std::string sql = "UPDATE Stats set coinCount = ?; " \
		              "SELECT * from Stats";
	/* Execute SQL statement */

	/*rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Operation done successfully\n");
	}
	sqlite3_close(db);
	return 0;
}*/