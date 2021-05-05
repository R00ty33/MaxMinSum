/*******************************/
/****** Nicholas Rudolph  ******/
/******         		  ******/
/******                   ******/
/****** Mar 28, 2020      ******/
/******                   ******/
/******                   ******/
/*******************************/


/****    D I R E C T I V E S    *****/
#include <stdio.h> /* printf */
#include <stdlib.h> /* for generating random number */
#include <string.h>
#include <time.h>  /* seeding */
#include <stdbool.h> /* boolean */
#include <ctype.h> /* isalpha(), toupper(), tolower() */

/****    M A C R O S    ****/

/****    F U N C T I O N S    ****/
/**** MIN FUNCTION ****/
/** returns the minimum of data[1]-data[total] */
float min(int total, char *data[total]) {
	float min_value;
	if (total == 1) {
		min_value = atof(data[1]);
	}
	else {
		min_value = atof(data[1]);
		for (int i = 1; i <= total; i++) {
			if (atof(data[i]) < min_value) {
				min_value = atof(data[i]);
			}
		}
	}
	return min_value;
}

/**** MAX FUNCTION ****/
/** it returns the maximum of data[1]~data[total]  */
float max(int total, char *data[total]){
	float max_value;
	if (total == 1) {
		max_value = atof(data[1]);
	}
	else {
		max_value = atof(data[1]);
		for (int i = 1; i <= total; i++) {
			if (atof(data[i]) > max_value) {
				max_value = atof(data[i]);
			}
		}
	}
	return max_value;
}

/**** MIN2 FUNCTION ****/
/** it returnsthe second minimum of data[1]~data[total] */
float min2(int total, char *data[total]) {
	float min_value, min2_value;
	if (total == 1) {
		min2_value = atof(data[1]);
	}
	else {
		min_value = max(total, data);

		for (int i = 1; i <= total; i++) {
			if (atof(data[i]) < min_value) {
				min2_value = min_value;
				min_value = atof(data[i]);
			}
			else if (atof(data[i]) < min2_value && atof(data[i]) != min_value) {
				min2_value = atof(data[i]);
			}
		}
	}
	return min2_value;
}


/**** MAX2 FUNCTION ****/
/** it returns the second maximum of data[1]~data[total]  */
float max2(int total, char *data[total]){
	float max_value, max2_value;
	if (total == 1) {
		max2_value = atof(data[1]);
	}
	else {
		max_value = min(total, data);

		for (int i = 1; i <= total; i++) {
			if (atof(data[i]) > max_value) {
				max2_value = max_value;
				max_value = atof(data[i]);
			}
			else if (atof(data[i]) > max2_value && atof(data[i]) != max_value) {
				max2_value = atof(data[i]);
			}
		}
	}
	return max2_value;
}

/**** SUM_AVG ****/
/* it returns the sum and average of data[1]~data[total] through its 3rd and 4th parameters, respectively. */
void sum_avg(int total, char *data[total], float *sum, float *average){
	*sum = 0.0;
	for (int i = 1; i <= total; i++) {
		*sum = *sum + atof(data[i]);
	}
	*average = *sum / total;
}

/******** DRIVER ********/
int main(int argc, char *argv[])
{
    /******** DATA FIELDS ********/
	float min_value, min2_value, max_value, max2_value, sum_value, avg_value;

	if (argc == 1) {
		printf("You must enter at least one number after program name.\n");
	} else {
		printf("\nTotal numbers enter = %d\n", argc - 1);
		min_value = min(argc - 1, argv);
		printf("min = %.3f\n", min_value);
		min2_value = min2(argc - 1, argv);
		printf("min2 = %.3f\n", min2_value);
		max_value = max(argc - 1, argv);
		printf("max = %.3f\n", max_value);
		max2_value = max2(argc - 1, argv);
		printf("max2 = %.3f\n", max2_value);
		sum_avg(argc - 1, argv, &sum_value, &avg_value);
		printf("sum = %.3f\n", sum_value);
		printf("avg = %.3f\n", avg_value);
	}

	return 0;
} // end of main