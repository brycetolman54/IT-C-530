# Checkpointing

- checkpointing allows us to save our space in a program in the event of:
  - crashing
  - debugging several hours into the program
  - saving work that we cannot do in one sitting

- We can submit jobs on the supercomputer with slurm
  - We can do this in the script file specifying the parameters with SBATCH or
  - we can also put the parameters in the command line
  - What are they?
    - [ ] number of nodes (N#)
    - [ ] number of cpus (n#)
    - [ ] mem-per-cpu=xM (megabytes)
    - [ ] time (txx:xx:xx, h:m:s)
    - [ ] --qos=test (if we want it there quick
    - [ ] the file to run (or -J thenTheFile if you are doing SBATCH)

- `scontrol show job #` will show you about the job you have run
- you can run `sbatch -H jobName` to put a job on hold
- you can use `squeue -u username` to look at what all you have running or held
- you can use `scancel #` to cancel your jobs
