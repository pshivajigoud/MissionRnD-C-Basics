/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int validate(char* dob1, char* dob2);
int check(int d1, int m1, int y1, int d2, int m2, int y2);
int isOlder(char *dob1, char *dob2) {
	int val_check;
	val_check = validate(dob1, dob2);
	return val_check;

}
int validate(char* dob1, char* dob2){
	int d1 = 0, m1 = 0, y1 = 0, d2 = 0, m2 = 0, y2 = 0, i = 0, flag = 0;
	while (dob1[i] != '\0'){
		if (dob1[i] == '-' || (dob1[i] > 47 && dob1[i] < 58)){
			if (i == 0 || i == 1){
				d1 = d1 * 10 + (dob1[i] - 48);
			}
			if (i == 3 || i == 4){
				m1 = m1 * 10 + (dob1[i] - 48);
			}
			if (i == 6 || i == 7 || i == 8 || i == 9) {
				y1 = y1 * 10 + (dob1[i] - 48);
			}
			i++;
		}
		else{
			flag = -1;
			break;
		}
	}
	if ((i != 10) && (flag == 0))
		flag = -1;
	i = 0;
	while ((dob2[i] != '\0') && (flag == 0)){
		if (dob2[i] == '-' || (dob2[i] > 47 && dob2[i] < 58)){
			if (i == 0 || i == 1){
				d2 = d2 * 10 + (dob2[i] - 48);
			}
			if (i == 3 || i == 4){
				m2 = m2 * 10 + (dob2[i] - 48);
			}
			if (i == 6 || i == 7 || i == 8 || i == 9) {
				y2 = y2 * 10 + (dob2[i] - 48);
			}
		}
		else{
			flag = -1;
			break;
		}
		i++;
	}
	if ((i != 10) && (flag == 0))
		flag = -1;
	if ((flag == 0) && ((m1>12) || (m2 > 12)))
		flag = -1;
	if ((flag == 0) && (((y1 % 4) == 0) && (m1 == 2) && (d1 > 29)))
		flag = -1;
	if ((flag == 0) && (((y2 % 4) == 0) && (m2 == 2) && (d2 > 29)))
		flag = -1;
	if ((flag == 0) && (((y1 % 4) != 0) && (m1 == 2) && (d1 > 28)))
		flag = -1;
	if ((flag == 0) && (((y2 % 4) != 0) && (m2 == 2) && (d2 > 28)))
		flag = -1;
	if (flag == 0){
		flag = check(d1, m1, y1, d2, m2, y2);
	}
	return flag;
}
int check(int d1, int m1, int y1, int d2, int m2, int y2){
	if (d1 == d2 && m1 == m2 && y1 == y2)
		return 0;
	if (y1 > y2)
		return 2;
	else if (y1 < y2)
		return 1;
	else if (y1 == y2){
		if (m1 > m2)
			return 2;
		else if (m1 < m2)
			return 1;
		else if (m1 == m2){
			if (d1 > d2)
				return 2;
			else if (d1 < d2)
				return 1;
		}

	}
}

