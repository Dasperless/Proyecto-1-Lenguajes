MYSQL *mysql;
char *server = "localhost";
char *user = "root";
char *password = "Proyecto_1_Lenguajes"; /* set me first */
char *database = "proyecto-1";

void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
}

/**
 * @brief Inserta en la base de datos
 * 
 * @param table La tabla a la cual insertar
 * @param columns  Las columnas a las cuales insertar ej(nombre,capacidad)
 * @param values  Los valores ej ("string",entero)
 */
int insertOnDatabase(char *table, char *columns, char *values)
{
  char query[512] = {0};
  snprintf(query, 512, "INSERT INTO %s %s VALUES%s", table, columns, values);
  printf("%s\n", query);

  MYSQL *con = mysql_init(NULL);
  if (con == NULL)
  {
    fprintf(stderr, "%s\n", mysql_error(con));
    return 1;
  }
  if (mysql_real_connect(con, server, user, password,
                         database, 0, NULL, 0) == NULL)
  {
    finish_with_error(con);
  }
  if (mysql_query(con, query))
  {
    finish_with_error(con);
  }
  mysql_close(con);
  printf("Se insertado en la base de datos con exito\n");
  return 0;
}

void printTable(char* table)
{
  char query[512] = {0};
  snprintf(query, 512, "SELECT * FROM %s", table);
  MYSQL *con = mysql_init(NULL);

  if (con == NULL)
  {
    fprintf(stderr, "mysql_init() failed\n");
  }

  if (mysql_real_connect(con, server, user, password,
                         database, 0, NULL, 0) == NULL)
  {
    finish_with_error(con);
  }

  if (mysql_query(con, query))
  {
    finish_with_error(con);
  }

  MYSQL_RES *result = mysql_store_result(con);

  if (result == NULL)
  {
    finish_with_error(con);
  }

  int num_fields = mysql_num_fields(result);

  MYSQL_ROW row;
  while ((row = mysql_fetch_row(result)))
  {
    for (int i = 0; i < num_fields; i++)
    {
      printf("%s ", row[i] ? row[i] : "NULL");
    }

    printf("\n");
  }

  mysql_free_result(result);
  mysql_close(con);
}

void storedProcedure(){
    char query[512] = "call p1('Stored',99)";

  MYSQL *con = mysql_init(NULL);
  if (con == NULL)
  {
    fprintf(stderr, "%s\n", mysql_error(con));
  }
  if (mysql_real_connect(con, server, user, password,
                         database, 0, NULL, 0) == NULL)
  {
    finish_with_error(con);
  }
  if (mysql_query(con, query))
  {
    finish_with_error(con);
  }
  mysql_close(con);
  printf("Se insertado en la base de datos con exito\n");
}
