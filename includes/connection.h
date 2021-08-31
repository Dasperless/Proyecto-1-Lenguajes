MYSQL *mysql;
char *server = "localhost";
char *user = "root";
char *password = "Proyecto_1_Lenguajes"; /* set me first */
char *database = "proyecto-1";

void finish_with_error(MYSQL *con);
void callStoredProcedure(char *sp, char *values);
int callStoredProcedureOutput(char *sp, char *values);

void printStoredProcedure(char *sp);
void printTable(char *table);
void printFormatedTable(char table[]);
/**
 * @brief Imprime con encabezado las tablas
 * 
 * @param table la tabla a imprimir
 */
void printFormatedTable(char table[])
{

  if (strcmp(table, "teacher") == 0)
  {
    printf("Id\t\tCedula\t\t\tNombre\n");
  }
  else if (strcmp(table, "classroom") == 0)
  {
    printf("Id\t\tNombre\t\tCapacidad\n");
  }
  else if (strcmp(table, "course") == 0)
  {
    printf("Id\t\tCod.carrera\tCod.curso\t\tnombre\n");
  }
  else if (strcmp(table, "periodxcourse") == 0)
  {
    printf("Id\t\tCod.curso\tanio\t\tperiodo\t\tgrupo\t\tprofesor\t\tcant.estudiantes\n");
    printStoredProcedure("SP_PrintPeriodxCourse");
    return;
  }
  else if (strcmp(table, "reservation") == 0)
  {
    printf("Id\t\tfecha\t\t\thora inicio\t\thora fin\t\taula\t\tanio\t\tperiodo\t\tcod.curso\tgrupo\n");
    printStoredProcedure("SP_PrintReservation");
    return;
  }
  else
  {
    printf("No existe la tabla\n");
    return;
  }
  printTable(table);
}

/**
 * @brief Imprime errores de una consulta
 * 
 * @param con la conexión 
 */
void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
}

/**
 * @brief Imprime los datos de una tabla de la base de datos
 * 
 * @param sp La tabla a imprimir.
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
 * @brief Imprime el stored procedure
 * 
 * @param sp El procedimiento
 */
void printStoredProcedure(char *sp)
{
  char query[512] = {0};
  snprintf(query, 512, "CALL %s", sp);
  printf("%s\n",query);
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
 * @brief Imprime el stored procedure
 * 
 * @param sp El procedimiento
 */
int printStoredProcedureOutput(char *sp, char*values)
{
  char query[512] = {0};
  char output[10] = {0};
  snprintf(query, 512, "CALL %s (%s,@output)", sp,values);
  printf("%s\n",query);
  MYSQL *con = mysql_init(NULL);

  if (con == NULL)
  {
    fprintf(stderr, "mysql_init() failed\n");
  }

  if (mysql_real_connect(con, server, user, password,database, 0, NULL, 0) == NULL)
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
  return atoi(output);
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

/**
 * @brief LLama un procedimiento almacenado con un solo output.
 * 
 * @param sp      el procedimiento almacenado.
 * @param values  los valores del procedimiento.
 * @return int    el output del procedimiento.
 */
int callStoredProcedureOutput(char *sp, char *values)
{
  char query[512] = {0};
  char output[4] = {0};
  snprintf(query, 512, "CALL %s (%s,@output)", sp, values);
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
