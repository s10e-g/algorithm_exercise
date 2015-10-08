#!/bin/sh
until [[ -s different ]]
do
    head /dev/urandom | cksum | cut -f1 -d" " > srand
    ./rand
    cat in.txt | ./a.out > out_a.txt
    cat in.txt | ./b.out > out_b.txt
    diff out_a.txt out_b.txt > different
done
