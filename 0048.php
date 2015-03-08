<?php while($n = trim(fgets(STDIN)))
{
  if($n>91)
    $a = 'heavy';
  else if($n>81)
    $a = 'light heavy';
  else if($n>75)
    $a = 'middle';
  else if($n>69)
    $a = 'light middle';
  else if($n>64)
    $a = 'welter';
  else if($n>60)
    $a = 'light welter';
  else if($n>57)
    $a = 'light';
  else if($n>54)
    $a = 'feather';
  else if($n>51)
    $a = 'bantam';
  else if($n>48)
    $a = 'fly';
  else
    $a = 'light fly';
  echo $a . "\n";
}
