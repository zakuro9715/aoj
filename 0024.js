var input = "";
process.stdin.resume();
process.stdin.setEncoding('utf8');
process.stdin.on('data', function(chunk){input += chunk});
process.stdin.on('end', function()
{
  input = input.split('\n');
  for(var i = 0; i < input.length - 1; i++)
  {
    a = Math.pow(input[i] / 9.8, 2)  * 4.9;
    for(var j = 1; ; j++)
    {
      if(j * 5 - 5 >= a)
      {
        console.log(j);
        break;
      }
    }
  }
});
