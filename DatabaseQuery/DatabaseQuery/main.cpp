#include <winsock.h>
#include "mysql.h"
#include <string>

#define IP "127.0.0.1"
#define ID "root"
#define PW "root"
#define DB "sinkthatbase"

int main(int argc, char *argv[]) {
	//Remove the console
	FreeConsole();

	//Initialisation du context mysql
	MYSQL *mysql = mysql_init(NULL);

	//Connexion à la base de données
	if (mysql_real_connect(mysql, IP, ID, PW, DB, 3306, NULL, 0)) {

		//Construction de la requête
		std::string Query = 
			"INSERT INTO tb_player VALUES (NULL, '" + std::string(argv[1]) + "'";
		
		for (int i = 2; i < argc; ++i)
			Query += ", " + std::string(argv[i]);

		Query += ");";

		//Passage de la requête sur la base
		mysql_query(mysql, Query.c_str());

		//Fermeture du context mysql
		mysql_close(mysql);
	}
	else 
		return -1;
	return 0;
}