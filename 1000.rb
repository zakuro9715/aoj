while s = gets
  a, b = s.split.map(&:to_i)
  puts a + b
end
