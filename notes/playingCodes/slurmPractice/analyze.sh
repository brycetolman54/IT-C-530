#!/bin/bash

#SBATCH -N1 -n1 --mem-per-cpu=100M -t00:05:00

files=$(ls | grep ^$1.*.nrg)

cat $files | awk -v lowNRG="0" -v id="0" -f analyze.awk


