#!/bin/bash


#SBATCH -N1 -n1 --mem-per-cpu=100M -t00:05:00 --output=%A.%a.nrg

#SBATCH --array 1-10:1

echo $SLURM_ARRAY_TASK_ID $RANDOM
