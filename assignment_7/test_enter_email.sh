

run () {
    echo "$*"
    if $*
    then echo 'success'
    else echo 'error'
    fi
}

# valid
run ./enter_email Iamanemail@gmail.com
run ./enter_email john.doe@gmail.com
run ./enter_email john_doe@gmail.com
run ./enter_email john-doe@gmail.com
run ./enter_email john123@gmail.com
run ./enter_email a@b.com

# multiple @ symbols
run ./enter_email Iamanemail@@gmail.com
run ./enter_email john@gmail@com
run ./enter_email @@gmail.com

# missing @
run ./enter_email Iamanemailgmail.com
run ./enter_email john.doe.com

# missing period after @
run ./enter_email Iamanemail@gmailcom
run ./enter_email john@gmail

# bad period placement
run ./enter_email Iamanemail@gmail..com
run ./enter_email Iamanemail@gmail.
run ./enter_email Iamanemail@.com

# missing portions
run ./enter_email @gmail.com
run ./enter_email john@com
run ./enter_email john@
run ./enter_email @

# illegal characters
run ./enter_email john!doe@gmail.com
run ./enter_email john#doe@gmail.com
run ./enter_email john@gmail!.com
run ./enter_email john@gmail.c_m

# argument-count tests
run ./enter_email
run ./enter_email john@gmail.com extra_argument

exit 0