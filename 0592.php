<?php
$ave = 0;
for($i = 0; $i < 5; $i++)
{
  fscanf(STDIN, "%d", $n);
  if($n < 40)
    $n = 40;
  $ave += $n / 5;
}
echo $ave . "\n";
