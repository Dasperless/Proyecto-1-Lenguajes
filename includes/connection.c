#include <mysql.h>
#include <string.h>
#include <stdio.h>

MYSQL *mysql;
char *server = "localhost";
char *user = "root";
char *password = "Proyecto_1_Lenguajes"; /* set me first */
char *database = "proyecto-1";

void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);
}

int main(){
  MYSQL *con = mysql_init(NULL);

  if (con == NULL)
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      exit(1);
  }
  if (mysql_real_connect(con, server, user, password,
          database, 0, NULL, 0) == NULL)
  {
      finish_with_error(con);
  }  
  if (mysql_query(con, "INSERT INTO aulas(nombre,capacidad) VALUES('A2',35)")) {
        finish_with_error(con);
    }  
  mysql_close(con);
  printf("Se agrego un aula con exito");
  exit(0);    
}
