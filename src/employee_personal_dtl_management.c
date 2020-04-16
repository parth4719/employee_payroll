#include<stdio.h>
#include<windows.h>
#include<mysql.h>
#include "..\include\Validation.h"
#include "..\include\employee_personal_dtl_management.h"
#include "..\include\employee.h"
#define YEAR 2020
#define MIN_YEAR 2018

MYSQL *conn3;
MYSQL *conn8;
MYSQL *conn9;

int port7=3305;

// In this function, it will display the detail of the employee and doesnot return nothing but instead printing the messages on the console screen.
void emp_display(char stmt[]){
    MYSQL_RES *read=NULL;
    MYSQL_RES *res=NULL;
    MYSQL_ROW row=NULL;
    MYSQL_FIELD *field;
    int num;

    if(conn3)
    {
        mysql_query(conn3,stmt);
        read = mysql_store_result(conn3);
        if (mysql_query(conn3,stmt))
        {
            printf(" Error: %s\n", mysql_error(conn3));
            printf("Failed to execute query.");
        }

        else
        {
            while (row = mysql_fetch_row(read))
            {
                int num_fields;
                num_fields = mysql_num_fields(read);
                int i;
                for(i = 0; i < num_fields; i++)
                {
                    printf("|");
                    if (i == 0)
                    {
                        while(field = mysql_fetch_field(read))
                        {
                            printf("%s|", field->name);
                        }
                        printf("\n");
                    }
                    printf(" %s", row[i] ? row[i] : "NULL");
                }
            }

            printf("\n");
        }
    }

    else
    {
        printf("not connected");
        printf("%s\n", mysql_error(conn3));
    }

}

//end of displaying a employee detail.


//Start of update employee function.
char* update_employee(int emp_id)
{
    conn3=mysql_init(NULL);
    int id;
    mysql_real_connect(conn3, "localhost", "root", "1234","payroll", port7, NULL, 0);
    struct employee
    {
        char address1[45];
        char address2[45];
        char phonenumber[20];
        char gender[10];
        char email[100];
    };

    struct employee emp;
    int i=0;
    char stmt[1500];
    printf("                Press 1 Address Line 1\n");
    printf("                Press 2 Address Line 2\n");
    printf("                Press 3 Phone Number\n");
    printf("                Press 4 Gender\n");
    printf("                Press 5 Email\n");
    printf("                Press 6 Exit\n");
    scanf("%d",&i);
    switch(i)
    {
        case 1:
        {
            int x=0;
            do
            {
                printf("Enter address line 1\n");
                gets(emp.address1);
                x=notempty(emp.address1);
            }while(x==0);
            char qry[]={"update emp_details set address_l1='%s' where emp_id='%d'"};
            if(conn3)
            {
                sprintf(stmt,qry,emp.address1,emp_id);
                if(mysql_query(conn3,stmt))
                {
                    printf(" Error: %s\n", mysql_error(conn3));
                    return "Failed to execute query.";
                }
                else
                {
                    return "\n\n\n\nUser modified successfully\n\n\n\n";
                }
            }
            else
            {
                printf("not connected");
                printf("%s\n", mysql_error(conn3));
            }
            break;
        }

        case 2:
        {
            int x=0;
            do
            {
                printf("Enter address line 2\n");
                gets(emp.address2);
                x=notempty(emp.address2);
            }while(x==0);

            char qry[]={"update emp_details set address_l2='%s' where emp_id='%d'"};
            if(conn3)
            {
                sprintf(stmt,qry,emp.address2,emp_id);
                if(mysql_query(conn3,stmt))
                {
                    printf(" Error: %s\n", mysql_error(conn3));
                    return "Failed to execute query.";
                }
                else
                {
                    return "\n\n\n\nUser modified successfully\n\n\n\n";
                }
            }
            else
            {
                printf("not connected");
                printf("%s\n", mysql_error(conn3));
            }
            break;
        }

        case 3:
        {
            int x=0;
            do
            {
                printf("Please provide the phone number: \n");
                scanf("%s",emp.phonenumber);
                x=valid_phone(emp.phonenumber);
            }while(x==0);


            char qry[]={"update emp_details set phonen='%s' where emp_id='%d'"};

            if(conn3)
            {
                sprintf(stmt,qry,emp.phonenumber,emp_id);
                if(mysql_query(conn3,stmt))
                {
                    printf(" Error: %s\n", mysql_error(conn3));
                    return "Failed to execute query.";
                }
                else
                {
                    return "\n\n\n\nUser modified successfully\n\n\n\n";
                }
            }
            else
            {
                printf("not connected");
                printf("%s\n", mysql_error(conn3));
            }
            break;
        }

        case 4:
        {
            printf("Enter gender Male,Female or Others\n");
            scanf("%s",emp.gender);
            char qry[]={"update emp_details set gender='%s' where emp_id='%d'"};
            if(conn3)
            {
                sprintf(stmt,qry,emp.gender,emp_id);
                if(mysql_query(conn3,stmt))
                {
                    printf(" Error: %s\n", mysql_error(conn3));
                    return "Failed to execute query.";
                }
                else
                {
                    return "\n\n\n\nUser modified successfully\n\n\n\n";
                }
            }
            else
            {
                printf("not connected");
                printf("%s\n", mysql_error(conn3));
            }
            break;
        }
        case 5:
        {
            int x=0;
            do{
                printf("Please provide the email: \n");
                scanf("%s",emp.email);
                x=valid_email(emp.email);
            }while(x==0);

            char qry[]={"update emp_details set email='%s' where emp_id='%d'"};
            if(conn3)
            {
                sprintf(stmt,qry,emp.email,emp_id);
                if(mysql_query(conn3,stmt))
                {
                    printf(" Error: %s\n", mysql_error(conn3));
                    return "Failed to execute query.";
                }
                else
                {
                    return "\n\n\n\nUser modified successfully\n\n\n\n";
                }
            }
            else
            {
                printf("not connected");
                printf("%s\n", mysql_error(conn3));
            }

            break;
        }
    }
}
// end of update employee


// Starting of the raise grievance function.
char* raise_grievances(int e_id)
{
	conn8 = mysql_init(NULL);
	mysql_real_connect(conn8, "localhost", "root", "1234","payroll", port7, NULL, 0);

	if(!conn8)
	{
		printf("Connection error");
		return "0";
	}

	else
	{
		char stmt[1500];
		char description[200];
		char choice[10];
		int x=0;
		getchar();

		do
		{
    		printf("Redress the problem in 200 characters\n");
    		gets(description);
    		x=notempty(description);
    	}while(x==0);

    	printf("Do you want to anonymous? y/n: ");
    	scanf("%s",choice);

    	if ( 0 == strcasecmp(choice,"y"))
		{
			char qry[]={"insert into grievances (response_number,emp_id,description) VALUES(NULL,NULL,'%s')"};
			sprintf(stmt,qry,description);
			if (mysql_query(conn8,stmt))
    		{
   				printf(" Error: %s\n", mysql_error(conn8));
   				return "Failed to execute query.";
   			}

			else
 			{
 	   			return "\n\n\n Grievance Raised. \n\n\n\n";
 			}
    	}

		else if (0 == strcasecmp(choice,"n"))
    	{
			char qry[]={"insert into grievances (response_number,emp_id,description) VALUES(NULL, %d,'%s')"};
			sprintf(stmt,qry,e_id,description);

			if (mysql_query(conn8,stmt))
    		{
   				printf(" Error: %s\n", mysql_error(conn8));
   				return "Failed to execute query.";
   			}

			else
	 		{
	 			return "\n\n\n Grievance Raised. \n\n\n\n";
	 		}
    	}

	    else
	    {
	    	printf("Wrong choice.");
	    	return "1";
	    }
	}
}
// Ending of the raise grievance function.


// For viewing the grievances: view_raise_grievances();
void view_raised_grievances()
{
	MYSQL_RES *read=NULL;
	MYSQL_RES *res=NULL;
	MYSQL_ROW row=NULL;
	MYSQL_FIELD *field;

	conn8 = mysql_init(NULL);
	mysql_real_connect(conn8, "localhost", "root", "1234","payroll", 3306, NULL, 0);

	if(!conn8)
	{
		printf("Connection error");
		printf("%s\n", mysql_error(conn8));
	}

	else
	{	char stmt[1500];
		int choice;
		printf("		Press 1 View Grievances by employee id\n");
		printf("		Press 2 View all Grievances\n");
		scanf("%d",&choice);

		if (1 == choice)
		{
			int gri_choice;
			printf("Enter the employee id to see their grievances: \n");
			scanf("%d",&gri_choice);
			char qry[]={"select response_number, description from grievances where emp_id = %d"};
			sprintf(stmt,qry,gri_choice);
			if (mysql_query(conn8,stmt))
    		{
   				printf(" Error: %s\n", mysql_error(conn8));
   				printf("Failed to execute query.");
   			}

			else
 			{
 				read = mysql_store_result(conn8);
 				int count_rows = mysql_num_rows(read);
				if (count_rows>0)
				{
        			while (row = mysql_fetch_row(read))
	  				{
		  				int num_fields;
						num_fields = mysql_num_fields(read);
	  					int i;
    					for(i = 0; i < num_fields; i++)
	    				{
		    				printf("|");
			       		   	if (i == 0)
			          		{
			            		while(field = mysql_fetch_field(read))
		  			          	{
		        			    	printf("%s|", field->name);
        		    			}
			            		printf("\n");
			          		}
							printf(" %s", row[i] ? row[i] : "NULL");
	    	  			}
	  				}
					printf("\n");
 				}
 				else{
 					printf("\nNo Record with the query.");
				}
			}
		}

		else if (2 == choice)
		{
			char qry[]={"select response_number, description from grievances"};
			sprintf(stmt,qry);
			if (mysql_query(conn8,stmt))
    		{
   				printf(" Error: %s\n", mysql_error(conn8));
   				printf("Failed to execute query.");
   			}

			else
 			{
 				read = mysql_store_result(conn8);
 				int count_rows = mysql_num_rows(read);
				if (count_rows>0)
				{
        			while (row = mysql_fetch_row(read))
	  				{
		  				int num_fields;
						num_fields = mysql_num_fields(read);
	  					int i;
    					for(i = 0; i < num_fields; i++)
	    				{
		    				printf("|");
			       		   	if (i == 0)
			          		{
			            		while(field = mysql_fetch_field(read))
		  			          	{
		        			    	printf("%s|", field->name);
        		    			}
			            		printf("\n");
			          		}
							printf(" %s", row[i] ? row[i] : "NULL");
	    	  			}
	  				}
					printf("\n");
 				}
 				else{
 					printf("\nNo Record Found in the Grievance Table.");
				}
			}
		}

		else
		{
			printf("Wrong choice.");
	    }
	}
}
// Ending of the view raised grievances


// Rate or Feedback the employee
char* employee_rating()
{
	MYSQL_RES *read=NULL;
	MYSQL_ROW row=NULL;
	MYSQL_RES *read1=NULL;
	MYSQL_ROW rows=NULL;

	conn8 = mysql_init(NULL);
	mysql_real_connect(conn8, "localhost", "root", "1234","payroll", port7, NULL, 0);

	if(!conn8)
	{
		printf("Connection error");
		return "0";
	}

	else
	{
		char stmt[1500];
		char description[200];
		int temp,x=0,year=0,rate=0,e_id=0;
		char *choice;

		do
		{
			temp = 0;
			printf("Enter the Employee ID for rating: ");
  			scanf("%d",&e_id);
			char qry1[]={"select * from emp_details where emp_id=%d"};
			sprintf(stmt,qry1,e_id);
			if (mysql_query(conn8,stmt))
			{
        		printf("		Error: %s\n", mysql_error(conn8));
        		return ("		Failed to execute query.");
    		}

    		else
    		{
    			read = mysql_store_result(conn8);
				row = mysql_fetch_row(read);
				int num_rows = mysql_num_rows(read);
				if(num_rows<0)
				{
					printf("		Employee ID not found\n");
					temp=0;
				}
				else
				{
					temp=1;
				}
    		}
		}while (temp!=1);

		do
		{
			printf("Enter the rating of the employee: ");
			scanf("%d",&rate);

			if(rate <= 0)
			{
				printf("		Rating cannot be 0.\n");
				temp = 0;
			}

			else if (rate >1 && rate <=5)
			{
				rate = rate;
				temp =1;
			}

			else
			{
				printf("		Rating does not exceed 5.\n");
				temp = 0;
			}
		}while (temp!=1);

		getchar();

		do
		{
    		printf("Feedback of the employee under 200 characters\n");
			gets(description);
			x=notempty(description);
    	}while(x==0);

    	getchar();
    	do
		{
    		printf("Enter the year for rating\n");
			scanf("%d",&year);
			if(year<=YEAR && year>=MIN_YEAR)
            {
            	x=1;
			}
			else{
				printf("\t\t INVALID year\n");
			}
    	}while(x==0);

		conn9 = mysql_init(NULL);
		mysql_real_connect(conn9, "localhost", "root", "1234","payroll", port7, NULL, 0);

		if(!conn9)
		{
			printf("Connection error");
			return "0";
		}

		else
		{
			char qry4[]={"select ep.emp_id,ep.rating,ep.description,ep.year,ed.emp_id from emp_perfor ep inner join emp_details ed on (ep.emp_id=ed.emp_id)"};
			sprintf(stmt,qry4);

			if (mysql_query(conn9,stmt))
			{
        		printf("		Error: %s\n", mysql_error(conn9));
        		return ("		Failed to execute query.");
    		}

    		else
    		{
    			read1 = mysql_store_result(conn9);
				rows = mysql_fetch_row(read);
				int num_rows = mysql_num_rows(read);
				if(num_rows<0 )
				{
					char qry2[]={"insert into emp_perfor (emp_id,rating,description,year) VALUES('%d','%d','%s','%d')"};
					sprintf(stmt,qry2,rate,description,e_id,year);

					if (mysql_query(conn9,stmt))
					{
						printf("		Error: %s\n", mysql_error(conn9));
						return ("		Failed to execute query.");
					}

					else
					{
   						printf ("\n\n Rating Added. \n");
					}
				}

				else
				{
					printf("\t Already in database so going to update it.\n");
    				char qry2[]={"update emp_perfor set rating = '%d',description ='%s',year='%d' where emp_id= '%d'"};
					sprintf(stmt,qry2,rate,description,year,e_id);

					if (mysql_query(conn8,stmt))
					{
						printf("		Error: %s\n", mysql_error(conn8));
						return ("		Failed to execute query.");
					}

					else
					{
   						printf ("\n\n Rating Updated. \n");
					}
				}
			}
		}
	}
}
// End of the rating of the employee.


int emp_detail_mgmt(int emp_id)
{
    conn3=mysql_init(NULL);
    int id;
    mysql_real_connect(conn3, "localhost", "root", "1234","payroll", port7, NULL, 0);
    int i;
    printf("                Press 1 Display employee details \n");
    printf("                Press 2 Update employee details\n");
    printf("                Press 3 View employee feedback\n");
    printf("                Press 4 Change password\n");
    printf("                Press 5 Log out\n");
    scanf("%d",&i);
    switch (i)
    {
        case 1:
        {
            char stmt[1500];
            char qry[] = {"select * from emp_details where emp_id = %d"};
            int n = sprintf(stmt,qry,emp_id);
            emp_display(stmt);
            break;
        }
        case 2:
        printf("%s",update_employee(emp_id));
        break;
        case 3:
        {
            char stmt[1500];
            char qry[] = {"select * from emp_perfor where emp_id = %d"};
            int n = sprintf(stmt,qry,emp_id);
            emp_display(stmt);
            break;
        }
        case 4:
        {
            change_password(emp_id);
            break;
        }
        case 5:
            {
                return 1;
            }
        default:
            {
                printf("\nInvalid Input\n");
            }
        break;
    }
    return 0;
}
