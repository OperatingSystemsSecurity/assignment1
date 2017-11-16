---
title: Assignment 1
author: Hendrik Werner s4549775
date: \today
fontsize: 12pt
geometry: margin=5em
---

# 1
## a

* Require passsword to use `rm`

	**/etc/pam.d/rm**

		auth sufficient pam_unix.so

	Szenario: Peter always accidentally deleted his files. Therefore he wants to require athentication, so this does not happen as often.

* 2-factor authentication for `dd`

	**/etc/pam.d/dd**

		auth reqisite pam_second_factor.so
		auth sufficient pam_unix.so

	Szenario: It's very easy to do damage with `dd`, so the admin wants to make sure that users really are who they pretend to be.

* Require either password or second factor key to use `less`

	**/etc/pam.d/less**

		auth sufficient pam_second_factor.so
		auth required pam_unix.so

	(There is no module named `pam_second_factor.so`, but there is, for example, a `pam_google_authenticator.so` module, which is not default, but can be installed.)

	Szenario: `less` is pretty harmless, so the admin wants to make it's use easier, so he allows to use your password, or your athentication code. Users can use whatever is more convenient at the time.

* Write to some logfile after login

	**/etc/pam.d/login**

		auth required pam_unix.so
		auth optional pam_write_file.so /var/log/login "Sucessful login"

	(I made up the `pam_write_file.so` module. It should be obvious what it does: Write `$2` to file `$1`.)

	Szenario: A reseachers wants to find out how many people sucesfully log into the computer every day. He uses this ruleset to keep logs.

## b

# 2
