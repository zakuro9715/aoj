<?php
while(1)
{
  $d = $a = -PHP_INT_MAX;
  
  fscanf(STDIN, "%d", $n);
  if(!$n)
    break;
  for($i = 0; $i < $n; $i++)
  {
    fscanf(STDIN, "%d", $m);
    $d = max($d + $m, $m);
    $a = max($a, $d);
  }
  echo $a . "\n";
}
