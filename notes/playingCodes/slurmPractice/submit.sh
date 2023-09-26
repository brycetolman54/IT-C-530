#!/bin/bash

# run the job first
job_id=$(sbatch --parsable energize.sh)

# now we can pass that id into the next part
sbatch analyze.sh $job_id
