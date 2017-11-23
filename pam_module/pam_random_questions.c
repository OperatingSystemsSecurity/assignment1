// author: Hendrik Werner s4549775

#define PAM_SM_AUTH

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <security/pam_appl.h>
#include <security/pam_modules.h>

void str_tolower(char *str) {
	for (char *c = str; *c; c++) {
		*c = tolower(*c);
	}
}

bool question1() {
	int integer1 = rand() % 100;
	int integer2 = rand() % 100;
	int answer;
	printf("%d + %d = ", integer1, integer2);
	scanf("%d", &answer);
	return answer == integer1 + integer2;
}

bool question2() {
	char answer[32];
	printf("%s", "Which planet is the third from the sun? ");
	scanf("%s", &answer);
	str_tolower(answer);
	return strcmp(answer, "earth") == 0;
}

bool question3() {
	int answer;
	printf("%s", "sin(0.5 * pi) = ");
	scanf("%d", &answer);
	return answer == 1;
}

bool question4() {
	char answer[32];
	printf("%s",
		"What are the first four characters of Valeesha Moonsamy's "
		"fingerprint? (see veelasha.org) "
	);
	scanf("%s", answer);
	str_tolower(answer);
	return strcmp(answer, "231c") == 0;
}

int pam_sm_authenticate(
	pam_handle_t *pamh
	, int flags
	, int argc
	, const char **argv
) {
	bool (*questions[])() = {
		&question1
		, &question2
		, &question3
		, &question4
	};
	if (questions[rand() % 1]()) {
		return PAM_SUCCESS;
	} else {
		return PAM_AUTH_ERR;
	}
}

int pam_sm_setcred(
	pam_handle_t *pamh
	, int flags
	, int argc
	, const char **argv
) {
	return PAM_IGNORE;
}
