<?php
$a = array(0, 0, 0, 0, 0);
fscanf(STDIN, "%d %d %d %d %d", $a[0], $a[1], $a[2], $a[3], $a[4]);
rsort($a);
fprintf(STDOUT, "%d %d %d %d %d\n", $a[0], $a[1], $a[2], $a[3], $a[4]);
