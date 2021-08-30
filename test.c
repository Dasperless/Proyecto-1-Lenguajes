#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/connection.h"

int main(int argc, char const *argv[])
{

	int i = callStoredProcedureOutput("SP_InsertCurseByPeriod","'dsadsa', 2021, 1, 'dsada','dasdsa',1");
	printf("%d",i);
	return 0;
}
