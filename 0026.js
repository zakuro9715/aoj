var input = "";
var mem = new Array(10);
for(var i = 0; i < 10; i++)
{
  mem[i] = new Array(10);
  for(var j = 0; j < 10; j++)
    mem[i][j] = 0;
}
var dx = [
  [0, -1, 0, 1, 0],
  [-1, 0, 1, -1, 0, 1, -1, 0, 1],
  [0, -1, 0, -1, -2, -1, 0, 1, 2, -1, 0, 1, 0]
]
var dy =[
  [-1, 0, 0, 0, 1],
  [-1, -1, -1, 0, 0, 0, 1, 1, 1,],
  [-2, -1, -1, -1, 0, 0, 0, 0, 0, 1, 1, 1, 2]
]
process.stdin.resume();
process.stdin.setEncoding('utf8');
process.stdin.on('data', function(chunk){input += chunk});
process.stdin.on('end', function()
{
  input = input.split('\n');
  for(var i = 0; i < input.length; i++)
  {
    s = input[i].split(',');
    x = Number(s[0]);
    y = Number(s[1]);
    v = Number(s[2]) - 1;
    for(var j in dx[v])
      if(!(x + dx[v][j] < 0 || x + dx[v][j] >= 10 || y + dy[v][j] < 0 || y + dy[v][j] >= 10))
        mem[x + dx[v][j]][y + dy[v][j]] += 1;
  }
  m = 0;
  b = 0;
  for(var i = 0; i < 10; i++)
  {
    for(var j = 0; j < 10; j++)
    {
      if(mem[i][j] == 0)
        b++;
      m = Math.max(m, mem[i][j]);
    }
  }
  console.log(b);
  console.log(m);
});
