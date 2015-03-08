<?php
$x = 0; $y = 0;
while(!feof(STDIN))
{
  fscanf(STDIN, "%d,%d,%d", $a, $b, $c);
  if($a * $a + $b * $b == $c * $c)
    $x++;
  if($a === $b)
    $y++;
}
echo $x . "\n" . $y . "\n";
