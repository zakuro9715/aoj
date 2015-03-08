var ii = 0;
function read()
{
  return Number(input[ii++]);
}
var input = "";
process.stdin.resume();
process.stdin.setEncoding('utf8');
process.stdin.on('data', function(chunk){input += chunk});
process.stdin.on('end', function()
{
  input = input.split('\n');
  while(1)
  {
    n = read();
    if(n == 0)
      break;
    var a = -10000000, d = -1000000;
    for(var i = 0; i < n; i++)
    {
      m = read();
      d = Math.max(d + m, m);
      a = Math.max(a, d);
    }
    console.log(a);
  }
});
