MYSQL *mysql;
char *server = "localhost";
char *user = "root";
char *password = "Proyecto_1_Lenguajes"; /* set me first */
char *database = "proyecto-1";

void printFormatedTable(char table[])
{

  if (table == "teacher")
  {
    printf("Id\t\t cedula\t\t nombre\n");
    
  }
  else if (table == "classroom")
  {
    printf("Id\t\t nombre\t\t capacidad\n");
  }
  else if (table == "course")
  {
    printf("Id\t\t codigo de carrera\t\t codigo de curso\n");
  }
  else if (table == "periodxcourse")
  {
    printf("Id\t\t id \t\t codigo de curso\t\t anio\t\t periodo\t\t grupo \t\t profesor\t\t cantidad de estudiantes\n");
    //Colocar otro print

  }
  else if (table == "reservation")
  {
    printf("Id\t\t fecha\t\t hora inicio\t\t hora fin\t\t aula \t\t curso\t\t \n");
    //colocar otro print

  }else{
    printf("No existe la tabla\n");
  } 
  printTable(table);

}

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

/**
 * @brief Imprime los datos de una tabla de la base de datos
 * 
 * @param table La tabla a imprimir.
 */
void printTable(char *table)
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
      printf("%s\t\t", row[i] ? row[i] : "NULL");
    }

    printf("\n");
  }

  mysql_free_result(result);
  mysql_close(con);
}

/**
 * @brief Llama un procedimiento almacenado mediante mysql_query.
 * 
 * @param sp      
 * @param values 
 */
void callStoredProcedure(char *sp, char *values)
{
  char query[512] = {0};
  snprintf(query, 512, "CALL %s (%s)", sp, values);
  printf("%s\n", query);

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
}

int callStoredProcedureOutput(char *sp, char *values)
{
  char query[512] = {0};
  char output[4] = {0};
  snprintf(query, 512, "CALL %s (%s,@output)", sp, values);

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

  if (mysql_query(con, "SELECT @output"))
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
      snprintf(output, 4, "%s", row[i]);
    }
  }

  mysql_free_result(result);
  mysql_close(con);
  return atoi(output);
}
