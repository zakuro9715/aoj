while true
  n, x, a = gets.strip.to_i, 1, 0
  break if n == 0
  n.times { |i| x *= (i + 1) }
  while x % 10 == 0
    a += 1
    x /= 10
  end
  puts a
end
