//
// Created by khoa on 24/04/2017.
//

#ifndef NATIVE_VALIDATOR_H
#define NATIVE_VALIDATOR_H

#define EMAIL_PATTERN "^[[:alnum:]._]+[@][a-z]{3,10}[.][a-z]{2,5}"
#define URL_PATTERN   "http(s|)://[[:alnum:].-]+[.][a-z]{2,5}([:digit:]{1,5}||)[[:alnum:]?<>+=!/:]+"
#define PHONE_PATTERN "(01[2689]|09|08)[0-9]{8}"

int match_email(char *email);
int match_phone_number(char *phone_number);
int match_url(char *url);

#endif //NATIVE_VALIDATOR_H
