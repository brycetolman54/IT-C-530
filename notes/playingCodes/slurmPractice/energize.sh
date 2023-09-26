#!/bin/bash


#SBATCH -N1 -n1 --mem-per-cpu=100M -t00:05:00 --qos=test --output=%A.%a.nrg

echo $SLURM_ARRAY_TASK_ID $RANDOM
