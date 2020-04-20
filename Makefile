# ------------------------------------------------
# Generic Makefile
#
# @author Arshpreet Singh -
# @author Jagdeep Singh -
# @author Puneet Singh -
# @author Varinder Singh Dhanda -varinderdhanda@cmail.carleton.ca
# 

# Date  : 2020-04-18
#
# Changelog :
# 2020-04-18: Inital Draft
# 2020-04-18: Makefile
#
# ------------------------------------------------

# project name (generate executable with this name)
TARGET   = PAYROLL

# change these to proper directories where each file should be


SRCDIR     	 = src
SRCTESTDIR	 = test
OBJDIR    	 = obj
BINDIR    	 = bin
INCDIR	  	 = include

CC       = gcc
INC      := -I$(INCDIR)
#starting of compilation of all source files...........
PAYROLL:
	
	$(CC) -g -O -c $(SRCDIR)/Main.c -fPIC -DPIC -o $(OBJDIR)/Main.o

	$(CC) -g -O -c $(SRCDIR)/validation.c -fPIC -DPIC -o $(OBJDIR)/validation.o
	
	$(CC) -g -O -c $(SRCDIR)/employee_management.c -fPIC -DPIC -o $(OBJDIR)/employee_management.o
	
	$(CC) -g -O -c $(SRCDIR)/employee.c -fPIC -DPIC -o $(OBJDIR)/employee.o
	
	$(CC) -g -O -c $(SRCDIR)/employee_personal_dtl_management.c -fPIC -DPIC -o $(OBJDIR)/employee_personal_dtl_management.o
	
	$(CC) -g -O -c $(SRCDIR)/employee_attdnce_management.c -fPIC -DPIC -o $(OBJDIR)/employee_attdnce_management.o

	$(CC) -g -O -c $(SRCDIR)/admin_attend_mgmt.c -fPIC -DPIC -o $(OBJDIR)/admin_attend_mgmt.o

	$(CC) -g -O -c $(SRCDIR)/manager_dept_management.c -fPIC -DPIC -o $(OBJDIR)/manager_dept_management.o

	$(CC) -g -O -c $(SRCDIR)/admin_dept_management.c -fPIC -DPIC -o $(OBJDIR)/admin_dept_management.o

	$(CC) -g -O -c $(SRCDIR)/attendance_display.c -fPIC -DPIC -o $(OBJDIR)/attendance_display.o

	$(CC) -g -O -c $(SRCDIR)/leave_request.c -fPIC -DPIC -o $(OBJDIR)/leave_request.o

	$(CC) -g -O -c $(SRCDIR)/salary_management.c -fPIC -DPIC -o $(OBJDIR)/salary_management.o
	
	$(CC) -g -O -c $(SRCTESTDIR)/test.c -fPIC -DPIC -o $(OBJDIR)/objtest/test.o
	
	
	
	$(CC) -o $(BINDIR)/$(TARGET) $(OBJDIR)/*.o libmysql.dll
	
	$(CC) -o $(BINDIR)/test $(OBJDIR)/objtest/test.o  $(OBJDIR)/employee_management.o $(OBJDIR)/validation.o $(OBJDIR)/employee.o $(OBJDIR)/employee_personal_dtl_management.o $(OBJDIR)/employee_attdnce_management.o $(OBJDIR)/admin_attend_mgmt.o $(OBJDIR)/manager_dept_management.o $(OBJDIR)/admin_dept_management.o $(OBJDIR)/attendance_display.o $(OBJDIR)/leave_request.o $(OBJDIR)/salary_management.o libmysql.dll
	


	@echo "Now you can run test and Payroll files from  bin directory by using following commands"
	@echo "bin/./Payroll"
	@echo "bin/./test"
.PHONY: clean
clean:
	@$(rm) $(BINDIR)/$(TARGET)
	@$(rm) payroll.txt
	@echo "Cleanup complete!"