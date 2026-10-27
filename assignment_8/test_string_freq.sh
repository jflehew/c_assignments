#! /bin/bash

# Simple tests for the string_freq program.

run () {
  echo "$*"
  if $*
  then echo 'success'
  else echo 'error'
  fi
}

# A few valid inputs.
run ./string_freq <<EOF
"Despair, or folly?" said Gandalf. "It is not despair, for despair is only for those who see the end beyond all doubt. We do not. It is wisdom to recognize necessity, when all other courses have been weighed, though as folly it may appear to those who cling to false hope. Well, let folly be our cloak, a veil before the eyes of the Enemy! For he is very wise, and weighs all things to a nicety in the scales of his malice. But the only measure that he knows is desire, desire for power; and so he judges all hearts. Into his heart the thought will not enter that any will refuse it, that having the Ring we may seek to destroy it. If we seek this, we shall put him out of reckoning."
EOF

echo "=================================================================================="


run ./string_freq -s 8 <<EOF
attention home planet STOP prepare invasion STOP earth is
ripe for the taking STOP see you soon FULL STOP
EOF

echo "=================================================================================="


run ./string_freq -s 10 <<EOF
“At least for a while,” said Elrond. “The road must be trod, but it will be very hard. And neither strength nor wisdom will carry us far upon it. This quest may be attempted by the weak with as much hope as the strong. Yet such is oft the course of deeds that move the wheels of the world: small hands do them because they must, while the eyes of the great are elsewhere.”
EOF

echo "=================================================================================="


# Test empty set of strings.
run ./string_freq <<EOF
EOF

echo "=================================================================================="


# Test usage message.
run ./string_freq -h <<EOF
abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789 ~!@#$%^&*
EOF

echo "=================================================================================="


# These last runs test invalid command line input.

run ./string_freq -s 100 <<EOF
blah blah
EOF

run ./string_freq -s <<EOF
this is not looking good
EOF

run ./string_freq -s -h <<EOF
not looking good either
EOF

run ./string_freq -s 16 -w <<EOF
one more dud
EOF

exit 0
