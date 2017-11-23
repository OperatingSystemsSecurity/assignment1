// author: Hendrik Werner s4549775

#define PAM_SM_AUTH

#include <security/pam_appl.h>
#include <security/pam_modules.h>

int pam_sm_authenticate(
	pam_handle_t *pamh
	, int flags
	, int argc
	, const char **argv
) {
	return PAM_SUCCESS;
}

int pam_sm_setcred(
	pam_handle_t *pamh
	, int flags
	, int argc
	, const char **argv
) {
	return PAM_IGNORE;
}
