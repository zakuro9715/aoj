<?php 
$n = trim(fgets(STDIN));
$m = 1;
for(; $n > 0; $n--)
  $m *= $n;
echo $m . "\n";
