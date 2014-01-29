/*
*  doomsday.c
*  A program to test a function dayOfWeek which determines which
*  day of the week a particular date falls on.
*  (only for dates after the start of the Gregorian calendar).
*
*  Program stub created by Richard Buckland on 27/03/12
*  This program by YOUR-NAME-HERE
*  Freely licensed under Creative Commons CC-BY-3.0
*
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define THURSDAY 0
#define FRIDAY   1
#define SATURDAY 2
#define SUNDAY   3
#define MONDAY   4
#define TUESDAY  5
#define WEDNESDAY 6

#define TRUE 1
#define FALSE 0
#define DAYS_PER_WEEK 7

int dayOfWeek(int doomsday, int leapYear, int month, int day);
int isLeapYear(int year);


int day;
int month;
int year;
int doomsday;
int leapYear;

int main(int argc, char *argv[]) {


	assert(dayOfWeek(THURSDAY, FALSE, 4, 4) == THURSDAY);
	assert(dayOfWeek(FRIDAY, FALSE, 6, 6) == FRIDAY);
	assert(dayOfWeek(MONDAY, FALSE, 8, 8) == MONDAY);
	assert(dayOfWeek(WEDNESDAY, FALSE, 10, 10) == WEDNESDAY);
	assert(dayOfWeek(FRIDAY, FALSE, 12, 12) == FRIDAY);
	assert(dayOfWeek(THURSDAY, FALSE, 9, 5) == THURSDAY);
	assert(dayOfWeek(FRIDAY, FALSE, 5, 9) == FRIDAY);
	assert(dayOfWeek(SUNDAY, FALSE, 7, 11) == SUNDAY);
	assert(dayOfWeek(TUESDAY, FALSE, 11, 7) == TUESDAY);
	assert(dayOfWeek(WEDNESDAY, FALSE, 3, 7) == WEDNESDAY);

	assert(dayOfWeek(THURSDAY, FALSE, 4, 5) == FRIDAY);
	assert(dayOfWeek(SATURDAY, FALSE, 6, 5) == FRIDAY);
	assert(dayOfWeek(MONDAY, FALSE, 8, 9) == TUESDAY);
	assert(dayOfWeek(WEDNESDAY, FALSE, 10, 9) == TUESDAY);
	assert(dayOfWeek(FRIDAY, FALSE, 12, 20) == SATURDAY);
	assert(dayOfWeek(THURSDAY, FALSE, 9, 9) == MONDAY);
	assert(dayOfWeek(FRIDAY, FALSE, 5, 5) == MONDAY);
	assert(dayOfWeek(SUNDAY, FALSE, 7, 7) == WEDNESDAY);
	assert(dayOfWeek(TUESDAY, FALSE, 11, 11) == SATURDAY);
	assert(dayOfWeek(THURSDAY, FALSE, 3, 30) == SATURDAY);

	assert(dayOfWeek(TUESDAY, FALSE, 2, 28) == TUESDAY);
	assert(dayOfWeek(TUESDAY, FALSE, 2, 27) == MONDAY);
	assert(dayOfWeek(THURSDAY, FALSE, 1, 3) == THURSDAY);
	

	printf("all tests passed - You are awesome!\n");

	printf("Enter Day(DD)\n");
	scanf("%d", &day);
	printf("Enter Month(MM)\n");
	scanf("%d", &month);
	printf("Enter Year(YYYY)\n");
	scanf("%d", &year);

	doomsday = (TUESDAY + year + (year / 4) - (year / 100) + (year / 400)) % 7;
	printf("%d is doomsday\n", doomsday);
	int isLeapYear(int year);
	int dayOfWeek(int doomsday, int leapYear, int month, int day);
	printf("%d is day of week", dayOfWeek);

	return EXIT_SUCCESS;
}


// given the doomsday for a year, and whether or not it is a
// leap year, this function return the day of the week for any
// given month and day in the year.

int dayOfWeek(int doomsday, int leapYear, int month, int day) {
	
	int dayOfWeek;
	int doomsdate;

	// INSERT YOUR CODE HERE
	
	printf("%d is month\n", month);
	printf("%d is day\n", day);
	printf("New Check\n");
	

	//doomsday = 31/1(32ifleap), 28/2(29ifleap), 0/3, 4/4, 9/5, 6/6, 11/7, 8/8, 5/9, 10/10, 7/11, 12/12
	//aka if doomsday = jeudi = le 4 avril est un jeudi

	if (month == 1)
	{
		if (leapYear == TRUE)
		{
			doomsdate = 32;
		}
		else
		{
			doomsdate = 31;
		}
	}
	if (month == 2)
	{
		if (leapYear == TRUE)
		{
			doomsdate = 29;
		}
		else
		{
			doomsdate = 28;
		}
	}
	if (month == 3)
	{
		doomsdate = 0;
	}
	if (month == 4)
	{
		doomsdate = 4;
	}
	if (month == 5)
	{
		doomsdate = 9;
	}
	if (month == 6)
	{
		doomsdate = 6;
	}
	if (month == 7)
	{
		doomsdate = 11;
	}
	if (month == 8)
	{
		doomsdate = 8;
	}
	if (month == 9)
	{
		doomsdate = 5;
	}
	if (month == 10)
	{
		doomsdate = 10;
	}
	if (month == 11)
	{
		doomsdate = 7;
	}
	if (month == 12)
	{
		doomsdate = 12;
	}
	printf("%d is doomsdate\n", doomsdate);
	
	//faut kisspasskekchose icitte
	if ((doomsday - ((doomsdate - day) % 7)) > 0)
	{
		dayOfWeek = (doomsday - ((doomsdate - day)) % 7 );
		printf("+\n");
	}
	else if ((doomsdate - day) == 0)
	{
		dayOfWeek = ((doomsday + ((day - doomsdate) % 7)) % 7);
		printf("-\n");
	}

	else
	{
		dayOfWeek = ((doomsday + ((day - doomsdate)%7)) % 7 ) + 7;
		printf("-\n");
	}

	if (dayOfWeek > 6)
	{
		dayOfWeek = dayOfWeek - 7 ;
	}
	//dayOfWeek = (doomsday - (doomsdate - day)) % 7;
	printf("%d is day of week\n\n", dayOfWeek);

	return (dayOfWeek);

}


int isLeapYear(int year)
{

	int leapYear;

	if ((year % 4) == 0) {
		if ((year % 100) == 0) 
		{
			if ((year % 400) == 0) 
			{
				leapYear = TRUE;
			}
			else
			{
				leapYear = FALSE;
			}
		}
		else
		{
			leapYear = TRUE;
		}
	}
	else
	{
		leapYear = FALSE;
	}
	return leapYear;
}

