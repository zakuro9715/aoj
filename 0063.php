<?php
$a = 0;
while(!feof(STDIN))
{
  $s = "";
  fscanf(STDIN, "%s", $s);
  if($s == "")
    break;
  $b = true;
  for($i = 0; $i < strlen($s); $i++)
  {
    if($s[$i] != $s[strlen($s) - $i - 1])
      $b = false;
  }
  if($b)
    $a++;
}
echo $a . "\n";
