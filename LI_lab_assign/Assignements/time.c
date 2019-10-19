/* localtime example */
#include <stdio.h>
#include <time.h>

int main (int argc,char **argv)
{
  time_t ptime;
  struct tm * timeinfo;

  time ( &ptime );
  timeinfo = localtime ( &ptime );

  printf("%d\n", timeinfo -> tm_min);

  char *s = argv[1];
  char hours[3];
  char mins[3];
 int i = 0;
  while(*s !=':')
  {
	hours[i] = *s;
	i++;
	s++;
  }
  hours[i] = '\0';
  i=0;
  s++;
  while(*s)
  {
  	  mins[i]=*s;
  	  i++;
  	  s++;
  }
  mins[2] = '\0';
  printf ("%s:%s\n",hours,mins);
  char min,hour;	
 if(atoi(mins) < timeinfo -> tm_min)
 {
	min = 60 + atoi(mins) - timeinfo -> tm_min;
	hour = atoi(hours) - 1 - timeinfo -> tm_hour;
 }
 else
 {
 	 min = atoi(mins) - timeinfo -> tm_min;
 }

  return 0;
}
