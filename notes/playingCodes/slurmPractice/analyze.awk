#!/bin/bash/awk

{
  if ((lowNRG==0 || $2<lowNRG))
  {  
    lowNRG=$2;
    id=$1; 
  }

}
END {print id, lowNRG}

