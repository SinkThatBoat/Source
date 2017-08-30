#include <winsock.h>
#include "mysql.h"
#include <string>

#define IP "127.0.0.1"
#define ID "root"
#define PW "root"
#define DB "sinkthatbase"

int main(int argc, char *argv[]) {
	// Remove the console
	FreeConsole();

	// Vérifie que le nombe d'arguments est suffisant
	if (argc >= 2) {

		// Initialisation du contexte mysql
		MYSQL *mysql = mysql_init(NULL);

		// Connexion à la base de données
		if (mysql_real_connect(mysql, IP, ID, PW, DB, 3306, NULL, 0)) {
			
			// Construction de la requête
			std::string Query =
				"INSERT INTO tb_player "
				"VALUES (NULL, '" + std::string(argv[1]) + "', '" + std::string(argv[2]) + ");";

			// Passage de la requête sur la base
			mysql_query(mysql, Query.c_str());
		}

		// Fermeture du contexte mysql
		mysql_close(mysql);
	}

	return 0;
}