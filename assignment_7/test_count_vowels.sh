#! /bin/bash

# Simple test for the count_vowels program.

run () {
  echo "$*"
  if $*
  then echo 'success'
  else echo 'error'
  fi
}

run ./count_vowels <<EOF
To sleep, perchance to dream. 
EOF
echo '-----------------------------------'

run ./count_vowels <<EOF
At last they came up the long road, and reached the very pass where the goblins had captured them before. But they came to that high point at morning, and looking backward they saw a white sun shining over the outstretched lands. There behind lay Mirkwood, blue in the distance, and darkly green at the nearer edge even in the spring. There far away was the Lonely Mountain on the edge of eyesight. On its highest peak snow yet unmelted was gleaming pale.
EOF
echo '-----------------------------------'

run ./count_vowels <<EOF
Peiorem semper sequitur conclusio partem. Blah blah blah 
EOF
echo '-----------------------------------'

run ./count_vowels <<EOF
abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789 ~!@#$%^&*
EOF
echo '-----------------------------------'

run ./count_vowels <<EOF
EOF

exit 0
