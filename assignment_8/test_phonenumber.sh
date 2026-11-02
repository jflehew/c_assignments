run () {
    echo "$*"
    if $*
    then echo 'success'
    else echo 'error'
    fi
}

#Valid: First type
run ./phonenumber <<EOF
(888) 800-1808
EOF
echo '------------------------------'

# Valid: second Type
run ./phonenumber <<EOF
999-189-4444
EOF
echo '------------------------------'

# Valid: all zeros
run ./phonenumber <<EOF
(000) 000-0000
EOF
echo '------------------------------'

# Valid: no parentheses format
run ./phonenumber <<EOF
123-456-7890
EOF
echo '------------------------------'

# Invalid: missing space after )
run ./phonenumber <<EOF
(888)800-1808
EOF
echo '------------------------------'

# Invalid: space in wrong location
run ./phonenumber <<EOF
(888) 800 1808
EOF
echo '------------------------------'

# Invalid: wrong separator
run ./phonenumber <<EOF
888.800.1808
EOF
echo '------------------------------'

# Invalid: missing dash
run ./phonenumber <<EOF
888-8001808
EOF
echo '------------------------------'

# Invalid: extra digit
run ./phonenumber <<EOF
888-800-18088
EOF
echo '------------------------------'

# Invalid: missing digit
run ./phonenumber <<EOF
888-800-180
EOF
echo '------------------------------'

# Invalid: letter in area code
run ./phonenumber <<EOF
8A8-800-1808
EOF
echo '------------------------------'

# Invalid: letter in middle section
run ./phonenumber <<EOF
888-8A0-1808
EOF
echo '------------------------------'

# Invalid: letter in final section
run ./phonenumber <<EOF
888-800-18A8
EOF
echo '------------------------------'

# Invalid: missing closing parenthesis
run ./phonenumber <<EOF
(888 800-1808
EOF
echo '------------------------------'

# Invalid: wrong character where ) should be
run ./phonenumber <<EOF
(888- 800-1808
EOF
echo '------------------------------'

# Invalid: starts with a space
run ./phonenumber <<EOF
 888-800-1808
EOF
echo '------------------------------'

# Invalid: starts with a letter
run ./phonenumber <<EOF
A88-800-1808
EOF
echo '------------------------------'

# Invalid: empty-ish formatting
run ./phonenumber <<EOF
--- 
EOF
echo '------------------------------'